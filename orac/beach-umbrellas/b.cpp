#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
// JUST THOUGHT ABOUT IT
// the transition should be go as far as possible 
// while you have "overhang" when crossing umbrellas
// the moment your extra umbrellas end up inside an existing one, you stop
//
// if you use X umbrellas, this is optimal
// if you use less, you can simulate / bash it out manually
//
// the below code is before this

#define int long long
signed main() {
    int N,M,K,X;cin>>N>>M>>K>>X;
    using pii=pair<int,int>;
    vector<pii>s;
    for(int i=1;i<=M;i++){
        int l,r;cin>>l>>r;
        s.push_back({l,r});
    }
    sort(s.begin(),s.end());
    vector<pii>ns={{0,0}};
    for(int i=0;i<M;){
        auto [l,r]=s[i];
        i++;
        while(i<M&&s[i].first<=r+1){
            r=max(r,s[i].second);
            i++;
        }
        ns.push_back({l,r});
    }
    int G=ns.size()-1;
    using ai3=array<int,3>;
    vector<array<ai3,28>>jump(G+1);
    vector<int>left(G+1);
    for(int i=1;i<=G-1;i++){
        auto it=upper_bound(ns.begin()+1,ns.end(),pii{ns[i].second+X+1,INT_MAX});
        if(it!=ns.begin()+1){
            it--;
            if(it->first<=ns[i].second+X+1&&ns[i].second+X+1<=it->second){
                jump[i][0]={(int)(it-ns.begin()),1,max(ns[i].second+X,it->second)};
                left[i]=min(it->first-X,ns[i].first);
                continue;
            }
        }
        int j=(ns[i+1].first-ns[i].second-1+X-1)/X;
        jump[i][0]={i+1,j,max(ns[i].second+j*X,ns[i+1].second)};
        left[i]=max(1ll,min(ns[i+1].first-X,ns[i].first));
    }
    jump[G][0]={G,0,ns[G].second};
    left[G]=ns[G].first-X;
    for(int k=1;k<=27;k++){
        for(int i=1;i<=G;i++){
            jump[i][k]={
                jump[jump[i][k-1][0]][k-1][0],
                jump[jump[i][k-1][0]][k-1][1]+jump[i][k-1][1],
                max(jump[i][k-1][2],jump[jump[i][k-1][0]][k-1][2])
            };
        }
    }
    // for(int k=0;k<=27;k++){
    // for(int i=1;i<=G;i++)printf("%d,%d,%d ",jump[i][k][0],jump[i][k][1],jump[i][k][2]);
    // printf("\n");
    // }
    int ans=0;
    for(int i=1;i<=G;i++){
        int c=K,v=i,r=ns[i].second;
        for(int k=27;k>=0;k--){
            if(jump[v][k][1]==0)break;
            if(c>=jump[v][k][1]){
                r=jump[v][k][2];
                c-=jump[v][k][1];
                v=jump[v][k][0];
            }
        }
        r=min(r,N);
        int l=ns[i].first;
        if(K>0&&c<K){
            l=left[i];
        }
        int extral=(l-1)/X,extrar=(N-r)/X,len=r-l+1;
        if(extral+extrar>=c){
            len+=c*X;
        } else {
            len+=(extral+extrar)*X;
            c-=(extral+extrar);
            r+=extrar*X;
            l-=extral*X;
            auto[m1,m2]=minmax({N-r,l-1});
            if(c>0)len+=m2,c--;
            if(c>0)len+=m1,c--;
        }
        // printf("at %d with %d left %d-%d\n",v,c,l,r);
        ans=max(ans,len);
    }
    cout<<ans<<endl;
}

// begin signature
// +----------------------------------------+
// |陽奏和労汎山火ビミシシシシミビ火山洪李奏|
// |和労允せビミヘ一・　　　・一ヘミビ山洪李|
// |汎せ丁ヘ一・　　　ㇸㇵシミミミシミせ山汎|
// |ビシㇸㇸㇵ一ㇸ一ㇵ一一一ㇵシ丁ビ丁ミビ山|
// |ヘ・ㇸ・　ㇸ一ㇸㇸㇸ・　　・ㇵミ火ビ丁丁|
// |ㇵ　　一ヘㇵ・・ㇵ　一ㇸㇸㇵシミシビ火せ|
// |ㇵ　・一ㇵ・・一一ㇸㇸ一ㇵ一　一シビミシ|
// |ㇵ　ㇸ・　・　ㇵ・・・・・ㇵシㇵ　ㇵ丁ミ|
// |　ㇸㇸ一・ㇵ・ㇵ・ㇸㇸㇵヘシミシヘ・シ丁|
// |　・一ㇸㇸ・ㇵ　・ヘㇵ一一一ㇵシミㇸシ丁|
// |　ヘ丁一一ㇸㇸ一　・ㇸㇸㇸ・　ㇸㇵㇸ丁ヘ|
// |・シミシ・ㇵ・一ヘミ丁丁ミシヘㇸ　ㇵミビ|
// |　ヘビヘ・ㇸヘ丁火せ山山山せビミㇵ　一ミ|
// |・　シㇵ　ヘ丁せ允洪労労労労汎山火ミ一・|
// |ミㇸ　ㇵ・シビ允洪和耗奏和洪山ビミシシヘ|
// |せミ一　ㇸミせ汎李奏陽奏労允火シㇵ・　　|
// |汎火シ　ㇵビ允李奏義群和汎火シㇸ・ㇵヘヘ|
// |山ミㇸ一丁允李奏慶陽和汎火シ・ㇵミ火火ビ|
// |丁一ㇸ丁山労奏慶義耗洪せシ　ヘビ允汎允火|
// |シ　ヘ火汎和陽覇群李允丁一ㇸ丁山労和汎火|
// +----------------------------------------+
// 2026 (May 28th) 20:42:47
// end signature

