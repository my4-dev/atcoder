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

const int MAX_N = 1000100;

int main() {

  vector<int> c;
  int cnt = 1;
  while(cnt*(cnt+1)*(cnt+2)/6 < MAX_N){
    int res = cnt*(cnt+1)*(cnt+2)/6;
    c.push_back(res);
    cnt++;
  }
  int cn = c.size();

  vp ans;

  while(true){
    int n; cin >> n;
    if(n == 0) break;

    int dp[cn][n+1], dp2[cn][n+1];
    rep(i,n+1) dp[0][i] = i, dp2[0][i] = i;

    rep(i,cn){
      if(i == 0) continue;
      rep(j,n+1){
        if(j<c[i]) dp[i][j] = dp[i-1][j], dp2[i][j] = dp2[i-1][j];
        else{
          dp[i][j] = min(dp[i-1][j],min(dp[i][j-c[i]]+1, dp[i-1][j-c[i]]+1));
          if(c[i] % 2 == 1){
            dp2[i][j] = min(dp2[i-1][j],min(dp2[i][j-c[i]]+1, dp2[i-1][j-c[i]]+1));
          }else{
            dp2[i][j] = dp2[i-1][j];
          }
        }
      }
    }
    ans.push_back(make_pair(dp[cn-1][n],dp2[cn-1][n]));
  }

  for(auto res: ans){
    cout << res.first << " " << res.second << endl;
  }
  return 0;
}
