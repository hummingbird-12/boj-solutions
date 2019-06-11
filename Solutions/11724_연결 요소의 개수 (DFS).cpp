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

vector < vector < int > > graph;
vector < bool > visited;

void dfs(int start) {
    stack < int > st;

    st.push(start);
    visited[start] = true;

    while (!st.empty()) {
        int cur = st.top();
        st.pop();

        for (int i : graph[cur]) {
            if (!visited[i]) {
                visited[i] = true;
                st.push(i);
            }
        }
    }
}

int main() {
    int n, m, u, v;
    int cnt = 0;

    scanf("%d%d", &n, &m);
    graph.resize(n + 1);
    visited.resize(n + 1);

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cnt++;
            dfs(i);
        }
    }

    printf("%d\n", cnt);

    return 0;
}
