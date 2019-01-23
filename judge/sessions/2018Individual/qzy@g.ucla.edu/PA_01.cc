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
#define DEBUG(x)                                                                                                                                               \
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


namespace {
  int solve(int n, std::vector<int>& as, std::vector<int> & bs) {
    std::sort(as.begin(), as.end());
    std::sort(bs.begin(), bs.end());
    if (as.size() > bs.size()) std::swap(as, bs);
    DUMPVAR(as.size());
    DUMPVAR(bs.size());

    int answer = -1;
    for (int a : as) {
      DUMPVAR(a);
      auto bit = std::lower_bound(bs.begin(), bs.end(), n-a);
      if (bit == bs.end()) -- bit;
      if (*bit + a > n) {if (bit != bs.begin()) --bit; else return answer;}
      if (*bit + a > answer) { answer = *bit+a;}
    }
    return answer;
  }
}

int
main() {
  int t;
  scanf("%d", &t);
  for (int tt = 0; tt < t; ++tt) {
    int n;
    scanf("%d", &n);
    int p, q;
    scanf("%d%d", &p, &q);
    std::vector<int> as, bs;
    for (int i = 0; i < p; ++i) {
      int k;
      scanf("%d", &k);
      as.push_back(k);
    }
    for (int i = 0; i < q; ++i) {
      int k;
      scanf("%d", &k);
      bs.push_back(k);
    }
    printf("%d\n", solve(n, as, bs));
  }
  exit(0);
}
