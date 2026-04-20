#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define pb push_back
#define vs vector<string>
ll n;
vl arr;

bool ok(ll k, ll maxx){
	ll c = 0, sum = 0;
	ff(i, 0, n){
		if(arr[i] > maxx) return false;
		sum += arr[i];
		if(sum > maxx){
			c++;
			sum = arr[i];
		}
	}
	c++;
	return c <= k;
}

int main(){
	ll k;
	cin >> n >> k;
	arr = vl(n);
	ll sum = 0;
	ff(i, 0, n){
		cin >> arr[i];
		sum += arr[i];
	}
	ll l = 0, r = sum+5;
	ll minn = 0;
	while(l <= r){
		ll mid = l+(r-l)/2;
		if(ok(k, mid)){
			minn = mid;
			r = mid-1;
		}
		else l = mid+1;
	}
	cout << minn;
}

