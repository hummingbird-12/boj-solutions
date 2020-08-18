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
vector < int > in_cnt;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    in_cnt.resize(n + 1);

    int u, v;
    while (m--) {
        cin >> u >> v;
        graph[v].push_back(u);
        in_cnt[u]++;
    }

    stack < int > s;
    queue < int > q;
    for (int i = 1; i <= n; i++) {
        if (in_cnt[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        const int& cur = q.front();
        s.push(cur);
        for (const int& next : graph[cur]) {
            in_cnt[next]--;
            if (in_cnt[next] == 0) {
                q.push(next);
            }
        }
        q.pop();
    }

    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    cout << '\n';

    return 0;
}
