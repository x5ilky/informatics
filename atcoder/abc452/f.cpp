#include <bits/stdc++.h>

using namespace std;

#define int long long

struct segtree {
    vector<int>T;
    segtree(int N):T(N*4){}
    void update(int v,int tl,int tr,int pos,int a){
        if(tl==tr){
            T[v]=a;
            return;
        }
        int tm=(tl+tr)/2;
        if(pos<=tm)update(v*2,tl,tm,pos,a);
        if(pos >tm)update(v*2+1,tm+1,tr,pos,a);
        T[v]=T[v*2]+T[v*2+1];
    }
    int query(int v,int tl,int tr,int ql,int qr){
        if(ql<=tl&&tr<=qr){
            return T[v];
        }
        int tm=(tl+tr)/2,ans=0;
        if(ql<=tm)ans+=query(v*2,tl,tm,ql,qr);
        if(qr >tm)ans+=query(v*2+1,tm+1,tr,ql,qr);
        return ans;
    }
};
struct segtree2 {
    vector<int>T;
    segtree2(int N):T(N*4,(1ull<<60)){}
    void update(int v,int tl,int tr,int pos,int a){
        if(tl==tr){
            T[v]=a;
            return;
        }
        int tm=(tl+tr)/2;
        if(pos<=tm)update(v*2,tl,tm,pos,a);
        if(pos >tm)update(v*2+1,tm+1,tr,pos,a);
        T[v]=min(T[v*2],T[v*2+1]);
    }
    int query(int v,int tl,int tr,int ql,int qr){
        if(ql<=tl&&tr<=qr){
            return T[v];
        }
        int tm=(tl+tr)/2,ans=(1ull<<60);
        if(ql<=tm)ans=min(ans,query(v*2,tl,tm,ql,qr));
        if(qr >tm)ans=min(ans,query(v*2+1,tm+1,tr,ql,qr));
        return ans;
    }
};

signed main() {
    const int INF=1ull<<60;
    int N,K;cin>>N>>K;
    vector<int>A(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    int r=1,cnt=0,ans=0; 
    set<int>cur;
    segtree st(N+10);
    segtree2 pos(N+10);
    queue<int> next;

    for (int i=2;i<=N;i++)
        if(A[i-1]>A[i])next.push(i);
    for (int i=1;i<=N;i++)pos.update(1,1,N,A[i],i);

    st.update(1,0,N+1,A[1],1);
    cur.insert(A[1]);
    pos.update(1,1,N,A[1],INF);

    for (int l=1;l<=N;l++){
        // printf("%d-%d = %d\n", l,r,cnt);
        if (l>r&&l<=N) {
            r=l; cur.insert(A[l]);
            st.update(1,0,N+1,A[l],1);
            pos.update(1,1,N,A[l],INF);
        }
        while (cnt<K&&r<N){
            r++;
            cur.insert(A[r]);
            cnt+=st.query(1,0,N+1,A[r]+1,N+1);
            st.update(1,0,N+1,A[r],1);
            pos.update(1,1,N,A[r],INF);
            // printf("%d-%d = %d\n", l,r,cnt);
        }
        if(cnt==K) {
            while(!next.empty()&&next.front()<=r)next.pop();
            int ns=pos.query(1,1,N,1,*cur.rbegin());
            int add=N+1-r;
            if(ns<INF)add=min(add,ns-r);
            if(!next.empty()){
                add=min(add,next.front()-r);
            }
            // printf("add %lld\n", add);
            ans+=add;
        }
        cur.erase(A[l]);
        cnt-=st.query(1,0,N+1,0,A[l]-1);
        st.update(1,0,N+1,A[l],0);
    }
    cout<<ans<<endl;
}

// begin signature
// +----------------------------------------+
// |陽奏和労汎山せ火火火せ山汎洪李奏陽覇覇覇|
// |和労允せビミシヘヘシミ丁火允洪和奏陽義義|
// |汎せ丁ヘ一ㇸヘミ丁ビ丁丁丁せ允労和和耗奏|
// |ビシㇸㇸシ丁火せせ山允山火ビ山汎汎洪労李|
// |ヘ・ㇸシ丁ミミミミミビビ火火火ビ火せ山允|
// |ㇵ　一シㇵ一・・・ㇸ一ヘヘヘヘㇵヘヘミ丁|
// |　　　　　ㇸ一・ㇸㇸㇸㇸㇸ・一ㇵヘヘㇵㇸ|
// |ヘシシシヘ・一一ㇸ・ㇸㇸ・・・・ㇸㇵシミ|
// |・ㇸ　・ㇸ一ㇸㇸㇵヘシシヘㇵㇸ・　　ㇸシ|
// |　・ヘㇵ一一シ丁ミヘㇵㇵ一ㇵヘ一　　　一|
// |　ヘビ丁シ丁ヘ一　　ㇸㇸㇸ・　ㇸㇵ・　・|
// |・シせビシㇸ　一ヘミミ丁ミシㇵㇸ　ㇵ　　|
// |　ヘビシㇸㇸヘ丁火せ山山山せビミㇵ　一　|
// |・　シㇵ　ㇵ丁せ允洪労労労洪汎山火シ一・|
// |ミㇸ　ㇵ・ヘビ山洪李耗奏和洪山火丁シシヘ|
// |せミ一　ㇸミせ汎李奏陽奏労允火ミㇵ・　・|
// |汎火シ　ㇵビ允李奏義群和汎火シㇸ・ㇵヘㇵ|
// |山ミㇸ一丁允李奏慶陽和汎火シ・一ミビ火丁|
// |丁一ㇸ丁山労奏慶義耗洪せシ　ヘビ火丁シ火|
// |シ　ヘ火汎和陽覇群李允丁一ㇸミシミビせ火|
// +----------------------------------------+
// 2026 (April 6th) 13:06:32
// end signature



