#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
#define v vector
    v A(11,v(11,v(11,v(11,v(11,v<int>(11))))));
    v P(11,v(11,v(11,v(11,v(11,v<int>(11))))));
#undef v
    for(int i=1;i<=N;i++){
        string S;cin>>S;int a;cin>>a;
        A[S[0]-'0'+1][S[1]-'0'+1][S[2]-'0'+1][S[3]-'0'+1][S[4]-'0'+1][S[5]-'0'+1]=a;
    }
    for(int a=1;a<=10;a++){
        for(int b=1;b<=10;b++){
            for(int c=1;c<=10;c++){
                for(int d=1;d<=10;d++){
                    for(int e=1;e<=10;e++){
                        for(int f=1;f<=10;f++){
                            P[a][b][c][d][e][f]=
                                P[a-1][b-0][c-0][d-0][e-0][f-0]+
                                P[a-0][b-1][c-0][d-0][e-0][f-0]+
                                P[a-0][b-0][c-1][d-0][e-0][f-0]+
                                P[a-0][b-0][c-0][d-1][e-0][f-0]+
                                P[a-0][b-0][c-0][d-0][e-1][f-0]+
                                P[a-0][b-0][c-0][d-0][e-0][f-1]+
                                A[a][b][c][d][e][f];
                        }
                    }
                }
            }
        }
    }
    auto qr=[&](array<int,6>a){
        return P[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]];
    };
    int Q;cin>>Q;
    for(int q=1;q<=Q;q++){
        string A,B;cin>>A>>B;
        int s=0;
        for(int k=0;k<(1<<7);k++){
            array<int,6>a;
            for(int j=0;j<6;j++){
                if(k&(1<<j))a[j]=B[j]-'0'+1;
                else a[j]=A[j]-'0'+1;
            }
            int sgn=-(popcount(unsigned(k))%2);
            s+=sgn*qr(a);
        }
        cout<<s<<endl;
    }
}
