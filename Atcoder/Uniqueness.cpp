//25 de Enero 2026 21:44
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
	vl b = arr;
	sort(rall(b));
	ll search = -1;
	ff(i, 0, n){
		if(i == 0 && b[i] != b[i+1]){
			search = b[i];
			break;
		}
		else if(i == n-1 && b[i-1] != b[i]){
			search = b[i];
			break;
		}
		else if(0 < i && i < n-1 && b[i-1] != b[i] && b[i] != b[i+1]){
			search = b[i];
			break;
		}
	}
	if(search == -1){
		cout << -1;
		return 0;
	}
	ff(i, 0, n){
		if(arr[i] == search){
			cout << i+1;
			return 0;
		}
	}
	cout << -1;
	
		
}
