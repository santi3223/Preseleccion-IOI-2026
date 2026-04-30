//17 de Marzo 2026 22:51
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
#define ed endl
#define vs vector<string>
const ll MOD = 1e9+7;

int main(){
	ll n;
	cin >> n;
	vl arr(n), b(n), pos(n+5), c(n+5), ans;
	ff(i, 0, n){
		cin >> arr[i];
		pos[arr[i]] = i+1;
	}
	ff(i, 0, n){
		cin >> b[i];
		c[i+1] = pos[b[i]];
		//cout << c[i+1] << " ";
	}
	//cout << ed;
	ff(i, 1, n+1){
		ll p = lower_bound(all(ans), c[i]) - ans.begin();
		if(p == ans.size()) ans.pb(c[i]);
		else ans[p] = c[i];
		/*ff(i, 0, ans.size()){
			cout << ans[i] << " ";
		}
		cout << ed;*/
	}
	cout << ans.size();
	
}
