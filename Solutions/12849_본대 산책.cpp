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

constexpr int VERT = 8;
constexpr int EDGES = 12;
constexpr int MAX_D = 100'001;
constexpr int MOD = 1'000'000'007;

const int edges[EDGES][2] = {
    1, 2,
    1, 8,
    2, 8,
    2, 3,
    3, 8,
    3, 7,
    3, 4,
    7, 8,
    4, 7,
    4, 5,
    5, 6,
    6, 7
};

vector < vector < int > > graph;
int dp[MAX_D][VERT + 1];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    graph.resize(VERT + 1);
    for (int i = 0; i < EDGES; i++) {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    int d;
    cin >> d;

    dp[0][1] = 1;
    for (int i = 1; i <= d; i++) {
        for (int prev = 1; prev <= VERT; prev++) {
            for (const int& cur : graph[prev]) {
                dp[i][cur] = (dp[i][cur] + dp[i - 1][prev]) % MOD;
            }
        }
    }

    cout << dp[d][1] << '\n';

    return 0;
}
