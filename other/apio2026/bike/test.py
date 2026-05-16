import random
print(1)
N = 7
print(N)
surp=[]
for i in range(N):
    surp.append(random.randint(-100, 100))
surp[len(surp)-1]-=sum(surp)
a=[]
b=[]
for i in range(N):
    if surp[i]<0:
        a.append(0)
        b.append(-surp[i])
    else:
        a.append(surp[i])
        b.append(0)
print(" ".join(map(str, a)))
print(" ".join(map(str, b)))
for i in range(1,N):
    print(i,random.randint(0,i-1))
