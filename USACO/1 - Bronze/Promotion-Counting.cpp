//13 de Febrero 2026 22:56
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define pb push_back
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define vs vector<string>
#define ed "\n"

int main(){
	freopen("promote.in", "r", stdin);
	freopen("promote.out", "w", stdout);
	ll n = 4;
	vector<pll> arr(n);
	ff(i, 0, 4){
		cin >> arr[i].fi >> arr[i].se;
	}
	vl ans;
	for(ll i = n-1; i >= 1; i--){
		ll dif = arr[i].se-arr[i].fi;
		ans.pb(dif);
		arr[i-1].fi -= dif;
	}
	reverse(all(ans));
	ff(i, 0, ans.size()) cout << ans[i] << ed;
	
}
