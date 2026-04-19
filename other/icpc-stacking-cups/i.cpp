#include <bits/stdc++.h>
using namespace std;
#define int int64_t
signed main() {
    int N,K;cin>>N>>K;

    if(K<2*N-1||K>N*N){
        cout<<"impossible\n";
        return 0;
    }
    int T=N*N-K;
    auto poss=[&](int K,int N){
        if(N<0||N>K*K)return false;
        if(K==0)return N==0;
        if(K==1)return N==0||N==1;
        return !(N==2||N==K*K-2);
    };
    auto cons=[&](int K,int N)->set<int>{
        if(!poss(K,N))return {-1};
        set<int>order;
        while(K>2){
            int lim=(K-1)*(K-1);
            if(!(N<=lim&&N!=lim-2)){
                order.insert(2*K-1);
                N-=2*K-1;
            }
            K--;
        }
        if(K==2){
            if(N==0){}
            else if(N==1)order.insert(1);
            else if(N==3)order.insert(3);
            else if(N==4)order.insert(1),order.insert(3);
            else return {-1};
        }else if(K==1){
            if(N==0){}
            else if(N==1)order.insert(1);
            else return {-1};
        }
        return order;
    };
    int n=N-1;
    auto large=cons(n,n*n-(K-(2*N-1)));
    auto small=cons(n,n*n-(K-1));
    if(large.find(-1)==large.end()){
        // printf("large\n");
        vector<int>cons;
        vector<int>after;
        for(int i=1;i<=N;i++){
            if(large.find(2*i-1)!=large.end()){
                after.push_back(2*i-1);
            } else {
                cons.push_back(2*i-1);
            }
        }
        while(!after.empty())cons.push_back(after.back()),after.pop_back();
        for(auto e:cons)cout<<e<<" ";
        cout<<endl;
    }else if(small.find(-1)==small.end()){
        vector<int>cons;
        cons.push_back(2*N-1);
        vector<int>after;
        for(int i=1;i<=N-1;i++){
            if(small.find(2*i-1)!=small.end()){
                after.push_back(2*i-1);
            } else {
                cons.push_back(2*i-1);
            }
        }
        while(!after.empty())cons.push_back(after.back()),after.pop_back();
        for(auto e:cons)cout<<e<<" ";
        cout<<endl;
    }else{
        cout<<"impossible\n";
    }
}


// begin signature
// +----------------------------------------+
// |奏耗李洪允山一シミミミシㇵ一ㇸ　ミ丁ビせ|
// |労洪允せヘビせせ火丁シㇵ一・・　　ㇵシ丁|
// |山火ㇵせ允汎せ丁ヘㇸ　　・　・ㇸ　　ㇸヘ|
// |ミ丁汎労允ビシㇸ・ㇵ一一ㇵㇵㇵㇵ一　　一|
// |ミ汎李允火シㇸ　　・ㇸㇸ　　・・　ㇸ　・|
// |ビ労労允ビミミミ丁丁丁ミシヘシミシㇵ　　|
// |丁労李允火火せ山山ビせ山せ火火せせビミㇵ|
// |せ洪和汎せ允洪洪汎山汎洪労洪汎洪洪汎山ビ|
// |せ李李允允労耗耗和洪李耗奏和李耗耗李洪せ|
// |汎耗洪山労奏義陽耗李群義陽耗奏義陽和洪せ|
// |和労山洪耗義慶群李奏義慶群奏義義奏李允丁|
// |和洪山労耗群奏和李群義陽耗耗奏耗李汎火ヘ|
// |耗洪せ允労李李洪洪和耗耗労労労洪汎山丁ㇵ|
// |汎和汎火せ允允山汎和奏奏和労允山せ火ミ一|
// |せ汎李允火丁ビビ允李群奏李汎せビミシヘㇸ|
// |シミ允労允ビヘミせ洪耗耗労山ビシ一・　・|
// |　・ビ汎汎せミシ火汎李李允火シㇸ・ㇵヘヘ|
// |ㇸ・シせ汎山丁シ火允洪汎火ヘ　ㇵミビ火丁|
// |ㇸシㇸ丁せ山ビシ丁せ山火シ　ヘビ山汎允火|
// |ㇸ丁丁ㇸミ丁ビ丁シミミミ一ㇸ丁山労和汎火|
// +----------------------------------------+
// 2026 (April 19th) 14:30:57
// end signature

