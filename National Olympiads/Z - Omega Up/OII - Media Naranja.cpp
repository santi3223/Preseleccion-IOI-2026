//3 de Junio 2026 18:01
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

struct Fenwick{
	private:
		ll n;
		vl bit;
	public:
		Fenwick(ll sz){
			n = sz;
			bit = vl(n+1);
		}
		void add(ll i, ll v){
			for(++i; i <= n; i += i & -i){
				bit[i] += v;
			}
		}
		ll query(ll i){
			ll res = 0;
			for(++i; i > 0; i -= i & -i){
				res += bit[i];
			}
			return res;
		}
		ll rang(ll l, ll r){
			return query(r)-query(l-1);
		}
};

struct Event{
	ll x, type, id;
};

bool comp(Event a, Event b){
	if(a.x != b.x) return a.x < b.x;
	return a.type < b.type;
}

vl nwidx;

ll getpos(ll x){
	return lower_bound(all(nwidx), x) - nwidx.begin();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vl a(n), b(n), c(n);
	vl todo;
	ff(i, 0, n){
		cin >> a[i] >> b[i];
		c[i] = a[i]+b[i];
		a[i] *= 2;
		b[i] *= 2;
		todo.pb(a[i]);
		todo.pb(b[i]);
		todo.pb(c[i]);
	}
	nwidx = todo;
	sort(all(nwidx));
	nwidx.erase(unique(all(nwidx)), nwidx.end());
	vector<Event> events;
	ff(i, 0, n){
		events.pb({a[i], 0, i});
		events.pb({c[i], 1, i});
		events.pb({b[i], 2, i});
	}
	ll sssz = nwidx.size();
	Fenwick bit(sssz);
	ll ans = 0;
	
	sort(all(events), comp);
	for(auto &e : events){
		ll i = e.id;
		if(e.type == 0){
			bit.add(getpos(c[i]), 1);
		}
		else if(e.type == 1){
			ll l = lower_bound(all(nwidx), a[i]) - nwidx.begin();
			ll r = upper_bound(all(nwidx), b[i]) - nwidx.begin()-1;
			ans += bit.rang(l, r);
		}
		else{
			bit.add(getpos(c[i]), -1);
		}
	}
	//cout << ans << ed;
	cout << (ans-n)/2;
}
