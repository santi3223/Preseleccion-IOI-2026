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

int main(){
	ll n, x;
	unordered_map<ll, ll> mp;
	cin >> n >> x;
	ll cur = 0, ans = 0;
	mp[0]++;
	ff(i, 0, n){
		ll a;
		cin >> a;
		cur += a;
		mp[cur]++;
		//cout << cur << ' ' << x << "  " << mp[cur-x] << ed;
		ans += mp[cur-x];
	}
	cout << ans;	
}
