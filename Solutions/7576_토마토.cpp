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

#define MAX 1001

queue < pair < pair < int, int >, int > > q;

int raw;
short tomato[MAX][MAX];
bool visited[MAX][MAX];
short dy[] = { -1, 0, 1, 0 };
short dx[] = { 0, 1, 0, -1 };

int bfs(int rowCnt, int colCnt) {
    int row, col;

    if (raw == 0) {
        if (q.empty()) {
            return -1;
        }
        return 0;
    }

    while (!q.empty()) {
        auto cur = q.front().first;

        for (int i = 0; i < 4; i++) {
            row = cur.first + dy[i];
            col = cur.second + dx[i];

            if (row >= 0 && row < rowCnt && col >= 0 && col < colCnt) {
                if (!visited[row][col]) {
                    visited[row][col] = true;
                    q.push(make_pair(make_pair(row, col), q.front().second + 1));
                    if (--raw == 0) {
                        return q.front().second + 1;
                    }
                }
            }
        }
        q.pop();
    }
    return -1;
}

int main() {
    int m, n;

    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%hd", &tomato[i][j]);
            switch (tomato[i][j]) {
            case 1:
                q.push(make_pair(make_pair(i, j), 0));
                visited[i][j] = true;
                break;
            case -1:
                visited[i][j] = true;
                break;
            case 0:
                raw++;
                break;
            }
        }
    }

    printf("%d\n", bfs(n, m));
    return 0;
}
