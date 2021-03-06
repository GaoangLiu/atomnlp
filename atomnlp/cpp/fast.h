// Containers
#include <deque>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <vector>
#include <iostream>
#include <numeric>

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define INF 0x3F3F3F3F
#define all(v) v.begin(), v.end()
#define MOD 1000000007
#define vt(T) vector<T>

#define FOR(i, n) for (int i = 0; i <= n; i++)
#define FORUP(i, a, b) for (int i = a; i <= b; i++)
#define FORDN(i, a, b) for (int i = a; i >= b; --i)
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

typedef std::map<int, int> MII;
typedef std::vector<int> VI;
typedef std::vector<std::string> VS;
typedef std::vector<std::vector<int>> VVI;
typedef std::pair<int, int> PII;
typedef std::pair<int, std::pair<int, int>> PIPII;
typedef std::vector<std::pair<int, int>> VPII;

template <class T> bool in(const T e, std::unordered_set<T> &s) { return s.count(e) > 0; }
template <class T> bool in(const T e, std::set<T> &s) { return s.count(e) > 0; }
template <class K, class V> bool in(const K e, std::unordered_map<K, V> &s) { return s.count(e) > 0; }
template <class K, class V> bool in(const K e, std::map<K, V> &s) { return s.count(e) > 0; }
template <class T> bool between(const T &x, const T a, const T b) { return a <= x && x <= b; }
template <class T> bool hollow(T &vec) { return vec.size() == 0; }
template <class T> void setmax(T &x, const T y) { x = max(x, y); }
template <class T> void setmin(T &x, const T y) { x = min(x, y); }

// More for fast coding 
#define itsize(_sz_, _v_) int _sz_ = _v_.size()

// Modify in-place
// void PSUM(vector<int> &a) { for(int i=1; i<a.size(); ++i) a[i] += a[i - 1]; }   
// void SSUM(vector<int> &a) { for(int i=a.size()-1; i>=0; --i) a[i] += a[i + 1]; }

using namespace std;
int dirs[5] = {-1, 0, 1, 0, -1};

// fast IO
static auto _su_ = []() { std::ios::sync_with_stdio(false); std::cin.tie(0); return 0; }();
// --------------------------------------------------------
