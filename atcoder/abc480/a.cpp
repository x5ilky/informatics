#include <bits/stdc++.h>
using namespace std;
int main() {
    string A[2]{};cin>>A[0]>>A[1];
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            if(A[i][j]=='A'){
                if(A[i^1][j]=='D'||A[i][j^1]=='D')
                    return cout<<"Yes\n",0;
            }
    cout<<"No\n",0;
}
