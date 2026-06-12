//11 de Junio 2026 23:27
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
const long double PI = acos(-1.0);

struct Query{
	ll l, r, idx;
};
ll block = 320;
bool comp(Query a, Query b){
	if(a.l/block != b.l/block) return a.l < b.l;
	if((a.l/block) & 1) return a.r > b.r;
	return a.r < b.r;
}

vl arr;
unordered_map<ll, ll> mp;
ll ans = 0;
void add(ll i){
	if(mp[arr[i]] == arr[i]) ans--;
	mp[arr[i]]++;
	if(mp[arr[i]] == arr[i]) ans++;
}

void rem(ll i){
	if(mp[arr[i]] == arr[i]) ans--;
	mp[arr[i]]--;
	if(mp[arr[i]] == arr[i]) ans++;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, q;
	cin >> n >> q;
	arr = vl(n);
	ff(i, 0, n) cin >> arr[i];
	vector<Query> queries(q);
	ff(i, 0, q){
		cin >> queries[i].l >> queries[i].r;
		queries[i].l--;
		queries[i].r--;
		queries[i].idx = i;
	}
	sort(all(queries), comp);
	ll cl = 0, cr = -1;
	vl ok(q);
	ff(i, 0, q){
		ll l = queries[i].l, r = queries[i].r;
		while(cl > l) add(--cl);
		while(cr < r) add(++cr);
		while(cl < l) rem(cl++);
		while(cr > r) rem(cr--);
		ok[queries[i].idx] = ans;
	}
	for(auto x : ok) cout << x << ed;
}
