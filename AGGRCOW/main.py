# N = number of stalls (2 .. 100.000)
# C = number of cows (2 .. N)
# xi = positions x1 to xN (0 .. 1.000.000.000)

from sys import stdin

numTest = int(stdin.readline())
for i in range(numTest):
    N, C = [int(x) for x in stdin.readline().split()]
    pos = []
    for x in range(N):
        pos.append(int(stdin.readline()))
    print("numtest = {}, N = {}, C = {}, post = {}".format(numTest, N, C, pos))


