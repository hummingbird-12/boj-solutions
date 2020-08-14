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

inline int gcd(int x, int y) {
    int r;
    while (y != 0) {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a, b, c, d;

    cin >> a >> b >> c >> d;
    a = a * d + c * b;
    b *= d;

    c = gcd(a, b);
    a /= c;
    b /= c;

    cout << a << ' ' << b << '\n';

    return 0;
}
