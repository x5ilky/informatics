#include <algorithm>
#include <bits/stdc++.h>
#include "silky/stl.hpp"
using namespace std;
int main() {
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        Vec<int>A(N+1);read(A);
        int mx=*max_element(A.begin()+1,A.end());
        bool bad=0;
        Vec<int>suf(N+2),pref(N+1);
        {
            Vec<int>st,diff(N+2);
            FOR(i,1,N){
                while(st.size()&&A[st.back()]<A[i])st.pop_back();
                if(st.size()&&A[st.back()]==A[i]){
                    diff[st.back()]++;
                    diff[i+1]--;
                    st.pop_back();
                }
                st.push_back(i);
            }
            int cur=0;
            Vec<int>good(N+1);
            FOR(i,1,N){
                cur+=diff[i];
                good[i]=!!cur;
                if(!cur)bad=1;
            }
            pref[0]=true;
            FOR(i,1,N)pref[i]=pref[i-1]&good[i];
            suf[N+1]=true;
            ROF(i,N,1)suf[i]=suf[i+1]&good[i];
        }
        StableMax st(A);
        int l=0,r=N;
        if(!bad){
            cout<<0<<endl;
            goto skip;
        }
        // FOR(i,1,N){
        //     int mx=st.query_min(1,i);
        //     if(suf[i+1]&&A[1]==mx){
        //         cout<<1<<endl;
        //         cout<<i<<" "<<mx<<endl;
        //         goto skip;
        //     }
        //     if(suf[i+1]&&A[i]==mx){
        //         cout<<1<<endl;
        //         cout<<1<<" "<<mx<<endl;
        //         goto skip;
        //     }
        // }
        // ROF(i,N,1){
        //     int mx=st.query_min(i,N);
        //     if(pref[i-1]&&A[N]==mx){
        //         cout<<1<<endl;
        //         cout<<i<<" "<<mx<<endl;
        //         goto skip;
        //     }
        //     if(pref[i-1]&&A[i]==mx){
        //         cout<<1<<endl;
        //         cout<<N<<" "<<mx<<endl;
        //         goto skip;
        //     }
        // }
        FOR(i,1,N)if(pref[i])l=i;
        ROF(i,N,1)if(suf[i])r=i;
        FOR(i,1,r-1){
            int mx=st.query_min(r,N);
            if(pref[i-1]&&(i+1>=r||st.query_min(i+1,r-1)<=mx)){
                cout<<1<<endl;
                cout<<i<<" "<<mx<<endl;
                goto skip;
            }
        }
        ROF(i,N,max(l+1,2)){
            int mx=st.query_min(1,max(l,1));
            if(suf[i+1]&&(i-1<=l||st.query_min(max(l+1,2),i-1)<=mx)){
                cout<<1<<endl;
                cout<<i<<" "<<mx<<endl;
                goto skip;
            }
        }


        cout<<2<<endl;
        cout<<1<<" "<<(int)1e9<<endl;
        cout<<N<<" "<<(int)1e9<<endl;
skip:;
    }
}
