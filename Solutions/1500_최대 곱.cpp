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

    int sum, numbers;
    int i, j, k;

    cin >> sum >> numbers;

    long long maxProduct = 1;
    const int quot = sum / numbers;
    const int modulo = sum % numbers;

    for (int i = 0; i < modulo; i++) {
        maxProduct *= quot + 1ll;
    }
    for (int i = 0; i < numbers - modulo; i++) {
        maxProduct *= quot;
    }

    cout << maxProduct << '\n';

    return 0;
}
