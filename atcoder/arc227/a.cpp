#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
    string A,B,C;cin>>A>>B>>C;
    vector<vector<int>>D(N);
    {
        int c=0;
        for(int i=0;i<2*N;i++){
            if(A[i]=='1')D[c++].push_back(i);
        }
    }
    {
        int c=0;
        for(int i=0;i<2*N;i++){
            if(B[i]=='1')D[c++].push_back(i);
        }
    }
    {
        int c=0;
        for(int i=0;i<2*N;i++){
            if(C[i]=='1')D[c++].push_back(i);
        }
    }
    for(int i=0;i<N;i++)sort(D[i].begin(),D[i].end());
    string S(2*N,'0');
    long long ans=0;
    for(int i=0;i<N;i++)ans+=D[i][1]-D[i][0]+D[i][2]-D[i][1];
    for(int i=0;i<N;i++)S[D[i][1]]='1';
    cout<<ans<<endl;
    cout<<S<<endl;
}
