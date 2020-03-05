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

constexpr int MOD = 1000000007;
constexpr int MAX = 51;

int mem[MAX] = { 1, 1 };

int fibonacci(const int n) {
    if (n < 2) {
        return mem[n];
    }

    for (int i = 2; i <= n; i++) {
        mem[i] = (mem[i - 2] + mem[i - 1] + 1) % MOD;
    }

    return mem[n];
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cout << fibonacci(n) << '\n';

    return 0;
}
