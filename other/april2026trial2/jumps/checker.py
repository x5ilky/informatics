import random
from subprocess import *

for i in range(10000):
    print(f"VALID CASE {i+1}")
    cases = []
    while True:
        N = random.randint(10, 10000)
        heights = list(range(0,N))
        random.shuffle(heights)
        # heights.insert(0,N)
        # for i in range(1,N-1):
        #     if random.random()>0.3:
        #         heights[i],heights[i+1]=heights[i+1],heights[i]

        b = False
        u = random.randint(0,N-1);
        v = random.randint(0,N-1);
        if not u < v: continue
        if u == v: continue
        for i in range(u, v+1):
            if heights[i] > heights[v]:
                b = True
                break
        if b: continue
        else: break
    with open("in.txt","w") as f:
        f.write(f"{N} 1\n");
        f.write(" ".join(map(str, heights)) + "\n");
        f.write(f"{u} {u} {v} {v}\n");
    run("./jumps < in.txt > out1.txt", shell=True);
    run("./brute < in.txt > out2.txt", shell=True);
    in1 = ""
    in2 = ""
    with open("out1.txt","r") as f:
        in1 = f.read()
    with open("out2.txt","r") as f:
        in2 = f.read()
    if in1.strip() == "-1": print("WTF BAD CASE")
    if(in1.strip() != in2.strip()):
        print("BREAKING CASE")
        print(f"{N} 1");
        print(" ".join(map(str, heights)));
        print(f"{u} {u} {v} {v}");
