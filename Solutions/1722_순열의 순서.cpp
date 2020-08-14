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

int n;
long long mem[21] = { 1 };
bool used[21];

long long fact(int n) {
    if (mem[n] != 0) {
        return mem[n];
    }
    return (mem[n] = fact(n - 1) * n);
}

void kth_perm_query(const int iteration, const long long order, vector < int >& buffer) {
    if (iteration == 0) {
        for (const int& i : buffer) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }

    long long accum = 0;
    const long long f = fact(iteration - 1);
    for (int i = 0; i < iteration; i++) {
        if (order <= accum + f) {
            for (int j = 1; j <= n; j++) {
                if (!used[j]) {
                    if (i == 0) {
                        used[j] = true;
                        buffer.push_back(j);
                        kth_perm_query(iteration - 1, order - accum, buffer);
                    }
                    i--;
                }
            }
            break;
        }
        accum += f;
    }
}

long long perm_order_query(const vector < int >& perm, int index = 0, long long accum = 0) {
    if (index == perm.size()) {
        return accum + 1;
    }

    int current = perm[index];
    long long f = fact(n - index - 1);
    for (int i = 1; i < current; i++) {
        if (!used[i]) {
            accum += f;
        }
    }
    used[current] = true;

    return perm_order_query(perm, index + 1, accum);
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    int q;
    long long k;
    vector < int > v;
    cin >> q;
    if (q == 1) {
        cin >> k;

        kth_perm_query(n, k, v);
    }
    else {
        v.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        cout << perm_order_query(v) << '\n';
    }

    return 0;
}
