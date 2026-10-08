#ifndef INTERACTION_IMLP
#define INTERACTION_IMLP

#include "icc.h"

#include <cstdio>
#include <cmath>

#include <array>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#define DEBUG(...) if (1) { __VA_ARGS__; }

namespace ceoi_2016 {

void Fail(const string&);

// If condition is not true, sets score to 0 because reasons.
void Expect(bool condition, const string& message) {
    if (not condition) {
        Fail(message);
    }
};

class Solver {
  public:
    // query provided by the problem
    virtual bool Query(int n, int m, int* a, int* b) = 0;

    // checks whatever or not that is the edge. order does not matter.
    // does not crash if it's false. just returnes true.
    virtual bool SetEdge(int a, int b) = 0;

    // returns true if threre're no more edges left to add.
    virtual bool IsOver() = 0;

    virtual int NumVertices() = 0;
};

struct BasicSolver : public Solver {
    BasicSolver(istream& fin) {
        fin >> n;
        edges_order.resize(n - 1);
        for (int i = 0; i < n - 1; i += 1) {
            fin >> edges_order[i].first >> edges_order[i].second;
        }

        current_edge = 0;
    }

    bool Query(int a, int b, int* A, int *B);

    bool SetEdge(int a, int b);

    bool IsOver() { return current_edge == n - 1; }

    int NumVertices() { return n; }

private:
    vector<pair<int, int> > edges_order;
    int n, current_edge;
};

bool BasicSolver::Query(int a, int b, int A[], int B[]) {
    DEBUG({
        fprintf(stderr, "[Query]\n{");
        for (int i = 0; i < a; i += 1) { fprintf(stderr, "%d%s", A[i], ((i + 1 != a) ? (",\t") : (""))); }
        fprintf(stderr, "}\n{");
        for (int i = 0; i < b; i += 1) { fprintf(stderr, "%d%s", B[i], ((i + 1 != b) ? (",\t") : (""))); }
        fprintf(stderr, "}\n\n");
    });

    vector<int> left(n + 1, 0), right(n + 1, 0);

    for (int i = 0; i < a; i += 1) {
        // sanity check
        Expect(1 <= A[i] and A[i] <= n, "Query cities not in range [1, n]");

        left[A[i]] = 1;
    }

    for (int i = 0; i < b; i += 1) {
        // sanity check
        Expect(1 <= B[i] and B[i] <= n, "Query cities not in range [1, n]");
        
        right[B[i]] = 2;

        Expect(left[B[i]] == 0, "The query sets must be disjoint");
    }

    bool ok = false;
    for (int i = 0; i <= current_edge; i += 1) {
        ok |= (left[edges_order[i].first] + right[edges_order[i].second] == 3);   
        ok |= (left[edges_order[i].second] + right[edges_order[i].first] == 3);   
    }

    return ok;
}

bool BasicSolver::SetEdge(int a, int b) {
    int x = edges_order[current_edge].first;
    int y = edges_order[current_edge].second;
    
    if (x > y) { swap(x, y); }

    if (a > b) { swap(a, b); }

    DEBUG({
        fprintf(stderr, "[SetRoad]\nGiven Road\t%d\t%d\nActual Road\t%d\t%d\n\n\n\n", a, b, x, y);
    });

    if ((a == x and b == y) or (a == y and b == x)) {
        current_edge += 1;
        return true;
    } else {
        current_edge += 1;
        return false;
    }
}

// **********************************************************************************************************************************
// 
//   User Interaction
//
// **********************************************************************************************************************************

class Interaction {
  public:
    bool Query(int n, int m, int* a, int *b);
    void SetEdge(int a, int b);

    Interaction(Solver* solver, int max_steps, int max_score) 
        : num_steps(0), solver(solver), max_steps(max_steps), max_score(max_score) { }
    void Fail(const string&);

    int NumVertices() { return solver->NumVertices(); }

  private:
    void SetScore(int score, const string& message);

    void DecideScore();

    int num_steps;
    Solver* solver;

    int max_steps, max_score;
};

Interaction* interaction;

void Interaction::SetScore(int score, const string& message) {
    fprintf(stderr, "%d %s\n", score, message.c_str());
    exit(0);
};

// returnes score by the grader based on the number of
void Interaction::DecideScore() {
    if (num_steps <= max_steps) {
        SetScore(max_score, "Ok! " + to_string(num_steps) + " queries used.");
    } else {
        SetScore(0, "Too many queries! " + to_string(num_steps) + " out of " + to_string(max_steps));
    }
}

bool Interaction::Query(int n, int m, int* a, int *b) {
    num_steps += 1;
    Expect(num_steps <= 2 * max_steps, "Number of queries more than " + to_string(2 * max_steps) + " out of " + to_string(max_steps));

    return solver->Query(n, m, a, b);
}

void Interaction::SetEdge(int a, int b) {
    Expect(solver->SetEdge(a, b), "Wrong road!");
    if (solver->IsOver()) {
        DecideScore();
    }
}

// Called by various methods because reasons.
void Fail(const string& message) {
    interaction->Fail(message);
}

void Interaction::Fail(const string& message) {
    SetScore(0, message);
}
} // namespace ceoi_2016


// **********************************************************************************************************************************
// 
//   Main
//
// **********************************************************************************************************************************

extern "C" {
// Implementation of API's SetRoad(int, int)
void setRoad(int a, int b) {
    using namespace ceoi_2016;
    interaction->SetEdge(a, b);
}

// Implementation of API's Query(int, int, int*, int*)
int query(int n, int m, int* a, int* b) {
    using namespace ceoi_2016;
    return interaction->Query(n, m, a, b);
}


void InitGrader() {
    using namespace ceoi_2016;

    int max_steps = 2500;
    int max_points = 100;

    Solver* solver = new BasicSolver(cin);
    interaction = new Interaction(solver, max_steps, max_points);
}

void GraderExitFail() {
    using namespace ceoi_2016;
    Fail("Not all edges were guessed!");
}

int NumVertices() {
    using namespace ceoi_2016;
    return interaction->NumVertices();
}
}
#endif
