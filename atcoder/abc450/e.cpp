#include <bits/stdc++.h>

using namespace std;
using ll=long long;
#define int ll
using i128=__int128;

signed main() {
    string X,Y;cin>>X>>Y;

    vector<vector<int>>pxc(26),pyc(26);
    for(int c=0;c<=25;c++){
        vector<int>xc(X.size()+1,0),yc(Y.size()+1,0);
        for(int i=1;i<=X.size();i++)
            xc[i]=xc[i-1]+(X[i-1]==('a'+c));
        for(int i=1;i<=Y.size();i++)
            yc[i]=yc[i-1]+(Y[i-1]==('a'+c));
        pxc[c]=xc;
        pyc[c]=yc;
    }
    auto len=[&](int s){
        i128 a=X.size(),b=Y.size(),c=a+b;
        for (int i=1;i<=s-1;i++){
            a=b;
            b=c;
            c=a+b;
        }
        return a;
    };
    auto bc=[&](int C,int s){
        i128 a=pxc[C][X.size()],b=pyc[C][Y.size()],c=a+b;
        for (int i=1;i<=s-1;i++){
            a=b;
            b=c;
            c=a+b;
        }
        return a;
    };
    function<i128(int,int,int)> f=[&](int c,int s,int p){
        //printf("f(%lld,%lld,%lld)\n",c,s,p);
        if(p<=0)return (i128)0;
        if(s==1)return (i128)pxc[c][p];
        if(s==2)return (i128)pyc[c][p];
        i128 la=len(s-1);
        if(p<=la){
            return f(c,s-1,p);
        } else {
            return bc(c,s-1)+f(c,s-2,p-la);
        }
    };

    int Q;cin>>Q;
    for(int q=1;q<=Q;q++){
        ll l,r;string c;cin>>l>>r>>c;
        cout<<(ll)(f(c[0]-'a',88,r)-f(c[0]-'a',88,l-1))<<endl;
    }
}
