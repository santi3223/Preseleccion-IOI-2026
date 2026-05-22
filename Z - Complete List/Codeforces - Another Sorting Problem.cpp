//21 de Mayo 2026 11:00
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
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back

ll binexp(ll b, ll e, ll mod){
	if(e == 0) return 1;
	if(e == 1) return b%mod;
	ll mid = binexp(b, e/2, mod)%mod;
	if(e % 2 == 0) return mid*mid%mod;
	return (mid*mid%mod)*b%mod;
}

ll inv(ll x, ll p){
	return binexp(x, p-2, p)%p;
}

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
		ll cur = 0;
		ff(i, 1, n){
			if(arr[i-1] > arr[i]){
				cur = max(cur, arr[i-1]-arr[i]);
			}
		}
		ff(i, 1, n){
			if(arr[i-1] > arr[i]){
				arr[i] += cur;
			}
		}
		/*ff(i, 0, n){
			cout << arr[i] << ' ';
		}*/
		cout << (is_sorted(all(arr)) ? "YES" : "NO") << ed;
		//cout << ed << ed;
	}
	
}
