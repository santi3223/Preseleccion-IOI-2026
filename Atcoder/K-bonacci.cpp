//26 de Enero 2026 08:36
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
	ll n, k;
	cin >> n >> k;
	ll cur = k;
	if(n < k) cout << 1;
	else{
		vl arr(k, 1);
		ff(i, k, n+1){
			arr.pb(cur % MOD);
			cur = (cur-arr[i-k]+arr[i])%MOD;
			if(cur < 0) cur += MOD;
		}
		cout << arr[n]%MOD;
	}
}
