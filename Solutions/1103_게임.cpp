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

const short dx[] = { -1, 0, 1, 0 };
const short dy[] = { 0, 1, 0, -1 };

vector < string > board;
bool visited[50][50];
int mem[50][50];
int n, m;

inline bool in_board(int r, int c) {
    return (r >= 0 && r < n
        && c >= 0 && c < m);
}

int dfs(int row, int col, int moves) {
    if (!in_board(row, col)) {
        return moves;
    }
    if (board[row][col] == 'H') {
        return moves;
    }

    int mx = 0;
    int cur_num = board[row][col] - '0';
    for (int i = 0; i < 4; i++) {
        int new_row = row + dx[i] * cur_num;
        int new_col = col + dy[i] * cur_num;

        if (in_board(new_row, new_col)) {
            if (visited[new_row][new_col]) {
                cout << -1 << '\n';
                exit(0);
            }
            if (mem[new_row][new_col] > moves) {
                continue;
            }
            visited[new_row][new_col] = true;
            mem[row][col] = moves;
        }

        mx = max(mx, dfs(new_row, new_col, moves + 1));

        if (in_board(new_row, new_col)) {
            visited[new_row][new_col] = false;
        }
    }

    return mx;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    board.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    visited[0][0] = true;
    cout << dfs(0, 0, 0) << '\n';

    return 0;
}
