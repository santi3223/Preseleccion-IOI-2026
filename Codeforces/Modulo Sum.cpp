//3 de Mayo 2026 18:06
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

int main(){
	ll n, m;
	cin >> n >> m;
	vl arr(n);
	ff(i, 0, n) cin >> arr[i], arr[i] %= m;
	if(n > m){
		cout << "YES";
		return 0;
	}
	vb can(m, false), nw;
	ff(i, 0, n){
		ll q = arr[i];
		nw = can;
		nw[q] = true;
		ff(j, 0, m){
			if(can[j] && !can[(j+q)%m]) nw[(j+q)%m] = 1;
		}
		can = nw;
		/*ff(i, 0, m){
			cout << can[i] << ' ';
		}
		cout << ed;*/
	}
	cout << (can[0] ? "YES" : "NO");
}
