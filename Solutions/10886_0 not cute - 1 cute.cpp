#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>

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
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    short opinion = 0, input, n;
    cin >> n;
    while (n--) {
        cin >> input;
        opinion += input * 2 - 1;
    }
    cout << "Junhee is" << (opinion < 0 ? " not " : " ") << "cute!" << '\n';

    return 0;
}
