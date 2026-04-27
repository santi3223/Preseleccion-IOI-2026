//21 de Abril 2026 20:59
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define pb push_back
#define vs vector<string>

ll n;
vl block, pblock, arr, parr, pparr, start;

vl psum(vl a){
	vl x = a;
	ff(i, 1, a.size()){
		x[i] = x[i-1]+a[i];
	}
	return x;
}

ll part(ll id, ll l, ll r){
	if(r <= l) return 0LL;
	ll c = r-l;
	ll res = 0;
	if(id != 0) res = parr[id-1]*c;
	ll sum = pparr[r-1];
	if(l != 0) sum -= pparr[l-1];
	return sum-res;
}

pll conv(ll i){
	ll id = upper_bound(all(start), i) - start.begin()-1;
	return {id, i-start[id]+id};
}

ll queries(ll l, ll r){
	pll ql = conv(l), qr = conv(r);
	ll ans = pblock[qr.fi];
	if(ql.fi != 0) ans -= pblock[ql.fi-1];
	ans -= part(ql.fi, ql.fi, ql.se);
	ans -= part(qr.fi, qr.se+1, n);
	return ans;
}

int main(){
	cin >> n;
	arr = vl(n);
	ff(i, 0, n) cin >> arr[i];
	parr = psum(arr);
	pparr = psum(parr);
	start = {0};
	for(ll i = n; i >= 1; i--){
		start.pb(start.back()+i);
	}
	block = vl(n);
	ff(i, 0, n){
		block[i] = part(i, i, n);
	}
	pblock = psum(block);
	
	ll qq;
	cin >> qq;
	while(qq--){
		ll l, r;
		cin >> l >> r;
		cout << queries(l-1, r-1) << ed;
	}
	
}
