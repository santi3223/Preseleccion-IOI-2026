//27 de Mayo 2026 23:09
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


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	stack<pll> st;
	ff(i, 0, n){
		ll x;
		cin >> x;
		while(!st.empty() && st.top().fi >= x){
			st.pop();
		}
		if(st.empty()) cout << 0 << ' ';
		else cout << st.top().se << ' ';
		st.push({x, i+1});
	}
}
