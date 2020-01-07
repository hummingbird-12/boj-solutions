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

    int fixedCost, variableCost, price;
    cin >> fixedCost >> variableCost >> price;
    if (variableCost >= price) {
        cout << -1 << '\n';
    }
    else {
        cout << (fixedCost / (price - variableCost)) + 1 << '\n';
    }

    return 0;
}
