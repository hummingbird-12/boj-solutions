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

int cnt[10001];

void generate(int count, vector < int >& buffer) {
    if (count == 0) {
        for (const int& i : buffer) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i < 10001; i++) {
        if (cnt[i] > 0) {
            cnt[i]--;
            buffer.push_back(i);

            generate(count - 1, buffer);

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
    for (int i = 0; i < n; i++) {
        cin >> num;
        cnt[num]++;
    }

    vector < int > v;
    generate(m, v);

    return 0;
}
