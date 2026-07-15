//------------------------------------------------------------------///*@CodingBoy100*/
#include <bits/stdc++.h>
using namespace std;
#define cerr cout

#ifndef ONLINE_JUDGE
//#define debug(x) cerr << #x << " = " << x << '\n'
template<typename T> void _debug(const T&);
template<typename A, typename B> void _debug(const pair<A,B>&);
template<typename T> void _debug(const vector<T>&);
template<typename T> void _debug(const deque<T>&);
template<typename T> void _debug(const set<T>&);
template<typename T> void _debug(const multiset<T>&);
template<typename T> void _debug(const unordered_set<T>&);
template<typename T> void _debug(const unordered_multiset<T>&);
template<typename K, typename V> void _debug(const map<K,V>&);
template<typename K, typename V> void _debug(const multimap<K,V>&);
template<typename K, typename V> void _debug(const unordered_map<K,V>&);
template<typename K, typename V> void _debug(const unordered_multimap<K,V>&);
template<typename T> void _debug(queue<T>);
template<typename T> void _debug(stack<T>);
template<typename T> void _debug(priority_queue<T>);
template<typename T> void _debug(priority_queue<T, vector<T>, greater<T>>);
template<typename T>void _debug(const T &x){ cerr << x; } 
inline void _debug(const string &s){ cerr << '"' << s << '"'; }
inline void _debug(const char *s){ cerr << '"' << s << '"'; }
inline void _debug(char c){ cerr << '\'' << c << '\''; }
inline void _debug(bool b){ cerr << (b ? "true" : "false"); }
template<typename A, typename B> void _debug(const pair<A,B> &p){ 
cerr << "(";_debug(p.first); cerr << ", "; _debug(p.second); cerr << ")"; }
template<typename T> void _debug(const vector<T> &v){
    cerr << "["; bool first = true;
    for(const auto &x : v){ if(!first) cerr << ", "; first = false; _debug(x); }
    cerr << "]"; }
template<typename T> void _debug(const deque<T> &v){
    cerr << "[";  bool first = true; 
    for(const auto &x : v){ if(!first) cerr << ", "; first = false; _debug(x); }
    cerr << "]"; }
template<typename T> void _debug(const set<T> &s){
    cerr << "{"; bool first = true;
    for(const auto &x : s){ if(!first) cerr << ", "; first = false; _debug(x); }
    cerr << "}"; }
template<typename T> void _debug(const multiset<T> &s){
    cerr << "{"; bool first = true;
    for(const auto &x : s){ if(!first) cerr << ", "; first = false; _debug(x); }
    cerr << "}"; }
template<typename T> void _debug(const unordered_set<T> &s){
    cerr << "{"; bool first = true;
    for(const auto &x : s){ if(!first) cerr << ", "; first = false; _debug(x); }
    cerr << "}"; }
template<typename T> void _debug(const unordered_multiset<T> &s){
    cerr << "{"; bool first = true;
    for(const auto &x : s){ if(!first) cerr << ", "; first = false; _debug(x); }
    cerr << "}"; }
template<typename K, typename V> void _debug(const map<K,V> &m){
    cerr << "{"; bool first = true;
    for(const auto &x : m){ if(!first) cerr << ", "; first = false; _debug(x); }
    cerr << "}"; }
template<typename K, typename V> void _debug(const multimap<K,V> &m){
    cerr << "{"; bool first = true;
    for(const auto &x : m){ if(!first) cerr << ", "; first = false; _debug(x); }
    cerr << "}"; }
template<typename K, typename V> void _debug(const unordered_map<K,V> &m){
    cerr << "{"; bool first = true;
    for(const auto &x : m){ if(!first) cerr << ", "; first = false; _debug(x); }
    cerr << "}"; }
template<typename K, typename V> void _debug(const unordered_multimap<K,V> &m){
    cerr << "{"; bool first = true;
    for(const auto &x : m){ if(!first) cerr << ", "; first = false; _debug(x); }
    cerr << "}"; }
template<typename T> void _debug(queue<T> q){
    cerr << "<"; bool first = true;
    while(!q.empty()){if(!first)cerr<<", "; first=false; _debug(q.front()); q.pop(); }
    cerr << ">"; }
template<typename T> void _debug(stack<T> s){
    vector<T> v; while(!s.empty()){ v.push_back(s.top()); s.pop(); } _debug(v); }
template<typename T> void _debug(priority_queue<T> pq){
    cerr << "<"; bool first = true;
    while(!pq.empty()){if(!first) cerr<<", "; first=false; _debug(pq.top()); pq.pop(); }
    cerr << ">"; }
template<typename T> void _debug(priority_queue<T, vector<T>, greater<T>> pq){
    cerr << "<"; bool first = true;
    while(!pq.empty()){if(!first) cerr<<", "; first=false; _debug(pq.top()); pq.pop(); }
    cerr << ">"; }
#define debug(x) cerr << #x << " = ", _debug(x), cerr << '\n'
#else
#define debug(x)
#endif

using ll = long long; 
#define endl "\n"
#define F first
#define S second
#define pb push_back
#define tc int t; cin>>t; while(t--)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(x) ((int)(x).size())
#define lb lower_bound
#define ub upper_bound

#define p(x) cout << x
#define sp cout << ' '
#define pln(x) cout << x << '\n'
#define ln cout << '\n'

#define f(i,a,b) for(int i=(a); i<(b); i++)
#define fr(i,a,b) for(int i=(a); i>=(b); i--)
#define fx(i,a,b,x) for(int i=(a); i<(b); i+=(x))
#define frx(i,a,b,x) for(int i=(a); i>=(b); i-=(x))
#define fit(it,c) for(auto it=(c).begin(); it!=(c).end(); it++)
#define frit(it,c) for(auto it=(c).rbegin(); it!=(c).rend(); it++)
#define each(x,v) for(auto &x : v)

using vi = vector<int>;
using vc = vector<char>;
using vs = vector<string>;
using vll = vector<ll>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> using vv = vector<vector<T>>;
template<typename T> using pq = priority_queue<T>;
template<typename T> using minpq = priority_queue<T,vector<T>,greater<T>>;
template<typename T> using st = stack<T>;
template<typename T> using q = queue<T>;
template<typename T> using dq = deque<T>;
template<typename T> using us = unordered_set<T>;
template<typename K, typename V> using um = unordered_map<K,V>;
template<typename T1, typename T2> using vp = vector<pair<T1,T2>>;

template<typename T> void rev(T& c){ reverse(all(c)); }
template<typename T> void srt(T& c){ sort(all(c)); }
template<typename T> void rsrt(T& c){ sort(rall(c)); }
template<typename T>  long long accum(const vector<T>& v){ return accumulate(all(v), 0LL); }
template<typename T> T maxele(const vector<T>& v){ return *max_element(all(v)); }
template<typename T> T minele(const vector<T>& v){ return *min_element(all(v)); }
template<typename T> void uniq(vector<T>& v){ srt(v); v.erase(unique(all(v)), v.end()); }

// ll mygcd(ll a,ll b){return b?mygcd(b,a%b):a;}   //__gcd(a,b)
// ll mylcm(ll a, ll b) {return a/mygcd(a,b)*b;}
template<typename T> T gcd(T a, T b){ return std::gcd(a, b); }
template<typename T> T lcm(T a, T b){ return std::lcm(a, b); }
template<typename T>bool chmax(T &a,const T &b){ if(b>a){ a=b; return true; } return false; }
template<typename T>bool chmin(T &a,const T &b){ if(b<a){ a=b; return true; } return false; }
template<typename T> bool inside(T x,T y,T n,T m){ return x>=0 && x<n && y>=0 && y<m;}

template<typename T1, typename T2> ostream& operator<<(ostream& os, const pair<T1,T2>& p){
    return os << '(' << p.first << ", " << p.second << ')';
}
template<typename Container> 
void out(const Container& c){
    for(const auto &x : c) cout << x << ' ';
    cout << '\n'; }
template<typename T> 
void out(const vv<T>& v){ 
for(const auto &row:v)  out(row);}

//------------------------------------------------------------------///*@CodingBoy100*/

//#define mod  1000000000000000007LL;  
// const ll mod2= 1000000000000000007LL;  
const ll INF = (1LL<<60);
const ll M= 1000000000000000007LL; 
const ll MOD = 1000000007LL;
const ll MOD2 = 998244353LL;

class NumArray {
private:
    vi arr;
    vi pre;
public:
    NumArray(vector<int>& nums) {
        int n=sz(nums);

        arr.resize(n);
        arr=nums;

        pre.resize(n);

        pre[0]=arr[0];
        f(i,1,n){
            pre[i]=arr[i]+pre[i-1];
        }


    }
    
    int sumRange(int left, int right) {
        if(left==0){
            return pre[right];
        }
        else{

            return pre[right]- pre[left-1];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */