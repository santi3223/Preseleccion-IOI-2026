//1 de Abril 2026 22:56
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
 
int main(){
	ll n, t;
	cin >> n >> t;
	vl arr(n);
	ff(i, 0, n) cin >>arr[i];
	ll ans = 1e18, l = 0, r = *min_element(all(arr))*t+5;
	while(l <= r){
		ll mid = l + (r-l)/2;
		ll cur = 0;
		ff(i, 0, n){
			cur += mid/arr[i];
			if(cur >= t) break;
		}
		if(cur >= t){
			ans = mid;
			r = mid-1;
		}
		else l = mid+1;
	}
	cout << ans;
	
}
