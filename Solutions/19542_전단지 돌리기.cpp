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
vector < bool > visited;
int n, s, d, u, v;

int dfs(int cur) {
    int dist = -d, next_dist;
    visited[cur] = true;

    for (int next : graph[cur]) {
        if (!visited[next]) {
            next_dist = dfs(next);
            if (dist < 0) {
                dist = max(dist, next_dist);
            }
            else if (next_dist > 0) {
                dist += next_dist;
            }
        }
    }

    return dist + 1;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> s >> d;

    graph.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout << max((dfs(s) - 1) * 2, 0) << '\n';

    return 0;
}
