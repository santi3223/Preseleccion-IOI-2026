//19 de Julio 2026 11:13
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vb vector<bool>
#define pll pair<ll, ll>
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second
const ll MOD = 1e9+7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, k;
	cin >> n >> k;
	vl a(k);
	ff(i, 0, k) cin >> a[i];
	ll c = 0;
	ff(mask, 1, (1 << k)){
		ll q = 1;
		ff(i, 0, k){
			if(mask & (1 << i)){
				if(q > n/a[i]){
					q = n+1;
					break;
				}
				q *= a[i];
			}
		}
		if(__builtin_popcount(mask) % 2 != 0) c += n/q;
		else c -= n/q;
	}
	cout << c;
}
