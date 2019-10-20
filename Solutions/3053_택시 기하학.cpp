#include <cctype>
#include <climits>
#define _USE_MATH_DEFINES
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
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int radius;
    cin >> radius;

    cout << fixed;
    cout.precision(6);

    const int radiusSquare = radius * radius;
    cout << radiusSquare * M_PI << '\n';
    cout << radiusSquare * 2.0 << '\n';

    return 0;
}
