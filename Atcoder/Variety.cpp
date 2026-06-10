//6 de Junio 2026 08:16
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
#define vc vector<char>
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, k, m;
	cin >> n >> k >> m;
	vector<pll> arr(n);
	set<ll> tot;
	ff(i, 0, n){
		ll c, x;
		cin >> c >> x;
		tot.insert(c);
		arr[i] = {x, c};
	}
	sort(rall(arr));
	ll ans = 0, q = 0;
	set<ll> cur;
	ff(i, 0, n){
		//cout << arr[i].fi << ' ' << arr[i].se << ' ' << q << ' ' << k << ' ' << cur.size() << ' ';
		if(q == k) break;
		if(q < k-(m-cur.size()) || cur.size() > m){
			q++;
			cur.insert(arr[i].se);
			ans += arr[i].fi;
		}
		else{
			ll sz = cur.size();
			cur.insert(arr[i].se);
			if(sz != cur.size()){
				q++;
				ans += arr[i].fi;
			}
		}
		//cout << ans << ed;
	}
	cout << ans;
}

