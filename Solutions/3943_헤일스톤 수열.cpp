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

int hailstone(int n) {
    int mx = n;
    while (n != 1) {
        n = (n % 2 ? (n * 3 + 1) : (n / 2));
        mx = max(mx, n);
    }
    return mx;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        cout << hailstone(n) << '\n';
    }

    return 0;
}
