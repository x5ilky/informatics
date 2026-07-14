#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
using pii=pair<int,int>;
using ld=long double;
using pt=complex<ld>;
int main() {
    int N;cin>>N;
    vector<pt>pts(N+1);vector<bool>used(N+1);
    vector<ld>rad(N+1);
    for(int i=1;i<=N;i++){int x,y;cin>>x>>y;pts[i]=(ld)x+(ld)y*(pt)1i;}
    for(int q=1;q<=N;q++){
        vector<pair<ld,int>>about;
        for(int i=1;i<=N;i++){
            if(used[i])continue;
            ld dst=INT_MAX;
            for(int j=1;j<=N;j++){
                if(j==i)continue;
                dst=min(dst,sqrt(norm(pts[i]-pts[j]))-rad[j]);
            }
            dst=max(dst,(ld)0);
            about.push_back({dst,i});
        }
        sort(about.begin(),about.end());
        ld sum=0,sum2=0;
        for(auto [r,_]:about)sum+=r;
        for(auto [r,b]:about)if((sum2+=r)>=sqrt(sum)){
            used[b]=true;rad[b]=r;
            break;
        }
    }
    cout<<fixed<<setprecision(9);
    for(int i=1;i<=N;i++)cout<<max(rad[i],(ld)0)<<endl;
}
