N = int(input())
f = {}
for i in range(N):
    s = input()
    s = s.lower()
    if s in f:
        f[s] += 1
    else:
        f[s] = 1
ans = 0
for k in f:
    ans = max(ans,f[k])
print(ans)
