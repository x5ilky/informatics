import random
N = random.randint(5,10);
K = random.randint(1,100)

sm = 0
R = []
for i in range(N):
    v = random.randint(0,100)
    sm += v
    R.append(v);
C = []
sm2 = 0
for i in range(N):
    v = random.randint(0,100)
    v = min(v,sm-sm2)
    sm2 += v
    C.append(v)
print(N, K);
print(" ".join(map(str, R)))
print(" ".join(map(str, C)))

