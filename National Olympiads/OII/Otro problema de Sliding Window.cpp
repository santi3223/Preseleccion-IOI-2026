//3 de Junio 2026 14:17
#include <bits/stdc++.h>
using namespace std;
#define ll int
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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, k;
	cin >> n >> k;
	vl arr(n);
	ff(i, 0, n) cin >> arr[i];
	vl pos(n);
	ll pr = n-1;
	ll piv = -1;
	ff(i, 0, n){
		while(arr[pr]+arr[i] > k && pr >= 0) pr--;
		pos[i] = pr;
		if(piv != -1){
			pos[i] = min(pos[i], pos[i-1]-1);
		}
		if(piv == -1 && i >= pr) piv = i;
	}
	ll q;
	cin >> q;
	while(q--){
		ll l, r;
		cin >> l >> r;
		l--;
		r--;
		if(arr[r] > k){
			cout << 0;
			continue;
		}
		if((l+r-1) & 1) r--;
		cout << (l <= pos[r] || r <= piv || (r+l-1) <= 0);
	}
}
