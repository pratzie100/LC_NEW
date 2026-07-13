//------------------------------------------------------------------///*@CodingBoy100*/
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " = " << x << '\n'
using ll = long long;
// #define endl "\n"
#define F first
#define S second
#define pb push_back
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

// template<typename T1, typename T2>
// void out(const vp<T1,T2>& v){
//     for(const auto &[a,b] : v)
//         cout << a << ' ' << b << '\n';
// }
template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1,T2>& p){
    return os << '(' << p.first << ", " << p.second << ')';
}
template<typename Container>
void out(const Container& c){
    for(const auto &x : c)
        cout << x << ' ';
    cout << '\n';
}
template<typename T>
void out(const vector<vector<T>>& v){
    for(const auto &row:v)
        out(row);
}

//#define mod  1000000000000000007LL;  
// const ll mod2= 1000000000000000007LL;  
const ll INF = (1LL<<60);
const ll M= 1000000000000000007LL; 
const ll MOD = 1000000007LL;
const ll MOD2 = 998244353LL;

//------------------------------------------------------------------///*@CodingBoy100*/

class Solution {
public:
    char findTheDifference(string s, string t) {
        int n=sz(s);
        if(n==0) return t[0];

        um<char,int>m;
        each(x,t){
            m[x]++;
        }
        each(x,s){
            m[x]--;
            if(m[x]==0) m.erase(x);        
        }

        auto it=begin(m);
        return it->F;

    }
};