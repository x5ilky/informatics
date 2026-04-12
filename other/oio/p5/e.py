import heapq

board = []

for i in range(9):
    row = input().split()
    R = []
    for r in row:
        if r == "#":
            R.append(-1)
        else: R.append(int(r))
    board.append(R)

def pb(b):
    for r in b:
        s = []
        for c in r:
            s.append("#" if c == -1 else str(c))
        print(" ".join(s))

def solve(b):
    # pb(b)
    q = []
    heapq.heapify(q)
    for r in range(9):
        for c in range(9):
            if b[r][c]!=-1: continue
            cand=set(range(1,10))
            cr=r//3
            cc=c//3
            for dy in range(3):
                for dx in range(3):
                    v = b[cr*3+dy][cc*3+dx]
                    if v==-1: continue
                    if v in cand:
                        cand.remove(v)
            for dx in range(9):
                v = b[r][dx]
                if v==-1: continue
                if v in cand:
                    cand.remove(v)
            for dy in range(9):
                v = b[dy][c]
                if v==-1: continue
                if v in cand:
                    cand.remove(v)
            if len(cand) == 0: return (b, False)
            heapq.heappush(q, (len(cand),list(cand),r,c))
    if len(q) == 0: return (b, True)

    (_, cand, r, c) = heapq.heappop(q)
    # print(cand, r, c)
    for v in cand:
        b[r][c]=v
        # pb(b)
        if solve(b)[1]: return (b, True)
        b[r][c]=-1

    return (b, False)
(board, _) = solve(board)
pb(board)
