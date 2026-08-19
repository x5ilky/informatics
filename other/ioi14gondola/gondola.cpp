#include "gondola.h"
#include <bits/stdc++.h>
using namespace std;

int valid(int N, int inputSeq[])
{
    vector<int>A(N+1);
    for(int i=1;i<=N;i++)A[i]=inputSeq[i-1];
    auto mit=min_element(A.begin()+1,A.end());
    if(set<int>(A.begin()+1,A.end()).size()!=N)return 0;
    if(*mit>N)return 1;
    if(*mit<=N)rotate(A.begin()+1,A.begin()+((mit-A.begin()-*mit)%N+N)%N+1,A.end());
    for(int i=1;i<=N;i++){
        if(A[i]>N)continue;
        if(A[i]!=i)return false;
    }
    return 1;
}

//----------------------

int replacement(int N, int gondolaSeq[], int replacementSeq[])
{
    vector<int>A(N+1);
    for(int i=1;i<=N;i++)A[i]=gondolaSeq[i-1];

    int c=N+1,cnt=0;
    vector<int>B(N+1);
    iota(B.begin(),B.end(),0);

    auto mit=min_element(A.begin()+1,A.end());
    if(*mit<=N)rotate(A.begin()+1,A.begin()+((mit-A.begin()-*mit)%N+N)%N+1,A.end());
    using pii=pair<int,int>;
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    for(int i=1;i<=N;i++){
        if(A[i]>=c)pq.push({A[i],i});
    }
    while(pq.size()){
        auto [v,i]=pq.top();
        if(v==c)pq.pop();
        replacementSeq[cnt++]=B[i];B[i]=c++;
    }
    return cnt;
}

//----------------------

const int MOD=1e9+9;

int qpow(int _n,int e){
    long long v=1,n=_n;
    while(e){
        if(e&1)v*=n,v%=MOD;
        n*=n,n%=MOD;e>>=1;
    }
    return (int)v;
    
}
int countReplacement(int N, int inputSeq[])
{
    if(!valid(N,inputSeq))return 0;
    vector<int>A(N+1);
    for(int i=1;i<=N;i++)A[i]=inputSeq[i-1];
    int c=N;
    long long cnt=1;
    auto mit=min_element(A.begin()+1,A.end());
    if(*mit>N)cnt*=N;
    if(*mit<=N)rotate(A.begin()+1,A.begin()+((mit-A.begin()-*mit)%N+N)%N+1,A.end());
    using pii=pair<int,int>;
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    for(int i=1;i<=N;i++){
        if(A[i]>c)pq.push({A[i],i});
    }
    while(pq.size()){
        auto [v,i]=pq.top();
        cnt*=qpow(pq.size(),v-c-1);pq.pop();
        cnt%=MOD;c=v;
    }
    return (int)cnt;
}
