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

constexpr int MAX = 117;

long long mem[MAX] = { 0, 1, 1, 1 };

long long pseudoFib(int n) {
    if (mem[n] != 0) {
        return mem[n];
    }
    for (int i = 4; i <= n; i++) {
        mem[i] = mem[i - 1] + mem[i - 3];
    }
    return mem[n];
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cout << pseudoFib(n) << '\n';

    return 0;
}
