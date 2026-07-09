//8 de Julio 2026 23:41
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
const ll MOD = 1e9+7;

struct cmp{
	bool operator()(pll a, pll b){
		ll c1 = a.se-a.fi+1;
		ll c2 = b.se-b.fi+1;
		if(c1 != c2) return c1 < c2;
		return a.fi > b.fi;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		set<pll> st;
		vl arr(n+5, 0);
		priority_queue<pll, vector<pll>, cmp> q;
		q.push({1, n});
		ll i = 1;
		while(q.size()){
			auto [l, r] = q.top();
			//cout << l << ' ' << r << ed;
			q.pop();
			ll mid = (l+r)/2;
			if((r-l+1) % 2 == 0) mid = (l+r-1)/2;
			arr[mid] = i;
			i++;
			if(l <= mid-1) q.push({l, mid-1});
			if(mid+1 <= r) q.push({mid+1, r});
		}
		ff(id, 1, n+1) cout << arr[id] << ' ';
		cout << ed << ed;
	}
	
}
