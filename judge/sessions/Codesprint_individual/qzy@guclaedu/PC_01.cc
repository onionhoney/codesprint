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

void find_route(string& map, int rows, int cols, int cur_row, int cur_col, string& answer) {
  if (cur_row != 0) {
    int new_row = cur_row - 1, new_col = cur_col;
    if (map[new_row * cols + new_col] == '#') {
      answer += 'U';
      map[cur_row * cols + cur_col] = '.';
      find_route(map, rows, cols, new_row, new_col, answer);
    }
  }
  if (cur_col != 0) {
    int new_row = cur_row, new_col = cur_col - 1;
    if (map[new_row * cols + new_col] == '#') {
      map[cur_row * cols + cur_col] = '.';
      answer += 'L';
      find_route(map, rows, cols, new_row, new_col, answer);
    }
  }
  if (cur_row != rows - 1) {
    int new_row = cur_row + 1, new_col = cur_col;
    if (map[new_row * cols + new_col] == '#') {
      map[cur_row * cols + cur_col] = '.';
      answer += 'D';
      find_route(map, rows, cols, new_row, new_col, answer);
    }
  }
  if (cur_col != cols - 1) {
    int new_row = cur_row, new_col = cur_col + 1;
    if (map[new_row * cols + new_col] == '#') {
      map[cur_row * cols + cur_col] = '.';
      answer += 'R';
      find_route(map, rows, cols, new_row, new_col, answer);
    }
  }
}

int main() {
  int test_cases_count;
  scanf("%d", &test_cases_count);
  for (int zz = 0; zz < test_cases_count; ++zz) {
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    int start_row, start_col;
    scanf("%d %d", &start_row, &start_col);
    cin.ignore(100000, '\n');
    --start_col, --start_row;
    string map;
    for (int i = 0; i < rows; ++i) {
      string this_row_map;
      getline(cin, this_row_map);
      assert(this_row_map.size() == (size_t) cols);
      map += this_row_map;
    }
    assert(map[start_row * cols + start_col] == 'S');
    string answer;
    find_route(map, rows, cols, start_row, start_col, answer);
    puts(answer.c_str());
  }
  exit(0);
}
