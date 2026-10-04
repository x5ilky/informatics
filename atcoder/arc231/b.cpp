#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;cin>>T;
    while(T--){
        int A,B,C;cin>>A>>B>>C;
        int D=1024;
        if(A==0&&B==0){
            cout<<"Yes\n";
            cout<<1<<" "<<D<<endl;
            cout<<C<<" ";
            for(int i=0;i<C;i++)cout<<(i^D)<<" ";
            cout<<endl;
        }else if(A==0){
            cout<<"Yes\n";
            cout<<1<<" "<<D<<endl;
            vector<int>c;
            for(int i=0;i<B;i++)c.push_back(i);
            for(int i=0;i<C;i++)c.push_back(i^D);
            cout<<c.size()<<" ";
            for(auto v:c)cout<<v<<" ";cout<<endl;
        }else if(B==0){
            cout<<"Yes\n";
            vector<int>c;
            for(int i=0;i<A;i++)c.push_back(i);
            for(int i=0;i<C;i++)c.push_back(i^D);
            cout<<c.size()<<" ";
            for(auto v:c)cout<<v<<" ";cout<<endl;
            cout<<1<<" "<<D<<endl;
        }else{
            vector<int>a,b;
            {
                auto [X,Y]=minmax(A,B);
                for(int i=0;i<X;i++)a.push_back(i);
                for(int i=0;i<Y;i++)b.push_back(i);
                set<int>t;
                for(int i=0;i<X;i++){
                    for(int j=0;j<Y;j++)t.insert(i^j);
                }
                if(t.find(C)!=t.end()){
                    cout<<"No\n";
                    continue;
                }
                a.push_back(D);
                for(int i=0;i<C;i++)b.push_back(i^D);
            }
            if(A>B)swap(a,b);
            cout<<"Yes\n";
            cout<<a.size()<<" ";
            for(auto v:a)cout<<v<<" ";cout<<endl;
            cout<<b.size()<<" ";
            for(auto v:b)cout<<v<<" ";cout<<endl;
        }
    }
}
