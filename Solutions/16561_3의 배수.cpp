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

    int n, count = 0, k;
    cin >> n;

    for (int i = 3; i <= n - 6; i += 3) {
        count += (n - i) / 3 - 1;
    }
    cout << count << '\n';

    return 0;
}
