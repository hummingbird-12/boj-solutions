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
constexpr int MAX = 1'000'000'000;

class gostack {
private:
    stack < int > s;

public:
    gostack(int n) {
        s.push(n);
    }

    void num(int x) {
        s.push(x);
    }

    bool pop() {
        if (s.empty()) {
            return false;
        }
        s.pop();
        return true;
    }

    bool inv() {
        if (s.empty()) {
            return false;
        }
        const int top = s.top();
        s.pop();
        s.push(top * -1);
        return true;
    }

    bool dup() {
        if (s.empty()) {
            return false;
        }
        s.push(s.top());
        return true;
    }

    bool swp() {
        if (s.size() < 2) {
            return false;
        }
        const int first = s.top();
        s.pop();
        const int second = s.top();
        s.pop();
        s.push(first);
        s.push(second);
        return true;
    }

    bool add() {
        if (s.size() < 2) {
            return false;
        }
        const int first = s.top();
        s.pop();
        const int second = s.top();
        s.pop();
        if (abs(first + second) > MAX) {
            return false;
        }
        s.push(first + second);
        return true;
    }

    bool sub() {
        if (s.size() < 2) {
            return false;
        }
        const int first = s.top();
        s.pop();
        const int second = s.top();
        s.pop();
        if (abs(second - first) > MAX) {
            return false;
        }
        s.push(second - first);
        return true;
    }

    bool mul() {
        if (s.size() < 2) {
            return false;
        }
        const int first = s.top();
        s.pop();
        const int second = s.top();
        s.pop();
        if (llabs((long long)first * second) > MAX) {
            return false;
        }
        s.push(first * second);
        return true;
    }

    bool div() {
        if (s.size() < 2 || s.top() == 0) {
            return false;
        }
        const int first = s.top();
        s.pop();
        const int second = s.top();
        s.pop();
        s.push(second / first);
        return true;
    }

    bool mod() {
        if (s.size() < 2 || s.top() == 0) {
            return false;
        }
        const int first = s.top();
        s.pop();
        const int second = s.top();
        s.pop();
        s.push(second % first);
        return true;
    }

    int size() {
        return s.size();
    }

    int top() {
        return s.top();
    }
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    while (true) {
        string op;
        vector < pair < string, int > > operations;

        cin >> op;
        if (op == "QUIT") {
            break;
        }

        while (op != "END") {
            int par = 0;
            if (op == "NUM") {
                cin >> par;
            }
            operations.emplace_back(op, par);
            cin >> op;
        }

        int n, num;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> num;
            gostack gs = gostack(num);

            bool status = true;
            for (auto o : operations) {
                string& opr = o.first;
                if (!status) {
                    break;
                }

                if (opr == "NUM") {
                    gs.num(o.second);
                }
                else if (opr == "POP") {
                    status = gs.pop();
                }
                else if (opr == "INV") {
                    status = gs.inv();
                }
                else if (opr == "DUP") {
                    status = gs.dup();
                }
                else if (opr == "SWP") {
                    status = gs.swp();
                }
                else if (opr == "ADD") {
                    status = gs.add();
                }
                else if (opr == "SUB") {
                    status = gs.sub();
                }
                else if (opr == "MUL") {
                    status = gs.mul();
                }
                else if (opr == "DIV") {
                    status = gs.div();
                }
                else if (opr == "MOD") {
                    status = gs.mod();
                }
            }

            if (!status || gs.size() != 1) {
                cout << "ERROR\n";
            }
            else {
                cout << gs.top() << '\n';
            }
        }
        cout << '\n';
    }
    return 0;
}
