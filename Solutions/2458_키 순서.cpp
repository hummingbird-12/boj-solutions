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

vector < vector < int > > increasing; // In increasing order
vector < vector < int > > decreasing; // In decreasing order

vector < bool > visited; // For DFS

/*
 * DFS towards either bigger or smaller nodes than `current` node
 */
void dfs(const int current, const bool increase) {
    const vector < vector < int > >& graph = (increase ? increasing : decreasing);

    visited[current] = true;
    for (const int& next : graph[current]) {
        if (!visited[next]) {
            dfs(next, increase);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    increasing.resize(n + 1);
    decreasing.resize(n + 1);

    visited.resize(n + 1);

    int a, b;
    while (m--) {
        cin >> a >> b;
        increasing[a].push_back(b);
        decreasing[b].push_back(a);
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        dfs(i, true);
        dfs(i, false);
        if (*min_element(visited.begin() + 1, visited.end()) == true) {
            sum++;
        }
        fill(visited.begin(), visited.end(), false);
    }
    cout << sum << '\n';

    return 0;
}
