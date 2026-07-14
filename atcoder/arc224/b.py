import math
N = int(input())
for q in range(N):
    K = int(input())
    print(K*2-(math.isqrt(4*K-1)+1))
