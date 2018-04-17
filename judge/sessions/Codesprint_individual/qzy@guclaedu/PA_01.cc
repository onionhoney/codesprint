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
using namespace std;

int main() {
  int test_case_count;
  scanf("%d", &test_case_count);
  for (int zz = 0; zz < test_case_count; ++zz) {
    int type_count, flower_count;
    scanf("%d %d", &type_count, &flower_count);
    vector<tuple<int, int>> beauty;
    for (int i = 0; i < type_count; ++i) {
      int ni, bi;
      scanf("%d %d", &ni, &bi);
      beauty.emplace_back(bi, ni);
    }
    sort(beauty.begin(), beauty.end());
    int max_beauty = 0;
    for (int i = 0, ie = beauty.size(); i != ie; ++i) {
      int count = min(get<0>(beauty[i]), flower_count);
      max_beauty = max_beauty + get<1>(beauty [i]) * count;
      flower_count -= count;
      if (!flower_count) break;
    }
    printf("%d\n", max_beauty);
  }
  exit(0);
}
