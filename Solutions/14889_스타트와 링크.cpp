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

#define MAX_N 21

using namespace std;

short power[MAX_N][MAX_N];
vector < short > teamA;
vector < short > teamB;

int getDifference() {
    int p = 0;
    for (int m : teamA) {
        for (int n : teamA) {
            p += power[m][n];
        }
    }
    for (int m : teamB) {
        for (int n : teamB) {
            p -= power[m][n];
        }
    }

    return abs(p);
}

int backtracking(const int n, int cur) {
    if (teamA.size() == n / 2) {
        for (int i = cur; i <= n; i++) {
            teamB.push_back(i);
        }
        int p = getDifference();
        for (int i = cur; i <= n; i++) {
            teamB.pop_back();
        }
        return p;
    }
    if (teamB.size() == n / 2) {
        for (int i = cur; i <= n; i++) {
            teamA.push_back(i);
        }
        int p = getDifference();
        for (int i = cur; i <= n; i++) {
            teamA.pop_back();
        }
        return p;
    }

    teamA.push_back(cur);
    int p = backtracking(n, cur + 1);
    teamA.pop_back();
    teamB.push_back(cur);
    p = min(p, backtracking(n, cur + 1));
    teamB.pop_back();

    return p;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> power[i][j];
        }
    }

    cout << backtracking(n, 1) << '\n';

    return 0;
}
