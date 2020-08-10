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

bool cols[14];
bool board[14][14];
int n;

inline bool diag_check(int r, int c) {
    for (int i = r - 1; i >= 0; i--) {
        if (c + i - r >= 0 && board[i][c + i - r]) {
            return false;
        }
        if (c + (r - i) < n && board[i][c + (r - i)]) {
            return false;
        }
    }
    return true;
}

int backtracking(int cur_row) {
    if (cur_row == n) {
        return 1;
    }

    int cnt = 0;
    for (int j = 0; j < n; j++) {
        if (!cols[j] && diag_check(cur_row, j)) {
            cols[j] = true;
            board[cur_row][j] = true;
            cnt += backtracking(cur_row + 1);
            cols[j] = false;
            board[cur_row][j] = false;
        }
    }

    return cnt;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    cout << backtracking(0) << '\n';

    return 0;
}
