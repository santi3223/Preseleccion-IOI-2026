//30 de marzo 2026 21:29
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define ed endl
#define vs vector<string>

bool reach(ll x1, ll y1, ll t1, ll x2, ll y2, ll t2){
	ll x = x1-x2, y = y1-y2, t = t1-t2;
	return x*x+y*y<=t*t;
}

int main(){
	ll n, m;
	cin >> n >> m;
	vector<pair<ll, pll>> graze(n);
	ff(i, 0, n){
		ll a,b,c;
		cin >> a >> b >> c;
		graze[i] = {c, {a, b}};
	}
	sort(all(graze));
	ll c = 0;
	ff(idd, 0, m){
		ll x, y, t;
		cin >> x >> y >> t;
		ll pos = upper_bound(all(graze), make_pair(t, make_pair(LLONG_MAX, LLONG_MAX))) - graze.begin();
		//cout << pos << ed;
		ll proof = 0;
		ff(i, pos-1, pos+1){
			if(i < 0 || i >= n){proof++; continue;}
			
			ll t2 = graze[i].fi, x2 = graze[i].se.fi, y2 = graze[i].se.se;
			proof += reach(x, y, t, x2, y2, t2);
		}
		c += (proof == 2);
		
	}
	cout << m-c;
	
}
