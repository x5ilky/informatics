#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;cin>>S;
    vector<bool>prime(1e7+1,true);
    prime[0]=prime[1]=false;
    for (int i = 2; i <= 1e7; i++) {
        if (prime[i] && (long long)i * i <= 1e7) {
            for (int j = i * i; j <= 1e7; j += i)
                prime[j] = false;
        }
    }
    for(int i=2;i<=1e7;i++){
        if(!prime[i])continue;
        string T=to_string(i);
        if(T.size()!=S.size())continue;
        vector<int>map(256,-1),rmap(256,-1);
        for(int i=0;i<S.size();i++){
            if(map[S[i]]==-1){
                if(rmap[T[i]]==-1)map[S[i]]=T[i],rmap[T[i]]=S[i];
                else goto skip;
            }else if(map[S[i]]!=T[i])goto skip;
        }
        return cout<<T<<endl,0;
skip:;
    }
    cout<<-1<<endl;
}
