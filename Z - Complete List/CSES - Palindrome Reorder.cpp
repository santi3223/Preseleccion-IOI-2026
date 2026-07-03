//2 de Julio 2026 21:32
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
const ll MOD = 1e9+7;
 
int main(){
	string s;
	cin >> s;
	ll n = s.size();
	vl arr(26, 0);
	ff(i, 0, n){
		arr[s[i]-'A']++;
	}
	ll c0 = 0, c1 = 0;
	ff(i, 0, 26){
		if(arr[i] % 2 == 0) c0++;
		else c1++;
	}
	//for(auto x : arr) cout << x << ' ';
	//cout << ed;
	if((n % 2 == 0 && c1 != 0) || (n % 2 != 0 && c1 != 1)){
		//cout << n << ' ' << c1 << ed;
		cout << "NO SOLUTION";
		return 0;
	}
	vector<char> ans(n);
	if(n % 2 == 0){
		ll id = 0;
		ff(i, 0, n/2){
			while(arr[id] == 0)id++;
			ans[i] = id+'A';
			ans[n-1-i] = id+'A';
			arr[id]-=2;
		}
	}
	else{
		ll id = 0;
		ll pos = 0;
		ff(i, 0, 26) if(arr[i] % 2 != 0){pos = i; break;}
		ff(i, 0, n/2+1){
			while(id < 26 && (arr[id] == 0 || id == pos)) id++;
			if(id == 26){
				ans[i] = pos+'A';
				ans[n-1-i] = pos+'A';
				arr[pos]-=2;
			}
			else{
				ans[i] = id+'A';
				ans[n-1-i] = id+'A';
				arr[id]-=2;
			}
		}
	}
	for(auto x : ans) cout << x;
}
