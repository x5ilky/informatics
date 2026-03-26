#include <bits/stdc++.h>

using namespace std;

#define int long long
signed main() {
    freopen("race.in","r",stdin);
    freopen("race.out","w",stdout);
    int K,N;cin>>K>>N;
    for (int q=1;q<=N;q++){
        int X;cin>>X;
        int lo=0,hi=1e8+10;
        while(lo+1<hi){
            int mid=(lo+hi)/2;
            int a=mid*(mid+1)/2;
            if(mid>=X){
                a-=(X-1)*X/2;
                a+=(mid-1)*mid/2;
            }
            if (a>K)hi=mid;
            else lo=mid;
        }
        int c=lo;
        if(lo>=X){
            c+=lo-X;
        }
        int a=lo*(lo+1)/2;
        if(lo>=X){
            a-=(X-1)*X/2;
            a+=(lo-1)*lo/2;
        }
        c+=(K-a+lo-1)/lo;
        // printf("lo=%d,c=%d,a=%d\n",lo,c,a);
        cout<<c<<endl;
    }
}
