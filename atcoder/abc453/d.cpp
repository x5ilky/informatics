#include <bits/stdc++.h>

using namespace std;

int main() {
    int R,C;cin>>R>>C;
    using pii=pair<int,int>;
    queue<pii>q;
    const int INF=1e9+7;
    vector<array<array<int,3>,4>>dist(R*C+1);
    for(auto& c:dist)
        for(auto&d:c)
            for(auto&e:d)
                e=INF;
    vector<char>T(R*C+1);
    int U,V;
    for(int i=0;i<R;i++){
        string S;cin>>S;
        for(int j=0;j<S.size();j++){
            T[i*C+j]=S[j];
            if(S[j]=='S')U=i*C+j;
            if(S[j]=='G')V=i*C+j;
        }
    }
    // dir 0 1 2 3
    //     > v < ^
    dist[U][0]={0,U};
    q.push({U,0});
    while (!q.empty()){
        auto[u,dir]=q.front();
        // printf("at %d,%d dir %d\n",u/C,u%C,dir);
        q.pop();
        vector<pii>adj;
        int d[4]={-1,-1,-1,-1};
        if(u%C>0)d[2]=u-1;
        if(u%C<C-1)d[0]=u+1;
        if(u/C>0)d[3]=u-C;
        if(u/C<R-1)d[1]=u+C;
        for(int i=0;i<=3;i++){
            int v=d[i];
            if(v<0||v>R*C)continue;
            switch(T[u]){
                case '#': break;
                case '.': 
                case 'S':
                case 'G':{
                    adj.push_back({i,v});
                }break;
                case 'o': {
                    if(dir==i)
                        adj.push_back({i,v});
                }break;
                case 'x': {
                    if(dir!=i)
                        adj.push_back({i,v});
                }break;
            }
        }
        for (auto [d,v]:adj){
            if(v<0||v>R*C)continue;
            if(T[v]=='#')continue;
            if(dist[u][dir][0]+1>=dist[v][d][0])continue;
            dist[v][d]={dist[u][dir][0]+1,u,dir};
            q.push({v,d});
            // printf("go %d,%d dir %d\n",v/C,v%C,d);
        }
    }
    for(int i=0;i<4;i++){
        if(dist[V][i][0]<INF) {
            cout<<"Yes"<<endl;
            string s{};
            int v=V;
            while(v!=U) {
                // printf("retrace at %d,%d dir %d\n",v/C,v%C,i);
                if(i==0)s+="R";
                if(i==1)s+="D";
                if(i==2)s+="L";
                if(i==3)s+="U";
                auto o=dist[v][i];
                v=o[1];
                i=o[2];
            }
            reverse(s.begin(),s.end());
            cout<<s<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}

// begin signature
// +----------------------------------------+
// |ビシㇵ一ㇸ一ヘミビせ火火ミヘㇵ一ㇵヘ丁せ|
// |・ヘミ丁丁シㇵ・・一一ㇸ　ㇸヘミシㇵ　ㇵ|
// |山洪允丁ㇸ一ミ丁一ㇸシビせ山せ丁火火ミㇸ|
// |労火一一シヘ允和奏奏耗汎丁ミせ允丁山火ミ|
// |火一ㇵシ和慶・ㇸ・ㇵㇵ　・ㇸミヘミビ允ビ|
// |丁・ヘ山汎ㇵㇵ一ミ　シ一ㇸ　シシ　・ヘ允|
// |ビ・・ㇸビシ一シヘ一火汎ビ丁せビ丁丁　一|
// |ビ・一ビ丁ㇸㇸミㇸシ火せ山允洪せヘ・・ㇸ|
// |ミ一ミ火・丁ㇸミㇸ一　・一ミ山李せㇵ・ミ|
// |　ㇸ火・丁ㇸ丁　ㇵ丁ビ丁ヘ・丁洪允ヘ　火|
// |・ビ・ビシㇵヘㇵ・　　　一・丁洪山ㇵ　允|
// |ㇸ一シ山一ミㇸミビ火火丁シ・丁労せㇸ　シ|
// |　一シ允ヘ一シ一火労和労汎火ヘ丁丁一ㇵ　|
// |一・・せビシ一ミ　丁允洪火シ・・ㇸㇸㇸミ|
// |山ヘ　一山洪丁・シㇵㇸミミ　ヘビせ山せビ|
// |耗一シ　丁汎労せヘ　ㇵㇵ　ヘせ山丁ㇵㇸ一|
// |義ミ・シ・丁允李允ビシㇵㇵせ山ヘ・シ丁ミ|
// |山シヘせミㇵ丁ビㇸ一ㇵㇵ山せ一シ山洪労汎|
// |ミㇸ山労允せミㇸビ允せ山せ・丁洪群慶陽李|
// |・シ洪陽和火　ビ李奏允汎シヘ允群覇覇慶李|
// +----------------------------------------+
// 2026 (April 11th) 22:50:54
// end signature
