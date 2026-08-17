#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
    string S;cin>>S;
    S.insert(S.begin(),0);
    int ans=1e9;
    for(int d=1;d<=N;d++){
        if(N%d!=0)continue;
        string T=" ";
        for(int j=1;j<=d;j++){
            T+=S[j];
        }
        for(int i=1;i<=N;i++){
            if(i*d>N)break;
            for(int j=1;j<=d;j++){
                if(S[(i-1)*d+j]!=T[j])goto skip;
            }
        }
        ans=N/d;
        break;
skip:;
    }
    if(ans==1e9)ans=1;
    cout<<ans<<endl;
    S.erase(S.begin());
    cout<<N*N<<endl;
    for(int i=1;i<=N;i++)cout<<S;
    cout<<endl;
}
