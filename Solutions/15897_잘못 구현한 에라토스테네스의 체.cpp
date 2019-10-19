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
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// Calculates the sum of ( floor((n - 1) / i) + 1 ), where i is [1, n]
inline long long calculateSeriesSum(const long long n) {
    long long i, remainder, division, step, answer = 0;
    const long long numerator = n - 1ll;
    for (i = 1ll; i <= n - 1;) {
        division = numerator / i;
        remainder = numerator % i;

        step = remainder / division + 1;
        answer += division * step;
        i += step;
    }
    answer += n;
    return answer;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long n;
    cin >> n;

    const long long answer = calculateSeriesSum(n);
    cout << answer << '\n';

    return 0;
}