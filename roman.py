#!/usr/bin/env python3
import sys

def toroman(x):
    tmp = [(10 ** idx) * int(val) for idx, val in enumerate(str(x)[::-1])]
    tmp = [val if idx < 3 else sum(arr[3:]) for arr in [tmp] for idx, val in enumerate(arr)][:4]
    tmp = [int(val / (10 ** idx)) for idx, val in enumerate(tmp)]
    template = ([[0]] + [[5] + j if idx > 4 else j for idx, j in enumerate(([[int(r) for r in list("1" * i)] for i in range(4)] + [[1, 5]]) * 2)][1:-1] + [[1, 10]]) 
    rom = {1 : "I", 5 : "V", 10 : "X", 50 : "L", 100 : "C", 500 : "D", 1000 : "M"}
    tmp = [[rom[num * (10 ** idx)] for num in template[val]] if idx < 3 else ['M' * val] for idx, val in enumerate(tmp) if val != 0][::-1]
    return ''.join([j for i in tmp for j in i])

r = lambda x: ''.join([j for i in [[{1: "I", 5: "V", 10: "X", 50: "L", 100: "C", 500: "D", 1000: 'M'}[num * (10 ** idx)] for num in ([[0]] + [[5] + j if idx > 4 else j for idx, j in enumerate(([[int(r) for r in list("1" * i)] for i in range(4)] + [[1, 5]]) * 2)][1:-1] + [[1, 10]])[val]] if idx < 3 else ['M' * val] for idx, val in enumerate([int(val / (10 ** idx)) for idx, val in enumerate([val if idx < 3 else sum(arr[3:]) for arr in [[(10 ** idx) * int(val) for idx, val in enumerate(str(x)[::-1])]] for idx, val in enumerate(arr)][:4])]) if val != 0][::-1] for j in i])

# print(sys.argv[1])
# print(toroman(int(sys.argv[1])))
# print(r(int(sys.argv[1])))
for i in range(1001):
    print(str(i) + '\t', r(i))
