#include <bits/stdc++.h>
using namespace std;
int main() {
    int T,k;cin>>T>>k;
    while(T--){
        int N;cin>>N;
        string S;cin>>S;
        cout<<"YES\n";
        if(k){
            int b=false;
            string T(N,' ');
            for(int i=N;i>=1;i--){
                int B=S[i-1]=='O';
                T[i-1]="MO"[B^b];
                if(B^b)b^=1;
            }
            cout<<T<<endl;
        }
    }
}
