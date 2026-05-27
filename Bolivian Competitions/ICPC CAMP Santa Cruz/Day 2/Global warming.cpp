//26 de Mayo 2026 14:15
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vl arr(n);
	ff(i, 0, n) cin >> arr[i];
	ll l = 0, r = n-1;
	ll level = 0;
	vl ans(n, 0);
	while(l <= r){
		//cout << "L " << level << "   ";
		while(level > arr[l] && ans[l] == 0){
			//cout << l << ' ';
			ans[l] = level;
			l++;
		}
		//cout << ed;
		//cout << "R " << level << "   ";
		while(level > arr[r] && ans[r] == 0){
			//cout << r << ed;
			ans[r] = level;
			r--;
		}
		//cout << ed << ed;
		level++;
		if(l == r && ans[l] != 0) break;
	}
	ff(i, 0, n) cout << ans[i] << ' ';
}

