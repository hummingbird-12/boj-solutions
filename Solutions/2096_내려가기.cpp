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

int mx_dp[2][3];
int mn_dp[2][3];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int* mx_prev = mx_dp[0];
    int* mx_cur = mx_dp[1];
    int* mn_prev = mn_dp[0];
    int* mn_cur = mn_dp[1];
    int* temp;

    int x, y, z, i;
    cin >> x >> y >> z;
    mx_prev[0] = mn_prev[0] = x;
    mx_prev[1] = mn_prev[1] = y;
    mx_prev[2] = mn_prev[2] = z;

    for (i = 1; i < n; i++) {
        cin >> x >> y >> z;

        int& mx_left = mx_prev[0];
        int& mx_center = mx_prev[1];
        int& mx_right = mx_prev[2];

        int& mn_left = mn_prev[0];
        int& mn_center = mn_prev[1];
        int& mn_right = mn_prev[2];

        mx_cur[0] = max(mx_left, mx_center) + x;
        mx_cur[1] = max(mx_left, max(mx_center, mx_right)) + y;
        mx_cur[2] = max(mx_center, mx_right) + z;

        mn_cur[0] = min(mn_left, mn_center) + x;
        mn_cur[1] = min(mn_left, min(mn_center, mn_right)) + y;
        mn_cur[2] = min(mn_center, mn_right) + z;

        temp = mx_prev;
        mx_prev = mx_cur;
        mx_cur = temp;

        temp = mn_prev;
        mn_prev = mn_cur;
        mn_cur = temp;
    }

    x = 0;
    y = INT_MAX;
    for (z = 0; z < 3; z++) {
        x = max(x, mx_prev[z]);
        y = min(y, mn_prev[z]);
    }
    cout << x << ' ' << y << '\n';

    return 0;
}
