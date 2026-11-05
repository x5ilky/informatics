#include "silky/stl.hpp"
using namespace std;
int main() {
    READ(int,T);
    while(T--){
        READ(string,S,T);
        if(S<T){
            write(S);
            continue;
        }
        string S2=S;
        sort(S2.begin(),S2.end());
        int j=0;
        while(j<S2.size()&&S[j]==S2[j])j++;
        int b=j;
        for(int i=j;i<S.size();i++)if(S[i]<=S[b])b=i;
        swap(S[j],S[b]);
        if(S<T)write(S);
        else printf("---\n");
    }
}
