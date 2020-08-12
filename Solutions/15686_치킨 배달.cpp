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

const short dx[] = { -1, 0, 1, 0 };
const short dy[] = { 0, 1, 0, -1 };

vector < pair < int, int > > locations;
queue < pair < pair < int, int >, int > > q;
short world[50][50];
bool visited[50][50];
int n, m;

/*
 * BFS with a combination of `m` stores in queue initially
 */
int bfs() {
    int dist = 0;

    while (!q.empty()) {
        int cur_row = q.front().first.first;
        int cur_col = q.front().first.second;
        int cur_time = q.front().second;
        q.pop();

        if (world[cur_row][cur_col] == 1) {
            dist += cur_time;
        }

        for (int i = 0; i < 4; i++) {
            int new_row = cur_row + dx[i];
            int new_col = cur_col + dy[i];

            if (new_row >= 0 && new_row < n &&
                new_col >= 0 && new_col < n &&
                !visited[new_row][new_col]) {
                visited[new_row][new_col] = true;
                q.emplace(make_pair(new_row, new_col), cur_time + 1);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        fill(visited[i], visited[i] + n, false);
    }

    return dist;
}

/*
 * Backtracking for all combination of `m` stores
 */
int backtracking(vector < int >& selection, int index) {
    if (selection.size() == m) {
        for (int s : selection) {
            q.emplace(locations[s], 0);
        }
        return bfs();
    }

    int ans = INT_MAX;
    for (int i = index; i < locations.size(); i++) {
        selection.push_back(i);

        ans = min(ans, backtracking(selection, i + 1));

        selection.pop_back();
    }

    return ans;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> world[i][j];
            // Save all stores' locations
            if (world[i][j] == 2) {
                locations.emplace_back(i, j);
            }
        }
    }

    vector < int > selection;
    cout << backtracking(selection, 0) << '\n';

    return 0;
}
