#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int Q;
    cin >> Q;
    string S;
    cin >> S;
    string T;
    cin >> T;
    int n = S.size();
    int t = T.size();
    vector<int> a;
    vector<int> b;
    vector<int> L(Q);
    vector<int> R(Q);
    for(int i = 0; i < Q; i++ ) {
        cin >> L[i];
        cin >> R[i];
        L[i]--,R[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        if (S[i] == T[0])
            a.push_back(i);
    }
    int m = a.size();

    for (int k = 0; k < m; k++)
    {
        if (a[k] + t - 1 >= n) continue;
        bool g = 1;
        for (int p = 0; p < t; p++)
            if (S[a[k] + p] != T[p])
                g = 0;
        if (g == 1)
            b.push_back(a[k]);
    }

    for (int i = 0; i < Q; i++) {
        auto it = lower_bound(b.begin(), b.end(), L[i]);
        if (L[i] + t - 1 < n && it != b.end() && R[i] >= t + *it - 1)
            cout << "Yes\n";
        else cout <<  "No\n";
    }
}
