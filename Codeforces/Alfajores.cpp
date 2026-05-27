//26 de Mayo 2026 16:19
#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
	ll n, m;
	cin >> n >> m;
	vl trip(n);
	ff(i, 0, n) cin >> trip[i];
	vl arr;
	ll last = 1e18;
	ff(i, 0, m){
		ll x;
		cin >> x;
		if(x >= last) continue;
		last = x;
		arr.pb(x);
	}
	reverse(all(arr));
	m = arr.size();
	/*ff(i, 0, m){
		cout << arr[i] << ' ';
	}
	cout << ed;*/
	for(auto cur : trip){
		while(true){
			ll pos = upper_bound(all(arr), cur) - arr.begin()-1;
			if(pos < 0) break;
			cur %= arr[pos];
		}
		cout << cur << ' ';
	}
}
