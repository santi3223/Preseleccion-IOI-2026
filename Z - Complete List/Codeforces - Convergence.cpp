//30 de Mayo 2026 10:55
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
const long double PI = acos(-1.0);

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		map<ll, ll> mp;
		vl arr(n);
		ff(i, 0, n){
			cin >> arr[i];
		}
		sort(all(arr));
		ll c = n;
		for(ll l = 0; l < n;){
			ll r = l;
			while(r < n && arr[r] == arr[l])r++;
			c = min(c, max(l, n-r));
			l = r;
		}
		cout << c << ed;
	}
}
