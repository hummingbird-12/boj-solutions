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

#define MAX 501

int mapHeight[MAX][MAX];    // input data
int isPath[MAX][MAX];      // paths available from (x, y)
bool visited[MAX][MAX];     // DFS executed over (x, y)
short dx[] = { 1, 0, -1, 0 };
short dy[] = { 0, 1, 0, -1 };

int dpDFS(int m, int n, int x, int y) {
    int curPath = 0;

    if (isPath[x][y]) {
        return isPath[x][y];
    }

    visited[x][y] = true;
    if (x == m - 1 && y == n - 1) {
        isPath[x][y] = 1;
        return isPath[x][y];
    }

    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (newX < 0 || newX >= m || newY < 0 || newY >= n || mapHeight[x][y] <= mapHeight[newX][newY]) {
            continue;
        }
        if (!visited[newX][newY]) {
            curPath += dpDFS(m, n, newX, newY);
        }
        else if (isPath[newX][newY]) {
            curPath += isPath[newX][newY];
        }
    }
    isPath[x][y] = curPath;
    return curPath;
}


int main() {
    int m, n;

    scanf("%d%d", &m, &n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mapHeight[i][j]);
        }
    }

    dpDFS(m, n, 0, 0);
    printf("%d\n", isPath[0][0]);
    return 0;
}
