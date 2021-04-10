import sys, os, json, re

ws = set()


def extract_dict():
    with open('dict.txt', 'r') as f:
        for ln in f.readlines():
            w = ln.replace('\t', ' ').split(' ')[0]
            ws.add(w)
    print(len(ws))


def extract_dict_xinhua():
    '''新华字典词语'''
    with open('xinhua.txt', 'r') as f:
        for ln in f.readlines():
            w = re.findall(r'【(.*)】', ln)
            if w:
                ws.add(w[0])
    print(len(ws))


def save_dict():
    open('puredict.txt', 'w').write(','.join(ws))


extract_dict()
extract_dict_xinhua()
save_dict()
