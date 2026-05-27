//26 de Mayo 2026 15:57
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
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vl h(n), x(n-1);
		ff(i, 0, n) cin >> h[i];
		ff(i, 0, n-1) cin >> x[i];
		bool ok = true;
		ll large = 0;
		ff(i, 0, n-1){
			large = max(large-x[i], h[i]-x[i]);
			if(large <= 0){
				ok = false;
				break;
			}
		}
		
		if(ok){
			cout << "habibi" << ed;
			continue;
		}
		
		reverse(all(h));
		reverse(all(x));
		ok = true;
		large = 0;
		ff(i, 0, n-1){
			large = max(large-x[i], h[i]-x[i]);
			if(large <= 0){
				ok = false;
			}
		}
		if(!ok) cout << "which";
		else cout << "habibi";
		cout << ed;
	}
}
