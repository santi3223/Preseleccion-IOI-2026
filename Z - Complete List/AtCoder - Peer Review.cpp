//24 de Enero 2026 08:37
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

int main(){
	ll n, m;
	cin >> n >>  m;
	vl arr(n, 0);
	ff(i, 0, m){
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		arr[a]++;
		arr[b]++;
	}
	ff(i, 0, n){
		ll res = n-1-arr[i];
		if(res < 3) cout << 0 << " ";
		else cout << res*(res-1)*(res-2)/6 << " ";
	}
}
