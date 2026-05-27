//26 de Mayo 2026 15:11
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

vb diag1, diag2, r, c;
vector<string> arr, table;
ll n, ans;

void calc(ll row){
	if(row >= n){
		ans++;
		return;
	}
	ff(col, 0, n){
		if(arr[row][col] == '*' || diag1[row+col] || diag2[row-col+n-1] || r[row] || c[col])continue;
		diag1[row+col] = diag2[row-col+n-1] = r[row] = c[col] = 1;
		calc(row+1);
		diag1[row+col] = diag2[row-col+n-1] = r[row] = c[col] = 0;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	n = 8;
	diag1 = vb(2*n+5, 0);
	diag2 = vb(2*n+5, 0);
	r = vb(n, 0);
	c = vb(n, 0);
	arr = vector<string>(n);
	ff(i, 0, n) cin >> arr[i];
	ans = 0;
	calc(0);
	cout << ans;
}
