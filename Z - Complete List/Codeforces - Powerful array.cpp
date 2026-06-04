//3 de Junio 2026 23:15
//found this problem after 1 year from the last submission wow
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

ll block = 448;

struct Query{
	ll l, r, idx;
};

bool comp(Query a, Query b){
	if(a.l/block != b.l/block) return a.l < b.l;
	if((a.l/block) & 1) return a.r > b.r;
	return a.r < b.r;
}

vl freq, arr;
ll c = 0;

void add(ll i){
	c -= freq[arr[i]]*freq[arr[i]]*arr[i];
	freq[arr[i]]++;
	c += freq[arr[i]]*freq[arr[i]]*arr[i];
}

void rem(ll i){
	c -= freq[arr[i]]*freq[arr[i]]*arr[i];
	freq[arr[i]]--;
	c += freq[arr[i]]*freq[arr[i]]*arr[i];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, q;
	cin >> n >> q;
	arr = vl(n);
	ff(i, 0, n) cin >> arr[i];
	vector<Query> query(q);
	ff(i, 0, q){
		cin >> query[i].l >> query[i].r;
		query[i].l--;
		query[i].r--;
		query[i].idx = i;
	}
	sort(all(query), comp);
	freq = vl(1e6+5, 0);
	ll cl = 0, cr = -1;
	vl ans(q);
	ff(id, 0, q){
		ll l = query[id].l;
		ll r = query[id].r;
		ll i = query[id].idx;
		//cout << l << ' ' << r << ' ' << id << ed;
		while(cl > l) add(--cl);
		while(cr < r) add(++cr);
		while(cl < l) rem(cl++);
		while(cr > r) rem(cr--);
		/*ff(i, 0, 1e6+5){
			if(freq[i] != 0){
				cout << i << ' ' << freq[i] << "   ";
			}
		}
		cout << ed;*/
		ans[i] = c;
	}
	ff(i, 0, q) cout << ans[i] << ed;
}
