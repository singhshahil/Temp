
#define MOD      		1000000007
#define MOD1   			998244353
//Time:
#define debug2(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) \
    for ( \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second; \
        debug2("%s: %lld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
)
//debug:
void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
// #ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << "] = ["; _print(x)
// #else
// #define debug(x...)
// #endif
void line(ll x){while(x--){cout<<"-";}cout<<endl;}
template<typename T1,typename T2,typename T3>	//array
void arr_(T1 *a,T2 x,T3 y){ for(int i=x;i<=y;i++){ cout<<a[i]<<" ";} cout<<endl; }
template<typename T>	//queue
void queue_(queue<T> x){ while(!x.empty()){ T y=x.front(); x.pop(); debug(y); } line(20); }
template<typename T>	//stack
void stack_(stack<T> x){ while(!x.empty()){ T y=x.top(); x.pop(); debug(y); } line(20); }
template<typename T>	//priority_queue
void pqueue_(priority_queue<T> x){ while(!x.empty()){ T y=x.top(); x.pop(); debug(y); } line(20); }
template<typename T1,typename T2,typename T3,typename T4,typename T5>	//matrix
void arr2_(T1 *a,T2 x1,T3 x2,T4 y1,T5 y2){
	for(int i=x1;i<=x2;i++){
		for(int j=y1;j<=y2;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
//Generators:
// https://codeforces.com/blog/entry/58786
// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T1,typename T2> auto rng2(T1 a,T2 b){return a + rng() % (b - a + 1);}
//Functions:
void start(){
// #ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
// #endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);	// Remove in interactive problems
	// srand(time(NULL));	
}
 
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;	//https://codeforces.com/blog/entry/11080
//find_by_order(k) : returns an iterator to the k-th largest element (counting from zero)
//order_of_key(k) : number of elements in set that are strictly smaller than k
template<typename u,typename v> auto min(u a,v b){return a>b?b:a;}
template<typename u,typename v> auto max(u a,v b){return a<b?b:a;}
template<typename T> T power(T x,T y){if(y == 0){return 1;} T p = power(x, y/2); p = (p * p); return (y%2 == 0)? p : (x * p);}  
template<typename T> T powm(T x,T y,T m){T ans=1,r=1;x%=m;while(r>0&&r<=y){if(r&y){ans*=x;ans%=m;} r<<=1;x*=x;x%=m;}return ans;}   
template<typename T> T gcd(T a,T b) { if (b == 0){return a;} return gcd(b, a % b);}  
template<typename T> T lcm(T a,T b){T lar = max(a, b);T small = min(a, b);for (T i = lar; ; i += lar) { if (i % small == 0){ return i;} } }
template<typename T> T modinv(T a) { return powm(a, MOD-2); } //for prime
template<typename T> T mod(T a,T b){return ((a%b)+b)%b;}
template<typename T> T modsum(T a, T b, T m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
template<typename T> T modmul(T a, T b, T m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
template<typename T> T modmulf(T a,T b,T mod) {T res=0;a%= mod;while(b){if(b&1)res=(res+a)%mod;a=(2*a)%mod;b>>=1;}return res;}
template<typename T> T mod_sub(T a, T b, T m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
template<typename T> T mod_div(T a, T b, T m) {a = a % m; b = b % m; return (modmul(a, modinv(b, m), m) + m) % m;}  //only for prime m
template<typename T> T fact(T r){ T ans=1;while(r)ans=modmul(ans,r),r--;return ans; }
template<typename T> T invfact(T r){T ans=1;while(r)ans=modmul(ans,modinv(r)),r--; return ans;}
template<typename T> bool cmp1(const pair<T,T> &a, const pair<T,T> &b) {  return (a.ss<b.ss); }//sortbysec
template<typename T> bool cmp2(const pair<T,T> &a, const pair<T,T> &b) {  return (a.ff>b.ff); }//sortbydec
// void line(ll x){while(x--){cout<<"-";}cout<<endl;}
bool overflow(long double a, long double b){return a * b > 1e18 + 10;}
const long long N=(long long)(1e5+5);
const long long inf=(long long)(1e18);
void solve(int tc)
{
}
int main(){
	start();
	time__("solve"){
		int t=1;
		// cin>>t;
		for(int tc=1;tc<=t;tc++){	
			google(tc);
			solve(tc); 
		}
	}
        return 0;
}
