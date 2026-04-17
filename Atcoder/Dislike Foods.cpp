//26 de Enero 2026 08:53
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
ll MOD = 1e9;

int main(){
	ll n, m;
	cin >> n >> m;
	vector<vl> arr(m);
	ff(i, 0, m){
		ll k;
		cin >> k;
		ff(j, 0, k){
			ll x;
			cin >> x;
			arr[i].pb(x);
		}
	}
	vl b(n);
	map<ll, ll> mp;
	ff(i, 0, n){
		ll a;
		cin >> a;
		mp[a] = i+1;
	}
	vl ans(n, 0);
	ff(i, 0, m){
		ll maxx = 0;
		ff(j, 0, arr[i].size()){
			maxx = max(maxx, mp[arr[i][j]]);
		}
		if(maxx == 0) continue;
		else{
			ans[maxx-1]++;
		}
	}
	ll x = 0;
	ff(i, 0, n){
		x += ans[i];
		cout << x << ed;
	}
}
