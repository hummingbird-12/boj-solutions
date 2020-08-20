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

constexpr int MAX = 1000;

vector < int > dp;
vector < int > numbers;
vector < int > previous;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    dp.resize(n);
    numbers.resize(n);
    previous.resize(n, -1);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];

        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (numbers[j] < numbers[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                previous[i] = j;
            }
        }
    }

    int lis_index = max_element(dp.begin(), dp.end()) - dp.begin();
    cout << dp[lis_index] << '\n';

    stack < int > s;
    while (lis_index != -1) {
        s.push(numbers[lis_index]);
        lis_index = previous[lis_index];
    }

    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    cout << '\n';

    return 0;
}
