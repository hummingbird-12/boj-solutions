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

vector < vector < int > > graph;
vector < int > depth;

constexpr int MAX_EXP = 18; // 2^17 > 100'000
int parent_2k[100'001][MAX_EXP]; // List of 2^k-th parents of each node

void dfs(const int cur, const int par) {
    for (const int& next : graph[cur]) {
        if (next != par) {
            depth[next] = depth[cur] + 1;

            parent_2k[next][0] = cur;
            for (int i = 1; i < MAX_EXP; i++) {
                parent_2k[next][i] = parent_2k[parent_2k[next][i - 1]][i - 1];
            }

            dfs(next, cur);
        }
    }
}

int lca_query(int a, int b) {
    if (a == 1 || b == 1) {
        return 1;
    }

    // Make node `a` the deepest node
    if (depth[a] < depth[b]) {
        swap(a, b);
    }

    // Equalize node `a`'s depth to node `b`
    for (int i = MAX_EXP - 1; i >= 0; i--) {
        if ((1 << i) <= depth[a] - depth[b]) {
            a = parent_2k[a][i];
        }
    }

    if (a == b) {
        return a;
    }

    // Bring both nodes towards root until direct parent is same
    for (int i = MAX_EXP - 1; i >= 0; i--) {
        if (parent_2k[a][i] != parent_2k[b][i]) {
            a = parent_2k[a][i];
            b = parent_2k[b][i];
        }
    }

    return parent_2k[a][0];
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    graph.resize(n + 1);
    depth.resize(n + 1);

    int u, v;
    while (--n) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, 0);

    cin >> n;
    while (n--) {
        cin >> u >> v;
        cout << lca_query(u, v) << '\n';
    }

    return 0;
}
