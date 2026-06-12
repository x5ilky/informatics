#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
    vector<queue<int>>C(N);
    map<char,int>M;map<int,char>M2;
    M['2']=2;
    M['3']=3;
    M['4']=4;
    M['5']=5;
    M['6']=6;
    M['7']=7;
    M['8']=8;
    M['9']=9;
    M['T']=10;
    M['J']=11;
    M['Q']=12;
    M['K']=13;
    M['A']=1;
    M2[2]='2';
    M2[3]='3';
    M2[4]='4';
    M2[5]='5';
    M2[6]='6';
    M2[7]='7';
    M2[8]='8';
    M2[9]='9';
    M2[10]='T';
    M2[11]='J';
    M2[12]='Q';
    M2[13]='K';
    M2[1]='A';
    for(int i=1;i<=N;i++){
        for(int j=1;j<=13;j++){
            string S;cin>>S;
            C[i-1].push(M[S[0]]);
        }
    }
    int A;cin>>A;
    set<int>a;for(int i=1;i<=A;i++){
        string S;cin>>S;
        a.insert(M[S[0]]);
    }
    int B;cin>>B;
    set<int>b;for(int i=1;i<=B;i++){
        string BS;cin>>BS;
        b.insert(M[BS[0]]);
    }
    int p=0,d=1;
    using pii=pair<int,int>;
    vector<pii>O;
    while(true){
        int v=C[p].front();
        O.push_back({C[p].front(),p});
        C[p].pop();
        if(C[p].empty()){
            break;
        }
        if(a.find(v)!=a.end()){
            p+=d;
        }
        if(b.find(v)!=b.end()){
            d*=-1;
        }
        p+=d;p+=3*N;p%=N;
    }
    int c=O.size();
    vector<string>S(N);
    for(auto&s:S)s.resize(c,'.');
    for(int i=1;i<=c;i++){
        auto [ch,p]=O[i-1];
        S[p][i-1]=M2[ch];
    }
    for(auto&s:S)cout<<s<<endl;
    cout<<"Player "<<(p+1)<<" wins!"<<endl;
}
