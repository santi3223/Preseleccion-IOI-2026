//22 de Julio 2026 17:36
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vb vector<bool>
#define pll pair<ll, ll>
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second

vl T, a, A, B;

void build(ll i, ll l, ll r){
	if(l == r){
		T[i] = a[l];
		return;
	}
	ll mid = (l+r)/2;
	build(2*i+1, l, mid);
	build(2*i+2, mid+1, r);
	T[i] = T[2*i+1]+T[2*i+2];
}

ll rang(ll l, ll r){
	return (r*(r+1)/2)-(l*(l-1)/2);
}

void unlazy(ll i, ll l, ll r){
	if(A[i] == 0 && B[i] == 0) return;
	T[i] += A[i]*rang(l, r);
	T[i] += B[i]*(r-l+1);
	if(l != r){
		A[2*i+1] += A[i];
		A[2*i+2] += A[i];
		
		B[2*i+1] += B[i];
		B[2*i+2] += B[i];
	}
	A[i] = 0;
	B[i] = 0;
}

void update(ll i, ll tl, ll tr, ll l, ll r){
	if(tr < l || r < tl) return;
	if(l <= tl && tr <= r){
		A[i]++;
		B[i] += 1-l;
		unlazy(i, tl, tr);
		return;
	}
	ll mid = (tl+tr)/2;
	update(2*i+1, tl, mid, l, r);
	update(2*i+2, mid+1, tr, l, r);
	
	unlazy(2*i+1, tl, mid);
	unlazy(2*i+2, mid+1, tr);
	T[i] = T[2*i+1]+T[2*i+2];
}

ll query(ll i, ll tl, ll tr, ll l, ll r){
	if(tr < l || r < tl) return 0;
	unlazy(i, tl, tr);
	if(l <= tl && tr <= r){
		return T[i];
	}
	ll mid = (tl+tr)/2;
	return query(2*i+1, tl, mid, l, r)+query(2*i+2, mid+1, tr, l, r);
}

int main(){
	ll n, q;
	cin >> n >> q;
	a = vl(n);
	ff(i, 0, n) cin >> a[i];
	T = vl(4*n, 0);
	A = B = T;
	build(0, 0, n-1);
	while(q--){
		ll o, l, r;
		cin >> o >> l >> r;
		l--;
		r--;
		if(o == 1) update(0, 0, n-1, l, r);
		else cout << query(0, 0, n-1, l, r) << ed;
	}
}
