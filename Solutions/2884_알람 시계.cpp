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

class Time {
private:
    short _hour;
    short _minute;

    int _inMinutes() {
        return this->_hour * 60 + this->_minute;
    }

public:
    Time(short hour, short minute) {
        this->_hour = hour;
        this->_minute = minute;
    }

    Time substract(int minutesToSubstract) {
        const int inMinutes = this->_inMinutes() + 15;
        return Time((inMinutes / 60 + 23) % 24, inMinutes % 60);
    }

    void printTime() {
        cout << this->_hour << ' ' << this->_minute << '\n';
    }
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int hour, minute;
    cin >> hour >> minute;

    Time alarm = Time(hour, minute).substract(45);
    alarm.printTime();

    return 0;
}
