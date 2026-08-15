#include "rail.h"
#include <bits/stdc++.h>
using namespace std;

void findLocation(int N, int first, int L[], int S[])
{
#define printf(...)
    vector<int>dist(N);
    for(int i=1;i<N;i++)dist[i]=getDistance(0,i);
    int x=1;
    for(int i=1;i<N;i++)if(dist[i]<dist[x])x=i;
    L[0]=first;S[0]=1;
    L[x]=first+dist[x];S[x]=2;
    using pii=pair<int,int>;
    vector<pii>D;
    for(int i=1;i<N;i++){
        if(i==x)continue;
        D.push_back({dist[i],i});
    }
    sort(D.begin(),D.end());
    printf("starting %d, r = %d at %d\n",first,x,L[x]);

    int r=x,l=-1;
    priority_queue<pii>pq;
    pq.push({first,0});
    for(auto [_,i]:D){
        int d=getDistance(x,i);
        printf("processing %d. dist %d, %d\n",i,dist[i],d);
        if(dist[i]<d+dist[x]){
            int d2=getDistance(r,i);
            printf("d2 is %d, should be %d\n",d2,first+dist[i]-pq.top().first+L[r]-pq.top().first);
            printf("%d-%d+%d-%d\n",first+dist[i],pq.top().first,L[r],pq.top().first);
            if(d2!=first+dist[i]-pq.top().first+L[r]-pq.top().first){
                L[i]=L[r]-d2;S[i]=1;
                pq.push({L[i],i});
            } else {
                L[i]=dist[i]+first;S[i]=2;r=i;
            }
        } else if(dist[x]+d==dist[i]){
            if(l==-1){
                L[i]=dist[x]-d+first;S[i]=1;l=i;
                pq.push({L[i],i});
            }else{
                int d2=getDistance(l,i);
                if(L[x]-d==L[l]+d2){
                    L[i]=L[l]+d2;S[i]=2;
                }else{
                    L[i]=dist[x]-d+first;S[i]=1;l=i;
                    pq.push({L[i],i});
                }
            }
        } else assert(0);
        printf("answer %d is at %d type %d\n",i,L[i],S[i]);
    }
    for(int i=0;i<N;i++)printf("%2d ",L[i]);printf("\n");
    for(int i=0;i<N;i++)printf("%2d ",S[i]);printf("\n");
#undef printf
}

// begin signature
// +----------------------------------------+
// |覇覇覇陽耗李労洪汎洪汎せ丁火せ火丁ヘミビ|
// |覇陽耗洪允火ビ丁丁丁火せ山允汎汎汎汎火ㇵ|
// |耗洪せ丁ヘ一ミミ火火火火ビ丁ミミ丁ビせビ|
// |允丁ㇵ一丁ㇵミビビ丁シㇵㇸ　・　　一シビ|
// |丁ㇸ一シビ允・ㇸㇵヘ一　ㇸㇵㇵㇵㇸ　・ㇸ|
// |ㇵ　ヘ火・・ㇵ丁せ山せビビ火せせ火丁シㇸ|
// |ㇵㇵ・一ㇸ　シせ洪李和李汎せ汎李李労汎せ|
// |せせ火シㇵㇸ丁汎和陽群群耗労せ火汎山せ火|
// |李和洪せㇵ一火労奏和和労允山せ火ビシ一一|
// |義奏汎丁　丁汎李汎山せ丁シㇵ一ㇸ一ㇵシビ|
// |陽李火一シせ允火火シㇸ　ㇸ・ㇸㇸ・　一ㇵ|
// |和汎丁　ヘ山火ミㇸ　一シ丁火火火丁シ一・|
// |允火ヘㇸㇸ丁丁ㇵ・シ火火せ允労労洪山ビシ|
// |シヘ・ㇵ・ㇸシ・ヘヘ一ㇸ一シ丁山山允洪允|
// |ㇸㇸ　ミ丁ㇵシ　一・ㇵシシㇵ　一ヘヘミビ|
// |ビㇸヘ　シ丁シ　・シ火山允山ビヘ一ㇵㇸ　|
// |せヘビヘ・ミㇵ　ミ山労和和労允火せせビミ|
// |山シ火ビヘㇸ　丁火ビせ山せ允李労李労汎山|
// |山ミ山丁ミ　丁ヘ・ㇵビ汎李奏耗義陽奏耗汎|
// |洪ビ火シㇵㇵシㇸシㇸ火労陽群慶覇慶覇奏汎|
// +----------------------------------------+
// 2026 (August 15th) 18:57:05
// end signature


