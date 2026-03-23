#include <bits/stdc++.h>

using namespace std;
#define int long long
#define printf(...)
const int MOD=1e4+7;
signed main(){
    vector<int> inv(MOD+1);
    inv[1] = 1;
    for (int i = 2; i < MOD; i++) { inv[i] = MOD - MOD / i * inv[MOD % i] % MOD; }

    struct comp{
        vector<int> exp10={1,10};
        vector<vector<int>> expd;
        int MOD;
        comp(int mod) : expd(10),MOD(mod) {
            exp10.resize(31);
            for (int i=2;i<=30;i++){
                exp10[i]=exp10[i-1]*exp10[i-1];
                exp10[i]%=MOD;
            }
            for (int d=0;d<=9;d++){
                expd[d].resize(31);
                expd[d][0]=d;
                for (int k=1;k<=30;k++){
                    expd[d][k]=(expd[d][k-1]*exp10[k]+expd[d][k-1])%MOD;
                }
            }
        }
        int e10(int l){
            int lmod=1;
            for (int k=29;k>=0;k--){
                if (l>=(1<<k)) {
                    l-=(1<<k);
                    lmod*=exp10[k+1];
                    lmod%=MOD;
                }
            }
            return lmod;
        };
        int ed(int l,int d){
            int lmod=0;
            for (int k=29;k>=0;k--){
                if (l>=(1<<k)) {
                    l-=(1<<k);
                    lmod=expd[d][k]+lmod*exp10[k+1];
                    lmod%=MOD;
                }
            }
            return lmod;
        };
    };



    int K,M;cin>>K>>M;
    auto bm=comp(MOD*M);
    auto b=comp(M);
    for (auto e : bm.expd[1]) printf("%d ", e);
    printf("\n");
    for (int i=0;i<=10;i++)printf("%lld ",bm.e10(i));
    printf("\n");

    int kmodbm=0,kmodb=0;
    for (int i=1;i<=K;i++){
        int c,l;cin>>c>>l;        
        kmodbm*=bm.e10(l); kmodbm%=(MOD*M);
        kmodbm+=bm.ed(l,c); kmodbm%=(MOD*M);
        kmodb*=b.e10(l); kmodb%=M;
        kmodb+=b.ed(l,c); kmodb%=M;
    }
    printf("inv:%lld\n",inv[M%MOD]);
    cout<<(kmodbm-kmodb)/M<<endl;
}
