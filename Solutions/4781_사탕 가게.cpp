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

constexpr int MAX = 10001;

int dp[MAX];
int calorie[5000];
int price[5000];

int parseFloat(string s) {
    int i = 0;
    for (char c : s) {
        if (isdigit(c)) {
            i = i * 10 + (c - '0');
        }
    }
    return i;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, money;
    string m, p;

    cin >> n >> m;
    money = parseFloat(m);

    while (n != 0 || money != 0) {
        memset(dp, 0, sizeof dp);

        for (int i = 0; i < n; i++) {
            cin >> calorie[i] >> p;
            price[i] = parseFloat(p);
        }

        for (int i = 1; i <= money; i++) {
            for (int j = 0; j < n; j++) {
                if (price[j] <= i) {
                    dp[i] = max(dp[i], dp[i - price[j]] + calorie[j]);
                }
            }
        }

        cout << dp[money] << '\n';

        cin >> n >> m;
        money = parseFloat(m);
    }

    return 0;
}
