#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int main() {
    int N,K;cin>>N>>K;
    vector<string>S(N+1);
    for(int i=1;i<=N;i++)cin>>S[i];
    sort(S.begin()+1,S.end(),[](const auto&a,const auto&b){
        return a+b<b+a;
    });
    vector<int>rawl(N+1);
    for(int i=1;i<=N;i++){
        int j=0;
        for(;j<S[i].size();j++){
            if(S[i][j]!='0')break;
        }
        rawl[i]=S[i].size()-j;
    }
    vector<pii>L={{}};
    vector<int>used(N+1);
    for(int i=1;i<=N;i++)L.push_back({S[i].size(),i});
    sort(L.begin()+1,L.end());
    int s=0;
    for(int i=N;i>N-K+1;i--)s+=L[i].first,used[L[i].second]=true;
    using T=tuple<int,string,int>;
    T best={0,"",0};
    for(int i=1;i<=N;i++){
        // printf("raw = %d, sz = %d, s n-k+1 = %d\n",rawl[i],S[i].size(), L[N-K+1].first);
        int l=s;
        if(used[i])l-=S[i].size(),l+=rawl[i]+L[N-K+1].first;
        else l+=rawl[i];
        if(T{l,S[i],i}>best){
            best={l,S[i],i};
        }
    }
    vector<string>S2;
    int c=0;
    for(int i=N;c<K-1;i--){
        if(L[i].second==get<2>(best))continue;
        S2.push_back(S[L[i].second]);
        c++;
    }
    sort(S2.begin(),S2.end(),[](const auto&a,const auto&b){
        return a+b<b+a;
    });
    string S3=get<1>(best);
    for(int i=0;i<K-1;i++){
        S3+=S2.back();S2.pop_back();
    }
    bool b=false;
    for(int i=0;i<S3.size();i++){
        if(!b&&S3[i]=='0'&&i!=S3.size()-1)continue;
        else b=1;
        cout<<S3[i];
    }
    cout<<endl;
}
