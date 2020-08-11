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

inline int calc_rate(int wins, int games) {
    return ((long long)wins * 100) / games;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int x, y;
    cin >> x >> y;

    int left, right, mid;
    left = 1;
    right = x;

    int init_rate = calc_rate(y, x);

    while (left <= right) {
        mid = (left + right) / 2;

        if (calc_rate(y + mid, x + mid) != init_rate) {
            if (calc_rate(y + mid - 1, x + mid - 1) == init_rate) {
                cout << mid << '\n';
                exit(0);
            }
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    cout << -1 << '\n';

    return 0;
}
