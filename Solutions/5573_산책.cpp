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

/*
 * dp[i][j][0] : number of steps gone downwards from (i, j) in the n-th iteration
 * dp[i][j][1] : number of steps gone rightwards from (i, j) in the n-th iteration
 */
int dp[1000][1000][2];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int cur_row = 0, cur_col = 0; // Keeps track of n-th iteration's path
    int h, w, n, direction;
    cin >> h >> w >> n;

    // Process (0, 0)
    cin >> direction;
    if (direction == 0) { // If n is odd, go downwards
        dp[0][0][0] = n / 2 + (n % 2 == 1 ? 1 : 0);
        dp[0][0][1] = n / 2;
        (n % 2 == 0 ? cur_col : cur_row)++;
    }
    else { // If n is odd, go rightwards
        dp[0][0][1] = n / 2 + (n % 2 == 1 ? 1 : 0);
        dp[0][0][0] = n / 2;
        (n % 2 == 1 ? cur_col : cur_row)++;
    }

    // Process (0, 1~(w-1))
    for (int j = 1; j < w; j++) {
        const int& from_left = dp[0][j - 1][1];
        cin >> direction;

        if (direction == 0) { // If from_left is odd, go downwards
            dp[0][j][0] = from_left / 2 + (from_left % 2 == 1 ? 1 : 0);
            dp[0][j][1] = from_left / 2;
            if (cur_row == 0 && cur_col == j) {
                (from_left % 2 == 0 ? cur_col : cur_row)++;
            }
        }
        else { // If from_left is odd, go rightwards
            dp[0][j][1] = from_left / 2 + (from_left % 2 == 1 ? 1 : 0);
            dp[0][j][0] = from_left / 2;
            if (cur_row == 0 && cur_col == j) {
                (from_left % 2 == 1 ? cur_col : cur_row)++;
            }
        }
    }

    // Process (1~(h - 1), 0~(w-1))
    for (int i = 1; i < h; i++) {
        const int& from_up = dp[i - 1][0][0];
        cin >> direction;

        if (direction == 0) { // If from_up is odd, go downwards
            dp[i][0][0] = from_up / 2 + (from_up % 2 == 1 ? 1 : 0);
            dp[i][0][1] = from_up / 2;
            if (cur_row == i && cur_col == 0) {
                (from_up % 2 == 0 ? cur_col : cur_row)++;
            }
        }
        else { // If from_up is odd, go rightwards
            dp[i][0][1] = from_up / 2 + (from_up % 2 == 1 ? 1 : 0);
            dp[i][0][0] = from_up / 2;
            if (cur_row == i && cur_col == 0) {
                (from_up % 2 == 1 ? cur_col : cur_row)++;
            }
        }
        for (int j = 1; j < w; j++) {
            const int& from_up = dp[i - 1][j][0];
            const int& from_left = dp[i][j - 1][1];
            const int sum = from_up + from_left;
            cin >> direction;

            if (direction == 0) { // If sum is odd, go downwards
                dp[i][j][0] = sum / 2 + (sum % 2 == 1 ? 1 : 0);
                dp[i][j][1] = sum / 2;
                if (cur_row == i && cur_col == j) {
                    (sum % 2 == 0 ? cur_col : cur_row)++;
                }
            }
            else { // If sum is odd, go rightwards
                dp[i][j][1] = sum / 2 + (sum % 2 == 1 ? 1 : 0);
                dp[i][j][0] = sum / 2;
                if (cur_row == i && cur_col == j) {
                    (sum % 2 == 1 ? cur_col : cur_row)++;
                }
            }
        }
    }

    cout << cur_row + 1 << ' ' << cur_col + 1 << '\n';

    return 0;
}
