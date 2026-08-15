#include <bits/stdc++.h>
using namespace std;
int main() {
    int Q;cin>>Q;
    using uint=uint64_t;
    while(Q--){
        uint A,B;cin>>A>>B;
        if(B==1){
            cout<<0<<endl;
            continue;
        }
        if(!(A&1)){
            uint o=A;
            bool bad=true;
            for(int k=1;k<=64;k++){
                if(o==B){
                    cout<<k<<endl;
                    bad=false;
                    break;
                }
                o*=A;
            }
            if(bad)cout<<"broken message"<<endl;
            continue;
        }
        if(!(B&1)){
            cout<<"broken message"<<endl;continue;
        }
        uint ord=1,aord=A,x=0,ax=1;
        auto eq=[](uint a,uint b,uint m){
            return ((a-b)<<(64-m))==0;
        };
        bool good=true;
        for(int k=2;k<=64;k++){
            bool d=!eq(aord,1,k);
            if(!eq(ax,B,k)){
                if(!d){
                    good=false;break;
                }
                x+=ord;
                ax*=aord;
            }
            if(d){
                ord*=2;
                aord*=aord;
            }
        }
        if(good)cout<<x<<endl;
        else cout<<"broken message"<<endl;
    }
}

// begin signature
// +----------------------------------------+
// |群耗李洪允山せ火ビㇸ一ㇸ　丁ビ火ビ丁丁ミ|
// |和洪允せビ　ヘビせ山せビシㇵ・シㇵ一ㇸㇸ|
// |允火丁ㇸミ火允洪・ㇸㇸㇸミヘㇸ　・　・・|
// |ビヘヘ丁ㇸ　ヘ丁火火丁シㇸ　一・　　　　|
// |ヘヘミ　丁允労和耗耗李汎火ミㇸ　ㇸㇸヘヘ|
// |・ヘ　火労耗耗李李労労労汎山丁ヘミミミ火|
// |　ㇵヘ汎耗和労汎允丁火せせビミ丁火せ山せ|
// |　　ビ李和労允ㇵミせ允洪洪汎山せ山山労労|
// |・ヘ洪李洪　・ミ火允労和耗李洪汎労労洪汎|
// |ヘ洪汎允　シビ允洪李奏義陽耗洪和奏耗李允|
// |汎せ　シ允李耗奏耗奏義慶群李耗陽義耗労山|
// |ビㇸせ李奏和李労労奏群群和労奏耗耗李允ビ|
// |シせ和奏李洪允山汎李和李洪汎李労洪洪山丁|
// |ㇵ汎奏和洪允火丁火山汎汎允せ山山せせせミ|
// |ㇵ允奏和洪せ丁ヘㇵミビ火ビ丁ミビ丁シシシ|
// |一汎奏李汎火シ一　・一ヘヘㇵㇸㇵㇵㇸ　・|
// |ミ李耗洪山丁一・ㇵ一・　　・一・・一ヘㇵ|
// |洪奏労山丁一・　　ㇸ一一一ㇸ　一ミビビ丁|
// |奏李允ビㇵ・一・・一ㇸㇸ・　ㇵビ山汎山火|
// |耗労山ミㇸ一ヘㇵ一ㇸㇸ一ㇵシ丁山労李汎火|
// +----------------------------------------+
// 2026 (August 9th) 16:32:35
// end signature
