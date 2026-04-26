#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,M;cin>>N>>M;
    using ld=long double;
    vector<ld>no(101);
    no[0]=0;
    no[1]=1;
    pair<ld,int> best={1,1};
    for(int i=2;i<=min(M,100);i++){
        no[i]=(no[i-2]+no[i-1]*(N-1))/N; 
        best=min(best,{no[i-1],i});
        cout<<no[i]/N<<endl;
    }
    cout<<best.second<<endl;
}

// int yes,no
// yes[i]=no[i-1]/N
// no[i]=(no[i-2]+no[i-1]*(N-1))/N
