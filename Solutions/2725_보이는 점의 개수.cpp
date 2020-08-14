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

bool is_prime[1001];

/*
 * �����佺�׳׽��� ü
 */
void find_primes() {
    fill(is_prime + 2, is_prime + 1001, true);

    for (int i = 2; i < 1001; i++) {
        if (is_prime[i]) {
            for (int j = i * 2; j < 1001; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int pwr(int n, int m) {
    int ret = 1;
    while (m--) {
        ret *= n;
    }
    return ret;
}

/*
 * ���Ϸ����� �Լ� : n^power ���� �����鼭 ���μ��� ���� ����
 * PI(p^m) = p^m - p^(m - 1)  --> p�� �Ҽ�
 */
int euler_pi(int n, int power) {
    if (is_prime[n]) {
        return pwr(n, power) - pwr(n, power - 1);
    }
    int ret = 1;
    for (int i = 2; n != 1 && i <= n; i++) {
        if (is_prime[i] && n % i == 0) {
            int pw = 0;
            while (n % i == 0) {
                pw++;
                n /= i;
            }
            ret *= euler_pi(i, pw);
        }
    }
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    find_primes();

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        int ans = 0;
        for (int i = 2; i <= n; i++) {
            ans += euler_pi(i, 1);
        }
        // (0, 0), (1, 0), (0, 1) �߰�
        cout << ans * 2 + 3 << '\n';
    }

    return 0;
}
