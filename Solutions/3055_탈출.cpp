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
char world[50][50];
bool visited[50][50];
int r, c;

const short dx[] = { 0, 1, 0, -1 };
const short dy[] = { 1, 0, -1, 0 };

class Item {
public:
    int row;
    int col;
    int time;
    bool isWater;

    Item(int _row, int _col, int _time, bool _isWater) {
        row = _row;
        col = _col;
        time = _time;
        isWater = _isWater;
    }
};

queue < Item > q;

void bfs() {
    if (q.empty()) {
        return;
    }

    bool hedgehogMoved = false;
    int time = q.front().time;

    while (q.front().time == time) {
        int cur_row = q.front().row;
        int cur_col = q.front().col;
        int cur_time = q.front().time;
        bool cur_water = q.front().isWater;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int new_row = cur_row + dx[i];
            int new_col = cur_col + dy[i];

            if (new_row >= 0 && new_row < r &&
                new_col >= 0 && new_col < c) {
                // Water advances
                if (cur_water &&
                    (
                        world[new_row][new_col] == '.' ||
                        world[new_row][new_col] == 'S')
                    ) {
                    q.push(Item(new_row, new_col, cur_time + 1, cur_water));
                    world[new_row][new_col] = '*';
                }
                // Hedgehog advances
                else if (!cur_water && !visited[new_row][new_col]) {
                    // Found empty space
                    if (world[new_row][new_col] == '.') {
                        q.push(Item(new_row, new_col, cur_time + 1, cur_water));
                        world[new_row][new_col] = 'S';
                        visited[new_row][new_col] = true;
                        hedgehogMoved = true;
                    }
                    // Found beaver
                    else if (world[new_row][new_col] == 'D') {
                        cout << cur_time + 1 << '\n';
                        exit(0);
                    }
                }
            }
        }
    }

    if (!hedgehogMoved) {
        cout << "KAKTUS\n";
        exit(0);
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> r >> c;

    int sr, sc;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> world[i][j];
            if (world[i][j] == '*') {
                q.push(Item(i, j, 0, true));
            }
            else if (world[i][j] == 'S') {
                sr = i;
                sc = j;
            }
        }
    }
    q.push(Item(sr, sc, 0, false));
    visited[sr][sc] = true;

    while (true) {
        bfs();
    }

    return 0;
}
