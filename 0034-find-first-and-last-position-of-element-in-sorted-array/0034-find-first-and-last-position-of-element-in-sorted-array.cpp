//------------------------------------------------------------------///*@CodingBoy100*/
#include <bits/stdc++.h>
using namespace std;
#define cerr cout

#ifndef ONLINE_JUDGE
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

inline void _debug(const string &s){ cerr << '"' << s << '"'; }
inline void _debug(const char *s){ cerr << '"' << s << '"'; }
inline void _debug(char c){ cerr << '\'' << c << '\''; }
inline void _debug(bool b){ cerr << (b ? "true" : "false"); }
inline void _debug(float x){auto p=cerr.precision();cerr<<setprecision(7)<<x;cerr.precision(p);}
inline void _debug(double x){auto p=cerr.precision();cerr<<setprecision(15)<<x;cerr.precision(p);}
inline void _debug(long double x){auto p=cerr.precision();cerr<<setprecision(18)<<x;cerr.precision(p);}

template<typename T>void _debug(const T &x){ cerr << x; } 
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

// #define debug(x) cerr << #x << " = ", _debug(x), cerr << '\n'
void _debug_names(const char*) {}
template<typename T, typename... Rest>
void _debug_names(const char* names, const T& value, const Rest&... rest)
{
    while(*names==' ') names++;
    const char* comma = strchr(names, ',');
    if(comma==nullptr) {
        cerr.write(names,strlen(names)); cerr<<" = "; _debug(value); cerr<<'\n'; return; }
    cerr.write(names, comma-names); cerr << " = "; _debug(value); cerr << '\n';
    _debug_names(comma+1, rest...);
}
#define debug(...) _debug_names(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#endif

using ll = long long; 
using ull = unsigned long long;
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
template<typename T> vector<T> pref(const vector<T>& v){
    vector<T> pre(v.size()); partial_sum(all(v), pre.begin()); return pre; }
template<typename T> vector<T> suff(const vector<T>& v){
    vector<T> suf(v.size()); partial_sum(rall(v), suf.rbegin()); return suf; }

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

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        // int n=sz(nums);

        // int l=0;
        // int h=n-1;
        // int ans1=-1;
        // int mini=INT_MAX;
        // while(l<=h){
        //     int mid= l+(h-l)/2;
        //     if(nums[mid]<target){
        //         l=mid+1;
        //     }
        //     else if(nums[mid]> target){
        //         h=mid-1;
        //     }
        //     else{
        //         mini=min(mini,mid);
        //         h=mid-1;
        //     }
        // }
        // if(mini!=INT_MAX){
        //     ans1=mini;
        // }

        // int low=0;
        // int high=n-1;
        // int ans2=-1;
        // int maxi=INT_MIN;
        // while(low<=high){
        //     int mid=low+(high-low)/2;
        //     if(nums[mid]<target){
        //         low=mid+1;
        //     }
        //     else if(nums[mid]>target){
        //         high=mid-1;
        //     }
        //     else{
        //         maxi=max(maxi,mid);
        //         low=mid+1;
        //     }
        // }
        // if(maxi!=INT_MIN) ans2=maxi;

        // return {ans1,ans2};



//  int n=sz(nums);

//         int l=0;
//         int h=n-1;
//         int ans1=-1;

//         while(l<=h){
//             int mid= l+(h-l)/2;
//             if(nums[mid]<target){
//                 l=mid+1;
//             }
//             else if(nums[mid]> target){
//                 h=mid-1;
//             }
//             else{
//                 ans1=mid;
//                 h=mid-1;
//             }
//         }

//         int low=0;
//         int high=n-1;
//         int ans2=-1;

//         while(low<=high){
//             int mid=low+(high-low)/2;
//             if(nums[mid]<target){
//                 low=mid+1;
//             }
//             else if(nums[mid]>target){
//                 high=mid-1;
//             }
//             else{
//                 ans2=mid;
//                 low=mid+1;
//             }
//         }
//         return {ans1,ans2};



//  int n=sz(nums);
// // if(n==0) return {-1,-1};
//         int l=0;
//         int h=n-1;


//         while(l<=h){
//             int mid= l+(h-l)/2;
//             if(nums[mid]<target){
//                 l=mid+1;
//             }
//             else if(nums[mid]> target){
//                 h=mid-1;
//             }
//             else{
//                 h=mid-1;
//             }
//             debug(l,h);
//         }
//         //h is now at l-1;
//         //our starting index, if present, will be at l
//         //otherwise it will go out of bounds so check both
//         debug(l,h);
//         int ans1=(l>=0 && l<=n-1 && nums[l]==target) ? l : -1;
// debug(ans1);
//         int low=0;
//         int high=n-1;

//         while(low<=high){
//             int mid=low+(high-low)/2;
//             debug(mid);
//             if(nums[mid]<target){
//                 low=mid+1;
//             }
//             else if(nums[mid]>target){
//                 high=mid-1;
//             }
//             else{
               
//                 low=mid+1;
//             }
//                debug(low,high);
//         }

//       //high is again at low-1;  lol
//       //but careful of high=-1;
//         //our ending index, if present, will be at high
//         //otherwise it will go out of bounds so check both
        
//         int ans2=(high>=0 && high<=n-1 && nums[high]==target) ? high : -1;

//         return {ans1,ans2};




        auto it1= lb(all(nums),target);
        int idx1= it1-begin(nums);
        
        // Finding the first occurrence using lower_bound is safe from underflow. Because it looks for elements >= target, the lowest iterator it can return is begin(nums). Since we check the element at exactly idx1, we only need to guard against overflow (going off the right cliff) by checking it1 != end(nums).

        int ans1= (it1!=end(nums) && nums[idx1]==target)? idx1: -1;

        auto it2= ub(all(nums),target);
        int idx2= it2-begin(nums);
   
        // Finding the last occurrence using upper_bound requires caution. Because it looks for elements strictly > target, the actual target will live  at one index prior (idx2 - 1). 
        // Even if upper_bound returns end(nums), stepping back by 1 is completely safe. However, if the target is smaller than every element in the array, upper_bound returns begin(nums). Accessing idx2 - 1 here would cause an underflow crash.
        // Therefore, we must explicitly guard against the left cliff: it2 != begin(nums).

        int ans2= (it2!=begin(nums) && nums[idx2-1]==target)? idx2-1: -1;
        return {ans1,ans2};
    }
};