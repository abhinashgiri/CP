#include "bits/stdc++.h"
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define PI (2*acos(0.0))
#define sz(x)           ( (ll) (x).size())
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define pos_rt_stbt(x)   (__builtin_ffsll(x))   // return position of rightmost set bit ( 1 indexing ) pos_rt_stbt(10) = 2 ( 1010 )
#define ps(x,y)         fixed<<setprecision(y)<<x
#define w(test)            int test; cin>>test; while(test--)
#define nl "\n"
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
#define all(v) (v).begin(),(v).end()
#define clr(v) memset(v,0,sizeof(v));
#define sqr(x) ((x) * (x))
typedef long long int  ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef pair<ll, ll> pll;
typedef vector<pair<ll, ll>> vpll;
typedef vector<vpll>vvpll;
const long long int inf = 1e17;
const long long int mod = 1e9 + 7;
const long long int MOD =  998244353;
//----------------------------------------------------------------------------------------------------------------------
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; }; sim > rge<c> range(c i, c j) { return rge<c> {i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0); sim > char dud(...);
struct debug {
#ifdef ABHI
    eni( != ) cerr << boolalpha << i; ris;
    }
    eni( == ) ris << range(begin(i), end(i));
    }
    sim, class b dor(pair < b, c > d) {ris << "(" << d.first << ", " << d.second << ")";}
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wstring-plus-int"
    sim dor(rge<c> d) {*this << "["; for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it; ris << "]";}
#pragma clang diagnostic pop
#else
    sim dor(const c&) { ris; }
#endif
};
vector<char*> tokenizer(const char* args) {
    char *token = new char[111]; strcpy(token, args); token = strtok(token, ", ");
    vector<char*> v({token});
    while ((token = strtok(NULL, ", "))) v.push_back(token);
    return reverse(v.begin(), v.end()), v;
}
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"
void debugg(vector<char*> args) { cerr << "\b\b "; }
#pragma clang diagnostic pop
template <typename Head, typename... Tail>
void debugg(vector<char*> args, Head H, Tail... T) {
    debug() << " [" << args.back() << ": " << H << "] ";
    args.pop_back(); debugg(args, T...);
}
#define harg(...) #__VA_ARGS__
#ifdef ABHI
#define deb(...) { debugg(tokenizer(harg(__VA_ARGS__, \b\t-->Line)), __VA_ARGS__, __LINE__); cerr << endl;}
#else
#define deb(...) { }
#endif
/// --------------------------------------------------------------------------------------------------------------------

#define ptvs(v) for(auto &item :v) cout<<item<<" ";cout<<"\n";
#define pt(x) cout<<((x))<<"\n";
#define pt2(x,y) cout<<(x)<<" "<<(y)<<"\n";
#define cinvll(v,start,end) vll v(end+1);for(auto i=start;i<=end;i++) {cin>>v[i];}
//***********************************************************************************************
// Fast Exponentiation power(a,b) ==> a to the power b
template <typename T>
T  power(T  a, T  b) {
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    else {
        T  res = (power(a, b / 2));
        if (b % 2){
            return (res * 1LL * res * 1LL * a);
        }
        else{
            return res * 1LL *  res;
        }
    }
}

// Fast Modular Exponentiation  power(a,b,m) ==> (a to the power b) modulo m
template <typename T>
long long power(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// G C D
template <typename T>
T  gcd(T  a, T  b) {
    if (b == 0)
    {return a;}
    return gcd(b, a % b);
}

inline ll ceil(ll a, ll b) {    return a / b + (a % b == 0 ? 0 : 1);  }

void factorial(vll &fact, ll n){
    fact.resize(n + 1, 1);
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i <= n ; ++i){
        fact[i] = ((fact[i - 1] % mod) * (i % mod)) % mod;
    }
}

ll mod_inv(ll a) {    return (power<ll>(a, mod - 2, mod)) % mod;    }

ll ncr(ll n, ll r, vll &fact){
    if (r > n or n < 0 or r < 0) return 0LL;
    return  (((fact[n] % mod) * (mod_inv(fact[n - r]) % mod)) % mod * (mod_inv(fact[r]) % mod)) % mod;
}

ll NCR(ll n, ll r, vll &fact, vll &inv){
    if (r > n or n < 0 or r < 0) return 0LL;
    return  (((fact[n] % mod) * (inv[n - r]) )) % mod * (inv[r]) % mod;
}

void modI(vll &inv, ll n, vll &fact){
    inv.resize(n + 1, 1);
    inv[n] = mod_inv(fact[n]);
    for (int i = n - 1; i >= 0 ; --i){
        inv[i] = ((inv[i + 1]) % mod * ((i + 1)  % mod)) % mod;
    }
}

template <int MOD_> struct modnum {
    static constexpr int MOD = MOD_;
    static_assert(MOD_ > 0, "MOD must be positive");

private:
    using ll = long long;

    int v;
    static int minv(int a, int m) {
        a %= m;
        assert(a);
        return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
    }

public:

    modnum() : v(0) {}
    modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
    explicit operator int() const { return v; }
    friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
    friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }

    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

    modnum pow(modnum a, long long b) {
        assert(b >= 0);
        modnum r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
    }
    modnum inv() const {
        modnum res;
        res.v = minv(v, MOD);
        return res;
    }
    friend modnum inv(const modnum& m) { return m.inv(); }
    modnum neg() const {
        modnum res;
        res.v = v ? MOD - v : 0;
        return res;
    }
    friend modnum neg(const modnum& m) { return m.neg(); }

    modnum operator- () const {
        return neg();
    }
    modnum operator+ () const {
        return modnum(*this);
    }

    modnum& operator ++ () {
        v ++;
        if (v == MOD) v = 0;
        return *this;
    }
    modnum& operator -- () {
        if (v == 0) v = MOD;
        v --;
        return *this;
    }
    modnum& operator += (const modnum& o) {
        v -= MOD - o.v;
        v = (v < 0) ? v + MOD : v;
        return *this;
    }
    modnum& operator -= (const modnum& o) {
        v -= o.v;
        v = (v < 0) ? v + MOD : v;
        return *this;
    }
    modnum& operator *= (const modnum& o) {
        v = int(ll(v) * ll(o.v) % MOD);
        return *this;
    }
    modnum& operator /= (const modnum& o) {
        return *this *= o.inv();
    }

    friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
    friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};
using mint = modnum<mod>;



int main(){
    fast;
    int T;
    cin>>T;
    for (int test = 1; test <=T ; ++test){
        ll ans=0;







        cout << "Case #" << test << ": " << ans << "\n";
    }


}
