//27 de Mayo 2026 15:09
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

pair<pll, pll> inter(pll a, pll b, pll c, pll d){
	pair<pll, pll> ans;
	ll l = max(min(a.fi, b.fi), min(c.fi, d.fi));
	ll r = min(max(a.fi, b.fi), max(c.fi, d.fi));
	ll u = min(max(a.se, b.se), max(c.se, d.se));
	ll dw = max(min(a.se, b.se), min(c.se, d.se));
	if(r <= l || u <= dw) return {{0, 0}, {0, 0}};
	return {{l, dw}, {r, u}};
	
}

ll area(pll a, pll b){
	return abs(a.fi-b.fi)*abs(a.se-b.se);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<pll> co(7);
	ff(i, 1, 7) cin >> co[i].fi >> co[i].se;
	pair<pll, pll> in1 = inter(co[1], co[2], co[3], co[4]);
	pair<pll, pll> in2 = inter(co[1], co[2], co[5], co[6]);
	pair<pll, pll> in3 = inter(in1.fi, in1.se, in2.fi, in2.se);
	
	ll ar = area(co[1], co[2]), ar1 = area(in1.fi, in1.se), ar2 = area(in2.fi, in2.se), minus = area(in3.fi, in3.se);
	//cout << ar << ' ' << ar1 << ' ' << ar2 << ' ' << minus << ed;
	if(ar-ar1-ar2+minus > 0) cout << "YES";
	else cout << "NO";
}
