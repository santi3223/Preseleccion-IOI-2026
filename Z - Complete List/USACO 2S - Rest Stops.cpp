//18 de Junio 2026 21:10
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back

int main(){
	freopen("reststops.in", "r", stdin);
	freopen("reststops.out", "w", stdout);
	
	ll l, n, f, b;
	cin >> l >> n >> f >> b;
	vector<pll> a(n);
	ff(i, 0, n){
		cin >> a[i].fi >> a[i].se;
	}
	vl track(n);
	ll id = 0, maxx = 0;
	for(ll i = n-1; i >= 0; i--){
		if(a[i].se > maxx){
			id = i;
			maxx = a[i].se;
		}
		track[i] = id;
	}
	
	ll c = 0;
	ll curtime = 0;
	ll i = 0, w = 0;
	while(i < n){
		i = track[i];
		ll dist = a[i].fi, rate = a[i].se;
		//cout << dist << ' ' << rate << ' ' << i << ed;
		ll aa = rate*((dist*f)-curtime), bb = rate*((dist*b)-curtime+w);
		//cout << aa << ' '<<  bb << ' ' << aa-bb << ed;
		//cout << rate << ' ' << dist*b << ' ' << curtime << ' ' << w << ed;
		c += aa-bb;	
		//cout << rate*((dist*f)-curtime)-rate*((dist*b)-curtime) << ed;
		w += (aa-bb)/rate;
		curtime = f*dist;
		//cout << curtime << ' ' << w << ed << ed;
		
		i++;
	}
	cout << c;
	
}
