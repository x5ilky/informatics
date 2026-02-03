#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e7+10;
int HEAD[MAX_N + 30];
int idx[26], value[MAX_N+30], out[MAX_N];
int head(int node) {
    if (HEAD[node] == node) return node;
    return HEAD[node] = head(HEAD[node]);
}
void join(int a, int b) {
    if (head(a) != head(b))
        HEAD[head(a)] = head(b);
}

int c = 26;
int main() {
    int N; cin >> N;
    for (int i = 0; i < 26; i++) {
        idx[i] = i;
        HEAD[i] = i;
        value[i] = i;
    }
    int am = 0;
    for (int i = 0; i < N; i++) {
        int ins; cin >> ins;
        if (ins == 1) {
            string color; cin >> color;
            out[am++] = idx[color[0]-'a']; 
        } else if (ins == 2) {
            string a, b; cin >> a >> b;
            if (a[0] == b[0]) continue;
            int A = a[0]-'a', B = b[0]-'a';
            join(idx[A], idx[B]);

            value[c] = A;
            HEAD[c] = c;
            idx[A] = c++;
        }
    }
    for (int i = 0; i < am; i++) {
        printf("%c", value[head(out[i])]+'a');
    }
    printf("\n");
}
