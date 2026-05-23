#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int T;cin>>T;
    while(T--){
        int A,B,X,Y;cin>>A>>B>>X>>Y;
        int x1=A,y1=B,x2=B,y2=A;
        int sx=0,sy=0,sol=0;
        {
            int an=X*y2-x2*Y,ad=x1*y2-x2*y1;
            int bn=x1*Y-X*y1,bd=x1*y2-x2*y1;
            if(an%ad!=0||bn%bd!=0){
            } else if(ad==0){
            } else{
                sx=an/ad;sy=bn/bd;sol=1;
            }
        }
        x1=A,y1=B,x2=-B,y2=A;
        if(sol!=1){
            int an=X*y2-x2*Y,ad=x1*y2-x2*y1;
            int bn=x1*Y-X*y1,bd=x1*y2-x2*y1;
            if(an%ad!=0||bn%bd!=0){
            } else if(ad==0){
            } else{
                sx=an/ad;sy=bn/bd;sol=1;
            }
        }
        if(sol){
            cout<<abs(sx)+abs(sy)<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
}
