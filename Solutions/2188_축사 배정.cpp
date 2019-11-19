#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>

#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
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
#include <vector>

using namespace std;

constexpr int UNMAPPED = -1;

bool bipartiteMatching(const vector < vector < int > >& graph, vector < int >& mapped, vector < bool >& visited, const int cowIndex) {
    visited[cowIndex] = true;
    for (const int barnIndex : graph[cowIndex]) {
        // found an unmapped barn, map barn with the cow
        if (mapped[barnIndex] == UNMAPPED) {
            mapped[cowIndex] = barnIndex;
            mapped[barnIndex] = cowIndex;
            return true;
        }
        // found an already mapped barn, but succesfully mapped it with another cow
        else if (!visited[mapped[barnIndex]] && mapped[barnIndex] != cowIndex &&
            bipartiteMatching(graph, mapped, visited, mapped[barnIndex])) {
            mapped[cowIndex] = barnIndex;
            mapped[barnIndex] = cowIndex;
            return true;
        }
    }
    return false;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    vector < vector < int > > graph;
    vector < int > mapped;
    vector < bool > visited;
    int n, m, barns, b;
    int ans = 0;

    cin >> n >> m;
    graph.resize(n + m);
    mapped.resize(n + m, UNMAPPED);
    visited.resize(n + m);
    auto cowToIndex = [](int cow)->int {
        return cow - 1;
    };
    auto barnToIndex = [=](int barn)->int {
        return barn + n - 1;
    };

    for (int cow = 1; cow <= n; cow++) {
        cin >> barns;
        for (int j = 0; j < barns; j++) {
            cin >> b;
            // store as bidirectional graph with hashed index
            graph[cowToIndex(cow)].push_back(barnToIndex(b));
            graph[barnToIndex(b)].push_back(cowToIndex(cow));
        }
    }

    for (int cowIndex = 0; cowIndex < n; cowIndex++) {
        if (mapped[cowIndex] == UNMAPPED && bipartiteMatching(graph, mapped, visited, cowIndex)) {
            ans++;
        }
        // reset visited status for new dps iteration
        fill(visited.begin(), visited.end(), false);
    }
    cout << ans << '\n';

    return 0;
}
