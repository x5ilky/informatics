#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;
 
int main(){
    int T; cin >> T;
    while(T--){
        int N, M; cin >> N >> M;
        vector<int> a(N), b(M);
        for(int i = 0; i < N; i++) cin >> a[i];
        for(int i = 0; i < M; i++) cin >> b[i];
        vector<int> backwards_match(M);
        int j = N - 1;
        for(int i = M - 1; i >= 0; i--){
            while(j >= 0 && a[j] < b[i]) j--;
            backwards_match[i] = j--;
        }
        vector<int> forwards_match(M);
        j = 0;
        for(int i = 0; i < M; i++){
            while(j < N && a[j] < b[i]) j++;
            forwards_match[i] = j++;
        }
        if(forwards_match.back() < N){
            cout << 0 << endl;
            continue;
        }
        int ans = INF;
        for(int i = 0; i < M; i++){
            int match_previous = i == 0 ? -1 : forwards_match[i - 1];
            int match_next = i + 1 == M ? N : backwards_match[i + 1];
            if(match_next > match_previous){
                ans = min(ans, b[i]);
            }
        }
        cout << "ans:" << (ans == INF ? -1 : ans) << "\n";
        printf("Forwards: ");
        for (int i = 0; i < M; i++) {
            printf("%d ", forwards_match[i]);
        }
        printf("\n");
        printf("Backwards: ");
        for (int i = 0; i < M; i++) {
            printf("%d ", backwards_match[i]);
        }
        printf("\n");
    }
}