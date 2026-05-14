//13 de Mayo 2026 22:08
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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while(t--){
		ll n, p;
		cin >> n >> p;
		vector<pll> arr(n);
		vl orig(n);
		ff(i, 0, n){
			cin >> arr[i].fi;
			arr[i].se = i;
			orig[i] = arr[i].fi;
		}
		sort(all(arr));
		ll ans = 0, rem = n-1;
		vb visited(n, 0);
		ff(i, 0, n){
			ll j = arr[i].se;
			ll val = orig[j];
			if(val >= p) break;
			while(j > 0 && orig[j-1] % val == 0 && !visited[j-1]){
				visited[j-1] = 1;
				rem--;
				ans += val;
				j--;
			}
			j = arr[i].se;
			while(j < n-1 && orig[j+1] % val == 0 && !visited[j]){
				visited[j] = 1;
				rem--;
				ans += val;
				j++;
			}
		}
		ans += rem*p;
		cout << ans << ed;
	}
	
}
