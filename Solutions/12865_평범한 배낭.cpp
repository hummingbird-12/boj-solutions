#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>

#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector < int > weight;
vector < int > value;
vector < vector < int > > dp;

int knapsack(int n, int k) {
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= k; w++) {
            if (weight[i] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight[i]] + value[i]);
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][k];
}

int main() {
    int n, k, w, v;

    scanf("%d%d", &n, &k);
    dp.resize(n + 1);
    for (auto& it : dp) {
        it.resize(k + 1);
    }

    weight.push_back(0);
    value.push_back(0);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &w, &v);
        weight.push_back(w);
        value.push_back(v);
    }

    printf("%d\n", knapsack(n, k));
    return 0;
}
