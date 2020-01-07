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

    int _max = INT_MIN;
    int _min = INT_MAX;
    int n, num;

    cin >> n;
    while (n--) {
        cin >> num;
        _max = max(_max, num);
        _min = min(_min, num);
    }
    cout << _min << ' ' << _max << '\n';

    return 0;
}
