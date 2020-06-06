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

int days;
vector < short > duration;
vector < short > reward;

int backtracking(int day = 1, int sum = 0) {
    int ans = sum + (day + duration[day - 1] - 1 <= days ? reward[day - 1] : 0);
    for (int next = day + 1; next <= days; next++) {
        if (next >= day + duration[day - 1]) {
            ans = max(ans, backtracking(next, sum + reward[day - 1]));
        }
        ans = max(ans, backtracking(next, sum));
    }

    return ans;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> days;
    duration.resize(days);
    reward.resize(days);

    for (int i = 0; i < days; i++) {
        cin >> duration[i] >> reward[i];
    }

    cout << backtracking() << '\n';

    return 0;
}
