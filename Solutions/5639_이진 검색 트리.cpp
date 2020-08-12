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

class node {
public:
    int num;
    node* left;
    node* right;

    node(int n) {
        num = n;
        left = NULL;
        right = NULL;
    }
};

class binary_search_tree {
    node* root;

    void post_search(node* current) {
        if (current == NULL) {
            return;
        }

        post_search(current->left);
        post_search(current->right);
        cout << current->num << '\n';
    }

public:
    binary_search_tree(int n) {
        root = NULL;
    }

    void insert(int n) {
        node* cur = root;
        node* new_node = new node(n);

        if (root == NULL) {
            root = new_node;
            return;
        }

        while (true) {
            if (n < cur->num) {
                if (cur->left == NULL) {
                    cur->left = new_node;
                    break;
                }
                cur = cur->left;
            }
            else {
                if (cur->right == NULL) {
                    cur->right = new_node;
                    break;
                }
                cur = cur->right;
            }
        }
    }

    void start_post_search() {
        post_search(root);
    }
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    binary_search_tree bst = binary_search_tree(10000);

    int inp;
    while (cin >> inp) {
        bst.insert(inp);
    }

    bst.start_post_search();

    return 0;
}
