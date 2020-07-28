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

vector < vector < int > > groups;
vector < bool > infected, test;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m;
    groups.resize(m);

    for (int i = 0; i < m; i++) {
        cin >> k;
        groups[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> groups[i][j];
        }
    }

    infected.resize(n + 1);
    test.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> k;
        infected[i] = test[i] = (k == 1);
    }

    /*
     * Consider 0 as infected and 1 as non-infected.
     * Run simulation from bottom to top.
     */
    for (auto it = groups.rbegin(); it != groups.rend(); it++) {
        for (int i : *it) {
            if (!test[i]) {
                for (int j : *it) {
                    test[j] = false;
                }
                break;
            }
        }
    }

    /*
     * Save candidate answer
     */
    vector < bool > candidate = test;

    /*
     * Re-run simulation for the candidate answer from top to bottom.
     * 1 is infected and 0 is non-infected.
     */
    for (auto it = groups.begin(); it != groups.end(); it++) {
        for (int i : *it) {
            if (test[i]) {
                for (int j : *it) {
                    test[j] = true;
                }
                break;
            }
        }
    }

    /*
     * Check if the round way simulation equals the infection result.
     */
    for (auto it1 = test.begin(), it2 = infected.begin();
        it1 != test.end() && it2 != infected.end();
        it1++, it2++) {
        if (*it1 != *it2) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for (auto it = candidate.begin() + 1; it != candidate.end(); it++) {
        cout << *it << ' ';
    }
    cout << '\n';

    return 0;
}
