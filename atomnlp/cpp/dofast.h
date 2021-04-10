#pragma once 
// Containers
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;
#include "io.cpp"


#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define INF 0x3F3F3F3F
#define all(v) v.begin(), v.end()
#define MOD 1000000007
#define vt(T) vector<T>

#define loop(i, n) for (int i = 0; i <= n; i++)
#define loopup(i, a, b) for (int i = a; i <= b; i++)
#define loopdw(i, a, b) for (int i = a; i >= b; --i)
#define trav(e, C) for (auto &e : C)
#define len(v) (int)v.size()
#define PQ(type) priority_queue<type>
#define PQD(type) priority_queue<type, vector<type>, greater<type>>
#define US unordered_set
#define UM unordered_map

#define MEM(a, n) memset(a, (int)n, sizeof(a))
#define SUM(a) accumulate(a.begin(), a.end(), 0)             
#define QST(a) sort(a.begin(), a.end())                      
#define QSTD(a, type) sort(a.begin(), a.end(), greater<type>())
#define ones(n) __builtin_popcount(n)
#define bitlen(n) 32 - __builtin_clz32(n)


typedef std::map<int, int> mii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> pipii;
typedef vector<pair<int, int>> vpii;

template <class T> bool in(const T e, unordered_set<T> &s) { return s.count(e) > 0; }
template <class T> bool in(const T e, set<T> &s) { return s.count(e) > 0; }
template <class K, class V> bool in(const K e, unordered_map<K, V> &s) { return s.count(e) > 0; }
template <class K, class V> bool in(const K e, map<K, V> &s) { return s.count(e) > 0; }
template <class T> bool between(const T &x, const T a, const T b) { return a <= x && x <= b; }
template <class T> bool hollow(T &vec) { return vec.size() == 0; }
template <class T> void setmax(T &x, const T y) { x = max(x, y); }
template <class T> void setmin(T &x, const T y) { x = min(x, y); }

// More for fast coding 
#define itsize(_sz_, _v_) int _sz_ = _v_.size()

// Modify in-place
// void PSUM(vector<int> &a) { for(int i=1; i<a.size(); ++i) a[i] += a[i - 1]; }   
// void SSUM(vector<int> &a) { for(int i=a.size()-1; i>=0; --i) a[i] += a[i + 1]; }

int dirs[5] = {-1, 0, 1, 0, -1};

// fast IO
static auto _su_ = []() { ios::sync_with_stdio(false); cin.tie(0); return 0; }();
// -------------------------------------------------------- IO

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

// -------------------------------------------------------- String
// Manipulating string
void rstrip(string &str){ 
    str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
}

// -------------------------------------------------------- Number
string to_hex(int n) { 
    std::stringstream ss;
    ss << std::hex << n; 
    std::string res ( ss.str() );
    return res;
}

