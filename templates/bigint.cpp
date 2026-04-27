#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct bigint{
    static const ll BASE=1ull<<60;
    vector<ll>digits;
    bigint(ll num):digits({num}){}
    int dig(int i)const{
        return i<digits.size()?digits[i]:0;
    }
    friend bigint operator+(const bigint& a,const bigint&b){
        bigint c=0;int carry=0;c.digits.resize(max(a.digits.size(),b.digits.size())+1,0);
        for(int i=0;i<c.digits.size();i++){
            c.digits[i]=a.dig(i)+b.dig(i)+carry;
            carry=c.digits[i]>=bigint::BASE?(c.digits[i]-=bigint::BASE),1:0;
        }
        return a;
    }
    friend bigint operator-(const bigint& a,const bigint&b){
        bigint c=0;int borrow=0;c.digits.resize(max(a.digits.size(),b.digits.size())+1,0);
        for(int i=0;i<c.digits.size();i++){
            c.digits[i]=a.dig(i)-b.dig(i)-borrow;
            borrow=c.digits[i]<0?(c.digits[i]+=bigint::BASE),1:0;
        }
        return a;
    }
    friend bigint operator*(const bigint& a,const bigint&b){
        bigint c(0),m=a;
        for(auto d:b.digits)for(ll i=0;i<60;i++,m+=m)if(d&(1ull<<i))c+=m;
        return c;
    }
    friend bigint& operator+=(bigint&a,const bigint&b){a=a+b;return a;}
    friend bigint& operator-=(bigint&a,const bigint&b){a=a-b;return a;}
    friend bigint& operator*=(bigint&a,const bigint&b){a=a*b;return a;}
};
int main(){
    bigint a=6000000000000000;
    bigint b=342342342300032;
    bigint c=a*b;
    for(auto d:c.digits)printf("%lld,",d);
    printf("\n");
}
