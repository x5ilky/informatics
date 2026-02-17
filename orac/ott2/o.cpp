#include <algorithm>
#include <bits/stdc++.h>
#include <deque>
#include <vector>
using namespace std;

int main() {
    int N, L, M;
    cin >> N >> L >> M;
    
    vector<int> positions(N);
    for (int i = 0; i < N; i++) {
        cin >> positions[i];
    }
    sort(positions.begin(), positions.end());
    deque<int> dq(positions.begin(), positions.end());
    
    string s;
    cin >> s;

    int p = 0;
    for (auto& c : s) {
        if (p == 0) {
            if (c == 'B') {
                p++;
                while (!dq.empty() and dq.front() <= p) dq.pop_front();
            }
            if (c == 'F') {
                p--;
                while (!dq.empty() and dq.back() >= L+p) dq.pop_back();
            }
        } else if (p < 0) {
            if (c == 'B') p++;
            if (c == 'F') p--;
            while (!dq.empty() and dq.back() >= L+p) dq.pop_back();
        } else if (p > 0) {
            if (c == 'B') p++;
            if (c == 'F') p--;
            while (!dq.empty() and dq.front() <= p) dq.pop_front();
        }
    }
    cout << positions.size()-dq.size() << endl;
}
