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

char board[9][9];
bool row[9][10];
bool col[9][10];
bool box[9][10];
vector < pair < int, int > > blanks;

void backtracking(const int index = 0) {
    if (index == blanks.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j];
            }
            cout << '\n';
        }
        exit(0);
        return;
    }

    const int& cur_row = blanks[index].first;
    const int& cur_col = blanks[index].second;
    const int& cur_box = (blanks[index].first / 3) * 3 + (blanks[index].second / 3);
    for (int i = 1; i <= 9; i++) {
        if (!row[cur_row][i] && !col[cur_col][i] && !box[cur_box][i]) {
            row[cur_row][i] = true;
            col[cur_col][i] = true;
            box[cur_box][i] = true;

            board[cur_row][cur_col] = '0' + i;
            backtracking(index + 1);

            row[cur_row][i] = false;
            col[cur_col][i] = false;
            box[cur_box][i] = false;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    char c;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> c;

            board[i][j] = c;
            row[i][c - '0'] = true;
            col[j][c - '0'] = true;
            box[(i / 3) * 3 + (j / 3)][c - '0'] = true;

            if (c == '0') {
                blanks.emplace_back(i, j);
            }
        }
    }

    backtracking();

    return 0;
}
