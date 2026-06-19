#include "maze.h"
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <set>
using namespace std;

static int N;
static vector<vector<int>> queries;
static vector<vector<int>> edges;

static int Q;
const static int QMAX = 1000000;

static set<pair<int,int>> input;
static set<pair<int,int>> report;

static int _check;
const static int INF = 1000000000;

static void _dfs(int start, int current, int previous=-1, int exclusiveMin=INF)
{
    if (++_check > N) {
        printf("Invalid input (not a tree)\n");
        exit(0);
    }
    queries[start][current] = exclusiveMin;
    for (int next: edges[current]) {
        if (next != previous) {
            int nextMin = exclusiveMin;
            if (start != current) {
                nextMin = min(nextMin, current);
            }
            _dfs(start, next, current, nextMin);
        }
    }
}

int query(int A, int B)
{
    if (++Q > QMAX) {
        printf("Number of queries exceeded\n");
        exit(0);
    }

    if (A < 1 || A > N || B < 1 || B > N) {
        printf("Invalid query\n");
        exit(0);
    }

    int ans = queries[A-1][B-1];
    return (ans == INF) ? -1 : ans+1;
}

void report_passageway(int A, int B)
{
    pair<int,int> p = {min(A,B), max(A,B)};
    if (input.count(p) == 0) {
        printf("This passageway does not exist\n");
        exit(0);
    }
    if (report.count(p) > 0) {
        printf("You already reported this passageway\n");
        exit(0);
    }
    report.insert(p);
}

int main()
{
    int res = scanf("%d", &N);
    if (res != 1) {
        printf("Failed to read N\n");
        return 0;
    }

    edges.resize(N);
    for (int i=0; i<N-1; i++)
    {
        int A, B;
        int res = scanf("%d%d", &A, &B);
        if (res != 2) {
            printf("Failed to read edge\n");
            return 0;
        }
        if (A < 1 || A > N || B < 1 || B > N) {
            printf("Invalid edge in input\n");
            return 0;
        }
        edges[A-1].push_back(B-1);
        edges[B-1].push_back(A-1);
        input.insert({min(A,B), max(A,B)});
    }

    queries.assign(N, vector<int>(N, INF));
    for (int start = 0; start < N; ++start) {
        _check = 0;
        _dfs(start, start);
        if (_check != N) {
            printf("Invalid input (not a tree)\n");
            return 0;
        }
    }

    Q = 0;
    map_maze(N);

    if (report.size() < input.size()) {
        printf("Missing passageway\n");
        return 0;
    }

    printf("Correct (%d queries)\n", Q);
}
