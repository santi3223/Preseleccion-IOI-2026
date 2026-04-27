//26 de Enero 2026 13:56
//There's an error in the file name. You can't put "~" as a file name, so I put the problem letter at the start
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
ll MOD = 1e9;

int main(){
	ll n;
	cin >> n;
	vl aa(n);
	ff(i, 0, n){
		cin >> aa[i];
	}
	string str;
	ff(i, 0, n-1){
		if(aa[i] < aa[i+1]) str+='<';
		else str+='>';
	}
	vector<pair<char, ll>> arr;
	ll q = 1;
	ff(i, 1, str.size()){
		if(str[i] == str[i-1]){
			q++;
		}
		else{
			arr.pb({str[i-1], q});
			q = 1;
		}
	}
	arr.pb({str[str.size()-1], q});
	ll c = 0;
	if(arr.size() < 2){
		cout<<0;
		return 0;
	}
	ff(i, 0, arr.size()-2){
		if(arr[i].fi == '<'){
			c += arr[i].se*arr[i+2].se;
		}
	}
	cout << c;
	
}
