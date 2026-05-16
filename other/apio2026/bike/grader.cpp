#include "bike.h"
#include <cassert>
#include <cstdio>

int main() {

  int T;
  assert(scanf("%d", &T) == 1);
  
  std::vector<int> Nt(T);
  std::vector<std::vector<int>> At(T);
  std::vector<std::vector<int>> Bt(T);
  std::vector<std::vector<int>> Ut(T);
  std::vector<std::vector<int>> Vt(T);

  for (int t = 0; t < T; ++t) {
    int N;
    assert(scanf("%d", &N) == 1);
    Nt[t] = N;
    std::vector<int> A(N), B(N), U(N - 1), V(N - 1);
    for (int i = 0; i < N; i++)
      assert(scanf("%d", &A[i]) == 1);
    for (int i = 0; i < N; i++)
      assert(scanf("%d", &B[i]) == 1);
    for (int i = 0; i < N - 1; i++)
      assert(scanf("%d%d", &U[i], &V[i]) == 2);
    At[t] = A;
    Bt[t] = B;
    Ut[t] = U;
    Vt[t] = V;
  }
  fclose(stdin);
  
  std::vector<std::pair<std::vector<int>, std::vector<long long>>> ans(T);
  for (int t = 0; t < T; ++t) {
    auto ret = find_rebalancing_strategy(Nt[t], At[t], Bt[t], Ut[t], Vt[t]);
    ans[t] = ret;
  }
  
  for (int t = 0; t < T; ++t) {
    auto [X, Y] = ans[t];
    int k = int(X.size()) - 1;
    printf("%d\n", k);
    for (int j = 0; j <= k; j++)
      printf("%d%c", X[j], " \n"[j == k]);
    for (int j = 0; j <= k; j++)
      printf("%lld%c", Y[j], " \n"[j == k]);
  }
  fclose(stdout);
  return 0;
}
