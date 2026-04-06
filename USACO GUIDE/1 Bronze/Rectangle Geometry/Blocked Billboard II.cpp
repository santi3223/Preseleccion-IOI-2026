/*
19 de Febrero 2026 17:29
El problema esta mal para una variante del input 4, o sea q si fuera cf se podría hackear
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define pb push_back
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define vs vector<string>
#define ed "\n"

pair<pll, pll> inter(pll a, pll b, pll c, pll d){
	ll lef = max(min(a.fi, b.fi), min(c.fi, d.fi));
	ll rig = min(max(a.fi, b.fi), max(c.fi, d.fi));
	ll up = min(max(a.se, b.se), max(c.se, d.se));
	ll dow = max(min(a.se, b.se), min(c.se, d.se));
	//cout << lef << " " << rig << " " << up<< " " << dow << ed;
	if(rig <= lef || up <= dow) return {{0, 0}, {0, 0}};
	return {{lef, dow}, {rig, up}};
	
}

ll area(pll a, pll b){
	//cout << "AREA " << a.fi << " " << a.se << " " << b.fi << " " << b.se << ed;
	return (abs(a.fi-b.fi)*abs(a.se-b.se));
}

int main(){
	freopen("billboard.in","r",stdin);
	freopen("billboard.out","w",stdout);
	vector<pll> arr(4);
	ff(i, 0, 4){
		cin >> arr[i].fi >> arr[i].se;
	}
	pair<pll, pll> in1 = inter(arr[0], arr[1], arr[2], arr[3]);
	ll hor = arr[1].fi-arr[0].fi, vert = arr[1].se-arr[0].se;
	ll x = hor, y = vert;
	ll ar1 = area(in1.fi, in1.se);
	if(in1.fi.fi == arr[0].fi && in1.se.fi == arr[1].fi && (in1.fi.se == arr[0].se || in1.se.se == arr[1].se)){
		y -= ar1/hor;
	}
	if(in1.fi.se == arr[0].se && in1.se.se == arr[1].se && (in1.fi.fi == arr[0].fi || in1.se.fi == arr[1].fi)){
		x -= ar1/vert;
	}
	
	cout << x*y;
}
