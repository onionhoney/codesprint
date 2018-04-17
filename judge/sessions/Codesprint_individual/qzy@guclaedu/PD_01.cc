// -*- mode: c++; c-basic-offset: 2; c-file-style: "linux"; flycheck-clang-language-standard: "c++14"; -*-
//#define NDEBUG
#ifdef NDEBUG
#define DEBUG(x) ((void)0)
#pragma GCC optimize ("O3")
#else
#include <ostream>
#include <type_traits>
#include <iostream>
#define DEBUG(x) do { x; } while (0)
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
  vector<int> all_counts{1, 1, 2};
  for (int zz = 0; zz < test_case_count; ++zz) {
    int answer = 1;
    int section_count;
    scanf("%d", &section_count);
    for (int s = 0; s < section_count; ++s) {
      int stair_count;
      scanf("%d", &stair_count);
      if (stair_count > (int) all_counts.size() - 1) {
        for (int i = all_counts.size(); i <= stair_count; ++i) {
          all_counts.push_back((all_counts[i - 1] +
                                all_counts[i - 2] +
                                all_counts[i - 3]
                                 ) % 10007);
        }
      }

      assert(stair_count <= (int) all_counts.size() + 1);
      answer *= all_counts[stair_count];
      answer %= 10007;
    }
    printf("%d\n", answer);
  }
  exit(0);
}
