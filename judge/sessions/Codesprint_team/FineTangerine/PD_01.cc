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

int traverse(vector<vector<int>> const& tree, vector<bool>& visited, vector<int> const& pokestops, int cur_node, int acc) {
  if (binary_search(pokestops.begin(), pokestops.end(), cur_node))
    ++acc;
  int this_acc = acc;
  for (auto const& new_node : tree[cur_node]) {
    if (!visited[new_node]) {
      visited[new_node] = true;
      acc = max(acc, traverse(tree, visited, pokestops, new_node, this_acc));
    }
  }
  return acc;
}

int main() {
  int test_case_count;
  scanf("%d", &test_case_count);
  for (int zz = 0; zz < test_case_count; ++zz) {
    int node_count, pokestop_count, edge_count;
    scanf("%d %d %d", &node_count, &pokestop_count, &edge_count);
    vector<int> pokestops;
    for (int i = 0; i < pokestop_count; ++i) {
      int p;
      scanf("%d", &p);
      pokestops.emplace_back(p);
    }
    sort(pokestops.begin(), pokestops.end());
    vector<vector<int>> tree;
    tree.assign(node_count, {});
    for (int i = 0; i < edge_count; ++i) {
      int from, to;
      scanf("%d %d", &from, &to);
      tree[from].emplace_back(to);
      tree[to].emplace_back(from);
    }
    vector<bool> visited;
    visited.assign(node_count, false);
    visited[0] = true;

    printf("%d\n", traverse(tree, visited, pokestops, 0, 0));
  }
  exit(0);
}
