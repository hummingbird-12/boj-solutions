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

    int cardCount, card, upperBound;
    cin >> cardCount >> upperBound;
    vector < int > cards;
    cards.reserve(cardCount);

    while (cardCount--) {
        cin >> card;
        cards.push_back(card);
    }
    sort(cards.begin(), cards.end());

    int i, j, k, maxSum = INT_MIN;
    for (i = 0; i < cards.size() && cards[i] < upperBound; i++) {
        for (j = i + 1; j < cards.size() && cards[i] + cards[j] < upperBound; j++) {
            for (k = j + 1; k < cards.size() && cards[i] + cards[j] + cards[k] <= upperBound; k++) {
                maxSum = max(maxSum, cards[i] + cards[j] + cards[k]);
            }
        }
    }
    cout << maxSum << '\n';

    return 0;
}
