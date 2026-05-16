#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
    int hit=0,miss=0,hom=0;
    long double prev=0;
    for(int i=1;i<=N;i++){
        vector<int>A(5);for(auto&c:A)cin>>c;
        sort(A.begin(),A.end());
        if(i==1){
            hit++;
        }else{
            int h=0,m=0;
            for(auto c:A){
                if(c>prev)h++;
                else m++;
            }
            if(h==5)hit++;
            else if(m==5)miss++;
            else hom++;
        }
        prev=0;
        for(auto c:A)prev+=c;
        prev/=5;
    }
    if(miss>hit&&miss>hom){
        cout<<"miss "<<miss<<endl;
    }
    if(hit>miss&&hit>hom){
        cout<<"hit "<<hit<<endl;
    }
    if(hom>hit&&hom>miss){
        cout<<"hit or miss "<<hom<<endl;
    }
}
