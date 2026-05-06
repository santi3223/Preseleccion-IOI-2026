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

int main(){
	ll n, q;
	cin >> n >> q;
	vs arr(n);
	ff(i, 0, n) cin >> arr[i];
	vector<vl> nums(n, vl(n, 0));
	ff(i, 0, n){
		ff(j, 0, n){
			ll a = 0, b = 0, c = 0, d = 0;
			if(arr[i][j] == '*') a++;
			if(j-1 >= 0) b += nums[i][j-1];
			if(i-1 >= 0) c += nums[i-1][j];
			if(i-1 >= 0 && j-1 >= 0) d += nums[i-1][j-1];
			nums[i][j] = a+b+c-d;
			cout << nums[i][j] << ' ';
		}
		cout << ed;
	}
	while(q--){
		ll x1, x2, y1, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		x1--;
		x2--;
		y1--;
		y2--;
		ll a = nums[y2][x2], b = 0, c = 0, d = 0;
		if(x1-1 >= 0) b -= nums[y2][x1-1];
		if(y1-1 >= 0) c -= nums[y1-1][x2];
		if(x1-1 >= 0 && y1-1 >= 0) d += nums[y1-1][x1-1];
		cout << a+b+c+d << ed;
	}
}
