//27 de Enero 2026 20:21
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
	ll n;
	cin >> n;
	vl arr(n), b;
	map<ll, ll> pos;
	ff(i, 0, n){
		cin >> arr[i];
		pos[arr[i]] = i;
	}
	b = arr;
	sort(all(b));
	vector<pll> ans;
	ff(i, 0, n){
		if(arr[i] != b[i]){
			ll other = pos[b[i]];
			ans.pb({i+1, other+1});
			ll x = pos[arr[i]];
			pos[arr[i]] = pos[arr[other]];
			pos[arr[other]] = x;
			swap(arr[i], arr[other]);
		}
	}
	cout << ans.size() << ed;
	ff(i, 0, ans.size()){
		cout << ans[i].fi << " " << ans[i].se << ed;
	}
	
}
