// -*- mode: c++; c-basic-offset: 2; c-file-style: "linux"; flycheck-clang-language-standard: "c++14"; -*-
#define NDEBUG
#ifdef NDEBUG
#define DEBUG(x) ((void)0)
#define DUMPVAR(x) ((void)0)
#pragma GCC optimize ("O3")
#else
#include <ostream>
#include <type_traits>
#include <iostream>
#define DEBUG(x) do { x; } while (0)
#define DUMPVAR(x) DEBUG(std::cerr << #x << " = " << x << std::endl)
#endif
#include <cstdlib>
#include <cstdio>
#include <utility>
#include <string>
#include <vector>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>

#define READVAR(k) int k; scanf("%d", &k);

namespace {

}

int main() {
  READVAR(t);
  for (int tt = 0; tt < t; ++tt) {
    std::vector<int> as, bs, cs;
    for (int i = 0; i <100; ++i) { READVAR(k); as.push_back(k);}
    for (int i = 0; i <100; ++i) { READVAR(k); bs.push_back(k);}
    for (int i = 0; i <100; ++i) { READVAR(k); cs.push_back(k);}
    printf("%zu %zu %zu\n",
           std::lower_bound(as.begin(), as.end(), 1) - as.begin(),
           std::lower_bound(bs.begin(), bs.end(), 1) - bs.begin(),
           std::lower_bound(cs.begin(), cs.end(), 1) - cs.begin()
      );
  }
  exit(0);
}
