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

const short dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const short dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

vector < int > altitudes;
char graph[50][50];
int altitude[50][50];
bool visited[50][50];
int n, houses, px, py;

bool bfs(int left, int right) {
    queue < pair < int, int > > q;

    for (int i = 0; i < n; i++) {
        fill(visited[i], visited[i] + 50, false);
    }

    q.emplace(px, py);
    visited[px][py] = true;
    int h_cnt = 0;

    while (!q.empty()) {
        int cur_row = q.front().first;
        int cur_col = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int new_row = cur_row + dx[i];
            int new_col = cur_col + dy[i];

            if (new_row >= 0 && new_row < n &&
                new_col >= 0 && new_col < n &&
                !visited[new_row][new_col] &&
                altitude[new_row][new_col] >= left &&
                altitude[new_row][new_col] <= right) {
                if (graph[new_row][new_col] == 'K') {
                    h_cnt++;
                    if (h_cnt == houses) {
                        return true;
                    }
                }
                visited[new_row][new_col] = true;
                q.emplace(new_row, new_col);
            }
        }
    }
    return false;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    set < int > alt_set;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> altitude[i][j];
            if (alt_set.find(altitude[i][j]) == alt_set.end()) {
                altitudes.push_back(altitude[i][j]);
            }
            alt_set.insert(altitude[i][j]);

            switch (graph[i][j]) {
            case 'P':
                px = i;
                py = j;
                break;
            case 'K':
                houses++;
                break;
            default:
                break;
            }
        }
    }
    sort(altitudes.begin(), altitudes.end());

    int left = 0;
    int& post_alt = altitude[px][py];
    int right = find(altitudes.begin(), altitudes.end(), post_alt) - altitudes.begin();

    int ans = INT_MAX;
    while (left <= right && right < altitudes.size()) {
        int& down = altitudes[left];
        int& up = altitudes[right];

        if (down > post_alt) {
            break;
        }

        if (bfs(down, up)) {
            ans = min(ans, up - down);
            left++;
        }
        else {
            right++;
        }
    }

    cout << ans << '\n';

    return 0;
}
