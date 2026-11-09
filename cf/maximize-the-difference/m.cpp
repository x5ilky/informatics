#define PRAGMA
#include "silky/stl.hpp"
using namespace std;
int main() {
    int T;cin>>T;
    while(T--){
        int M,Q;cin>>M>>Q;
        using ad=vector<int>;
        int po2=1;
        while(po2<=M)po2<<=1;
        ad A(po2),B(po2);
        int mx=0;
        vector<int>st;
        st.reserve(po2*2);
        function<void(ad&,int)>add=[&](ad&bs,int m){
            st.clear();
            st.push_back(m);
            if(bs[m])return;
            bs[m]=1;
            while(st.size()){
                int m=st.back();st.pop_back();
                if(!m)continue;
                if(A[m]&&B[m]&&m>mx)mx=m;
                for(int b=m;b;b&=b-1){
                    int s=m^(b&-b);
                    if(s<mx)continue;
                    if(!s||bs[s])continue;
                    bs[s]=1;
                    st.push_back(s);
                }
            }
        };
        int prev=0;
        while(Q--){
            int v;cin>>v;
            v+=prev;
            v%=M;
            add(A,v);
            add(B,(~v)&(po2-1));
            prev=mx;
            cout<<prev<<" ";
        }
        cout<<endl;
    }
}
