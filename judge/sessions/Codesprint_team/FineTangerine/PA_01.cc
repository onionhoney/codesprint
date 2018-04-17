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
  cin.ignore(10000, '\n');
  for (int zz = 0; zz < test_case_count; ++zz) {
    string nameS;
    getline(cin, nameS);
    uint32_t letters = 0;
    for (auto c : nameS) {
      if (isalpha(c)) {
        c = tolower(c);
        letters |= 1u << (c - 'a');
      }
    }
    if (__builtin_popcount(letters) & 1) {
      puts("TRASH TALK THE USER");
    } else {
      puts("INVITE TO PARTY");
    }
  }
  exit(0);
}
