#include <bits/stdc++.h>

using namespace std;

/**
 * Task: C. Coloring Game
 * URL: https://codeforces.com/problemset/problem/2112/C
 * 
 * Alice and Bob are playing a game using an integer array $a$ of size n.
 * 
 * Initially, all elements of the array are colorless. First, Alice chooses 3
 *  elements and colors them red. Then Bob chooses any element and colors it blue (if it was red —  recolor it). 
 * Alice wins if the sum of the red elements is strictly greater than the value of the blue element.
 *
 * Your task is to calculate the number of ways that Alice can choose 3
 *  elements in order to win regardless of Bob's actions.
 * 
 * Solution:
 * Bob will win in two situations:
 *  * Maximum of the integer array is bigger than the sum of the chosen 3
 *      or
 *  * Maximum of the chosen 3 is bigger than the other 2
 * 
 * Looping over all three is essentially O(n^3), so loop over y & z
 * Determine the minimum possible number x could be and use lower_bound as binary search 
 *  to find the index of that number
 * All the numbers between that are guarenteed to be answers.
 * O(N^2 log N)
 */

void solve() {
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    long long ans = 0;
    for (int z = 2; z < n; z++) {
        for (int y = 1; y < z; y++) {
            int threshold = max(2 * a[z], a[n-1]) - a[z] - a[y] + 1;
            int min_x = lower_bound(a.begin(), a.begin() + y, threshold) - a.begin();
            ans += y - min_x;
        }
    }
    printf("%lld\n", ans);
}

signed main() {
    int t;
    scanf("%d", &t);

    for (int tt=0; tt<t; tt++) {
        solve();
    }

    return 0;
}