#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cerr<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;
template<typename T>istream& operator>>(istream&i,v(T)&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v){stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,const v(T)&v){if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.fi<<","<<v.se;}
template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}
template<typename T>bool maxs(T& x,const T&y){if(x<y){x=y;return true;}else return false;}
template<typename T>ll suma(const v(T)&a){ll res(0);for(auto&&x:a)res+=x;return res;}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;


int main() {
  ll n, m; cin >> n >> m;
  vl a(n);
  cin >> a;

  sort(rng(a));
  reverse(rng(a));

  rep(i,n){
    cout << a[i] << " ";
  }cout << endl;

  vl b(n);
  rep(i,n) b[i] = a[n-1-i];

  vl wa(n,0);
  wa[0] = a[0];
  rep(i,n){
    if(i == 0) continue;
    wa[i] = a[i]+wa[i-1];
  }

  rep(i,n){
    cout << wa[i] << " ";
  }cout << endl;

  ll ans = 0;
  rep(i,n){
    ans += a[i]*2; m--;
    ll t = max(a[i+1]*2-a[i],(ll)0);
    cout << "t: " << t << endl;
    ll index = n-distance(b.begin(), lower_bound(rng(b),t))-1;
    cout << "i: " << i << " index: " << index << endl;
    if(m>=(index-i)*2){
      ans += ((wa[index]-wa[i])+(index-i)*a[i])*2;
      m -= (index-i)*2;
    }else{
      for(int j=i+1;j<=index; j++){
        if(m>=2){
          ans += (a[i]+a[j])*2;
          m -= 2;
        }else if(m == 1){
          ans += a[i]+a[j];
          m--;
        }
        if(m == 0) break;
      }
    }
    if(m == 0) break;
  }
  cout << ans << endl;
  return 0;
}