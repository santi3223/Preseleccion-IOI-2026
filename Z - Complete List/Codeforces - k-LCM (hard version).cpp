//19 de Mayo 2026 23:35
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
		ll n, k;
		cin >> n >> k;
		ff(i, 0, k-3) cout << 1 << ' ';
		n -= k-3;
		if(n % 4 == 0) cout << n/4 << ' ' << n/4 << ' ' << n/2;
		else if(n % 2 == 0) cout << n/2-1 << ' ' << n/2-1 << ' ' << 2;
		else cout << n/2 << ' ' << n/2 << ' ' << 1;
		cout << ed;
	}
}
