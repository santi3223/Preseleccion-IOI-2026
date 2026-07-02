//1 de Julio 2026 19:01
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define ed "\n"
#define vb vector<bool>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second

int main(){
	ll n;
	cin >> n;
	vl xc(n), yc(n);
	vl north, east;
	ff(i, 0, n){
		char c;
		ll a, b;
		cin >> c >> a >> b;
		xc[i] = a;
		yc[i] = b;
		if(c == 'E') east.pb(i);
		else north.pb(i);
	}
	sort(all(north),
	[&](ll a, ll b){return xc[a] < xc[b];});
	sort(all(east),
	[&](ll a, ll b){return yc[a] < yc[b];});
	/*for(auto i : north) cout << i << ' ';
	cout << ed;
	for(auto i : east) cout << i << ' ';
	cout << ed;*/
	vb ok(n, 1);
	vl cou(n, 0);
	for(auto i : east){
		for(auto j : north){
			if(ok[j] && xc[i] < xc[j] && yc[i] > yc[j]){
				if(xc[j]-xc[i] < yc[i]-yc[j]){ //gano east
					ok[j] = false;
					cou[i] += cou[j]+1;
				}
				else if(xc[j]-xc[i] > yc[i]-yc[j]){
					ok[i] = false;
					cou[j] += cou[i]+1;
				}
			}
			if(!ok[i]) break;
		}
	}
	ff(i, 0, n) cout << cou[i] << ed;
}
