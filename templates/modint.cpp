#include <bits/stdc++.h>
using namespace std;
using ll=long long;
template<int MOD=1000000007>
struct mint{
    long long v;
    mint(long long x=0):v((x%MOD+MOD)%MOD){}
    mint& operator+=(const mint& o){v=(v+o.v)%MOD;return *this;}
    mint& operator-=(const mint& o){v=(v-o.v)%MOD;return *this;}
    mint& operator*=(const mint& o){v=(v*o.v)%MOD;return *this;}
    mint& operator/=(const mint& o){return *this*=o.inv();}
    mint pow(long long e)const{
        mint r=1,a=*this;
        for(;e;e>>=1,a*=a)if(e&1)r*=a;
        return r;
    }
    mint inv()const{return pow(MOD-2);}
    friend mint operator+(mint a,const mint& b){return a+=b;}
    friend mint operator-(mint a,const mint& b){return a-=b;}
    friend mint operator*(mint a,const mint& b){return a*=b;}
    friend mint operator/(mint a,const mint& b){return a/=b;}
    friend ostream& operator<<(ostream& os,const mint& x){return os<<x.v;}
    friend istream& operator>>(istream& is,mint& x){long long t;is>>t;x=t;return is;}
};
