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
#include <cinttypes>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <numeric>
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

struct S {
  int parent, size, rank;
};

typedef std::vector<S> SS;

int
find_root(SS& sets, int x) {
  while (sets[x].parent != x) {
    int prev = x;
    x = sets[x].parent;
    sets[prev].parent = sets[x].parent;
  }
  return x;
}

void
do_union(SS& sets, int x, int y) {
  int xroot = find_root(sets, x);
  int yroot = find_root(sets, y);
  if (xroot == yroot) return;
  if (sets[xroot].rank < sets[yroot].rank) std::swap(xroot, yroot);

  sets[yroot].parent = xroot;
  sets[xroot].size += sets[yroot].size;
  if (sets[xroot].rank == sets[yroot].rank) ++sets[xroot].rank;

}

void
init_s(SS& sets, int x) {
  sets[x] = S{x, 0, 1};
}


uint64_t
calc_sum_binom(std::vector<std::pair<int, uint64_t>> const& tallied) {
  uint64_t sum = 0;
  for (auto p : tallied) {
    assert(p.second >= 1);
    sum += p.second * (p.second - 1) / 2;
  }
  return sum;
}

uint64_t
solve(int n, int k, SS& sets) {

  // Do tally
  std::vector<std::pair<int, uint64_t>> tallied;
  for (int i = 1; i <= n; ++i)
    {
      int root = find_root(sets, i);
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
  DEBUG(fprintf(stderr, "dumping tallied\n"));
  DEBUG(for (auto t : tallied) { fprintf(stderr, "%d %" PRIu64 "\n", t.first, t.second); });

  std::sort(tallied.begin(), tallied.end(), [](auto a, auto b) { return a.second < b.second; });
  // Do merge from largest (XXX)
  for (int i = 0; i < k; ++i) {
    if (tallied.size() == 1) break;
    auto back = tallied.back().second;
    tallied.pop_back();
    tallied.back().second += back;
  }
  assert(std::accumulate(tallied.begin(), tallied.end(), 0, [](auto a, auto b) { return a + b.second; }) == n);
  return calc_sum_binom(tallied);
}
} // namespace

int
main() {
  READVAR(t);
  for (int tt = 0; tt < t; ++tt) {
    SS sets;

    READVAR(n);
    READVAR(l);
    READVAR(k);

    sets.resize(n + 1);
    for (int i = 1; i <= n; ++i) { init_s(sets, i); }
    sets[0] = S{0, 0, 0};

    // Union
    for (int i = 0; i < l; ++i) {
      READVAR(a);
      READVAR(b);
      do_union(sets, a, b);
    }

    printf("%" PRIu64 "\n", solve(n, k, sets));
  }
  exit(0);
}
