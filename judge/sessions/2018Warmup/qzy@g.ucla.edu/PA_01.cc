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

namespace {
std::array<int, 100005> fibs;

int
fib(int i) {
  if (i == 1 || i == 2) return 1;
  if (fibs[i] > -1) {
    return fibs[i];
  } else {
    int a = fib(i - 1);
    int b = fib(i - 2);
    int r = (a + b) % 100000007;
    fibs[i] = r;
    return r;
  }
}
} // namespace

int
main() {
  fibs.fill(-1);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    printf("%d\n", fib(a));
  }
  exit(0);
}
