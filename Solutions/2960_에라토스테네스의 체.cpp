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

bool e[1001];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    for (int i = 2; i <= n; i++) {
        if (!e[i]) {
            for (int j = i; j <= n; j += i) {
                if (e[j]) {
                    continue;
                }
                if (--k == 0) {
                    cout << j << '\n';
                }
                e[j] = true;
            }
        }
    }

    return 0;
}
