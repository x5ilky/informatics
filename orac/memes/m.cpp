#include <bits/stdc++.h>
using namespace std;
struct segtree2{
    struct node{
        int l,r,mx,same,sm;
    };
    vector<node>T;
    segtree2(int N):T(N*4,{0,0,0,0,0}){}
    node merge(node l,node r){
        node n={l.l,r.r,max(l.mx,r.mx),l.same&&r.same,l.sm+r.sm};
        n.mx=max(n.mx,l.r+r.l);
        if(l.same) n.l=l.r+r.l;
        if(r.same) n.r=l.r+r.l;
        return n;
    }
    void update(int v,int tl,int tr,int pos,int a){
        if(tl==tr){
            T[v]={a,a,a,a,a};
            return;
        }
        int tm=(tl+tr)/2;
        if(pos<=tm)update(v*2,tl,tm,pos,a);
        if(pos> tm)update(v*2+1,tm+1,tr,pos,a);
        T[v]=merge(T[v*2],T[v*2+1]);
    }
    node query(int v,int tl,int tr,int ql,int qr){
        if(ql<=tl&&tr<=qr)return T[v];
        int tm=(tl+tr)/2;node l,r;
        if(ql<=tm)l=query(v*2,tl,tm,ql,qr);
        if(qr >tm)r=query(v*2+1,tm+1,tr,ql,qr);
        if(ql<=tm&&qr>tm)return merge(l,r);
        if(ql<=tm)return l;
        if(qr >tm)return r;
        assert(false);
    }
};
struct segtree{
    struct node{
        int li,ll,ri,rl,rp,same,own;
    };
    vector<node>T;vector<int>S;vector<segtree2>start;multiset<int>longest;
    int SUM=0;
    unordered_map<int,int>lkp;int L;
    segtree(int N,vector<int>S):T(N*4,{-1,-1,-1,-1,-1,false,-1}),L((N+(int)S.size()-1)/S.size()),S(S){
        start=vector<segtree2>(S.size(),segtree2(L+1));
        for(int i=1;i<=S.size();i++)longest.insert(0);
        for(int i=0;i<S.size();i++){
            lkp[S[i]]=i;
        }
    }
    node merge(node l,node r){
        // printf("merge ");
        // printf("{li=%3d,ll=%3d,ri=%3d,rl=%3d,rp=%3d,same=%3d}",l.li,l.ll,l.ri,l.ri,l.rp,l.same);
        // printf(" and ");
        // printf("{li=%3d,ll=%3d,ri=%3d,rl=%3d,rp=%3d,same=%3d}",r.li,r.ll,r.ri,r.ri,r.rp,r.same);
        // printf(" -> ");
        node v=merge2(l,r);
        // printf("{li=%3d,ll=%3d,ri=%3d,rl=%3d,rp=%3d,same=%3d}",v.li,v.ll,v.ri,v.ri,v.rp,v.same);
        // printf("\n");
        return v;
    }
    void updstart(int i,int j,int v){
        // printf("start[%d][%d]=%d\n",i,j,v);
        longest.erase(longest.find(start[i].T[1].mx));
        SUM-=start[i].T[1].sm;
        start[i].update(1,0,L,j,v);
        SUM+=start[i].T[1].sm;
        longest.insert(start[i].T[1].mx);
    }
    node merge2(node l,node r){
        int M=S.size();
        node n={l.li,l.ll,r.ri,r.rl,r.rp,false,-1};
        if(l.ri==-1||r.li==-1)return n;
        if(l.ri+l.rl==r.li){
            if(l.same){
                n.li=l.ri;
                n.ll=l.rl+r.ll;
            }
            if(r.same){
                n.ri=l.ri;
                n.rl=l.rl+r.ll;
                n.rp=l.rp;
            }
            n.same=l.same&&r.same;
            if(l.ri==0&&l.rl+r.ll==M){
                n.own=l.rp;
            }
        }
        return n;
    }
    void update(int v,int tl,int tr,int pos,int a){
        int M=S.size();
        if(T[v].own!=-1){
            updstart(T[v].own%M,T[v].own/M,0);
        }
        if(tl==tr){
            if(lkp.find(a)==lkp.end())T[v]={-1,-1,-1,-1,-1,false,-1};
            else T[v]={lkp[a],1,lkp[a],1,pos,true,M==1?pos:-1};
        } else {
            int tm=(tl+tr)/2;
            if(pos<=tm)update(v*2,tl,tm,pos,a);
            if(pos> tm)update(v*2+1,tm+1,tr,pos,a);
            T[v]=merge(T[v*2],T[v*2+1]);
        }
        if(T[v].own!=-1){
            updstart(T[v].own%M,T[v].own/M,1);
        }
    }
};
int main() {
    int N,M;cin>>N>>M;
    vector<int>crit(N);for(int i=0;i<=N-1;i++)cin>>crit[i];
    segtree st(M,crit);
    for(int i=0;i<=M-1;i++){
        int v;cin>>v;
        // printf("== update %d at %d\n",v,i);
        st.update(1,0,M-1,i,v);
    }
    // for(auto r:st.start){
    //     for(int i=0;i<st.L;i++)printf("%d ",r.query(1,0,st.L,i,i).sm);
    //     printf("\n");
    // }
    // printf("ans=%d,%d\n",st.SUM,*st.longest.rbegin());
    int Q;cin>>Q;
    for (int q=1;q<=Q;q++){
        int i,v;cin>>i>>v;i--;
        // printf("== update %d at %d\n",v,i);
        st.update(1,0,M-1,i,v);
        cout<<st.SUM<<" "<<(*st.longest.rbegin())<<endl;;
    }
}

// begin signature
// +----------------------------------------+
// |覇義奏和労汎允山山山允汎労和奏義覇覇覇覇|
// |群和洪允せビミシシミ丁火山洪李奏義覇覇覇|
// |労山ビシㇵ一シ丁ビ火火ビビ山労耗陽覇覇覇|
// |火ミ一ㇸミ火山汎洪洪洪汎山火汎和群覇覇覇|
// |シ・ㇸミせ汎李耗奏奏耗和労汎汎洪耗義覇覇|
// |ヘ　ㇵビ允李奏陽慶義群奏奏耗耗李洪耗慶覇|
// |ヘ・ㇵビ汎和群群奏奏和耗奏群陽義群和耗慶|
// |ヘ　一ビ汎和耗李労洪洪洪洪労李耗奏義耗群|
// |ㇵㇸヘ火汎洪洪允せ火ビビ火せ山汎労耗群奏|
// |　・シ丁ビせビミヘㇵ一一ㇵシ丁火允労耗群|
// |・　　一シヘ・　　ㇸㇸㇸㇸ一ㇵミせ汎李群|
// |丁シヘㇸ・　一シミミミミミヘ一シ丁山労耗|
// |せシㇸ・・ヘ丁ヘ一・　　ㇸㇵミヘヘ丁允洪|
// |火ヘ　・ㇵ丁シ・ㇸ一　一ㇵㇵㇵヘ丁一丁火|
// |火ヘ　　ヘビㇵ・ヘ　ㇵミビ火ビ火火ビミ丁|
// |火ㇵ　　ヘ丁一一ㇵ・ミせ允洪洪汎允洪火ヘ|
// |ミ・ㇸ一　ヘ　シ　シ火汎汎允火山労李允ミ|
// |一　・丁ヘ・ヘ　シ火火火丁せ汎李群李山火|
// |・　シビ一一ㇸㇵミ丁ビ山汎李奏義奏労洪山|
// |ㇸ一ビミ・ヘ　シ山汎洪李耗陽慶義耗和汎山|
// +----------------------------------------+
// 2026 (April 18th) 15:13:18
// end signature


