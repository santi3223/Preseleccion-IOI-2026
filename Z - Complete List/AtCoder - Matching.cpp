//20 de Marzo 2026 14:18
//DP contest
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
const ll MOD = 1e9+7;

int main(){
	ll n;
	cin >> n;
	vl arr(n);
	ff(i, 0, n){
		cin >> arr[i];
	}
	ll res = 0, o = (ll)1e16;
	vb single(n, true), alive(n, true);
	ff(id, 0, n-1){
		pll best = {n, n};
		ll cost = o;
		ff(l, 0, n){
			if(!alive[l]) continue;
			ll al = arr[l];
			ff(r, l+1, n){
				if(!alive[r]) continue;
				ll ar = arr[r];
				if(cost > al+ar){
					best = {l, r};
					cost = ar+al;
				}
				if(single[r]) break;
			}
		}
		ll l = best.fi, r = best.se;
		res += cost;
		arr[l] = cost;
		alive[r] = false;
		single[l] = false;
		single[r] = false;
	}
	cout << res;
	
}
