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
struct C {
  int x, y, r;
  C(int x, int y, int r) : x(x), y(y), r(r) {}
};

bool visited[10005][10005] = {};

bool
is_point_blocked(int width, int my_radius, std::vector<C> const& circles, int x, int y) {
  if (x <= my_radius) return true;
  if (x >= width - my_radius) return true;
  if (y < 0) return true;
  for (C const& circle : circles) {
    int xd = x - circle.x;
    int yd = y - circle.y;
    int d2 = xd * xd + yd * yd;
    int minimum_distance = my_radius + circle.r;
    int minimum_d2 = minimum_distance * minimum_distance;
    if (d2 < minimum_d2) return true;
  }
  return false;
}

// TODO memoize

bool
dfs(int width, int height, int my_radius, std::vector<C> const& circles, int x, int y) {
  fprintf(stderr, "At (%d, %d)\n", x, y);
  if (is_point_blocked(width, my_radius, circles, x, y)) {  fprintf(stderr, "(%d, %d) blocked\n", x, y); return false;}
  if (visited[x][y]) return false;
  if (y >= height) return true;
  visited[x][y] = true;
  // try four possibilities now
  if (dfs(width, height, my_radius, circles, x, y + 1)) return true;
  if (dfs(width, height, my_radius, circles, x + 1, y)) return true;
  if (dfs(width, height, my_radius, circles, x - 1, y)) return true;
  if (dfs(width, height, my_radius, circles, x, y - 1)) return true;
  visited[x][y] = false;
  return false;
}

bool
solve(int width, int height, int my_radius, std::vector<C> const& circles) {
  // reinit
  memset(visited, 0, sizeof visited);

  for (int i = 0; i <= width; ++i) {
    if (dfs(width, height, my_radius, circles, i, 0)) return true;
  }
  return false;
}

} // namespace

int
main() {
  READVAR(t);
  for (int tt = 0; tt < t; ++tt) {
    READVAR(width);
    READVAR(height);
    READVAR(my_radius);
    READVAR(n);

    std::vector<C> circles;
    for (int i = 0; i < n; ++i) {
      READVAR(x);
      READVAR(y);
      READVAR(r);
      circles.emplace_back(x, y, r);
    }
    if (solve(width, height, my_radius, circles))
      puts("yes");
    else
      puts("no");
  }
  exit(0);
}
