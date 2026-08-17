#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
    for(int i=1;i<=N;i++)cout<<(i%3==0?"Fizz":to_string(i))<<endl;
}
