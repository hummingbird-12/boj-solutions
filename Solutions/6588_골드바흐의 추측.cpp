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

constexpr int MAX = 1'000'001;

bool e[MAX];
vector < int > primes;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    fill(e, e + MAX, true);

    for (int i = 2; i < MAX; i++) {
        if (e[i]) {
            if (i > 2) {
                primes.push_back(i);
            }
            for (int j = i * 2; j < MAX; j += i) {
                e[j] = false;
            }
        }
    }

    int n;
    cin >> n;

    while (n != 0) {
        for (int a : primes) {
            if (e[n - a]) {
                cout << n << " = " << a << " + " << n - a << '\n';
                n = 0;
                break;
            }
        }

        if (n != 0) {
            cout << "Goldbach's conjecture is wrong.\n";
        }

        cin >> n;
    }

    return 0;
}
