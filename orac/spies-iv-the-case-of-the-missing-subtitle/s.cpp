#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {
    freopen("spiesin.txt","r",stdin);
    freopen("spiesout.txt","w",stdout);
    int N;cin>>N;
    vector<int>X(N),Y(N);
    for (int i=0;i<N;i++)cin>>X[i]>>Y[i];
    sort(X.begin(),X.end()); sort(Y.begin(),Y.end());
    cout<<X[X.size()/2]<<" "<<Y[Y.size()/2]<<endl;
}
