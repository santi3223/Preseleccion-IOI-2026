//6 de Mayo 2026 18:54
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
#define ed "\n"
#define vs vector<string>

struct Query{ll l, r, id;};

ll block = 460;

bool comp(Query a, Query b){
	if(a.l/block != b.l/block) return a.l < b.l;
	if((a.l/block) & 1) return a.r > b.r;
	return a.r < b.r;
}

vl freq, arr;
ll dif = 0;

void add(ll i){
	if(freq[arr[i]] == 0) dif++;
	freq[arr[i]]++;
}

void rem(ll i){
	freq[arr[i]]--;
	if(freq[arr[i]] == 0) dif--;
}


int main(){
	ll n;
	cin >> n;
	arr = vl(n);
	ff(i, 0, n) cin >> arr[i];
	vl lis = arr;
	sort(all(lis));
	lis.erase(unique(all(lis)), lis.end());
	ff(i, 0, n){
		arr[i] = lower_bound(all(lis), arr[i]) - lis.begin();
	}
	ll q;
	cin >> q;
	vector<Query> ok(q);
	ff(i, 0, q){
		cin >> ok[i].l >> ok[i].r;
		ok[i].l--;
		ok[i].r--;
		ok[i].id = i;
	}
	
	freq = vl(lis.size(), 0);
	block = sqrt(n);
	sort(all(ok), comp);
	ll cl = 0, cr = -1;
	vl ans(q);
	ff(i, 0, q){
		ll l = ok[i].l, r = ok[i].r;
		while(cl > l) add(--cl);
		while(cr < r) add(++cr);
		while(cl < l) rem(cl++);
		while(cr > r) rem(cr--);
		ans[ok[i].id] = dif;
	}
	for(auto p : ans) cout << p << ed;
}
