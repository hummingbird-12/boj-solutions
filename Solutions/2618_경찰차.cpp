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
#include <unordered_map>
#include <vector>

using namespace std;

constexpr int COPS_COUNT = 2;
constexpr int COP_A = 0;
constexpr int COP_B = 1;
constexpr int CASES_MAX = 1001;

pair < int, int > COPS[COPS_COUNT];                 // The initial location of the cops, should NOT change while processing DP
pair < int, int > caseLocations[CASES_MAX];         // The locations of the cases
int dp[CASES_MAX][CASES_MAX];                       /*
                                                       The DP-array.
                                                       [i][j]: the minimum total distance when
                                                                `COP_A` is at i-th case's location and
                                                                `COP_B` is at j-th case's location
                                                    */
pair < int, int > dpTrace[CASES_MAX][CASES_MAX];    /*
                                                       The trace for each DP case.
                                                       [i][j]: the `dp[i][j]` state follows the state from
                                                                `dp[ dpTrance[i][j].first ][ dpTrace[i][j].second ]`
                                                    */

static int _distancesFromCop[COPS_COUNT][CASES_MAX]; // The distances to the cases from each cop's initial location
static int _distanceInbetween[CASES_MAX][CASES_MAX] = { 0 }; // [i][j]: the distance from i-th case to j-th case

inline int calculateDistance(const pair < int, int > p1, const pair < int, int > p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int distancesFromCop(const int cop, const int caseIndex) {
    if (_distancesFromCop[cop][caseIndex] != -1) {
        return _distancesFromCop[cop][caseIndex];
    }
    return (_distancesFromCop[cop][caseIndex] = calculateDistance(COPS[cop], caseLocations[caseIndex]));
}

int distanceInbetween(const int prevCaseIndex, const int nextCaseIndex) {
    if (_distanceInbetween[prevCaseIndex][nextCaseIndex] != -1) {
        return _distanceInbetween[prevCaseIndex][nextCaseIndex];
    }
    return (_distanceInbetween[prevCaseIndex][nextCaseIndex] = calculateDistance(caseLocations[prevCaseIndex], caseLocations[nextCaseIndex]));
}

void processDP(const int caseIndex) {
    /*
       [ PART_A ]
       First, process DP for
        `dp[caseIndex][0 ~ (caseIndex - 2)]` and
        `dp[0 ~ (caseIndex - 2)][caseIndex]`.
       They mean that the current case is handled by the same cop that handled the previous case.
       Only need to add `distanceInbetween[caseIndex - 1][caseIndex]` from the previous states.

       [ PART_B ]
       Then, handle separately
        `dp[caseIndex][caseIndex - 1]` and
        `dp[caseIndex - 1][caseIndex]`.
       For these, need to check the minimum distance state to follow from among
        `dp[0 ~ (caseIndex - 2)][caseIndex - 1]` and
        `dp[caseIndex - 1][0 ~ (caseIndex - 2)]` repectively
        to figure out which case that the cop that will handle current case
        was handling previously.
    */

    const int previousCase = caseIndex - 1;
    const int distanceFromPrevious = distanceInbetween(previousCase, caseIndex);
    dpTrace[caseIndex][previousCase].second = dpTrace[previousCase][caseIndex].first = previousCase;

    // Separate handling for case when `i = 0` in below for loop

    // [ PART_A ]
    // DP processing when current case is handled by `COP_A`
    dp[caseIndex][0] = dp[previousCase][0] + distanceFromPrevious;
    dpTrace[caseIndex][0].first = previousCase;
    dpTrace[caseIndex][0].second = 0;

    // DP processing when current case is handled by `COP_B`
    dp[0][caseIndex] = dp[0][previousCase] + distanceFromPrevious;
    dpTrace[0][caseIndex].first = 0;
    dpTrace[0][caseIndex].second = previousCase;

    // [ PART_B ]
    // find minimum when previous case was handled by `COP_A`, current by `COP_B`
    dp[caseIndex][previousCase] = dp[0][previousCase] + distancesFromCop(COP_A, caseIndex);
    dpTrace[caseIndex][previousCase].first = 0;

    // find minimnum when previous case was handled by `COP_B`, current by `COP_A`
    dp[previousCase][caseIndex] = dp[previousCase][0] + distancesFromCop(COP_B, caseIndex);
    dpTrace[previousCase][caseIndex].second = 0;

    int newDpValue[COPS_COUNT];

    for (int i = 1; i <= caseIndex - 2; i++) {
        // [ PART_A ]
        // DP processing when current case is handled by `COP_A`
        dp[caseIndex][i] = dp[previousCase][i] + distanceFromPrevious;
        dpTrace[caseIndex][i].first = previousCase;
        dpTrace[caseIndex][i].second = i;

        // DP processing when current case is handled by `COP_B`
        dp[i][caseIndex] = dp[i][previousCase] + distanceFromPrevious;
        dpTrace[i][caseIndex].first = i;
        dpTrace[i][caseIndex].second = previousCase;

        // [ PART_B ]
        // find minimum when previous case was handled by `COP_A`, current by `COP_B`
        newDpValue[COP_A] = dp[i][previousCase] + distanceInbetween(i, caseIndex);

        if (newDpValue[COP_A] < dp[caseIndex][previousCase]) {
            dp[caseIndex][previousCase] = newDpValue[COP_A];
            dpTrace[caseIndex][previousCase].first = i;
        }

        // find minimnum when previous case was handled by `COP_B`, current by `COP_A`
        newDpValue[COP_B] = dp[previousCase][i] + distanceInbetween(i, caseIndex);

        if (newDpValue[COP_B] < dp[previousCase][caseIndex]) {
            dp[previousCase][caseIndex] = newDpValue[COP_B];
            dpTrace[previousCase][caseIndex].second = i;
        }
    }
}

pair < int, int > findDpAnswer(const int casesCount) {
    int minimumDistance[COPS_COUNT] = { INT_MAX, INT_MAX };
    pair < int, int > minimumDpPair[COPS_COUNT];
    minimumDpPair[COP_A].first = minimumDpPair[COP_B].second = casesCount;

    for (int i = 0; i < casesCount; i++) {
        // find minimum when last case was solved by `COP_A`
        if (dp[casesCount][i] < minimumDistance[COP_A]) {
            minimumDpPair[COP_A].second = i;
            minimumDistance[COP_A] = dp[casesCount][i];
        }

        // find minimum when last case was solved by `COP_B`
        if (dp[i][casesCount] < minimumDistance[COP_B]) {
            minimumDpPair[COP_B].first = i;
            minimumDistance[COP_B] = dp[i][casesCount];
        }
    }

    return (
        minimumDistance[COP_A] < minimumDistance[COP_B] ?
        minimumDpPair[COP_A] :
        minimumDpPair[COP_B]
        );
}

stack < int > buildTraceStack(pair < int, int > caseDpPair) {
    stack < int > result;

    /*
      Backtrace until
      either one of `COP_A` or `COP_B` reaches initial state (0)
      and the other cop reaches the first case (1).
      i.e. dp[0][1] or dp[1][0]
    */
    while (caseDpPair.first + caseDpPair.second != 1) {
        result.push(caseDpPair.first > caseDpPair.second ? COP_A + 1 : COP_B + 1);
        caseDpPair = dpTrace[caseDpPair.first][caseDpPair.second];
    }
    result.push(caseDpPair.first == 1 ? COP_A + 1 : COP_B + 1);

    return result;
}

void printTraceStack(stack < int >& result) {
    while (!result.empty()) {
        cout << result.top() << '\n';
        result.pop();
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    fill(_distancesFromCop[0], _distancesFromCop[0] + CASES_MAX, -1);
    fill(_distancesFromCop[1], _distancesFromCop[1] + CASES_MAX, -1);
    for (int i = 0; i < CASES_MAX; i++) {
        fill(_distanceInbetween[i], _distanceInbetween[i] + CASES_MAX, -1);
    }

    int n, cases, x, y;
    cin >> n;
    cin >> cases;

    COPS[COP_A] = make_pair(1, 1);
    COPS[COP_B] = make_pair(n, n);

    cin >> x >> y;
    caseLocations[1] = make_pair(x, y);

    // DP initial case
    dp[0][1] = distancesFromCop(COP_B, 1);
    dp[1][0] = distancesFromCop(COP_A, 1);

    for (int i = 2; i <= cases; i++) {
        cin >> x >> y;
        caseLocations[i] = make_pair(x, y);
        processDP(i);
    }

    const pair < int, int > finalCasePair = findDpAnswer(cases);
    cout << dp[finalCasePair.first][finalCasePair.second] << '\n';

    stack < int > traceStack = buildTraceStack(finalCasePair);
    printTraceStack(traceStack);

    return 0;
}
