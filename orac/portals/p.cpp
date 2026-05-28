#pragma GCC optimize("O3")
#pragma GCC optimization("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int N,Q;cin>>N>>Q;
    const int B=700;
    vector<int>offset(N+1);
    for(int i=1;i<=N;i++)cin>>offset[i];
    vector<vector<array<int,3>>>blocks((Q+B-1)/B);
    for(int i=0;i<=Q-1;i++){
        int t;cin>>t;
        if(t==1){
            int a,x;cin>>a>>x;
            blocks[i/B].push_back({t,a,x});
        }
        if(t==2){
            int x;cin>>x;
            blocks[i/B].push_back({t,x,0});
        }
    }
    vector<int>been(N+1);int timer=0;
    vector<int>c;c.reserve(B);
    vector<short>spec(N+2),loop(N+2);
    vector<int>seen(N+1),dist(N+1,-2),goes(N+1,-1);;
    for(auto &b:blocks){
        fill(spec.begin(),spec.end(),0);
        fill(loop.begin(),loop.end(),0);
        fill(seen.begin(),seen.end(),0);
        fill(dist.begin(),dist.end(),-2);
        fill(goes.begin(),goes.end(),-1);
        for(auto&[t,a,x]:b)if(t==1)spec[a]=true;
        for(int i=1;i<=N;i++){
            if(seen[i]||spec[i])continue;
            // printf("starting %d\n",i);
            c.clear();c.push_back(i);
            while(true){
                auto u=c.back();loop[u]=true;
                seen[u]=true;
                // printf("at %d\n",u);
                int v=u+offset[u];
                if(v<=0||v>=N+1){
                    for(int i=0;i<c.size();i++){
                        dist[c[i]]=(int)c.size()-i;
                        loop[c[i]]=false;
                        goes[c[i]]=0;
                    }
                    break;
                }
                if(spec[v]){
                    for(int i=0;i<c.size();i++){
                        dist[c[i]]=(int)c.size()-i;
                        loop[c[i]]=false;
                        goes[c[i]]=v;
                    }
                    break;
                }
                if(seen[v]){
                    if(loop[v]){
                        break;
                    }
                    for(int i=0;i<c.size();i++){
                        dist[c[i]]=(int)c.size()-i+dist[v];
                        loop[c[i]]=false;
                        goes[c[i]]=goes[v];
                    }
                    break;
                }
                c.push_back(v);
            }
        }
        // for(int i=1;i<=N;i++)printf("%d ",goes[i]);printf("\n");
        // for(int i=1;i<=N;i++)printf("%d ",dist[i]);printf("\n");
        // for(int i=1;i<=N;i++)printf("%d ",(int)loop[i]);printf("\n");
        for(auto&[t,a,x]:b){
            if(t==1){
                offset[a]=x;
            }else if(t==2){
                timer++;
                int u=a,s=0;
                while(true){
                    // printf("u=%d, steps=%d\n",u,s);
                    if(spec[u]){
                        if(been[u]==timer){
                            s=-1;
                            cout<<s<<'\n';
                            goto skip;
                        }
                        been[u]=timer;
                        u+=offset[u];s++;
                        if(u<=0||u>=N+1){
                            cout<<s<<'\n';
                            goto skip;
                        }
                    } else {
                        if(loop[u]){
                            s=-1;
                            cout<<s<<'\n';
                            goto skip;
                        }
                        if(goes[u]==0){
                            s+=dist[u];
                            cout<<s<<'\n';
                            goto skip;
                        }
                        s+=dist[u];u=goes[u];
                    }
                }
                cout<<-1<<'\n';
            }
skip:;
        }
    }
}
