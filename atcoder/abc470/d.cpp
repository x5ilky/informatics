#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,Q;cin>>N>>Q;
    vector<int>P(N+1);
    for(int i=1;i<=N;i++)cin>>P[i];
    vector<int>pos(N+1);
    for(int i=1;i<=N;i++)pos[P[i]]=i;
    bool flip=false;
    auto swp=[&](int a,int b){
        swap(pos[P[a]],pos[P[b]]);
        swap(P[a],P[b]);
    };
    for(int i=1;i<=Q;i++){
        int t;cin>>t;
        if(t==1){
            int a,b;cin>>a>>b;
            if(!flip)swp(a,b);
            else swp(pos[a],pos[b]);
        }else if(t==2){
            flip=!flip;
        }
    }
    for(int i=1;i<=N;i++)cout<<(flip?pos[i]:P[i])<<" ";
    cout<<endl;
}
