#include "silky/stl.hpp"
using namespace std;
int main() {
    READ(int,N);
    Vec<int>A(N+1);read(A);
    Vec<pii>B(N+1);
    FOR(i,1,N)B[i]={A[i],i};
    B.rsort();
    Vec<pii>pos(N+1);
    Vec<int>cls(N+1);
    if(A.any(LAM(int x,x==0))){
        int prev=1;
        pos[B[N].second]={1,1};
        cls[B[N].second]=B[N].second;
        FOR(i,1,N-1){
            if(B[i].first==0){
                pos[B[i].second]={i+1,1};
                cls[B[i].second]=B[i].second;
            } else {
                prev+=(i%2==1?1:-1)*(B[i].first-1);
                pos[B[i].second]={i+1,prev};
                cls[B[i].second]=B[i==1?N:i-1].second;
            }
        }
    }else{
        bool good=0;
        FOR(i,1,N-1){
            if(B[i].first==B[i+1].first){
                int prev=B[i].first;
                pos[B[i].second]={i,1};
                pos[B[i+1].second]={i+1,B[i].first};
                cls[B[i].second]=B[i+1].second;
                cls[B[i+1].second]=B[i].second;
                int k=0;
                FOR(j,i+2,N){
                    if(B[j].first==0){
                        pos[B[j].second]={j,1};
                        cls[B[j].second]=B[j].second;
                    } else {
                        prev+=(k%2==1?1:-1)*(B[j].first-1);
                        pos[B[j].second]={j,prev};
                        cls[B[j].second]=B[j-1].second;
                    }
                    k++;
                }
                prev=1,k=1;
                ROF(j,i-1,1){
                    prev+=(k++%2==1?1:-1)*(B[j].first-1);
                    pos[B[j].second]={j,prev};
                    cls[B[j].second]=B[j+1].second;
                }
                good=1;
                break;
            }
        }
        if(!good){
            if(N==2)return YES(0);
            B.reverse();
            Vec<int>I(N+1);FOR(i,1,N)I[i]=B[i].second;
            pos[I[1]]={1,N/2};
            FOR(i,2,N){
                pos[I[i]]={i,pos[I[i-1]].second+(i%2==1?1:-1)*(i-2)};
            }
            FOR(i,1,N-1)cls[I[i]]=I[i+1];
            auto [x,y]=pos[I[N]];
            FOR(i,1,N){
                auto [x2,y2]=pos[I[i]];
                if(abs(x-x2)+abs(y-y2)==N){
                    cls[I[N]]=I[i];
                }
            }
        }
    }
    YES(1);
    int mn=INT_MAX;
    FOR(i,1,N)mn=min<int>(mn,pos[i].second);
    FOR(i,1,N)pos[i].second+=1-mn;
    FOR(i,1,N)cout<<pos[i].first<<" "<<pos[i].second<<endl;
    FOR(i,1,N)cout<<cls[i]<<" ";cout<<endl;
}
