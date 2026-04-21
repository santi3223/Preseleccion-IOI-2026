//20 de Marzo 2026 15:58
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

vl t;

void update(ll i, ll l, ll r, ll pos, ll val){
	if(l == r){
		t[i] = max(t[i], val);
		return;
	}
	ll mid = (l+r)/2;
	if(pos <= mid) update(2*i+1, l, mid, pos, val);
	else update(2*i+2, mid+1, r, pos, val);
	t[i] = max(t[i*2+1], t[i*2+2]);
}

ll query(ll i, ll l, ll r, ll ql, ll qr){
	if(qr < l || r < ql) return 0;
	if(ql <= l && r <= qr) return t[i];
	ll mid = (l+r)/2;
	return max(query(2*i+1, l, mid, ql, qr), query(2*i+2, mid+1, r, ql, qr));
}

int main(){
	ll n;
	cin >> n;
	vl arr(n), h(n);
	ff(i, 0, n) cin >> h[i];
	ff(i, 0, n) cin >> arr[i];
	
	t = vl(4*n, 0);
	ff(i, 0, n){
		ll best = query(0, 0, n-1, 0, h[i]-1);
		ll dp = best+arr[i];
		update(0, 0, n-1, h[i], dp);
	}
	cout << query(0, 0, n-1, 0, n-1);
}
