#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>

using namespace std; 

template <class T> void say(const T n) { cout << fixed << boolalpha << n << endl; };
template <class T> void say(const pair<T, T> &p) { cout << p.first << ", " << p.second << endl;}
template <class T> void say(const vector<T> &vt) { for (auto t : vt) cout << t << ", "; cout << endl;}
template <class T> void say(const unordered_set<T> &s) { for (auto i: s) cout << i << ", "; cout << endl; }
template <class T> void say(const set<T> &s) { for (auto i: s) cout << i << ", "; cout << endl; }
template <class K, class V> void say(const map<K, V> &m) { for (auto &[k, v]: m) cout << k << ", " << v << endl;}
template <class T> void say(vector<vector<T>> &vv) { 
    for (auto &v : vv){ 
        cout << "[" ; 
        for (int i=0; i< v.size(); ++i) { cout << v[i]; if (i < v.size() - 1) cout << ", " ;}
        cout << "]" << endl; 
    } 
}
template <class T> void say(vector<pair<T, T>> &vv) { for (auto v : vv) cout << v.first << ", " << v.second << endl;}
template <class T> void say(T a[], int n) { 
    cout << "["; 
    for (int i=0; i< n; i++) { cout << a[i]; if (i < n-1) cout << ", "; }
    cout << "]" << endl; 
}


// struct Node {
//   char val;
//   Node *left;
//   Node *right;
//   Node() : val(' '), left(nullptr), right(nullptr) {}
//   Node(char x) : val(x), left(nullptr), right(nullptr) {}
//   Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
// };


struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};