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

//  13325
constexpr int MAX_NODES = (1 << 21);

long long tree[MAX_NODES];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int k;
    cin >> k;

    const int nodes = (1 << (k + 1));
    const int leaf_start = nodes - (1 << k);

    for (int i = 2; i < nodes; i++) {
        cin >> tree[i];
    }

    long long sum = 0;
    for (int i = leaf_start - 1; i >= 1; i--) {
        const long long bigger = max(tree[i * 2], tree[i * 2 + 1]);
        sum += bigger;
        tree[i] += bigger;
    }
    cout << sum + tree[1] << '\n';

    return 0;
}
