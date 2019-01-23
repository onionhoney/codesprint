// -*- mode: c++; c-basic-offset: 2; c-file-style: "linux"; flycheck-clang-language-standard: "c++14"; -*-
#define NDEBUG
#ifdef NDEBUG
#define DEBUG(x) ((void) 0)
#define DUMPVAR(x) ((void) 0)
#pragma GCC optimize("O3")
#else
#include <iostream>
#include <ostream>
#include <type_traits>
#define DEBUG(x)                                                                                                       \
  do { x; } while (0)
#define DUMPVAR(x) DEBUG(std::cerr << #x << " = " << x << std::endl)
#endif
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define READVAR(k)                                                                                                     \
  int k;                                                                                                               \
  scanf("%d", &k);

namespace {
const int MAXN = 1005;
const int MAXK = 1005;

std::vector<int> a;
int p[MAXK][MAXN];

/*
  Let P(j, i) be the maximum possible points for choosing j times in the first i entries of a.
*/

int
P(int j, int i) {
  if (p[j][i] > -1) return p[j][i];


  int answer;
  if (j == 0)
    answer = 0; // Choose 0 times
  else if (i == 0 && j == 1)
    answer = a[0]; // Choose only the 0-th item once
  else if (j > (i & 1 ? (i + 1) / 2 : i / 2 + 1))
    answer = 0; // Choose more than the maximum
  else {
    int max_choose = i == 1 && j == 1 ? a[i] : 0;
    for (int k = 0; k < i - 1; ++k) { max_choose = std::max(max_choose, a[i] + P(j - 1, k)); }

    int max_not_choose = 0;
    for (int k = 0; k < i; ++k) { max_not_choose = std::max(max_not_choose, P(j, k)); }

    DEBUG(fprintf(stderr, "Choose %d times in the range [0,%d] when choosing %d = %d\n", j, i, i, max_choose));
    DEBUG(fprintf(stderr, "Choose %d times in the range [0,%d] when not choosing it = %d\n", j, i, max_not_choose));

    answer = std::max(max_choose, max_not_choose);
  }
  p[j][i] = answer;
  DEBUG(fprintf(stderr, "Choose %d times in the range [0,%d] = %d\n", j, i, p[j][i]));
  return p[j][i];
}

void
solve(int k) {
  DUMPVAR(k);
  int n = a.size();
  DUMPVAR(n);

  // Init
  for (int j = 0; j < n; ++j) { std::fill(p[j], p[j] + n, -1); }

  printf("%d\n", P(k, n - 1));
}
} // namespace

int
main() {
  READVAR(t);
  for (int tt = 0; tt < t; ++tt) {
    READVAR(n);
    READVAR(k);

    a.clear();
    for (int i = 0; i < n; ++i) {
      READVAR(x);
      a.push_back(x);
    }

    solve(k);
  }
  exit(0);
}
