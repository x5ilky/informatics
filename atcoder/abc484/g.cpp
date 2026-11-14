#include "silky/stl.hpp"
using namespace std;
int main() {
    READ(string,S,X,Y);
    int N=S.size(),A=X.size(),B=Y.size();
    int mx[2]{},my[2]{};
    FOR(i,0,A-1)
        FOR(c,0,1)
            if(X[i]=='?'||X[i]=='0'+c)mx[c]|=1<<i;
    FOR(i,0,B-1)
        FOR(c,0,1)
            if(Y[i]=='?'||Y[i]=='0'+c)my[c]|=1<<i;
    auto id=[&](int a,int b,int u){
        return ((a<<B)+b)*2+u;
    };
}
