#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int T;cin>>T;
    while(T--){
        int N,M;cin>>N>>M;
        vector<int>HEAD(N*M),A(N*M),bad(N*M);
        auto id=[&](int r,int c){
            return (r-1)*(M-1)+(c-1);
        };
        for(int i=1;i<=N-1;i++){
            for(int j=1;j<=M;j++){
                int v;cin>>v;
                if(j<=M-1)A[id(i,j)]+=v;
                if(j-1>=1)A[id(i,j-1)]-=v;
            }
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M-1;j++){
                int v;cin>>v;
                if(i<=N-1)A[id(i,j)]+=v;
                if(i-1>=1)A[id(i-1,j)]-=v;
            }
        }
        iota(HEAD.begin(),HEAD.end(),0);
        function<int(int)>head=[&](int u){
            return u==HEAD[u]?u:HEAD[u]=head(HEAD[u]);
        };
        function<void(int,int)>join=[&](int a,int b){
            a=head(a),b=head(b);
            if(a==b)return;
            A[b]+=A[a];
            bad[b]|=bad[a];
            HEAD[a]=b;
        };
        for(int i=1;i<=N-1;i++){
            string S;cin>>S;
            for(int j=1;j<=M;j++){
                if(S[j-1]=='0'){
                    if(j-1==0)bad[head(id(i,j))]=true;
                    else if(j==M)bad[head(id(i,j-1))]=true;
                    else join(id(i,j),id(i,j-1));
                }
            }
        }
        for(int i=1;i<=N;i++){
            string S;cin>>S;
            for(int j=1;j<=M-1;j++){
                if(S[j-1]=='0'){
                    if(i-1==0)bad[head(id(i,j))]=true;
                    else if(i==N)bad[head(id(i-1,j))]=true;
                    else join(id(i,j),id(i-1,j));
                }
            }
        }
        vector<int>used(N*M);
        int ans=0;
        for(int i=1;i<=N-1;i++){
            for(int j=1;j<=M-1;j++){
                int k=head(id(i,j));
                if(used[k])continue;
                if(bad[k])continue;
                used[k]=true;
                if(A[k]>0)ans+=A[k];
            }
        }
        cout<<ans<<endl;
    }
}

// begin signature
// +----------------------------------------+
// |陽奏李洪汎山せビ丁ミシシシミ丁火山汎労和|
// |和洪允せビミシㇵㇸ・　　・ㇸㇵシ丁せ汎労|
// |允せ丁ヘ一ㇸ　ㇸ一ㇸ・ㇸㇸㇸ　一シビ山允|
// |ビヘㇸㇸ　一・・一ㇵ一一一・・　ㇵミ丁火|
// |ヘ・ㇸ　一　ㇵㇸ　・ㇸㇸ　・　　　・ㇵシ|
// |ㇵ　ㇸ一・ㇸ　ㇸㇵシミミシㇵㇵヘヘㇵㇸ　|
// |ㇵ　ㇸ一・　ㇵシシビせ山せ火丁ビ火火丁シ|
// |ㇵ　ㇸ一・一ミヘ丁せ汎労労洪山允汎汎允せ|
// |一・　一一ミㇵシ火汎李耗奏和洪労和和李汎|
// |　　ㇵ一ヘ・ㇵビ允李群慶陽耗労奏陽群和汎|
// |ㇸㇵㇵ一・ㇸ丁山労奏慶慶群李耗義義奏労山|
// |ヘ一ㇸㇸ・ㇵビ允李奏群群和労耗奏奏李允ビ|
// |ㇵㇵ一ㇸㇸㇸミせ汎労李李洪允労労労汎せミ|
// |シㇸ　ㇸ　ㇵミ火山汎洪労労洪允山山せビシ|
// |ㇵㇵ・　一ヘビ山洪李和耗和洪山火丁ミミㇵ|
// |ㇵシㇸ　・シ火汎李耗群奏労允火ミㇵㇸ・・|
// |ㇵㇵ・・ㇵビ允労耗陽群和汎火ミ一　一ㇵㇵ|
// |・ㇵㇸ一丁山労奏義陽和汎火シ・一シビビ丁|
// |　　ㇸミ山労奏義陽耗洪せシ　ㇵビ山允允ビ|
// |一　ヘ火汎和陽慶群李允丁一ㇸ丁山労李汎火|
// +----------------------------------------+
// 2026 (August 16th) 17:20:07
// end signature
