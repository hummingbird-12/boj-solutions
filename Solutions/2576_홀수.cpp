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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    short n;
    vector < short > odds;
    odds.reserve(100);

    while (scanf("%hd", &n) == 1) {
        if (n % 2 == 1) {
            odds.push_back(n);
        }
    }
    if (odds.empty()) {
        cout << -1 << '\n';
        return 0;
    }
    sort(odds.begin(), odds.end());

    cout << accumulate(odds.begin(), odds.end(), 0) << '\n';
    cout << odds.front() << '\n';

    return 0;
}
