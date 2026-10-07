#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        string S;cin>>S;
        S.insert(S.begin(),' ');
        vector<int>seen(N+1),st{};
        for(int i=1;i<=N;i++){
            if(S[i]=='1')st.push_back(i);
            if(S[i]=='2'){
                if(st.empty())
                    seen[i]=true;
                else seen[st.back()]=true,st.pop_back();
            }
            if(S[i]=='3')seen[i]=true;
        }
        int cnt=0;
        for(int i=1;i<=N;i++)cnt+=!seen[i];
        cout<<cnt<<endl;
        for(int i=1;i<=N;i++)if(!seen[i])cout<<i<<" ";
        cout<<endl;
    }
}

