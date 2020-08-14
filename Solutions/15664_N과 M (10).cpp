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

int cnt[10'001];

void generate(const int remaining, vector < int >& buffer, int current = 1) {
    if (remaining == 0) {
        for (const int& i : buffer) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = current; i <= 10'000; i++) {
        if (cnt[i] > 0) {
            cnt[i]--;
            buffer.push_back(i);

            generate(remaining - 1, buffer, i);

            cnt[i]++;
            buffer.pop_back();
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int num;
    while (n--) {
        cin >> num;
        cnt[num]++;
    }

    vector < int > v;
    generate(m, v);

    return 0;
}
