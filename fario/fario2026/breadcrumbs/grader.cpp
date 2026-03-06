#include "crumbs.h"
#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>
using namespace std;

const int NUM_BITS = 1000;
const int NUM_ROUNDS = 50;
const int MAX_WALK_LEN = 10000;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    for (int j = 0; j < M; j++) {
        cin >> A[j] >> B[j];
    }

    set<pair<int,int>> edges;
    for (int j = 0; j < M; j++) {
        int u = A[j], v = B[j];
        if (u > v) swap(u, v);
        edges.insert({u, v});
    }

    init(N, M, A, B);

    srand(12345);
    int maxWalkLen = 0;
    for (int r = 0; r < NUM_ROUNDS; r++) {
        vector<int> bits(NUM_BITS);
        for (int i = 0; i < NUM_BITS; i++) {
            bits[i] = rand() % 2;
        }

        vector<int> walk = encode(bits);
        if (walk.empty() || walk[0] != 1) {
            cout << "Error: Walk must start at location 1\n";
            return 1;
        }
        for (int v : walk) {
            if (v < 1 || v > N) {
                cout << "Error: Walk contains invalid vertex\n";
                return 1;
            }
        }
        for (size_t i = 0; i + 1 < walk.size(); i++) {
            int u = walk[i], v = walk[i+1];
            if (u > v) swap(u, v);
            if (!edges.count({u, v})) {
                cout << "Error: Walk is not a valid walk (missing edge)\n";
                return 1;
            }
        }
        if ((int)walk.size() > MAX_WALK_LEN) {
            cout << "Error: Walk too long\n";
            return 1;
        }
        maxWalkLen = max(maxWalkLen, (int)walk.size());

        vector<int> decoded = decode(walk);
        if ((int)decoded.size() != NUM_BITS) {
            cout << "Error: Decode must return 1000 bits\n";
            return 1;
        }
        for (int i = 0; i < NUM_BITS; i++) {
            if (decoded[i] != bits[i]) {
                cout << "Error: Decoded message does not match original\n";
                return 1;
            }
        }
    }
    cout << "Max walk length: " << maxWalkLen << endl;
    return 0;
}
