#include "kthnumber.h"
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <unordered_set>
#include <cassert>
using namespace std;
static int N, M, K, num_questions;
static vector<int> P;
int ask_host(vector<int> I) {
    if (int(I.size()) != M) {
        printf("Invalid Question: I has size %lu, but it should have size M=%d\n", I.size(), M);
        exit(0);
    }
    vector<int> vals;
    unordered_set<int> seen;
    for (auto i : I) {
        if (i < 0 || i >= N) {
            printf("Invalid Question: Index %d in I is outside the range [%d, %d]\n", i, 0, N-1);
            exit(0);
        }
        if (seen.find(i) != seen.end()) {
            printf("Invalid Question: Index %d in I was duplicated\n", i);
            exit(0);
        }
        seen.insert(i);
        vals.push_back(P[i]);
    }
    assert(int(seen.size()) == M);

    num_questions++;

    nth_element(vals.begin(), vals.begin()+K-1, vals.end());
    return vals[K-1];
}

int main() {
    int T, subtask;
    if (scanf("%d%d", &T, &subtask) != 2) {
        printf("Invalid input: first line should contain T and subtask\n");
        return 0;
    }
    if (subtask != 1 && subtask != 2 && subtask != 3) {
        printf("Invalid input: Subtask must be 1, 2, or 3\n");
        return 0;
    }
    if (T <= 0) {
        printf("Invalid input: T should be >= 1, not %d\n", T);
        return 0;
    }
    int overall_score = 100;
    for (int CASE = 1; CASE <= T; CASE++) {
        printf("Case #%d\n", CASE);
        P.clear();
        num_questions = 0;
        if (scanf("%d%d%d", &N, &M, &K) != 3) {
            printf("Invalid input: first line of case should contain N, M, K\n");
            return 0;
        }
        if (!(2 <= M && M <= N-1)) {
            printf("Invalid input: M = %d and N = %d, so M does not satisfy 2 <= M <= N-1\n", M, N);
            return 0;
        }
        if (!(1 <= K && K <= M)) {
            printf("Invalid input: K = %d and M = %d, so K does not satisfy 1 <= K <= M\n", K, M);
            return 0;
        }
        unordered_set<int> seen;
        for (int i = 0; i < N; i++) {
            int j;
            if (scanf("%d", &j) != 1) {
                printf("Invalid input: second line of case should contain P\n");
                return 0;
            }
            if (j < 1 || j > N) {
                printf("Invalid Input: Value %d in P is outside the range [%d, %d]\n", j, 1, N);
                return 0;
            }
            if (seen.find(j) != seen.end()) {
                printf("Invalid Input: Value %d in P was duplicated in P\n", j);
                return 0;
            }
            seen.insert(j);
            P.push_back(j);
        }
        assert(int(seen.size()) == N);
        int student_answer = find_K(N, M, subtask);
        int case_score = 0;
        if (student_answer != K) {
            printf("Incorrect: you returned %d, but K=%d\n", student_answer, K);
        } else {
            printf("Correct!\n");
            if (subtask == 1) {
                if (num_questions <= 3) case_score = 25;
                else if (num_questions <= (N+1)/2) case_score = 15;
                else if (num_questions <= N*N) case_score = 10;
            } else if (subtask == 2) {
                if (num_questions <= (N+1)/2 + 1) case_score = 30;
                else if (num_questions <= N) case_score = 15;
            } else {
                if (num_questions <= (N+1)/2 + 1) case_score = 45;
                else if (num_questions <= (8*N+9)/10) case_score = 40;
                else if (num_questions <= N) case_score = 30;
                else if (num_questions <= N*M) case_score = 20;
            }

        }
        printf("Asked %d questions\n", num_questions);
        printf("%d points\n", case_score);
        overall_score = min(overall_score, case_score);
        printf("\n");
    }

    int max_score;
    if (subtask == 1) max_score = 25;
    else if (subtask == 2) max_score = 30;
    else max_score = 45;
    printf("Overall: %d / %d points\n", overall_score, max_score);
}