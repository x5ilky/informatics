#include <bits/stdc++.h>
using namespace std;
#define printf(...)
#define int long long
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int N;cin>>N;
    using pii=pair<int,int>;
    vector<array<pii,2>>g(N+1);vector<int>p(N+1);
    for(int i=1;i<=N;i++){
        int w1,r1,r2,w2;cin>>w1>>r1>>w2>>r2;
        g[i][0]={r1,w1};
        g[i][1]={r2,w2};
        p[r1]=i;p[r2]=i;
    }
    vector<int>sm(N+1,0);
    function<void(int)>fdSm=[&](int u){
        for(auto [v,w]:g[u]){
            if(v==0)sm[u]+=w;
            else sm[v]+=w,fdSm(v),sm[u]+=sm[v];
        }
    };
    auto val=[&](int u,int s){
        auto [v,w]=g[u][s];
        return v?sm[v]:w;
    };
    function<int(int)>cont=[&](int u){
        return abs(val(u,0)-val(u,1));
    };
    int base=0;
    function<void(int)>fdCont=[&](int u){
        if(u==0)return;
        for(auto [v,w]:g[u])fdCont(v);
        base+=cont(u);
    };
    fdSm(1);fdCont(1);
    int best=base;
    // for(int i=1;i<=N;i++)printf("%d ",sm[i]);printf("\n");
    printf("cont is %d\n",base);
    for(int i=2;i<=N;i++){
        printf("===%d===\n",i);
        int o=i==g[p[i]][0].first;
        int W=sm[i]-g[p[i]][!o].second;
        printf("W = %d\n",W);
        function<void(int,int)>dfsDown=[&](int u,int a){
            printf("dat %d with %d\n",u,a);
            for(int s=0;s<=1;s++){
                auto [v,w]=g[u][s];
                int o=!s;
                if(v==0){
                    // leaf node
                    printf("at leaf with %d %d\n",u,a);
                    int ow=val(u,o);
                    int ans=a-cont(u)+abs(w+W-ow);
                    printf("ans %d at %d\n",ans,u);
                    best=min(best,ans);
                } else {
                    int d=abs(sm[v]+W-val(u,o));
                    dfsDown(v,a-cont(u)+d);
                }
            }
        };
        function<void(int,int,int,int)>dfsUp=[&](int u,int a,int par,int rollback){
            printf("at %d with %d rb %d\n",u,a,rollback);
            if(u!=1){
                int o=u==g[p[u]][0].first;
                int d=abs(sm[u]-W-val(p[u],o));
                dfsUp(p[u],a-cont(p[u])+d,u,d);
            }
            if(u!=i){
                for(int s=0;s<=1;s++){
                    auto [v,w]=g[u][s];
                    if(v==par)continue;
                    int o=!s;
                    if(v==0){
                        // leaf node
                        int ow=val(u,o)-W;
                        int ans=a-rollback+abs(w+W-ow);
                        printf("ans %d at %d\n",ans,u);
                        best=min(best,ans);
                    } else {
                        int d=abs(sm[v]+W-(val(u,o)-W));
                        dfsDown(v,a-rollback+d);
                    }
                }
            }
        };
        dfsUp(i,base,i,0);
    }
    cout<<best<<endl;
}

// begin signature
// +----------------------------------------+
// |覇慶義群耗李洪允せビ丁丁シㇵㇸ・・ㇸㇵシ|
// |奏和李洪允火丁ヘ一・　　一ヘシミシヘ一　|
// |允せ火丁ㇵ一一ㇵ・・ヘビせ山允允山せ丁ヘ|
// |ヘ一ㇸ・ㇸ・ㇸㇵシミミシヘシ丁せ汎洪山ビ|
// |ㇸヘシシシシビシヘㇵヘミヘㇵ一ヘビ汎李允|
// |ビせ山允火丁一ㇵ・ㇵ一・ㇸㇵヘ一・ミ允和|
// |允洪労洪せシ　一一ビせ火丁火ミヘヘ・ヘせ|
// |労耗李山丁ㇸ一ㇸヘせ労労允丁一・一ㇸㇸヘ|
// |汎允允丁ㇸㇵ・　丁汎耗李せㇵ一丁せビㇵㇸ|
// |ミシシ　シㇵ一ヘ山和和允シㇸビ洪労山ヘヘ|
// |・・一丁ミ・ㇸ火労和洪丁　ミ允和汎丁・ビ|
// |・丁丁せヘ一ヘせ汎山せミ　ミせせ丁ㇸシ允|
// |　ミ火允ミ・・ビ丁シㇵ一一　ㇵㇵㇸ　丁汎|
// |ㇸ・丁汎山ヘ一・一　一ヘヘヘㇸ一ㇸ・丁汎|
// |火ㇵ　ミ允山ヘㇸ・ヘビせ山山せ火火ビ丁允|
// |洪火ヘ　シせビㇸㇵビ允労和和允ビヘシせ洪|
// |洪汎火ヘ・シヘㇸビ汎和陽耗汎ビシ丁山洪汎|
// |せせビビシ一ㇸビ洪奏慶奏汎火せ允汎山火ミ|
// |ㇵㇵ山允ミ・ビ洪奏覇奏洪丁ミミミシㇵ・ㇸ|
// |・ミ允火一ヘ山和慶義和山ㇵ　　・ㇸㇵミ火|
// +----------------------------------------+
// 2026 (May 16th) 15:06:33
// end signature

