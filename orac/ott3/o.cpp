#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, L; cin >> N >> L;
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i]; 
    }

    set<int> s;
    using pii = pair<int, int>;
    int leftest = INT_MAX, rightest = INT_MIN;

    pii gl = {1e8, -1}, gr = {1e8, -1};
    for (int i = 0; i < N; i++) {
        int ans = INT_MAX;
        auto [t, _] = s.insert(p[i]);
        if (gl.second != -1) {
            auto rightp = s.lower_bound(gl.second+1);
            auto right = *rightp;
            gl = min<pii>(
                {(L-right)*2 + gl.second, gl.second},
                {L-right + gl.second*2, gl.second}
            );
        }
        if (gr.second != -1) {
            auto rightp = s.lower_bound(gr.second);
            auto leftp = prev(rightp);
            auto left = *leftp, right = *rightp;
            gr = min<pii>(
                {(L-gr.second)*2 + left, gr.second},
                {L-gr.second + left*2, gr.second}
            );
        }

        auto rightp = next(t);
        if (rightp != s.end()) {
            int right = *rightp;
            gl = min(gl, {(L-right)*2 + p[i], p[i]});
            gl = min(gl, {L-right + p[i]*2, p[i]});
        } 
        if (t != s.begin()) {
            auto leftp = prev(t);
            int left = *leftp;

            gr = min(gr, {(L-p[i])*2 + left, p[i]});
            gr = min(gr, {L-p[i] + left*2, p[i]});
        }
        leftest = min(leftest, p[i]);
        rightest = max(rightest, p[i]);
        
        ans = min(ans, rightest);
        ans = min(ans, L-leftest);
        ans = min(ans, gl.first);
        ans = min(ans, gr.first);
        cout << ans << endl;
    }
}
