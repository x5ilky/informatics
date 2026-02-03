#include <bits/stdc++.h>
#include <set>

using namespace std;

template <typename T>
void print_multiset(multiset<T>& vec) {
    bool first = true;
    for (auto& a : vec) {
        if (first) {
            cout << a;
            first = false;
        }
        else cout << " " << a;
    }
    cout << endl;
}

signed main() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (auto& i : x) cin >> i;

    multiset<int> low, high;

    auto balance = [&](){
        if (high.size() > low.size()) {
            auto bot = high.begin();
            low.insert(*bot);
            high.erase(bot);
        } else if (low.size() > high.size() + 1) {
            auto bot = low.rbegin();
            high.insert(*bot);
            low.erase(low.find(*bot));
        }
    };

    low.insert(x[0]);
    for (int i = 1; i < k; i++) {
        if (x[i] > *low.rbegin()) {
            high.insert(x[i]);
        } else {
            low.insert(x[i]);
        }
        balance();
    }
    cout << *low.rbegin();
    for (int i = k; i < n; i++) {
        if (x[i-k] > *low.rbegin()) {
            high.erase(high.find(x[i-k])); 
        } else {
            low.erase(low.find(x[i-k]));
        }
        balance();

        
        if (k > 1 && x[i] > *low.rbegin()) {
            high.insert(x[i]);
        } else {
            low.insert(x[i]);
        }
        balance();
        // print_multiset(low);
        // print_multiset(high);
        // cout << endl;
        cout << " " << *low.rbegin();
        // cout << endl;
    }
    cout << endl;
}
