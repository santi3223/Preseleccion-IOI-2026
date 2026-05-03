//3 de Mayo 2026 17:33
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
ll MOD = 1e9+7;

int main(){
	ll n;
	cin >> n;
	vector<vl> arr(n, vl(n));
	ff(i, 0, n) ff(j, 0, n) cin >> arr[i][j];
	vl x(n);
	ff(i, 0, n) cin >> x[i], x[i]--;
	reverse(all(x));
	vb visited(n, false);
	vl ans;
	for(ll k : x){
		ll sum = 0;
		visited[k] = true;
		ff(i, 0, n){
			ff(j, 0, n){
				arr[i][j] = min(arr[i][j], arr[i][k]+arr[k][j]);
				if(visited[i] && visited[j]) sum += arr[i][j];
			}
		}
		ans.pb(sum);
	}
	reverse(all(ans));
	for(auto p : ans) cout << p << ' ';
}
