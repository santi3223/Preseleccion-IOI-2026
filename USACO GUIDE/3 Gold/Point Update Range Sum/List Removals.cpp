//25 de Mayo 2026 22:35
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
	set<ll> st;
	ll n;
	cin >> n;
	ordered_set<ll> ost;
	vl arr(n);
	ff(i, 0, n){
		ost.insert(i);
		cin >> arr[i];
	}
	ff(i, 0, n){
		ll ind;
		cin >> ind;
		ind--;
		ll pos = *ost.find_by_order(ind);
		ost.erase(pos);
		cout << arr[pos] << ' ';
	}
}
