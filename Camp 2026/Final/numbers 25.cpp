#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define pb push_back
#define vs vector<string>

ll ok(ll L, ll R){
	ll ans = 0;
	ff(numb, L, R+1){
		string cur = to_string(numb);
		ll n = cur.size();
		bool ok = true;
		ff(l, 0, n){
			ff(r, l+1, n){
				//cout << "L " << l << "  R " << r << ed;
				ll countcur = 0, tot = 0;
				ff(i, l, (l+r)/2+1){
					tot++;
					//cout << i << ' ' << r-(i-l) << ed;
					if(cur[i] == cur[r-(i-l)]){
						countcur++;
					}
				}
				if(tot == countcur) ok = 0;
				if(!ok) break;
			}
			if(!ok) break;
		}
		if(ok) ans++;
	}
	return ans;
}

int main(){
	ll a, b;
	cin >> a >> b;
	cout << ok(a, b);
}
