#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N;cin>>N;string S;cin>>S;
    vector<int>left,right;
    for(int i=0;i<N;i++){
        if(S[i]=='L')left.push_back(i+1);
        if(S[i]=='R')right.push_back(i+1);
    }
    int L=left.size(),R=right.size();
    vector<int>psleft(L+1),psright(R+1);
    for(int i=1;i<=L;i++)psleft[i]=psleft[i-1]+left[i-1];
    for(int i=1;i<=R;i++)psright[i]=psright[i-1]+right[i-1];
    for(int i=1;i<=N;i++){
        int il=lower_bound(left.begin(),left.end(),i)-left.begin()+1,
            ir=lower_bound(right.begin(),right.end(),i)-right.begin()+1;
        int ans,c=L-il+1;
        if(S[i-1]=='L'){
            if(c>=ir) ans=(psleft[il+ir-1]-psleft[il])*2-psright[ir-1]*2+i;
            else ans=i-(psright[ir-1]-psright[ir-1-c])*2+(psleft[il+c-1]-psleft[il])*2+N+1;
        } else {
            if(c>=ir) ans=(psleft[il+ir-1]-psleft[il-1])*2-psright[ir-1]*2-i;
            else ans=(psleft[il+c-1]-psleft[il-1])*2-(psright[ir-1]-psright[ir-1-c])*2-i+N+1;
        }
        cout<<ans<<endl;
    }
}

// begin signature
// +----------------------------------------+
// |慶群耗李洪允山せビ丁ミ丁ビビ丁丁ビ火せ允|
// |奏李汎山火丁ミシシシミビせ允允山ビヘミビ|
// |汎せビシ一一ヘミ丁ビビ丁丁せ山允せ丁ㇵシ|
// |ビシㇸㇸシビビミミシシヘシミ丁ビ火ミヘ一|
// |シ・ㇸミシㇵ一一一ㇵㇸㇸヘミㇵシ丁せミ一|
// |ㇵ　ㇵㇵ・　　一ヘシミミミシㇵミヘミ火火|
// |ヘ　一ミヘ一ㇵミビせせ山せせせビシミシミ|
// |ヘ　一丁せビビ火山允洪山汎労労汎山ビシ・|
// |ㇵㇸㇵビ汎せ允洪労労洪汎和奏奏和洪山ビㇵ|
// |　・ミ山允労和耗李労洪和陽慶陽奏李汎火ヘ|
// |　ヘ火洪和群義耗汎汎和群慶慶陽群李允ビㇵ|
// |・ミ山労奏慶陽和洪汎李奏群奏群群李允丁一|
// |　ヘ火洪耗陽義奏労汎汎労李労李李労允ビㇵ|
// |・　シせ洪和群義奏李汎せ山山山允允せ丁シ|
// |ミ一　ヘ火允李耗群陽耗洪山ビミ丁丁ミミビ|
// |山丁ㇵ　ヘビ山汎李和耗和李汎山せ火火せ火|
// |汎せミㇵ　ヘ丁せ山汎汎汎允山火せ洪洪允ビ|
// |労允火ミㇵㇸヘミ丁ビビビ丁火允労労允山火|
// |李洪山火丁ミシシシミビせ允洪和労汎労洪せ|
// |奏労汎汎山せせせせ山汎洪和奏和汎和奏洪山|
// +----------------------------------------+
// 2026 (May 8th) 14:03:03
// end signature


