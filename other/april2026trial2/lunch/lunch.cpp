#include "kitchen.h"

#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
void createAdvice(int N, int B) {
    queue<int>one,two;
    vector<int>take(N+1,false);
    for(int i=1;i<=N;i++){
        int e=nextEvent();
        if(e==0){
            if(two.empty()){
                if(!one.empty()) {
                    take[one.front()]=true;
                    one.pop();
                }
            } else {
                take[two.front()]=true;
                two.pop();
            }
        } else if (e==2) {
            if(one.size()+two.size()>=B){
                if(!one.empty())one.pop();
            }
            if(one.size()+two.size()<B) two.push(i);
        } else if (e==1){
            if(one.size()+two.size()>=B){
                continue;
            }
            one.push(i);
            
        }
    }
    while(!two.empty())take[two.front()]=true,two.pop();
    while(!one.empty())take[one.front()]=true,one.pop();

    take.resize(N+10);
    vector<int>freq(16,0);
    for(int i=1;i<=N;i+=4){
        int num=(take[i]<<3)|(take[i+1]<<2)|(take[i+2]<<1)|(take[i+3]<<0);
        freq[num]++;
    }
    vector<pii>sortfreq{};for(int i=0;i<=15;i++)if(freq[i]!=0)sortfreq.push_back({freq[i],i});
    sort(sortfreq.rbegin(),sortfreq.rend());
    vector<int>code(16,0);
    function<map<int,vector<int>>(vector<pii>)>assign=[&](vector<pii>freq)->map<int,vector<int>>{
        sort(freq.rbegin(),freq.rend());
        map<int,vector<int>>ass;
        if(freq.size()==2){
            ass[freq[0].second]={0};
            ass[freq[1].second]={1};
            return ass;
        }
        if(freq.size()==1){
            ass[freq[0].second]={0};
            return ass;
        }
        int sum=0,psum=0;
        for(auto [f,_]:freq)sum+=f;
        if(sum==0)return {};
        for(int i=0;i<freq.size();i++){
            psum+=freq[i].first;
            if(psum*2>=sum){
                vector<pii>l,r;
                for(int j=0;j<=i;j++)l.push_back(freq[j]);
                for(int j=i+1;j<freq.size();j++)r.push_back(freq[j]);
                map<int,vector<int>>left=assign(l),right=assign(r);
                for(auto [k,v]:left){
                    v.push_back(0);
                    ass[k]=v;
                }
                for(auto [k,v]:right){
                    v.push_back(1);
                    ass[k]=v;
                }
                return ass;
            }
        }
        assert(false);
    };
    auto m=assign(sortfreq);
    // for(int i=0;i<=15;i++){
    //     printf("%d: ",i);
    //     for(int j=m[i].size()-1;j>=0;j--){
    //         printf("%d",m[i][j]);
    //     }
    //     printf("\n");
    // }
    for(int i=0;i<=15;i++)m[i];
    vector<int>bits;
    for(auto [k,v]:m){
        int len=v.empty()?0:ceil(log2(v.size()));
        for(int i=4;i>=0;i--)bits.push_back((len&(1<<i))>>i);
        for(int i=v.size()-1;i>=0;i--)bits.push_back(v[i]);
    }
    for(int i=1;i<=N;i+=4){
        int num=(take[i]<<3)|(take[i+1]<<2)|(take[i+2]<<1)|(take[i+3]<<0);
        for(int i=m[num].size()-1;i>=0;i--){
            bits.push_back(m[num][i]);
        }
    }
    for(auto b:bits){
        printf("%d",b);
        sendNextBit(b);
    }
    printf("\n");
}

void receiveAdvice(int N, int B, int L) {
    map<string,int>M;
    int c=0;
    for(int i=0;i<=15;i++){
        int len=0;string m;
        for(int j=0;j<=4;j++){
            len<<=1;
            len|=getNextBit();c++;
        }
        for(int j=1;j<=len;j++){
            m+=getNextBit()+'0';
            c++;
        }
        M[m]=i;
    }
    vector<int>raw;
    string s;
    while(c<L){
        s+=getNextBit();
        if(M.find(s)!=M.end()){
            raw.push_back(M[s]&(1<<3));
        }
        c++;
    }
    for(int i=1;i<=N;i++){
        int e=nextEvent();
        if(e){
            if(1)acceptDish();
            else discardDish();
        }
    }
}
