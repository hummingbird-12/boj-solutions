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

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    for (int x = -999; x <= 999; x++) {
        for (int y = -999; y <= 999; y++) {
            if (a * x + b * y == c && d * x + e * y == f) {
                cout << x << ' ' << y << '\n';
                break;
            }
        }
    }

    return 0;
}
