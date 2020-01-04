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

/*
 * The JavaScript code:
 * ```javascript
 * var cnt = 0;
 * var s = $("#sampleoutput1 .sampledata");
 * var eevee = ['Vaporeon', 'Jolteon', 'Flareon'];
 * s.html("Eevee");
 * setInterval(function(){ s.html(eevee[(++cnt)%3]); }, 1000);
 * ```
 */

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int level;
    const string evolutions[] = { "Vaporeon", "Jolteon", "Flareon" };
    cin >> level;
    cout << evolutions[++level % 3] << '\n';
    return 0;
}
