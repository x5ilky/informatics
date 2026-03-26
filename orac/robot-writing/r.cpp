#include <bits/stdc++.h>
#include <vector>

using namespace std;

#define printf(...)
int main() {
    using pii=pair<int,int>;
    int N;cin>>N;
    set<pii>by_value,by_index;
    vector<int>A(N+1);
    for(int i=1;i<=N;i++){
        int a; cin>>a;
        A[i]=a;
        by_value.insert({a,i});
        by_index.insert({i,a});
    }
    by_value.insert({1e9,0});
    by_value.insert({1e9,1e9});
    by_index.insert({0,1e9});
    by_index.insert({1e9,1e9});
    int M;cin>>M;
    vector<pii>rle;
    {
        int c=0,p=-1;
        for (int i=1;i<=M;i++){
            int v;cin>>v;
            if(v<p){
                cout<<"NO\n";
                return 0;
            }
            if(v!=p){
                rle.push_back({p,c});
                p=v;
                c=1;
            } else {
                c++;
            }
        }
        rle.push_back({p,c});
    }
    // for(auto[p,c]:rle)printf("rle: %d x%d\n",p,c);

    int R=rle.size()-1;
    set<int>cand;
    for (auto [a,i]:by_value)
        if(a==rle[1].first)
            cand.insert(i);
    for (int r=1;r<=R;r++){
        // for (auto i:cand){
        //     printf("r=%d,cand %d\n",r,i);
        // }
        {
            // remove all of a
            for (auto it=by_value.begin();it!=by_value.end();){
                if(it->first<=rle[r].first) {
                    by_index.erase({it->second,it->first});
                    it=by_value.erase(it);
                }
                else break;
            }
        };
        auto [v,c]=rle[r];

        set<int> newcand;
        for (auto i:cand){
            if (c==1){
                if (i<N) {
                    bool works=true;
                    if(r<R)works&=A[i+1]==rle[r+1].first;
                    if(works){
                        newcand.insert(i+1);
                    }
                }
                if (i>1){
                    bool works=true;
                    if(r<R)works&=A[i-1]==rle[r+1].first;
                    if(works){
                        newcand.insert(i-1);
                    }
                }
            } else {
                auto aft=by_index.lower_bound({i,0});
                printf("aft: %d,%d\n",aft->first,aft->second);
                bool buffer=false;
                if (i>1){
                    if(A[i-1]<=v)buffer=true;
                }
                if (i<N){
                    if(A[i+1]<=v)buffer=true;
                }
                if(!buffer)continue;
                if (aft!=by_index.end()) {
                    if(r<R){
                        if(aft->first-i<=c&&((aft->first-i)&1)==(c&1)&&aft->second==rle[r+1].first){
                            newcand.insert(aft->first);
                        }
                    } else newcand.insert(i);
                }
                if (aft!=by_index.begin()){
                    auto bef=prev(aft);
                    if(r<R){
                        if(i-bef->first<=c&&((i-bef->first)&1)==(c&1)&&bef->second==rle[r+1].first){
                            newcand.insert(bef->first);
                        }
                    } else newcand.insert(i);
                }
            }
        }
        cand=newcand;
    }
    cout<<(cand.empty()?"NO\n":"YES\n")<<endl;
}
