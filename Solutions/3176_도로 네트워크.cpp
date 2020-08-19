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

vector < vector < pair < int, int > > > graph;
vector < int > depth;

constexpr int MAX_EXP = 18; // 2^17 > 100'000
/*
 * parent_2k[i][k][0] : i-th node's 2^k-th parent
 * parent_2k[i][k][1] : minimum cost until i-th node's 2^k-th parent
 * parent_2k[i][k][2] : maximum cost until i-th node's 2^k-th parent
 */
int parent_2k[100'001][MAX_EXP][3];

void dfs(const int cur, const int par) {
    for (const auto& next : graph[cur]) {
        if (next.first != par) {
            depth[next.first] = depth[cur] + 1;

            // Fill 2^-th parents list
            parent_2k[next.first][0][0] = cur;
            parent_2k[next.first][0][1] = parent_2k[next.first][0][2] = next.second;
            for (int i = 1; i < MAX_EXP; i++) {
                parent_2k[next.first][i][0] =
                    parent_2k[parent_2k[next.first][i - 1][0]][i - 1][0];

                parent_2k[next.first][i][1] = min(
                    parent_2k[parent_2k[next.first][i - 1][0]][i - 1][1],
                    parent_2k[next.first][i - 1][1]
                );

                parent_2k[next.first][i][2] = max(
                    parent_2k[parent_2k[next.first][i - 1][0]][i - 1][2],
                    parent_2k[next.first][i - 1][2]
                );
            }

            dfs(next.first, cur);
        }
    }
}

// Returns < MIN, MAX >
pair < int, int > lca_query(int a, int b) {
    pair < int, int > ans(INT_MAX, 0);

    // Make node `a` the deepest node
    if (depth[a] < depth[b]) {
        swap(a, b);
    }

    // Equalize node `a`'s depth to node `b`
    for (int i = MAX_EXP - 1; i >= 0; i--) {
        if ((1 << i) <= depth[a] - depth[b]) {
            ans.first = min(parent_2k[a][i][1], ans.first);
            ans.second = max(parent_2k[a][i][2], ans.second);
            a = parent_2k[a][i][0];
        }
    }

    if (a == b) {
        return ans;
    }

    // Bring both nodes towards root until direct parent is same
    for (int i = MAX_EXP - 1; i >= 0; i--) {
        if (parent_2k[a][i][0] != parent_2k[b][i][0]) {
            ans.first = min(
                min(parent_2k[a][i][1], parent_2k[b][i][1]),
                ans.first
            );
            ans.second = max(
                max(parent_2k[a][i][2], parent_2k[b][i][2]),
                ans.second
            );

            a = parent_2k[a][i][0];
            b = parent_2k[b][i][0];
        }
    }

    ans.first = min(min(parent_2k[a][0][1], parent_2k[b][0][1]), ans.first);
    ans.second = max(max(parent_2k[a][0][2], parent_2k[b][0][2]), ans.second);

    return ans;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    graph.resize(n + 1);
    depth.resize(n + 1);

    int u, v, w;
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < MAX_EXP; j++) {
            parent_2k[i][j][1] = INT_MAX;
            parent_2k[i][j][2] = 0;
        }
    }
    dfs(1, 0);

    cin >> n;
    while (n--) {
        cin >> u >> v;
        const auto ans = lca_query(u, v);
        cout << ans.first << ' ' << ans.second << '\n';
    }

    return 0;
}
