//3 de Abril 2026 23:09
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

vl ok(vl &arr){
	ll n = arr.size();
	priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> pq;
	ff(i, 0, n-1) pq.push({arr[i]+arr[i+1], {i, i+1}});
	vl ans;
	while(ans.size() != n-1){
		auto p = pq.top();
		ll val = p.fi, i = p.se.fi, j = p.se.se;
		pq.pop();
		ans.pb(val);
		if(j+1 < n) pq.push({arr[i]+arr[j+1], {i, j+1}});
	}
	return ans;
	
}

int main(){
	ll n;
	cin >> n;
	vl arr(n);
	ff(i, 0, n) cin >> arr[i];
	sort(all(arr));
	vl pw(n+5);
	pw[0] = 1;
	ff(i, 1, n) pw[i] = pw[i-1]*2%MOD;
	ll ans = 0;
	for(ll s = n-1; s >= 1; s--){
		ll minn = arr[0];
		ans = (ans+minn%MOD*pw[s])%MOD;
		for(auto &p : arr) p -= minn;
		arr = ok(arr);
	}
	ans = (ans+arr[0]%MOD)%MOD;
	cout << ans;
}
