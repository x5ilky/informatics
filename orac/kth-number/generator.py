import random
T = 100
MAX_N = 100
print(T, 3) 
for i in range(T):
    N = random.randint(5, MAX_N)
    M = random.randint(N//2, N-1)
    K = random.randint(1, M)
    print(N, M, K)
    l = list(range(1,N+1))
    random.shuffle(l)
    print(" ".join(map(str, l)))
