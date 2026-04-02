//3 de Marzo 2026 21:04
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
#define ed "\n"
#define vb vector<bool>

vl pref;
string str;
ll c;

void check(ll i, bool stat){
	//cout << str[i] << " "  << str[i+1] << "  " << pref[i] << " " << i << ed;
	if(str[i] == 'L' && str[i+1] == 'R' && pref[i] > i+1){
		if(stat) c++;
		else c--;
	}
}

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n, q;
		cin >> n >> q;
		vl arr(n);
		ff(i, 0, n){
			cin >> arr[i];
		}
		cin >> str;
		pref = vl(n);
		pref[0] = arr[0];
		ff(i, 1, n) pref[i] = max(pref[i-1], arr[i]);
		c = 0;
		/*ff(i, 0, n) cout << pref[i] << " ";
		cout << ed;*/
 		ff(i, 0, n-1){
			check(i, true);
			//cout << i << " "  << c << ed;
		}
		while(q--){
			ll x;
			cin >> x;
			x--;
			check(x, false);
			check(x-1, false);
			if(str[x] == 'L') str[x] = 'R';
			else str[x] = 'L';
			check(x, true);
			check(x-1, true);
			if(c > 0) cout << "NO";
			else cout << "YES";
			cout << ed;
		}
	}
}
