#include <bits/stdc++.h>

using namespace std;

#define printf(...)
#define int long long
struct state{
    int up,down,mod,time;
};
const int INF=(1ULL<<60);
signed main() {
    int N,A,D,M;cin>>N>>A>>D>>M;
    vector<int>count(5010,0);
    set<int>Vr{};
    for (int i=1;i<=N;i++){
        int v; cin>>v; count[v]++;
        Vr.insert(v);
    }
    using pii=pair<int,int>;
    int L=Vr.size();
    vector<int>V(L+1);
    {
        int i=1; for (auto e : Vr)V[i++]=e;
    };
    vector<int>summable(5010,false);
    summable[0]=true;
    for (int i=1;i<=N;i++){
        if (count[i]==0){
            for (int j=1;j<=N-i;j++){
                if(summable[j])summable[i+j]=true;
            }
            summable[i]=true;
        }
    }

    auto optimise=[&](state u){
        state v=u;
        auto max_opt=min(u.down,u.up);
        if (M*max_opt<(A+D)*max_opt){
            v={u.up-max_opt,u.down-max_opt,u.mod+max_opt,u.time};
        }
        return v;
    };
    auto cost=[&](state u){
        return u.up*A+u.down*D+u.mod*M;
    };
    array<state,5010> best_up{},best_down{};
    array<state,5010> new_best_up{},new_best_down{};
    auto merge_up=[&](state mod){
        if(new_best_up[mod.up].time<mod.time)new_best_up[mod.up]=mod;
        else if(cost(mod)<cost(new_best_up[mod.up])){
            new_best_up[mod.up]=mod;
        }
    };
    auto merge_down=[&](state mod){
        if(new_best_down[mod.down].time<mod.time)new_best_down[mod.down]=mod;
        else if(cost(mod)<cost(new_best_down[mod.down])){
            new_best_down[mod.down]=mod;
        }
    };
    auto merge=[&](state mod) {
        auto opt=optimise(mod);
        printf("merge %lld %lld %lld = %lld\n",opt.up,opt.down,opt.mod,cost(opt));
        merge_up(opt);
        merge_down(opt);
        for (int add=1;add<=opt.down;add++) {
            if(!summable[add])continue;
            state convert={opt.up,opt.down-add,opt.mod+add,opt.time};
            merge_up(convert);
            merge_down(convert);
        }
    };

    for (int i=1;i<=L;i++){
        int v=V[i];
        if(count[v]<v) {
            // new up
            auto up_by=v-count[v];
            for (auto& e : best_up){
                if(e.time!=i-1)continue;
                merge({e.up+up_by,e.down,e.mod,i});
            }
            for (auto& e : best_down){
                if(e.time!=i-1)continue;
                merge({e.up+up_by,e.down,e.mod,i});
            }
        }
        if (count[v]>v){
            auto down_by=count[v]-v;
            for (auto& e : best_up){
                if(e.time!=i-1)continue;
                merge({e.up,e.down+down_by,e.mod,i});
            }
            for (auto& e : best_down){
                if(e.time!=i-1)continue;
                merge({e.up,e.down+down_by,e.mod,i});
            }
        }
        {
            auto down_by=count[v];
            for (auto& e : best_up){
                if(e.time!=i-1)continue;
                merge({e.up,e.down+down_by,e.mod,i});
            }
            for (auto& e : best_down){
                if(e.time!=i-1)continue;
                merge({e.up,e.down+down_by,e.mod,i});
            }
        }
        if (count[v]==v){
            for (auto& e : best_up){
                if(e.time!=i-1)continue;
                merge({e.up,e.down,e.mod,i});
            }
            for (auto& e : best_down){
                if(e.time!=i-1)continue;
                merge({e.up,e.down,e.mod,i});
            }
        }
        swap(new_best_up,best_up);
        swap(new_best_down,best_down);
        printf("time = %lld\n",i);
        for (auto& e : best_up){
            if(e.time!=i)continue;
            printf("%lld %lld %lld = %lld\n",e.up,e.down,e.mod,cost(e));
        }
        for (auto& e : best_down){
            if(e.time!=i)continue;
            printf("%lld %lld %lld = %lld\n",e.up,e.down,e.mod,cost(e));
        }
    }
    int ans=INF;
    for (auto& e : best_up){
        if(e.time!=L)continue;
        ans=min(ans,cost(e));
    }
    for (auto& e : best_down){
        if(e.time!=L)continue;
        ans=min(ans,cost(e));
    }
    cout<<ans<<endl;
}
