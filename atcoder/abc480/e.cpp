#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    long long N;cin>>N;
    int c=0;
    using i128=__int128;
    // i love algebra bash
    for(int a=1;(i128)a*(a+1)*(a+2)<=N;a++){
        int x=a*a+8*(N/a);
        int s=sqrtl(x);
        while((i128)(s+1)*(s+1)<=x)s++;
        while((i128)s*s>x)s--;
        int d=max(0LL,(s-3*a)/4);
        while((i128)a*(a+d+1)*(a+2*d+2)<=N)d++;
        while(d&&(i128)a*(a+d)*(a+2*d)>N)d--;
        c+=d;
    }
    for(int n=4;n<=20;n++){
        for(int d=1;d;d++){
            bool bad=0;
            {
                i128 c=1;
                for(int i=0;i<n;i++){
                    c*=1+d*i;
                    if(c>N)bad=1;
                }
            }
            if(bad)break;
            int lo=1,hi=1e6+2;
            while(lo+1<hi){
                int mid=(lo+hi)/2;
                i128 c=1;
                for(int i=0;i<n;i++){
                    c*=mid+d*i;
                    if(c>N)break;
                }
                if(c>N)hi=mid;
                else lo=mid;
            }
            // printf("n %lld d %lld lo hi %lld %lld\n",n,d,lo,hi);
            if(lo==-1)break;
            c+=lo;
        }
    }
    cout<<(long long)c<<endl;
}
