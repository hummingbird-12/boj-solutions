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

constexpr int MAX_NUMBERS = 3;
int numbers[MAX_NUMBERS];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, i;
    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    sort(numbers, numbers + n);

    int MCD;
    for (MCD = numbers[0]; MCD >= 1; MCD--) {
        for (i = 0; i < n && numbers[i] % MCD == 0; i++);
        if (i == n) {
            break;
        }
    }

    if (MCD == 1) {
        cout << 1 << '\n';
        return 0;
    }

    stack < int > divisors;
    for (i = 1; i <= sqrt(MCD); i++) {
        if (MCD % i == 0) {
            divisors.push(i);
            cout << i << '\n';
        }
    }

    if (divisors.top() * divisors.top() == MCD) {
        divisors.pop();
    }

    while (!divisors.empty()) {
        cout << MCD / divisors.top() << '\n';
        divisors.pop();
    }

    return 0;
}
