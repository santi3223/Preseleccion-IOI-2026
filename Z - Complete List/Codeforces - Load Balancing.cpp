//27 de Mayo 2026 17:16
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
	ll a = 0, b = 0;
	vl arr(n);
	ll s = 0;
	ff(i, 0, n){
		cin >> arr[i];
		s += arr[i];
	}
	ll l = s/n, r = s/n;
	if(l*n != s) r++;
	ff(i, 0, n){
		if(arr[i] < r){
			a += abs(arr[i]-l);
		}
		else{
			b += abs(arr[i]-r);
		}
	}
	cout << max(a, b);
}
