//7 de Marzo 2026 08:13
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
#define ed "\n"
#define vs vector<string>

int main(){
	ll n, x;
	cin >> n >> x;
	vl arr(n), b(n), c(x);
	ff(i, 0, x){
		cin >> c[i];
	}
	ff(i, 0, n){
		cin >> arr[i] >> b[i];
		arr[i]--;
	}
	ll ans = 0;
	ff(i, 0, n){
		ll s = c[arr[i]];
		if(s-b[i] >=  0) s -= b[i];
		else s = 0;
		ans += c[arr[i]]-s;
		c[arr[i]] = s;
	}
	cout << ans;
	
}
