//11 de Julio 2026 16:22
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
 
int main(){
	ll n;
	cin >> n;
	vl arr(n);
	ff(i, 0, n){
		cin >> arr[i];
	}
	sort(all(arr));
	ll cur = 1, ans = 0;
	ff(i, 1, n){
		if(arr[i] != arr[i-1]){
			if(ans == 0){
				ans = i;
				cur = 1;
			}
			else{
				ans += ans*cur+cur;
				cur = 1;
			}
		}
		else cur++;
		if(ans >= MOD) ans %= MOD;
		//cout << ans << ' ';
	}
	ans += ans*cur+cur;
	cout << ans%MOD;
}
