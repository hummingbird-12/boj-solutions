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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    vector < int > v;

    int n, i, num;
    cin >> n;

    cin >> num;
    v.push_back(num);

    for (i = 1; i < n; i++) {
        cin >> num;
        if (v.back() < num) {
            v.push_back(num);
            continue;
        }
        *lower_bound(v.begin(), v.end(), num) = num;
    }

    cout << v.size() << '\n';

    return 0;
}
