//22 de Enero 2026 22:50
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
	vl arr(26, 0);
	string a, b;
	cin >> a >> b;
	ff(i, 0, a.size()){
		if(a[i] != '@') arr[a[i]-'a']++;
		if(b[i] != '@') arr[b[i]-'a']++;
	}
	ff(i, 0, 26){
		char x = 'a'+i;
		if(arr[x-'a'] %2 != 0){
			if(x == 'a' || x == 't' || x == 'c' || x == 'o' || x == 'd' || x == 'e' || x == 'r' ){
				continue;
			}
			else{
				cout << "No";
				return 0;
			}
		}
	}
	vl count(26, 0);
	ll ar = 0, br = 0;
	ff(i, 0, a.size()){
		if(a[i] != '@') count[a[i]-'a']++;
		else ar++;
		if(b[i] != '@') count[b[i]-'a']--;
		else br++;
	}
	ff(i, 0, 26){
		char x = 'a'+i;
		if(count[i] != 0){
			if(!(x == 'a' || x == 't' || x == 'c' || x == 'o' || x == 'd' || x == 'e' || x == 'r')){
				//cout << 0 << " " << x << ed;
				cout << "No";
				return 0;
			}
		}
		if(count[i] < 0){
			if(ar >= count[i]*(-1)){
				ar -= count[i]*(-1);
				count[i] = 0;
			}
			else{
				//cout << 1 << " " << x << ed;
				cout << "No";
				return 0;
			}
		}
		if(count[i] > 0){
			if(br >= count[i]){
				br -= count[i];
				count[i] = 0;
			}
			else{
				//cout << 2 << " " << x << ed;
				cout << "No";
				return 0;
			}
		}
	}
	cout << "Yes";
}
