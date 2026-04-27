//22 de Abril 2026 21:03
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
#define ed endl
#define vs vector<string>

int main(){
	ll n;
	cin >> n;
	vl arr(n);
	ff(i, 0, n){
		cin >> arr[i];
		arr[i]--;
	}
	cout << 1 << ' ';
	ll last = n-1;
	vb ok(n, 0);
	ff(i, 0, n){
		ok[arr[i]] = 1;
		while(last >= 0 && ok[last] == 1) last--;
		cout << (i+1)+1-((n-1)-last)<< ' ';
	}
}
