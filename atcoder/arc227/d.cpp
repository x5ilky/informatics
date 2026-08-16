#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,M,Q;cin>>N>>M>>Q;
    vector<string>S(N+1);
    for(int i=1;i<=N;i++)cin>>S[i];
    struct node {
        node *c[3];
        int cnt;
    };

    node root={nullptr,nullptr,nullptr};
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i==j)continue;
            vector<int>B(M);
            for(int k=1;k<=M;k++){
                if(S[i][k-1]==S[j][k-1])B[k-1]=S[j][k-1]-'0';
                else B[k-1]=2;
            }
            node*u=&root;
            for(int k=0;k<M;k++){
                if(u->c[B[k]]==nullptr){
                    u->c[B[k]]=new node{nullptr,nullptr,nullptr};
                }
                u=u->c[B[k]];
            }
        }
    }

    while(Q--){
        string T;cin>>T;
        for(int i=1;i<=N;i++)
            if(S[i]==T){
                cout<<"Yes\n";
                goto skip;
            }
        for(int i=1;i<=N;i++){
            vector<int>B(M);
            for(int k=1;k<=M;k++){
                if(S[i][k-1]==T[k-1])B[k-1]=2;
                else B[k-1]=T[k-1]-'0';
            }
            function<bool(node*,int)>dfs=[&](node*u,int d){
                if(d==M)return true;
                if(B[d]==2){
                    int a=u->c[T[d]-'0']==nullptr?false:dfs(u->c[T[d]-'0'],d+1);
                    int b=u->c[2]==nullptr?false:dfs(u->c[2],d+1);
                    return a||b;
                }
                if(u->c[B[d]]==nullptr)return false;
                return dfs(u->c[B[d]],d+1);
            };
            if(dfs(&root,0)){
                cout<<"Yes"<<endl;
                goto skip;
            }
        }
        cout<<"No"<<endl;
skip:;
    }
}

// begin signature
// +----------------------------------------+
// |奏和労汎允山山せ火丁丁丁丁ビせ允労和群義|
// |洪山火丁ミシシヘㇸ・　　ㇸㇵシビ山汎和群|
// |丁ヘㇸ　　・・ㇵㇸㇸ　ㇸ一一ㇸヘ丁山労耗|
// |　一ヘミ丁丁ヘ・・ㇵㇵㇵヘミ丁シヘ火汎和|
// |シビせ山ミㇸ・一　一・　・・ヘビビシせ洪|
// |ビ允洪火ヘ　一ㇸヘ　ㇵミ丁シミ丁丁山丁火|
// |せ洪允ビㇵ・ㇸㇵ一ㇸミせ允火シ火汎允せ火|
// |山労山ミ・ㇵ・ヘ・ㇵビ汎労汎山丁ビビ火せ|
// |洪汎丁一一ヘ・ヘ・丁火火せビシㇵㇸㇸ一ヘ|
// |汎ビ一一シ・シ　シヘㇵヘシ・ㇸㇵヘヘ一　|
// |ビㇸ・ミㇵ一一・ㇸ一一・一ミ火せせ火ミㇵ|
// |ㇵㇸヘビㇸヘㇸシビ火ビシビ允労李労汎せシ|
// |一一ビシㇵㇸミせ汎労汎せ允李奏群奏耗洪火|
// |シ・シ　シ　ミ山李奏奏李允和和労洪汎汎汎|
// |火一　ㇸヘ一ㇵ火労群覇群労労労允火ビ丁ビ|
// |火ミ　　　シ　ミ允和群群李允允ビシ一ㇸㇸ|
// |シ丁ㇸヘ・ㇵ・ヘ火汎労労允せビㇵ　ㇵヘヘ|
// |ㇵ丁・ヘヘㇸㇸ一丁火せ火ミ丁ㇸㇵ丁せ山火|
// |　ㇵ　ヘ火丁ㇵ　一ヘㇵㇸ一・シせ洪李労山|
// |ㇵ・・ㇸミせ丁ヘ一ㇸ一ヘ　一火洪奏陽和山|
// +----------------------------------------+
// 2026 (August 16th) 23:27:45
// end signature
