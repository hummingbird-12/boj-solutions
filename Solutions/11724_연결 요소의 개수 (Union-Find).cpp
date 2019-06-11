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

vector < int > parent;

int _find(int i) {
    if (parent[i] != -1) {
        return (parent[i] = _find(parent[i]));
    }
    return i;
}

void _union(int i, int j) {
    int parX = _find(i);
    int parY = _find(j);

    if (parX != parY) {
        parent[parX] = parY;
    }
}

int main() {
    int n, m, u, v;
    int cnt = 0;

    scanf("%d%d", &n, &m);
    parent.resize(n + 1);

    for (auto& i : parent) {
        i = -1;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        _union(u, v);
    }

    for (int i = 1; i <= n; i++) {
        if (parent[i] == -1) {
            cnt++;
        }
    }

    printf("%d\n", cnt);

    return 0;
}
