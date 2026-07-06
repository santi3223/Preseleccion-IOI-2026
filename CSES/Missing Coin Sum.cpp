//4 de Julio 2026 14:53
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define ed "\n"
#define vb vector<bool>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second
 
int main(){
	ll n;
	cin >> n;
	vl arr(n);
	ff(i, 0, n) cin >> arr[i];
	sort(all(arr));
	ll s = 0;
	ff(i, 0, n){
		if(arr[i] > s && s+1 != arr[i]){
			break;
		}
		s += arr[i];
	}
	cout << s+1;
}
