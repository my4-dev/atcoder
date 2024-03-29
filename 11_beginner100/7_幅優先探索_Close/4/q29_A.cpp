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

const int mve_h[4] = {-1,0,1,0};
const int mve_w[4] = {0,1,0,-1};

int main() {
  int h, w; cin >> h >> w;
  int sw,sh;cin>>sh>>sw;--sw,--sh;
  int gw,gh;cin>>gh>>gw;--gw,--gh;
  int c[h][w];
  rep(i,h){
    rep(j,w){
      char moji; cin >> moji;
      if(moji == '#') c[i][j] = 1;
      else c[i][j] = 0;
    }
  }

  int dis[h][w];
  rep(i,h)rep(j,w)dis[i][j] = INF;

  dis[sh][sw] = 0;
  queue<P> q;
  q.push(make_pair(sh,sw));

  while(!q.empty()){
    int uh = q.front().first;
    int uw = q.front().second;
    q.pop();
    rep(i,4){
      int vh = uh+mve_h[i];
      int vw = uw+mve_w[i];
      if(vh<0||vw<0||vh>=h||vw>=w) continue;
      if(dis[vh][vw] == INF && c[vh][vw] == 0){
        dis[vh][vw] = dis[uh][uw]+1;
        q.push(make_pair(vh,vw));
      }
    }
  }
  cout << dis[gh][gw] << endl;
  return 0;
}
