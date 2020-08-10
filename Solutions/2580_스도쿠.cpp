#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

short sudoku[9][9];
bool rows[9][10];
bool cols[9][10];
bool box[9][10];
vector < pair < int, int > > blanks;

inline int cur_box(int row, int col) {
    return (row / 3) * 3 + col / 3;
}

void backtracking(int index) {
    if (index == blanks.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << sudoku[i][j] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }

    int& cur_row = blanks[index].first;
    int& cur_col = blanks[index].second;

    for (int i = 1; i <= 9; i++) {
        if (!rows[cur_row][i] &&
            !cols[cur_col][i] &&
            !box[cur_box(cur_row, cur_col)][i]
            ) {
            sudoku[cur_row][cur_col] = i;
            rows[cur_row][i] = true;
            cols[cur_col][i] = true;
            box[cur_box(cur_row, cur_col)][i] = true;

            backtracking(index + 1);

            sudoku[cur_row][cur_col] = 0;
            rows[cur_row][i] = false;
            cols[cur_col][i] = false;
            box[cur_box(cur_row, cur_col)][i] = false;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
            switch (sudoku[i][j]) {
            case 0:
                blanks.emplace_back(i, j);
                break;
            default:
                short& cur = sudoku[i][j];
                rows[i][cur] = true;
                cols[j][cur] = true;
                box[cur_box(i, j)][cur] = true;
                break;
            }
        }
    }

    backtracking(0);

    return 0;
}
