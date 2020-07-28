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
vector < int > spread;
queue < pair < int, int > > q;

void bfs() {
    int count;

    while (!q.empty()) {
        int cur = q.front().first;
        int time = q.front().second;
        q.pop();

        for (int next : graph[cur]) {
            if (spread[next] == -1) {
                count = 0;
                // Count neighbors with rumors already spread
                for (int adj : graph[next]) {
                    if (spread[adj] != -1 && spread[adj] <= time) {
                        count++;
                    }
                }
                // When majority of neighbors have rumors spread, it is spread to `next` node
                if (2 * count >= graph[next].size()) {
                    spread[next] = time + 1;
                    q.emplace(next, time + 1);
                }
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n;
    graph.resize(n + 1);
    spread.resize(n + 1, -1);

    int v;
    for (int i = 1; i <= n; i++) {
        while (true) {
            cin >> v;
            if (v == 0) {
                break;
            }
            graph[i].push_back(v);
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> v;
        spread[v] = 0;
        q.emplace(v, 0);
    }

    bfs();
    for (int i = 1; i <= n; i++) {
        cout << spread[i] << ' ';
    }
    cout << '\n';

    return 0;
}
