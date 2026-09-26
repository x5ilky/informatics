#include "combo.h"
#include <bits/stdc++.h>
using namespace std;
string T[4]={"A","B","X","Y"};
std::string guess_sequence(int N) {
    string A{};
    int f=0;
    if(press("AB")){
        if(press("A"))f=0;
        else f=1;
    }else{
        if(press("X"))f=2;
        else f=3;
    }
    A+=T[f];

    string B[3]{};
    for(int i=0,j=0;i<4;i++)if(i!=f)B[j++]=T[i];
    for(int i=2;i<=N-1;i++){
        string Q{};
        Q+=A;Q+=B[1];
        for(int j=0;j<3;j++)Q+=A+B[2]+B[j];
        int res=press(Q);
        A+=B[res-(i-1)];
    }
    if(N==1)return A;
    int l=0;
    if(press(A+B[1])==N)l=1;
    if(press(A+B[2])==N)l=2;
    A+=B[l];
    return A;
}
// ABXY
// A
// ABX
