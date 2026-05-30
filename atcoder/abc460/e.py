import math
T = int(input())
MOD = 998244353
while T>0:
    T-=1
    N, M = map(int, input().split())
    amt = len(str(N))
    ans = 0
    for i in range(1,9999):
        num_b = min(10**i,N+1) - 10**(i-1)
        if num_b<=0: break
        ans += num_b * (N // int(M // math.gcd(M, 10**i - 1)))
        ans %= MOD
    print(ans)
