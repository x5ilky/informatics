#include "icc.h"
#include <bits/stdc++.h>
using namespace std;
void run(int N) {
    set<pair<int,int>>E;
    for(int q=1;q<=N-1;q++){
        for(int i=1;i<=N;i++){
            for(int j=i+1;j<=N;j++){
                if(E.find({i,j})!=E.end())continue;
                int a[1]={i},b[1]={j};
                if(query(1,1,a,b)){
                    setRoad(i,j);
                    E.insert({i,j});
                }
            }
        }
    }
}
