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

bool is_prime[1'000'001];
vector < int > primes;

void get_primes(const int n) {
    fill(is_prime, is_prime + 1'000'001, true);
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int mod(const string& n, const int p) {
    int ret = 0;
    for (const char& c : n) {
        ret = (ret * 10 + (c - '0')) % p;
    }
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string pwd;
    int k;

    cin >> pwd >> k;

    get_primes(k - 1);

    for (const int& p : primes) {
        if (mod(pwd, p) == 0) {
            cout << "BAD " << p << '\n';
            return 0;
        }
    }
    cout << "GOOD\n";

    return 0;
}
