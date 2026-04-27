//7 de Marzo 2026 08:26
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
#define ed "\n"
#define vs vector<string>

int main(){
	ll n, q;
	cin >> n >> q;
	vector<pll> arr(n);
	ff(i, 0, n){
		cin >> arr[i].fi;
		arr[i].se = i;
	}
	sort(all(arr));
	while(q--){
		ll minn = LLONG_MAX;
		ll m;
		cin >> m;
		vb no(6, false);
		ff(id, 0, m){
			ll x;
			cin >> x;
			ff(i, 0, 6){
				if(arr[i].se == x-1){
					no[i] = true;
				}
			}
		}
		ff(i, 0, 6){
			if(no[i] == false){
				minn = arr[i].fi;
				break;
			}
		}
		cout << minn << ed;
	}
	
}
