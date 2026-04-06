//24 de Marzo 2026 22:33
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
	ll n, m, q;
	cin >> n >> m >> q;
	vl a(n), b(m);
	ff(i, 0, n){
		cin >> a[i];
	}
	ff(i, 0, m){
		cin >> b[i];
	}
	
	vl odd(m), even(m);
	ff(i, 0, m){
		if(i % 2 != 0) odd[i] = b[i];
		else even[i] = b[i];
		if(i > 0) odd[i] += odd[i-1], even[i] += even[i-1];
	}
	vl seg(m-n+1);
	ff(i, 0, m-n+1){
		ll seven = even[i+n-1]-(i != 0 ? even[i-1] : 0);
		ll sodd = odd[i+n-1]-(i != 0 ? odd[i-1] : 0);
		if(i % 2 != 0) seg[i] = sodd-seven;
		else seg[i] = seven-sodd;
	}
	sort(all(seg));
	ll sum = 0;
	ff(i, 0, n) sum += (i % 2 != 0 ? -a[i] : a[i]);
	
	auto query = [&](auto it){
		auto loc = it;
		if(loc == seg.end())cout << llabs(*(prev(loc)) - sum) << ed;
		else{
			ll ans = *loc-sum;
			if(loc != prev(seg.end())) ans = min(ans, llabs(*(next(loc))-sum));
			if(loc != seg.begin()) ans = min(ans, llabs(*(prev(loc))-sum));
			cout << ans << ed;
		}
	};
	
	query(lower_bound(all(seg), sum));
	
	while(q--){
		ll l, r, v;
		cin >> l >> r >> v;
		if((r-l+1) % 2 != 0){
			if(l % 2 != 0) sum += v;
			else sum -= v;
		}
		query(lower_bound(all(seg), sum));
	}
}
