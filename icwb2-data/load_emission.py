import pickle

with open('emission_p.json', 'rb') as f:
    emit_p = pickle.load(f)

print(emit_p['我', 'B'])