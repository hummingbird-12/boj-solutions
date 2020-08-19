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
vector < bool > visited;
vector < vector < int > > parent_2k; // List of 2^k-th parents of each node

void dfs(const int cur, vector < int >& path) {
    // Get 2^k-th parents
    for (int j = 1; j <= path.size() - 1; j *= 2) {
        parent_2k[cur].push_back(path[path.size() - j - 1]);
    }

    for (const int& next : graph[cur]) {
        if (!visited[next]) {
            visited[next] = true;
            depth[next] = depth[cur] + 1;

            path.push_back(next);
            dfs(next, path);
            path.pop_back();
        }
    }
}

int query(int a, int b) {
    if (a == 1 || b == 1) {
        return 1;
    }

    // Equalize depth
    while (depth[a] != depth[b]) {
        const int diff = log2(abs(depth[a] - depth[b]));
        int& deeper = (depth[a] > depth[b] ? a : b);
        deeper = parent_2k[deeper][diff];
    }

    int i;
    // Bring both nodes towards root until both's 2k-th parent is the same
    while (true) {
        for (i = 0; i < parent_2k[a].size(); i++) {
            if (parent_2k[a][i] == parent_2k[b][i]) {
                break;
            }
        }

        // 2^0-th parent is the same
        if (i == 0) {
            break;
        }

        // 2^i-th parent is the same
        if (i < parent_2k[a].size()) {
            a = parent_2k[a][i - 1];
            b = parent_2k[b][i - 1];
            break;
        }

        // No 2^k-th parent is the same
        a = parent_2k[a].back();
        b = parent_2k[b].back();
    }

    // Bring both nodes towards root until LCA is found
    while (a != b) {
        for (const int& next : graph[a]) {
            if (depth[next] < depth[a]) {
                a = next;
                break;
            }
        }

        for (const int& next : graph[b]) {
            if (depth[next] < depth[b]) {
                b = next;
                break;
            }
        }
    }

    return a;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    graph.resize(n + 1);
    depth.resize(n + 1);
    visited.resize(n + 1);
    parent_2k.resize(n + 1);

    int u, v;
    while (--n) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector < int > path;
    visited[1] = true;
    path.push_back(1);

    dfs(1, path);

    cin >> n;
    while (n--) {
        cin >> u >> v;
        cout << query(u, v) << '\n';
    }

    return 0;
}
