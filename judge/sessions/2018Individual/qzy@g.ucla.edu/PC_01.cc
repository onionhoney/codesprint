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
#include <array>
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

size_t
calc_sum_binom(std::vector<std::pair<int, size_t>> const& tallied) {
  size_t sum = 0;
  for (auto p : tallied) { sum += p.second * (p.second - 1) / 2; }
  return sum;
}

size_t
solve(int n, int k, std::vector<int>& sets) {
  // Path compression
  for (int i = 1; i <= n; ++i) {
    int parent = sets[i];
    while (parent != sets[parent]) parent = sets[parent];
    sets[i] = parent;
  }

  // Do tally
  std::vector<std::pair<int, size_t>> tallied;
  for (int i = 1; i <= n; ++i) {
    int root = sets[i];
    auto ins = std::lower_bound(tallied.begin(), tallied.end(), std::make_pair(root, 0),
                                [](auto a, auto b) { return a.first < b.first; });
    if (ins == tallied.end()) {
      tallied.emplace_back(root, 1);
    } else if (ins->first == root) {
      ++ins->second;
    } else {
      tallied.emplace(ins, root, 1);
    }
  }

  std::sort(tallied.begin(), tallied.end(), [](auto a, auto b) { return a.second < b.second; });
  // Do merge from largest (XXX)
  for (int i = 0; i < k; ++i) {
    if (tallied.size() == 1) break;
    auto back = tallied.back().second;
    tallied.pop_back();
    tallied.back().second += back;
  }
  return calc_sum_binom(tallied);
}
} // namespace

int
main() {
  READVAR(t);
  for (int tt = 0; tt < t; ++tt) {
    std::vector<int> sets; // parent index

    READVAR(n);
    READVAR(l);
    READVAR(k);

    sets.resize(n + 1);
    for (int i = 1; i <= n; ++i) { sets[i] = i; }

    for (int i = 0; i < l; ++i) {
      READVAR(a);
      READVAR(b);
      if (a > b) std::swap(a, b);
      sets[b] = sets[a];
    }
    printf("%zu\n", solve(n, k, sets));
  }
  exit(0);
}
