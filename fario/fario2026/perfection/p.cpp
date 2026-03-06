#include <bits/stdc++.h>

using namespace std;

#define printf(...)
#define int long long
const int INF=(1ULL<<60);
signed main() {
    int N,A,D,M;cin>>N>>A>>D>>M;
    vector<int>count(5010,0);
    set<int>Vr{};
    for (int i=1;i<=N;i++){
        int v; cin>>v; count[v]++;
        Vr.insert(v);
    }
    vector<int>summable(5010,0);
    summable[0]=true;
    for (int i=1;i<=5000;i++){
        if(count[i]==0) {
            for (int j=1;j<=5000-i;j++){
                if(summable[j])summable[i+j]=true;
            }
            summable[i]=true;
        }
    }

    vector<int>V(Vr.begin(),Vr.end());
    if (true){
        int v=INF;
        if (count[V[0]]<V[0])v=min(v,(V[0]-count[V[0]])*A);
        if (count[V[0]]<V[0]) {
            int modify=V[0]-count[V[0]],best=INF;
            for (int i=0;i<=modify;i++){
                if(summable[i])best=min(best,i*M+(modify-i)*A);
            }
            v=min(v,best);
        }
        if (count[V[0]]>V[0]) {
            int modify=count[V[0]]-V[0],best=INF;
            for (int i=0;i<=modify;i++){
                if(summable[i])best=min(best,i*M+(modify-i)*D);
                printf("best:%lld\n",best);
            }
            v=min(v,best);
        }
        {
            int modify=count[V[0]],best=INF;
            for (int i=0;i<=modify;i++){
                if(summable[i])best=min(best,i*M+(modify-i)*D);
                printf("best2:%lld\n",best);
            }
            v=min(v,best);
        }
        if (count[V[0]]==V[0])v=min(v,0LL);
        cout<<v<<endl;
    } else {
    }
}
    
