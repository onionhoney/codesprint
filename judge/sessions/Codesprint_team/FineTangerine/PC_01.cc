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
  int test_case_count;
  scanf("%d", &test_case_count);
  for (int zz = 0; zz < test_case_count; ++zz) {
    int road_length, traf_light_count, speed_limit;
    scanf("%d %d %d", &road_length, &traf_light_count, &speed_limit);
    vector<pair<int, int>> lights;
    for (int i = 0; i < traf_light_count; ++i) {
      int loc, period;
      scanf("%d %d", &loc, &period);
      lights.emplace_back(loc, period);
    }
    for (int i = speed_limit; i >= 0; --i) {
      if (all_of(lights.cbegin(), lights.cend(),
                 [i] (pair<int, int> const& light) {
                   return light.first / i % (2 * light.second) < light.second;
                 })) {
        printf("%d\n", i);
        break;
      }
    }
  }
  exit(0);
}
