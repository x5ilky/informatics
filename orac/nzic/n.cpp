#pragma GCC optimize("O3")
#pragma GCC optimization("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N,Q;cin>>N>>Q;
    vector<vector<int>>A(N,vector<int>(N));
    // B^3 = N 
    // B = cbrt(N) 
    const int LAZY=INT_MAX;
    const int B=10,BQ=230;int S=(N+B-1)/B;
    vector<vector<int>>lz(S,vector<int>(S));
    vector<vector<array<int,5>>>q((Q+BQ-1)/BQ,vector<array<int,5>>());
    for(int i=0;i<=Q-1;i++){
        int t;cin>>t;
        if(t==1){
            int r,c;cin>>r>>c;q[i/BQ].push_back({t,r,c,0,0});
        }
        if(t==2){
            int r,c,x,v;cin>>r>>c>>x>>v;q[i/BQ].push_back({t,r,c,x,v});
        }
    }
    using ld=long double;
    vector<array<int,5>>C;
    using ll=long long;
    auto incirc=[](int cx,int cy,int r,int x,int y){
        ll dy=cy-y,dx=cx-x;
        // return 2*dx*dx+2*dx+1+2*dy*dy+2*dy<=2ll*r*r;
        return dx*dx+dy*dy<=1ll*r*r;
    };
    for(auto&b:q){
        C.clear();
        for(auto&[t,r,c,x,v]:b){
            if(t==1){
                int br=r/B,bc=c/B;
                int a=lz[br][bc]==LAZY?A[r][c]:lz[br][bc];
                for(auto&[_,r2,c2,rad,v]:C){
                    if(incirc(c2,r2,rad,c,r))a=v;
                }
                cout<<a<<'\n';
            }else if(t==2){
                C.push_back({t,r,c,x,v});
            }
        }
        for(auto&[t,cy,cx,rad,v]:C){
            for(int by=0;by<S;by++){
                for(int bx=0;bx<S;bx++){
                    int clx=min(max(cx,bx*B),bx*B+B-1);
                    int cly=min(max(cy,by*B),by*B+B-1);
                    if(incirc(cx,cy,rad,bx*B,by*B)
                     &&incirc(cx,cy,rad,bx*B+B-1,by*B)
                     &&incirc(cx,cy,rad,bx*B,by*B+B-1)
                     &&incirc(cx,cy,rad,bx*B+B-1,by*B+B-1)){
                        lz[by][bx]=v;
                    }else if(incirc(cx,cy,rad,clx,cly)){
                        for(int r=by*B;r<by*B+B;r++){
                            for(int c=bx*B;c<bx*B+B;c++){
                                if(r>=N||c>=N)continue;
                                if(incirc(cx,cy,rad,c,r))A[r][c]=v;
                                else if(lz[by][bx]!=LAZY)A[r][c]=lz[by][bx];
                            }
                        }
                        lz[by][bx]=LAZY;
                    }
                }
            }
        }
    }
}

// begin signature
// +----------------------------------------+
// |奏和労汎山山せ山火ビ丁丁丁火山汎洪和奏義|
// |汎せビミヘㇵㇵヘㇸ一一一ㇸ一シ丁火允労奏|
// |シㇵㇵㇵ一　　ㇸㇵ一ㇸ・　　　ㇸシ火汎和|
// |ㇵ一ㇸㇸ・ㇸㇸ・　ㇸ・ㇸ一・　・・シせ労|
// |ㇵヘシヘ一・　一・一・　・・ヘㇵ　　シ山|
// |火ミ一　・ㇵ　ㇸヘ　ㇵミビビ丁ビビヘ・シ|
// |ビ一・ㇵㇸ一ㇸㇵㇵ一丁山山洪汎洪労允火一|
// |シ・ㇵ　ヘㇸ・シㇸヘ火洪李允労労允せ火火|
// |・ㇸ　シシ・・シㇸビ汎耗陽李汎耗李山シㇸ|
// |　・丁ㇵ・ㇸシ　ミ汎労労和李汎耗和允シ・|
// |一ミ・ヘヘ一一ヘ山和陽群耗労労群李せㇵㇵ|
// |ミ　ミ火ㇸヘ・シ山李群覇義耗李陽労火ㇸ一|
// |一ㇵ火山ヘㇸヘㇸ丁允李奏群奏耗陽李火一ㇸ|
// |ㇵ・丁汎せヘㇸシ　シせ汎洪洪洪労労允シ・|
// |ヘ・　ミ允山ミ・ㇵ一ㇸシ丁ビビ火火ビビㇸ|
// |ㇸ　ヘ　シせ允ビㇵ　一一　・・ㇸミせ山ヘ|
// |ㇸ　丁ヘ・シ火汎火ミヘ一一ㇵシビ山労山ミ|
// |ㇵㇵせビシ一シビせ山せ火火山汎労耗洪汎山|
// |　ミ允允せビ丁ミ丁ビせ汎李耗群群和奏耗汎|
// |　ミ汎和労洪汎汎洪労和奏義覇陽李義覇奏汎|
// +----------------------------------------+
// 2026 (May 28th) 18:58:18
// end signature



