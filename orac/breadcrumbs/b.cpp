#include <bits/stdc++.h>
using namespace std;
struct bigint{
    static const int base=1000000000;
    vector<int>a; // little-endian

    bigint(long long v=0){*this=v;}

    bigint& operator=(long long v){
        a.clear();
        if(v==0)return *this;
        while(v)a.push_back(v%base),v/=base;
        return *this;
    }

    bool isZero()const{return a.empty();}

    void trim(){
        while(!a.empty()&&a.back()==0)a.pop_back();
    }

    // comparison
    friend bool operator<(const bigint& a,const bigint& b){
        if(a.a.size()!=b.a.size())return a.a.size()<b.a.size();
        for(int i=(int)a.a.size()-1;i>=0;i--)
            if(a.a[i]!=b.a[i])return a.a[i]<b.a[i];
        return false;
    }

    friend bool operator>=(const bigint& a,const bigint& b){
        return !(a<b);
    }

    // addition
    friend bigint operator+(bigint a,const bigint& b){
        int carry=0;
        for(int i=0;i<max(a.a.size(),b.a.size())||carry;i++){
            if(i==(int)a.a.size())a.a.push_back(0);
            a.a[i]+=carry+(i<(int)b.a.size()?b.a[i]:0);
            carry=a.a[i]>=base;
            if(carry)a.a[i]-=base;
        }
        return a;
    }

    // subtraction (assume a >= b)
    friend bigint operator-(bigint a,const bigint& b){
        int carry=0;
        for(int i=0;i<(int)b.a.size()||carry;i++){
            a.a[i]-=carry+(i<(int)b.a.size()?b.a[i]:0);
            carry=a.a[i]<0;
            if(carry)a.a[i]+=base;
        }
        a.trim();
        return a;
    }

    // multiplication
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

    // multiply by int
    friend bigint operator*(bigint a,int m){
        long long carry=0;
        for(int &x:a.a){
            long long cur=1ll*x*m+carry;
            x=cur%base;
            carry=cur/base;
        }
        while(carry)a.a.push_back(carry%base),carry/=base;
        a.trim();
        return a;
    }

    // division by int
    friend bigint operator/(bigint a,int d){
        long long rem=0;
        for(int i=(int)a.a.size()-1;i>=0;i--){
            long long cur=a.a[i]+rem*base;
            a.a[i]=cur/d;
            rem=cur%d;
        }
        a.trim();
        return a;
    }

    // full division (long division)
    friend bigint operator/(const bigint& a,const bigint& b){
        bigint cur,res;
        res.a.assign(a.a.size(),0);

        for(int i=(int)a.a.size()-1;i>=0;i--){
            cur.a.insert(cur.a.begin(),a.a[i]);
            cur.trim();

            int x=0,l=0,r=base-1;
            while(l<=r){
                int m=(l+r)/2;
                if(b*m<=cur)x=m,l=m+1;
                else r=m-1;
            }

            res.a[i]=x;
            cur=cur-b*x;
        }

        res.trim();
        return res;
    }

    // printing
    friend ostream& operator<<(ostream& os,const bigint& v){
        if(v.a.empty())return os<<0;
        os<<v.a.back();
        for(int i=(int)v.a.size()-2;i>=0;i--)
            os<<setw(9)<<setfill('0')<<v.a[i];
        return os;
    }
};
