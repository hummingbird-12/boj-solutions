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

priority_queue <
    int
> left_pq; // Stores numbers smaller or equal to mid
priority_queue <
    int,
    vector < int >,
    greater < int >
> right_pq; // Stores numbers larger than mid

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, mid, input;

    cin >> n;

    cin >> mid;
    cout << mid << '\n';

    for (int i = 2; i <= n; i++) {
        cin >> input;
        // Compare against current mid number
        if (input >= mid) {
            right_pq.push(input);
        }
        else {
            left_pq.push(input);
        }

        // Compare size of each min-heap
        if ((int)right_pq.size() - (int)left_pq.size() >= 2) {
            left_pq.push(mid);
            mid = right_pq.top();
            right_pq.pop();
        }
        else if ((int)left_pq.size() - (int)right_pq.size() >= 1) {
            right_pq.push(mid);
            mid = left_pq.top();
            left_pq.pop();
        }

        cout << mid << '\n';
    }

    return 0;
}
