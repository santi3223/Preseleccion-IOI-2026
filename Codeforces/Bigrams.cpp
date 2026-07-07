//6 de Julio 2026 10:37
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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll q2 = 0, q3 = 0;
		ff(i, 0, n){
			ll a;
			cin >> a;
			if(a >= 2)q2++;
			if(a >= 3)q3++;
		}
		if(q2 >= 2 || q3) cout << "YES";
		else cout << "NO";
		cout << ed;
	}
}
