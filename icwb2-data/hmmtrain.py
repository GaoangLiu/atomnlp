import os
import pickle
import math
import json
import operator
from collections import defaultdict
from dofast.utils import info
from typing import List


class HMM:
    TRAIN_CORPUS = 'training/msrHMMing.utf8'
    punctuations = set('，‘’“”。！？：')
    MIN_FLOAT = -1e10

    @classmethod
    def train(cls) -> (dict, dict, list):
        if all(os.path.exists(f) for f in ('emit_p.pickle', 'trans.pickle')):
            emit_p = pickle.load(open('emit_p.pickle', 'rb'))
            trans = pickle.load(open('trans.pickle', 'rb'))
            return emit_p, trans, {}

        emit_p = defaultdict(int)
        ci = defaultdict(int)
        # b0 m1 e2 s3
        trans = [[0] * 4 for _ in range(4)]
        _map = {'b': 0, 'm': 1, 'e': 2, 's': 3}

        def update_trans(i, j):
            if i < 0: return j
            trans[i][j] += 1
            return j

        with open(cls.TRAIN_CORPUS, 'r') as f:
            for ln in f.readlines():
                pre_symbol = -1
                _words = ln.split(' ')
                for cur in _words:
                    if not cur: continue
                    elif cur in cls.punctuations:
                        pre_symbol = -1
                    else:
                        if len(cur) == 1:
                            emit_p[(cur, 'S')] += 1
                            ci['S'] += 1
                            pre_symbol = update_trans(pre_symbol, 3)

                        else:
                            size = len(cur)
                            for i, c in enumerate(cur):
                                if i == 0:
                                    emit_p[(c, 'B')] += 1
                                    ci['B'] += 1
                                    pre_symbol = update_trans(pre_symbol, 0)
                                elif i == size - 1:
                                    emit_p[(c, 'E')] += 1
                                    ci['E'] += 1
                                    pre_symbol = update_trans(pre_symbol, 2)
                                else:
                                    ci['M'] += 1
                                    emit_p[(c, 'M')] += 1
                                    pre_symbol = update_trans(pre_symbol, 1)
        info('count pairs complete.')

        for i, t in enumerate(trans):  # normalization
            sum_ = sum(t)
            trans[i] = [
                math.log(e / sum_) if e > 0 else cls.MIN_FLOAT for e in t
            ]

        for key, v in emit_p.items():
            emit_p[key] = math.log(v / ci[key[1]])

        with open('emit_p.pickle', 'wb') as f:
            pickle.dump(emit_p, f)

        with open('trans.pickle', 'wb') as f:
            pickle.dump(trans, f)

        return emit_p, trans, ci

    @classmethod
    def calculate_trans(cls, emit_p: dict, ci: dict, obs: str,
                        state: str) -> float:
        return (1 + emit_p.get((obs, state), 0)) / ci.get(state, 1)

    @classmethod
    def viterbi(cls, states, text: str, start_p, trans_p, emit_p):
        map_state_index = dict(zip('BMES', range(4)))

        cache = {}
        for i, c in enumerate(text):
            if i == 0:
                for s in 'BS':
                    cache[s] = (start_p[map_state_index[s]] + emit_p[(c, s)],
                                s)
                min_value = min(cache.values(),
                                key=operator.itemgetter(0))[0] - 1
                cache['E'] = (cls.MIN_FLOAT, 'E')
                cache['M'] = (cls.MIN_FLOAT, 'M')
            else:
                copy_cache = cache.copy()
                for s in states:
                    max_prob, _seq = float('-inf'), ''
                    for prev_state, v in copy_cache.items():
                        prev_index, cur_index = map_state_index[
                            prev_state], map_state_index[s]
                        # not * but +
                        new_prob = v[0] + trans_p[prev_index][
                            cur_index] + emit_p.get((c, s), cls.MIN_FLOAT)
                        if new_prob > max_prob:
                            max_prob = new_prob
                            _seq = v[1]
                    cache[s] = (max_prob, _seq + '->' + s)
            # print(i, cache)
        # print(cache)
        # print(cache['S'], cache['E'])
        seq = cache['E'][1] if cache['E'][0] > cache['S'][0] else cache['S'][1]
        print(cls._cut(text, seq))

    @classmethod
    def _cut(cls, text: str, seq: str) -> str:
        seq = seq.split('->')
        res = ''
        for a, b in zip(text, seq):
            if (b == 'B' or b == 'S') and res:
                res += ' '
            res += a
        return res

    @classmethod
    def segment(cls, text: str) -> List[str]:
        res = []
        for i, c in enumerate(text):
            if c in cls.punctuations:
                # res += cls.viterbi(states, text, start_p, trans, emit_p)
                pass
            else:
                pass

emit_p, trans, _ = HMM.train()
start_p = [-0.6931471805599453, 0, 0, -0.6931471805599453]
states = ['B', 'M', 'E', 'S']

cnt = 0
for k, v in emit_p.items():
    print(k, v)
    if cnt > 10: break
    cnt += 1

print('-' * 80)
cs = defaultdict(dict)
for k, v in emit_p.items():
    if k[0] == '我':
        print(k, v)

print("\n\n")
texts = [
    '这是一种基于统计的分词方案', '这位先生您手机欠费了', '还有没有更快的方法', '买水果然后来世博园最后去世博会',
    '欢迎新老师生前来就餐', '北京大学生前来应聘', '今天天气不错哦', '就问你服不服', '我们不只在和你们一家公司对接',
    '结婚的和尚未结婚的都沿海边去了', '这也许就是一代人的命运吧', '改判被告人死刑立即执行', '检察院鲍绍坤检察长',
    '腾讯和阿里都在新零售大举布局'
]
for text in texts:
    HMM.viterbi(states, text, start_p, trans, emit_p)
