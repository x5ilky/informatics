#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N,K;cin>>N>>K;
    vector<int>A(K+1);
    multiset<int>B;
    for(int i=1;i<=N;i++){
        int v;cin>>v;
        if(i<=K)A[i]=v;
        else B.insert(v);
    }
    if(K==0){
        cout<<(*--B.end()-*B.begin())<<endl;
        return 0;
    }
    if(K==N){
        int c=0;
        for(int i=1;i<K;i++)c+=abs(A[i+1]-A[i]);
        return cout<<c<<endl,0;
    }
    int mn=*min_element(A.begin()+1,A.end());
    int mx=*max_element(A.begin()+1,A.end());
    int lo=min(mn,*B.begin());
    int hi=max(mx,*--B.end());
    vector<int>X={
        2*(mn-lo),
        abs(A[1]-lo),
        abs(A[K]-lo)
    };
    vector<int>Y={
        2*(hi-mx),
        abs(A[1]-hi),
        abs(A[K]-hi)
    };
    int c=0;
    for(int i=1;i<K;i++)c+=abs(A[i+1]-A[i]);
    int c2=LLONG_MAX;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            if(i==j&&i!=0)continue;
            c2=min(c2,X[i]+Y[j]);
        }
    cout<<c+c2<<endl;
}
