#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'

void Solve() {
    int n, k; cin >> n >> k;
    map<int, int> mp;
    int sum = 0, ans = 0;
    mp[0] = 1;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        sum += x;
        sum %= k;
        ans += mp[sum]++;
    }   
    cout << ans;
}
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);freopen("out.txt", "w", stdout);
#endif
    int t = 1;// cin >> t;
    while(t--) Solve();
}
