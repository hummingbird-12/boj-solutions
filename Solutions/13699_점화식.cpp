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

constexpr int MAX = 36;

long long mem[MAX] = { 1 };

long long sigma(int n) {
    if (mem[n] != 0) {
        return mem[n];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            mem[i] += mem[j] * mem[i - j - 1];
        }
    }
    return mem[n];
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cout << sigma(n) << '\n';

    return 0;
}
