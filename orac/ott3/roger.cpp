#include <bits/stdc++.h>
using namespace std;

signed main() {
    int N, L; cin >> N >> L;
    vector<int> pos(N);
    for(int i = 0; i < N; i++) cin >> pos[i];
 
    multiset<int> pot;
    multiset<int> cur;
    for(int i = 0; i < N; i++) {
        auto it = cur.insert(pos[i]);
        if (cur.size()==1) {
            pot.insert(L-pos[i]);
            pot.insert(pos[i]);
        } else if (it == cur.begin()) {
            int after = *next(it);
            pot.erase(pot.find(L-after));
            pot.insert(2*pos[i] + (L-after));
            pot.insert(2*(L-after) + pos[i]);
            pot.insert(L-pos[i]);
        } else if (it == prev(cur.end())) {
            int before = *prev(it);
            pot.erase(pot.find(before));
            pot.insert(2*(L-pos[i]) + before);
            pot.insert(2*before + (L-pos[i]));
            pot.insert(pos[i]);
        } else {
            int before = *prev(it);
            int after = *next(it);
            pot.insert(2*pos[i] + (L-after));
            pot.insert(2*(L-pos[i]) + before);
 
            pot.insert(2*(L-after) + pos[i]);
            pot.insert(2*before + (L-pos[i]));
 
            pot.erase(pot.find(2*before + (L-after)));
            pot.erase(pot.find(2*(L-after) + before));
        }
        cout << *pot.begin() << endl;
    }
 
    return 0;
}
