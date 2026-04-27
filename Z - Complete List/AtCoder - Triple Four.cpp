//25 de Enero 2026 20:55
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
	vl arr(n);
	ff(i, 0, n){
		cin >> arr[i];
	}
	ff(i, 0, n-2){
		if(arr[i] == arr[i+1] && arr[i+1] == arr[i+2]){
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	
		
}
