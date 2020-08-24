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

vector < pair < int, int > > input; // < WEIGHT, COLOR > in original input order
vector < pair < int, int > > balls; // < WEIGHT, COLOR > sorted
vector < vector < pair < int, int > > > ball_order; // < SORT_INDEX, ACCUMULATED_WEIGHT > for each color
vector < int > accum_weight;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    balls.resize(n);
    accum_weight.resize(n);
    ball_order.resize(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> balls[i].second >> balls[i].first;
    }

    input = balls;
    sort(balls.begin(), balls.end());

    accum_weight[0] = balls[0].first;
    ball_order[balls[0].second].emplace_back(0, balls[0].first);

    for (int i = 1; i < n; i++) {
        const int& weight = balls[i].first;
        const int& color = balls[i].second;

        accum_weight[i] = accum_weight[i - 1] + weight;
        if (ball_order[color].empty()) {
            ball_order[color].emplace_back(i, weight);
        }
        else {
            ball_order[color].emplace_back(i, ball_order[color].back().second + weight);
        }
    }

    for (const auto& inp : input) {
        const int& weight = inp.first;
        const int& color = inp.second;

        /*
         * Get SORT_INDEX of weight's lower_bound.
         * This part handles duplicate weights, as it only compares the weight value.
         */
        const int index = lower_bound(balls.begin(), balls.end(), weight,
            [](const pair < int, int >& p, const int& value) -> bool { return p.first < value; }) -
            balls.begin();
        /*
         * Use lower_bound to obtain the ACCUMULATED_WEIGHT within current color's upto current ball from `ball_order`.
         */
        const auto same = lower_bound(ball_order[color].begin(), ball_order[color].end(), index,
            [](const pair < int, int >& p, const int& value) -> bool { return p.first < value; });

        // TOTAL_ACCUM_WEIGHT - COLOR_ACCUM_WEIGTH
        cout << accum_weight[index] - same->second << '\n';
    }

    return 0;
}
