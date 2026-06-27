#include "arrayser.h"
#include <cstdio>
#include <cstdlib>
#include <random>
#include <string>
#include <vector>
using namespace std;

static const int RANDOM_SEED = 1;
static int DEBUG_LEVEL = 1;

static int N, number_turns;
static vector<int> A;
static mt19937 rng(RANDOM_SEED);

static void print_A() {
    for (int i = 0; i < N; i++) printf("%d", A[i]);
    printf("\n");
}

static bool is_done() {
    for (int i = 0; i < N; i++) {
        if (A[i]) return false;
    }
    return true;
}

static vector<int> get_available_indices() {
    vector<int> available;
    for (int i = 0; i < N; i++) {
        if (A[i]) {
            available.push_back(i);
        }
    }
    return available;
}

static void set_index(int i) {
    if (i >= 0 && i < N) A[i] = 0;
}

int do_turn(int i) {
    number_turns++;
    if (DEBUG_LEVEL >= 2) {
        printf("Turn %d: you chose index %d\n", number_turns, i);
    }
    
    if (is_done()) {
        printf("Invalid turn: game is over!\n");
        exit(0);
    }
    if (i < 0 || i >= N) {
        printf("Invalid turn: index out of bounds (%d)\n", i);
        exit(0);
    }
    if (!A[i]) {
        printf("Invalid turn: index already has A[i] = 0\n");
        exit(0);
    }

    set_index(i);
    set_index(i-1);
    set_index(i+1);

    // The opponent plays in a random index
    if (is_done()) return -1;
    vector<int> available = get_available_indices();
    int index = uniform_int_distribution<int>(0, int(available.size())-1)(rng);
    int move = available[index];

    number_turns++;
    set_index(move);
    set_index(move-1);
    set_index(move+1);

    if (DEBUG_LEVEL >= 2) {
        printf("Turn %d: the grader chose index %d\n", number_turns, move);
        print_A();
    }

    return move;
}

int main() {
    int t;
    if (scanf("%d%d", &N, &t) != 2) {
        printf("Error: input should contain two integers (N and T)\n");
        return 0;
    }
    long double total = 0;
    for (int GAME = 1; GAME <= t; GAME++) {
        if (DEBUG_LEVEL >= 1) {
            printf("GAME #%d\n", GAME);
        }

        A = vector<int>(N, 1);

        number_turns = 0;
        play_arrayser(N);
        total += number_turns;

        if (!is_done()) {
            printf("Error: play_game returned before the game finished\n");
            return 0;
        }

        if (DEBUG_LEVEL >= 1) {
            printf("Game lasted for %d turns\n\n", number_turns);
        }
    }
    long double average = total/t;
    printf("Average: %.2Lf turns\n", average);
}