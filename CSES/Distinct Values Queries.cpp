//30 de Abril 2026 20:12
#include <bits/stdc++.h>
using namespace std;
#define ll int
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
 
struct Query{
	ll l, r, id;
};
 
ll block = 460;
bool comp(Query a, Query b){
	if(a.l/block != b.l/block){
		return a.l < b.l;
	}
	if((a.l/block) & 1) return a.r > b.r;
	return a.r < b.r;
}
 
vl freq, arr;
ll dif = 0;
 
inline void add(ll p){
	if(freq[arr[p]] == 0) dif++;
	freq[arr[p]]++;
}
 
inline void remove(ll p){
	freq[arr[p]]--;
	if(freq[arr[p]] == 0) dif--;
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll n, q;
	cin >> n >> q;
	arr = vl(n);
	vl lis;
	ff(i, 0, n){
		cin >> arr[i];
		lis.pb(arr[i]);
	}
	sort(all(lis));
	lis.erase(unique(all(lis)), lis.end());
	ff(i, 0, n){
		arr[i] = lower_bound(all(lis), arr[i]) - lis.begin();
	}
	vector<Query> queries(q);
	ff(i, 0, q){
		ll a, b;
		cin >> a >> b;
		queries[i].l = a-1;
		queries[i].r = b-1;
		queries[i].id = i;
	}
	block = sqrt(n);
	sort(all(queries), comp);
	freq = vl(lis.size(), 0);
	ll cl = 0, cr = -1;
	vl ans(q);
	for(auto &k : queries){
		ll l = k.l, r = k.r;
		while(cl > l) add(--cl);
		while(cr < r) add(++cr);
		while(cl < l) remove(cl++);
		while(cr > r) remove(cr--);
		ans[k.id] = dif;
	}
	ff(i, 0, q) cout << ans[i] << ed;
	
}
