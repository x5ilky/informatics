#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct bigint{
    static const ll BASE=1ull<<60;
    vector<ll>digits;
    bigint(ll num):digits({num}){}
    friend bigint& operator+=(bigint& a,const bigint&b){
        a.digits.resize(max(a.digits.size(),b.digits.size()),0);
        int carry=0;
        for(int i=0;i<a.digits.size();i++){
            a.digits[i]+=b.digits[i]+carry;
            carry=a.digits[i]>=bigint::BASE?(a.digits[i]-=bigint::BASE),1:0;
        }
        if(carry)a.digits.push_back(carry);
        return a;
    }
    friend bigint operator*(const bigint& a,const bigint&b){
        bigint c(0),m=a;
        for(auto d:b.digits)for(ll i=0;i<60;i++,m+=m)if(d&(1ull<<i))c+=m;
        return c;
    }
    friend bigint operator+(const bigint&a,const bigint&b){ bigint c=a;c+=b;return c; }
    friend bigint& operator*=(bigint&a,const bigint&b){a=a*b;return a;}
};
int main(){
    bigint a=6000000000000000;
    bigint b=342342342300032;
    bigint c=a*b;
    for(auto d:c.digits)printf("%lld,",d);
    printf("\n");
}
