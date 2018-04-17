// -*- mode: c++; c-basic-offset: 2; c-file-style: "linux"; flycheck-clang-language-standard: "c++14"; -*-
//#define NDEBUG
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
using namespace std;

int main() {
  int test_cases;
  scanf("%d", &test_cases);
  for (int zz = 0; zz < test_cases; ++zz) {
    int width, height;
    int num_lines;
    scanf("%d %d %d", &width, &height, &num_lines);
    int horiz_count = 0, vert_count = 0;
    for (int i = 0; i < num_lines; ++i) {
      int x1, y1, x2, y2;
      scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
      if (x1 == x2) ++vert_count;
      else if (y1 == y2) ++horiz_count;
    }
    printf("%d\n", (vert_count + 1) * (horiz_count + 1)); // TODO boundaries
  }
  exit(0);
}
