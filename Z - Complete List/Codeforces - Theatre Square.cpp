//26 de Mayo 2026 14:50
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
	ll n, m, a;
	cin >> n >> m >> a;
	ll bn = (n+a-1)/a;
	ll bm = (m+a-1)/a;
	n = a*bn;
	m = a*bm;
	cout << (n*m)/(a*a);
}
