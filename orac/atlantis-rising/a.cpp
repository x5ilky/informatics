#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N;cin>>N;
    vector<int>A(N+2),psA(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    for(int i=1;i<=N;i++)psA[i]=psA[i-1]+A[i];
    vector<int>st;
    const int INF=1ull<<60;
    A[N+1]=INF;st.push_back(N+1);
    vector<int>l(N+1,N+1),r(N+1,N+1);
    for(int i=1;i<=N;i++){
        while(A[i]>=A[st.back()])r[st.back()]=i,st.pop_back();
        st.push_back(i);
    }
    st.push_back(N+1);
    for(int i=N;i>=1;i--){
        while(A[i]>=A[st.back()])l[st.back()]=i,st.pop_back();
        st.push_back(i);
    }
    int i=1,ans=0;
    while(true){
        if(r[i]==N+1)break;
        ans+=r[i]-i-1;
        i=r[i];
    }
    int j=i;
    i=N;
    while(true){
        if(l[i]==N+1||i==j)break;
        ans+=i-l[i]-1;
        i=l[i];
    }
    cout<<ans<<endl;
}
