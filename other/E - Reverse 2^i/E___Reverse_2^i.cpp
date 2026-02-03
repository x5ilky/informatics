#include <bits/stdc++.h>

using namespace std;

void rec(vector<int> &v) {
    if (v.size() == 1) return;
    vector<int> left(v.begin(), v.begin() + v.size() / 2);
    vector<int> right(v.begin() + v.size() / 2, v.end());

    rec(left);
    rec(right);
    if (left[0] > right[0])
        swap(left, right);
    left.insert(left.end(), right.begin(), right.end());
    v = left;
}

void task() {
    int k;
    scanf("%d", &k);
    
    vector<int> n(1 << k);
    for (int& k : n) {
        scanf("%d", &k);
    }

    rec(n);
    for (int k : n) {
        printf("%d ", k);
    }
    printf("\n");
}

signed main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        task();
    }

    return 0;
}