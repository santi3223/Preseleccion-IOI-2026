//4 de marzo 2026 17:35
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
#define ed "\n"
#define vb vector<bool>

int main(){
	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);
	ll n;
	cin >> n;
	vl arr(n);
	ff(i, 0, n){
		cin >> arr[i];
	}
	sort(all(arr));
	/*ff(i, 0, n){
		cout << arr[i] << " ";
	}*/
	ll minn = LLONG_MAX, maxx = 0;
	if(arr[n-2]-arr[0] == n-2 && arr[n-1]-arr[n-2] > 2) minn = 2;
	else if(arr[n-1]-arr[1] == n-2 && arr[1]-arr[0] > 2) minn = 2;
	else{
		ll r = 0;
		ff(l, 0, n){
			while(r+1 < n && arr[r+1]-arr[l] < n) r++;
			minn = min(minn, n-(r-l+1));
		}
	}
	ll c = 0;
	ff(i, 1, n){
		c += arr[i]-arr[i-1]-1;
	}
	maxx = max(c-(arr[1]-arr[0]-1), c-(arr[n-1]-arr[n-2]-1));
	cout << minn << ed << maxx;
	
}
