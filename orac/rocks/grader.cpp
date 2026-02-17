#include "rocks.h"
#include <iostream>
#include <cstdlib>
#include <unordered_set>
using namespace std;
static int N, answer;
static vector<int> r;
static int num_queries;

int use_scales(vector<int> piles) {
  unordered_set<int> ps;
  int weight = 0;
  for (auto a : piles) {
    ps.insert(a);
    if (a < 0 || a >= N) {
      cout << "Invalid pile given to scales\n";
      exit(0);
    }
    weight += r[a];
    weight += a == answer;
  }
  if (ps.size() != piles.size()) {
    cout << "Piles given to the scales are not distinct\n";
    for (auto a : piles) cout << a << " ";
    cout << "\n";
    exit(0);
  }
  num_queries++;
  return weight;
}


int main() {
  cin >> N;
  r.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> r[i];
  }
  cin >> answer;
  if (answer < 0 || answer >= N) {
    cout << "Invalid input (answer is not from 0 to N-1)\n";
    cout << "\n";
    return 0;
  }
  
  int their_ans = find_heavy_rock(N, r);

  cout << "Your answer: " << their_ans << "\n";
  if (their_ans == answer) cout << "Correct!\n";
  else cout << "Incorrect!\n";

  cout << "Used the scales " << num_queries << " times\n";
}
