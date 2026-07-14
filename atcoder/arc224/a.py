N = int(input())
for q in range(N):
    K = int(input())
    i = 1
    while True:
        if "00" in str(K*i):
            print(K*i)
            break
        i += 1
