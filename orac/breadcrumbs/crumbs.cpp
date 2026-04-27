#include "crumbs.h"
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct bigint{
    static const uint32_t base = 1u<<30;
    vector<uint32_t>a;

    bigint(long long v=0){*this=v;}

    bigint& operator=(long long v){
        a.clear();
        if(v==0)return *this;
        while(v)a.push_back(v%base),v/=base;
        return *this;
    }

    void trim(){
        while(!a.empty()&&a.back()==0)a.pop_back();
    }

    friend bool operator<(const bigint& a,const bigint& b){
        if(a.a.size()!=b.a.size())return a.a.size()<b.a.size();
        for(int i=(int)a.a.size()-1;i>=0;i--)
            if(a.a[i]!=b.a[i])return a.a[i]<b.a[i];
        return false;
    }

    friend bool operator>(const bigint& a,const bigint& b){return b<a;}
    friend bool operator>=(const bigint& a,const bigint& b){return !(a<b);}
    friend bool operator==(const bigint& a,const bigint& b){return !(a<b)&&!(b<a);}
    friend bool operator<=(const bigint& a,const bigint& b){return a<b||a==b;}

    friend bigint operator+(bigint a,const bigint& b){
        uint32_t carry=0;
        for(int i=0;i<max(a.a.size(),b.a.size())||carry;i++){
            if(i==(int)a.a.size())a.a.push_back(0);
            uint64_t cur=(uint64_t)a.a[i]+carry+(i<(int)b.a.size()?b.a[i]:0);
            a.a[i]=cur%base;
            carry=cur/base;
        }
        return a;
    }

    friend bigint operator-(bigint a,const bigint& b){
        int carry=0;
        for(int i=0;i<(int)b.a.size()||carry;i++){
            long long cur=(long long)a.a[i] - (i<(int)b.a.size()?b.a[i]:0) - carry;
            if(cur<0){cur+=base;carry=1;}
            else carry=0;
            a.a[i]=cur;
        }
        a.trim();
        return a;
    }

    friend bigint operator*(const bigint& a,const bigint& b){
        bigint res;
        res.a.assign(a.a.size()+b.a.size(),0);
        for(int i=0;i<(int)a.a.size();i++){
            long long carry=0;
            for(int j=0;j<(int)b.a.size()||carry;j++){
                long long cur=res.a[i+j]+carry+
                    1ll*a.a[i]*(j<(int)b.a.size()?b.a[j]:0);
                res.a[i+j]=cur%base;
                carry=cur/base;
            }
        }
        res.trim();
        return res;
    }

    friend bigint operator*(bigint a,uint32_t m){
        uint64_t carry=0;
        for(auto &x:a.a){
            uint64_t cur=(uint64_t)x*m+carry;
            x=cur%base;
            carry=cur/base;
        }
        while(carry)a.a.push_back(carry%base),carry/=base;
        a.trim();
        return a;
    }

    friend bigint operator/(bigint a,uint32_t d){
        uint64_t rem=0;
        for(int i=(int)a.a.size()-1;i>=0;i--){
            uint64_t cur=a.a[i]+rem*base;
            a.a[i]=cur/d;
            rem=cur%d;
        }
        a.trim();
        return a;
    }

    friend bigint operator/(const bigint& a,const bigint& b){
        bigint cur,res;
        res.a.assign(a.a.size(),0);

        for(int i=(int)a.a.size()-1;i>=0;i--){
            cur.a.insert(cur.a.begin(),a.a[i]);
            cur.trim();

            uint32_t x=0,l=0,r=base-1;
            while(l<=r){
                uint32_t m=(l+r)>>1;
                if(b*m<=cur)x=m,l=m+1;
                else r=m-1;
            }

            res.a[i]=x;
            cur=cur-b*x;
        }

        res.trim();
        return res;
    }

    friend bigint operator%(const bigint& a,const bigint& b){
        bigint cur;
        for(int i=(int)a.a.size()-1;i>=0;i--){
            cur.a.insert(cur.a.begin(),a.a[i]);
            cur.trim();

            uint32_t x=0,l=0,r=base-1;
            while(l<=r){
                uint32_t m=(l+r)>>1;
                if(b*m<=cur)x=m,l=m+1;
                else r=m-1;
            }
            cur=cur-b*x;
        }
        cur.trim();
        return cur;
    }

    uint32_t l(){
        return a.empty()?0:a[0];
    }
};

vector<vector<int>>g;
void init(int N, int M, std::vector<int> A, std::vector<int> B) {
    g.resize(N+1);
    for(int i=0;i<M;i++){
        g[A[i]].push_back(B[i]);
        g[B[i]].push_back(A[i]);
    }

}
int mod_int(const bigint& a,int m){
    uint64_t res=0;
    for(int i=(int)a.a.size()-1;i>=0;i--)
        res=((res<<30)+a.a[i])%m;
    return res;
}

std::vector<int> encode(std::vector<int> bits) {
    bigint L=0;
    for(auto b:bits){
        L=L+L+b;
    }
    vector<int>path={1};
    int u=1;
    while(!L.a.empty()){
        int deg=g[u].size();
        int dig=mod_int(L,deg);
        L=L/deg;
        u=g[u][dig];
        path.push_back(u);
    }
    return path;
}

std::vector<int> decode(std::vector<int> walk) {
    bigint L=0;
    for(int i=walk.size()-1;i>0;i--){
        int u=walk[i-1];
        int v=walk[i];

        int d=find(g[u].begin(),g[u].end(),v)-g[u].begin();

        L=L*g[u].size();
        L=L+d;
    }
    vector<int>bits;
    for(int i=1;i<=1000;i++){
        bits.push_back(L.l()%2);
        L=L/2;
    }
    reverse(bits.begin(),bits.end());
    return bits;
}
