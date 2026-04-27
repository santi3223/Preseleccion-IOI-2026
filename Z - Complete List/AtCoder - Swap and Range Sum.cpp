//24 de Enero 2026 08:28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vb vector<bool>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define pb push_back
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define fi first
#define se second
#define pll pair<ll, ll>

vl T, arr;

void build(ll i, ll tl, ll tr) {
    if (tl == tr) {
        T[i] = arr[tl];
        return;
    }
    ll tm = (tl + tr) / 2;
    build(2 * i + 1, tl, tm);
    build(2 * i + 2, tm + 1, tr);
    T[i] = T[2 * i + 1] + T[2 * i + 2];
}
 
void update(ll i, ll tl, ll tr, ll idx, ll val) {
    if (tl == tr) {
        T[i] = val;
        return;
    }
    ll tm = (tl + tr) / 2;
    if(idx <= tm){
        update(2 * i + 1, tl, tm, idx, val);
    }
    else{
        update(2 * i + 2, tm + 1, tr, idx, val);
    }
    T[i] = T[2 * i + 1]+ T[2 * i + 2];
}
 
ll query(ll i, ll l, ll r, ll s, ll e){
    if (r < s || l > e) return 0;
    if (l >= s && r <= e) return T[i];
    ll m = (l + r) / 2;
    return query(2 * i + 1, l, m, s, e) + query(2 * i + 2, m + 1, r, s, e);
}

int main(){
	ll n, q;
	cin >> n >> q;
	T = vl(4*n, 0);
	arr = vl(n);
	ff(i, 0, n){
		cin >> arr[i];
	}
	build(0,0,n-1);
	while(q--){
		ll o;
		cin >> o;
		if(o == 1){
			ll x;
			cin >> x;
			x--;
			update(0, 0, n-1, x, arr[x+1]);
			update(0, 0, n-1, x+1, arr[x]);
			swap(arr[x], arr[x+1]);
		}
		else{
			ll l, r;
			cin >> l >> r;
			l--;
			r--;
			cout << query(0, 0, n-1, l, r) << ed;
		}
	}
}
