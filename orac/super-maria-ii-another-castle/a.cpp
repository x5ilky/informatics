/*
 * this is not my code
 * signature at bottom for funsies
 */

#include "carriage_lib.h"
#include <bits/stdc++.h>
using namespace std;
#define sig signed
#define int long long
#define arr array
#define pii pair<int, int>
#define fir first 
#define sec second 
const int N = 1e6 + 5, INF = 1e18;
 
int n;
int opn, trn;
 
arr<pii, N> dp;
int rg(int s, int i) {
    return dp[s - i].fir;
}
int lf(int i) {
    if (i == 1) return 0;
    return trn + dp[i - 1].fir;
}
int srch(int s) {
    int lw = 1, hg = s;
    while (lw != hg) {
        int md = (lw + hg) / 2;
        if (rg(s, md) <= lf(md)) hg = md;
        else lw = md + 1;
    }
    return lw;
}
void dp_cmp() {
    dp[0] = {0, 0};
    for (int s = 1; s <= n; s++) {
        dp[s] = {INF, INF};
        int x = srch(s); // Optimal
        for (int i : {1ll, s, x - 1, x, x + 1}) {
            if (i < 1 || s < i) continue;
            dp[s] = min(dp[s], {opn + max(lf(i), rg(s, i)), i});
        }
    }
}
 
int ps = 0;
void mv(int x) { 
    carriage_move(x);
    ps += x; 
}
int qry() { 
    return carriage_open(); 
}
 
void ans_cmp() {
    int s = n, dr = 1;
    while (true) {
        int i = dp[s].sec;
        if (s == n) mv(i - 1);
        else mv(dr * i);
                
        int nw_dr = qry();
        s = (dr == nw_dr) ? s - i : i - 1;
        dr = nw_dr;
    }
}
 
sig main() {
    n = carriage_nb_cells(), opn = carriage_open_cost(), trn = carriage_reverse_cost();
    dp_cmp();
    ans_cmp();
}

// begin signature
// +----------------------------------------+
// |洪汎山せビ丁丁ミミミミシシヘㇵ一一ㇵㇵヘ|
// |允せビミシヘㇵㇸ一一一ㇸ・　　　　　・ㇸ|
// |ビミヘ一ㇸヘシシシヘ一ㇸㇸ一ㇵㇵㇵ一ㇸ　|
// |シㇵㇸシ丁ビミヘヘヘヘヘシミミミミシㇵ一|
// |一一丁火ビミヘㇵヘシミ丁ビ火火火火ビミヘ|
// |ㇸシ火せ丁シ一シミビ火火せ山允允允山火ビ|
// |一ミせせ丁シヘミビせ山允允汎洪労労洪汎山|
// |ㇸミ山せ丁シ丁ビ火山汎洪労労李和和和李洪|
// |ㇸ火允火ミ丁火山山汎労李和和耗奏群奏耗李|
// |丁允せ丁丁せ汎洪洪労和奏群奏陽義義群耗李|
// |允山ビ山汎允労和李和群義陽陽慶覇義群耗労|
// |允火允汎山洪李和李耗陽義群義覇慶陽奏李洪|
// |允允汎山せ汎洪労労和奏奏奏群陽陽群耗李汎|
// |山允允せビせ山允允洪李和和耗奏奏耗和労汎|
// |山允允せ丁ミビ火火山汎洪洪労李李李李洪汎|
// |ビ山汎せ丁シミビせせ允洪労汎汎洪洪洪汎山|
// |せ允汎せ火丁丁せせせ汎李李洪山山山山せ火|
// |せ汎山せビシビ山火允汎労洪允火ビビビ丁シ|
// |汎山せせ丁ミビせ山允允允山火ミシシヘㇵ一|
// |汎允允火ビミ丁ビ山允火火火ビミシシヘㇵ・|
// +----------------------------------------+
// 2026 (April 19th) 17:37:48
// end signature
