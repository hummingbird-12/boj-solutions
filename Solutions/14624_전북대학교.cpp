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

void printSymbol(const int n) {
    for (int i = 0; i < n; i++) {
        cout << '*';
    }
    cout << '\n';

    for (int i = 0; i < (n + 1) / 2; i++) {
        for (int j = 0; j < n / 2 - i; j++) {
            cout << ' ';
        }
        cout << '*';
        for (int j = 0; j < i * 2 - 1; j++) {
            cout << ' ';
        }
        if (i != 0) {
            cout << '*';
        }
        cout << '\n';
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    if (n % 2 == 1) {
        printSymbol(n);
    }
    else {
        cout << "I LOVE CBNU\n";
    }

    return 0;
}
