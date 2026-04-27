//23 de Enero 2026 15:31
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
	vl arr(5);
	ff(i, 0, 5){
		cin >> arr[i];
	}
	ff(i, 0, 5-1){
		swap(arr[i], arr[i+1]);
		if(is_sorted(all(arr))){
			cout << "Yes";
			return 0;
		}
		swap(arr[i], arr[i+1]);
	}
	cout << "No";
}
