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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    vector < short > inp(3);
    cin >> inp[0] >> inp[1] >> inp[2];
    sort(inp.begin(), inp.end());
    while (inp[2] != 0) {
        cout << (inp[0] * inp[0] + inp[1] * inp[1] == inp[2] * inp[2] ? "right\n" : "wrong\n");
        cin >> inp[0] >> inp[1] >> inp[2];
        sort(inp.begin(), inp.end());
    }

    return 0;
}
