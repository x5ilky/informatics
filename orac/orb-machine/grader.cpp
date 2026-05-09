#include "machine.h"
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

static int N;
static vector<int> permutation, location;

static int queryCount = 0;
static bool prefixUsed = false;
int query(vector<int> S) {
    queryCount++;
    if (S.empty()) {
        cout << "Invalid query (empty permutation)" << endl;
        exit(0);
    }
    if (S.size() > N) {
        cout << "Invalid query (permutation too large)" << endl;
        exit(0);
    }
    if (S.size() < N) {
        prefixUsed = true;
    }

    set<int> setS(S.begin(), S.end());
    if (setS.size() != S.size() || *setS.begin() != 1 || *setS.rbegin() != S.size()) {
        cout << "Invalid query (not a permutation of 1 to K)" << endl;
        exit(0);
    }

    vector<int> dp;
    for (int i : S) {
        int x = location[i];
        int index = lower_bound(begin(dp), end(dp), x) - begin(dp);
        if (index == dp.size()) {
            dp.push_back(x);
        }
        else {
            dp[index] = x;
        }
    }
    return dp.size();
}

int main() {
    if (!(cin >> N)) {
        cout << "Error reading N" << endl;
        return 0;
    }
    if (N < 1 || N > 200) {
        cout << "Invalid value of N" << endl;
        return 0;
    }

    permutation.resize(N);
    location.resize(N + 1, -1);
    for (int i = 0; i < N; i++) {
        if (!(cin >> permutation[i])) {
            cout << "Error reading permutation" << endl;
            return 0;
        }
        if (permutation[i] < 1 || permutation[i] > N) {
            cout << "Invalid value in input" << endl;
            return 0;
        }
        if (location[permutation[i]] != -1) {
            cout << "Duplicate values in input" << endl;
            return 0;
        }
        location[permutation[i]] = i;
    }

    vector<int> output = find_permutation(N);
    if (output != permutation) {
        cout << "Wrong output" << endl;
        return 0;
    }
    cout << queryCount << " queries used" << endl;
    cout << (prefixUsed ? "Some queries had K < N" : "All queries had K = N") << endl;

    return 0;
}
