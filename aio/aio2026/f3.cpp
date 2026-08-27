#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int N,K;cin>>N>>K;
    vector<int>R(N+1),C(N+1);
    for(int i=1;i<=N;i++)cin>>R[i];
    for(int i=1;i<=N;i++)cin>>C[i];
    if(accumulate(R.begin(),R.end(),0ll)!=accumulate(C.begin(),C.end(),0ll)){
        // printf("bad sum\n");
        cout<<"NO"<<endl;
        return 0;
    }
    using pii=pair<int,int>;
    vector<pii>RS(N+1);
    for(int i=1;i<=N;i++)RS[i]={R[i],i};
    sort(RS.begin()+1,RS.end());
    reverse(RS.begin()+1,RS.end());
    vector<pii>c(N+1);
    for(int i=1;i<=N;i++)c[i]={C[i],i};
    vector<vector<int>>out(N+1,vector<int>(N+1,0));
    for(int r=1;r<=N;r++){
        sort(c.begin()+1,c.end());
        vector<pii>nw(c.begin(),c.end());
        int j=N,i=N,rem=RS[r].first;
        vector<int>d(N+1),d2(N+1);
        int remaining=0;
        for(int i=1;i<=N;i++)remaining+=c[i].first;
        int v=c[N].first,v2=0;
        auto take=[&](int l,int r,int a){
            d[r]-=a;
            d[l-1]+=a;
            d2[r]-=a;
            d2[l-1]+=a;
            rem-=(r-l+1)*a;
            v-=a;
            v2+=a;
            printf("take %d-%d amt %d\n",l,r,a);
        };
        printf("[[START REM = %d]]\n",rem);
        while(rem){
            if(remaining<=0){
                // printf("NOT ENOUGH\n");
                cout<<"NO"<<endl;
                return 0;
            }
            printf("rem = %d, v = %d, v2 = %d\n",rem,v,v2);
            // for(int i=1;i<=N;i++)printf("%lld ",str.query(1,0,N,i,i));printf("\n");
            while(i>1&&v==c[i-1].first)i--,v+=d[i];
            int mxrem=K-v2;
            int dif=v-c[i-1].first;
            int rm=min(dif,mxrem);
            // printf("i,j = [%d,%d]\n",i,j);
            // printf("rm = %d\n",rm);
            if(rm<=0){
                // printf("rm <= 0\n");
                cout<<"NO"<<endl;
                return 0;
            }
            if((j-i+1)*rm<=rem){
                // printf("less\n");
                take(i,j,rm);
            }else{
                // printf("greater\n");
                int a=rem/(j-i+1);
                take(i,j,a);
                if(rem==0)break;
                for(int k=i;k<=i+rem-1;k++)nw[k].first--;
                break;
            }
            printf("out\n");
            while(j>1&&v2>=K){
                printf("i = %d, j = %d, rem = %d, v = %d, v2 = %d\n",i,j,rem,v,v2);
                j--;
                if(j<i){
                    i=j;
                    v+=d[i];
                }
                v2+=d2[j];
            }
        }
        int p=0;
        for(int i=N;i>=1;i--){
            p+=d[i];
            nw[i].first-=p;
        }
        // printf("[[END REM]]\n");
        for(int k=1;k<=N;k++)printf("%lld ",nw[k]);printf("\n");
        for(int k=1;k<=N;k++)out[RS[r].second][c[k].second]=c[k].first-nw[k].first;
        for(int k=1;k<=N;k++)c[k].first=nw[k].first;
    }
    int s=0;
    for(auto v:c)s+=v.first;
    if(s!=0){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)cout<<out[i][j]<<" ";
        cout<<"\n";
    }
    cout<<endl;
}
