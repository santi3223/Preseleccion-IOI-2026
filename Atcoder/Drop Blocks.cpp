//23 de Mayo 2026 08:37
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


struct BIT{
	private:
		ll n;
		vl bit;
	public:
		BIT(ll _n){
			n = _n;
			bit = vl(n+5, 0);
		}

		void add(ll i, ll v){
			for(++i; i <= n; i += i & -i){
				bit[i] += v;
			}
		}

		ll sum(ll i){
			ll res = 0;
			for(++i; i > 0; i -= i & -i){
				res += bit[i];
			}
			return res;
		}

		ll query(ll l, ll r){
			if(l > r) return 0;
			return sum(r) - sum(l - 1);
		}
};

int main(){
	ll n, q;
	cin >> n >> q;
	vl pos(n+1, 0);
	BIT cells(600000+1);
	cells.add(0, n);
	ll disc = 0, zero = n;
	while(q--){
		ll o, x;
		cin >> o >> x;
		if(o == 1){
			ll old = pos[x];
			cells.add(old, -1);
			if(old == disc) zero--;
			pos[x]++;
			ll nw = pos[x];
			cells.add(nw, 1);
			if(nw == disc) zero++;
			if(zero == 0){
				disc++;
				zero = cells.query(disc, disc);
			}
		}
		else{
			cout << cells.query(disc+x, 600000) << ed;
		}
	}
}
