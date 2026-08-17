#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
    vector<int>A(N+1);for(int i=1;i<=N;i++)cin>>A[i];
    vector<int>best(N+1,-1e9);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(j<i)printf("%6s ",".");
            else {
                int s=0;
                for(int k=1;k<=(j-i+1);k++)s+=A[k+i-1]*k;
                printf("% 6d ",s);
                best[i]=max(best[i],s);
            }
        }
        cout<<endl;
    }
    for(int i=1;i<=N;i++)printf("%6d ",best[i]);
    printf("\n");
}
