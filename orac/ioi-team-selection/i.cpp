#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {
    freopen("teamin.txt","r",stdin);
    freopen("teamout.txt","w",stdout);
    int N,K;cin>>N>>K;

    vector<int>dig={0};
    for(int i=2;i<=N;i++){
        int m=(K-1)%i;
        int b=(m+K-1)%(i-1);
        // printf("m=%d, b=%d\n",m,b);
        vector<int>D;
        D.push_back(0);
        for (auto d:dig){
            int t=(d+b+(i-1))%(i-1);
            if (t>=m)D.push_back((t+1-m+i)%i);
            else D.push_back((t-m+i)%i);
        }
        dig.clear();
        for (int j=max(0,(int)D.size()-4);j<D.size();j++){
            dig.push_back(D[j]);
        }
        if(i==N){
            for (auto e:dig){
                printf("%d ",(e+m)%i+1);
            }
            printf("\n");
        }
    }
}
