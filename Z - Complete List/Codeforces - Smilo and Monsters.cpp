//4 de Julio 2026 00:17
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define ed "\n"
#define vb vector<bool>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vl arr(n);
		ff(i, 0, n) cin >> arr[i];
		sort(all(arr));
		ll l = 0, r = n-1, c = 0, cur = 0;
		while(l < r){
			if(cur+arr[l] < arr[r]){
				c += arr[l];
				cur += arr[l];
				l++;
			}
			else{
				arr[l] -= arr[r]-cur;
				c += arr[r]-cur;
				c++;
				cur = 0;
				r--;
			}
		}
		ll pos = l;
		l = 0;
		r = arr[pos];
		//cout << c << ' ' << cur << ' ' << pos << ' ' << arr[pos] << ' ' << l << ' ' << r << ed;
		ll ans = 0;
		while(l <= r){
			ll mid = l+(r-l)/2;
			//cout << cur << ' ' << mid << ' ' << arr[pos] << "   " << cur+mid << ' ' << arr[pos]-mid << "   " << l << ' ' << r << ed;
			if(cur+mid >= arr[pos]-mid){
				ans = mid;
				if(arr[pos]-mid > 0) ans++;
				r = mid-1;
			}
			else l = mid+1;
			//cout << ans << ed;
		}
		//cout << l << ' ' << r << ' ' << ans << ed;
		cout << c+ans << ed;
	}
}
