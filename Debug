// Debug
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
