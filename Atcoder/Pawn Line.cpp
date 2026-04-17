//31 de Enero 2026 09:30
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vb vector<bool>
#define pb push_back
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define vl vector<ll>
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
constexpr ll MOD = 1e9+7;
 
int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vl arr(n);
		ff(i, 0, n){
			cin >> arr[i];
		}
		vl a = arr, b = arr;
		ff(i, 1, n){
			if(a[i-1] < a[i]){
				a[i] = a[i-1]+1;
			}
		}
		for(ll i = n-2; i >= 0; i--){
			if(b[i] > b[i+1]){
				b[i] = b[i+1]+1;
			}
		}
		vl ans(n);
		ll c = 0;
		ff(i, 0, n){
			ans[i] = min(a[i], b[i]);
			//cout << ans[i] << " ";
			c += arr[i]-ans[i];
		}
		//cout << ed;
		cout << c << ed;
		
	}
}
