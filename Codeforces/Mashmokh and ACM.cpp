//2 de Mayo 2026 23:37
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
ll MOD = 1e9+7;

int main(){
	ll n, k;
	cin >> n >> k;
	vector<vl> arr(k+5, vl(n+5, 0));
	vector<vl> lis(n+5);
	ff(i, 1, n+1){
		for(ll j = i; j <= n; j += i){
			lis[j].pb(i);
		}
	}
	/*cout << "LIS" << ed;
	ff(i, 0, n+1){
		cout << "I " << i << ' ';
		for(auto x : lis[i]) cout << x << ' ';
		cout << ed;
	}
	cout << ed;*/
	ff(i, 1, k+1){
		if(i == 1){
			ff(j, 1, n+1) arr[i][j] = 1;
			continue;
		}
		ff(j, 1, n+1){
			for(auto x : lis[j]){
				arr[i][j] += arr[i-1][x];
				if(arr[i][j] >= MOD) arr[i][j] %= MOD;
			}
		}
	}
	/*ff(i, 0, k+2){
		ff(j, 0, n+2) cout << arr[i][j] << ' ';
		cout << ed;
	}*/
	ll ans = 0;
	ff(j, 1, n+1){
		ans += arr[k][j];
		if(ans >= MOD) ans %= MOD;
	}
	cout << ans%MOD << ed;
}
