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

void draw(const int n, const int line) {
    // Base case
    if (n == 3) {
        switch (line) {
        case 0:
            cout << "  *  ";
            break;
        case 1:
            cout << " * * ";
            break;
        case 2:
            cout << "*****";
            break;
        }
        return;
    }

    // Top half
    if (line < n / 2) {
        for (int j = 0; j < n / 2; j++) {
            cout << " ";
        }
        draw(n / 2, line);
        for (int j = 0; j < n / 2; j++) {
            cout << " ";
        }
    }
    // Bottom half
    else {
        draw(n / 2, line % (n / 2));
        cout << ' ';
        draw(n / 2, line % (n / 2));
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        draw(n, i);
        cout << '\n';
    }

    return 0;
}
