//25 de Enero 2026 18:39
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vb vector<bool>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define pb push_back
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define fi first
#define se second
#define pll pair<ll, ll>


int main(){
	ll n;
	cin >> n;
	vector<pair<ll, string>> arr;
	ff(i, 0, n){
		string str;
		cin >> str;
		arr.pb({str.size(), str});
	}
	sort(all(arr));
	ff(i, 0, arr.size()){
		cout << arr[i].se;
	}
	
	
}
