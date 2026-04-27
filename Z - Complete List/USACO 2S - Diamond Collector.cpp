//4 de marzo 2026 12:30
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
#define ed "\n"
#define vb vector<bool>

int main(){
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);
	ll n, k;
	cin >> n >> k;
	vl arr(n);
	ff(i, 0, n){
		cin >> arr[i];
	}
	sort(all(arr));
	/*ff(i, 0, n){
		cout << arr[i] << " ";
	}
	cout << ed;*/
	ll l = 0, r = 0;
	vl pref(n, 1);
	while(l < n){
		pref[l] = r-l+1;
		if(r+1 < n && arr[r+1]-arr[l] <= k){
			r++;
		}
		else{
			l++;
		}
	}
	/*ff(i, 0, n){
		cout << pref[i] << " ";
	}
	cout << ed;*/
	ll ans = 0;
	ff(i, 0, n){
		ll maxx = pref[i];
		ff(j, i+pref[i], n){
			maxx = max(maxx, pref[i]+pref[j]);
		}
		ans = max(ans, maxx);
	}
	cout << ans;
}
