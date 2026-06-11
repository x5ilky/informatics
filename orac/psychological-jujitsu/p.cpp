#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int>B(14);
    for(int i=1;i<=13;i++)cin>>B[i];
    vector<array<int,1<<14>>A(13+10);
    for(auto&v:A)v.fill(-1000000);
    A[14][0]=0;
    for(int i=13;i>=1;i--){
        for(int j=0;j<(1<<14);j++){
            for(int k=1;k<=13;k++){
                if(!(j&(1<<(k-1))))continue;
                int v=A[i+1][j&~(1<<(k-1))];
                if(k<B[i])v-=i;
                if(k>B[i])v+=i;
                A[i][j]=max(A[i][j],v);
            }
        }
    }
    cout<<A[1][0b1111111111111]<<endl;
}
