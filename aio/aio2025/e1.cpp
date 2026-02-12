#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>


int N, D, S;
int m[1000020];
vector<int> takes[1000020];

void take_pair(int a, int b) {
    takes[a].push_back(b);
    takes[b].push_back(a);
}

bool can_take_pair(int a, int b) {
    return takes[b].size() < m[b];
}

bool take_sum(int i) {
    if (S - i > 0)
        if (can_take_pair(i, S-i)) {
            // take it
            take_pair(i, S-i);
            return true;
        }
    return false;
}

bool take_diff(int i) {
    if (can_take_pair(i, i+D)) {
        take_pair(i, i+D);
        return true;
    }
    return false;
}
bool try_erase(int a, int b) {
    auto back = takes[b].back();
    takes[b].pop_back();
    takes[back].erase(
        find(takes[back].begin(), takes[back].end(), b)
    );
    if (can_take_pair(a, a+D)) {
        take_pair(a, a+D);
    }
    takes[a].push_back(b);
    takes[b].push_back(a);
}
 
int main() {
    cin >> N >> D >> S;
    
    int prev = -1, count = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        m[a]++;
    }
    // for (auto& entry : m) {
    //     printf("%d: %d\n", entry.first, entry.second);
    // }
    for (int i = 0; i <= 1000000; i++) {
        if (m[i] <= 0) continue;
        
        while (takes[i].size() < m[i]) {
            // sum
            if (take_sum(i)) continue;
            // difference
            if (take_diff(i)) continue;
            // i cant take sum or difference, lets try sever the connection
            
            for (auto& take : takes[i]) {
                takes[take].erase(
                    find(takes[take].begin(), takes[take].end(), i)
                );
                takes[i].erase(
                    find(takes[i].begin(), takes[i].end(), take)
                );
                if (take_sum(take) || take_diff(take)) break;
                takes[take].push_back(i);
            }

            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");

    return 0;
}