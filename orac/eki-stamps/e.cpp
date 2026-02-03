#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;
 
signed main(){
    using pii = pair<int, int>;
    int n; cin>>n; vector<pii>a(n+1); 
    for(int i=1; i<=n; i++){
        cin>>a[i].first; a[i].second=i; 
    }
    sort(a.begin()+1,a.end()); int cur=(n+1)/2; 
    for(int i=0; i<n; i++){
        if(i%2==1)cur+=i; else cur-=i; 
        cout<<a[cur].second<<' '; 
    }
}
