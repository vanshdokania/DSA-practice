#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int t; 
    cin >> t;
    while(t--){
        int n; 
        string s; 
        cin >>n >> s;
        int ans = 0;
        for (int i = 0; i < n; i++) if (s[i] == '1') ans++;
        if (ans == 0) {
            cout << (n + 2) / 3 << "\n";
            continue;
        } 
        ll x = 0;
        int first = s.find('1');
        int last = s.rfind('1');
        x += (first + 1) / 3;
        for(int i = first; i < last;){
            int j = i + 1;
            int chain = 0;
            while (j <= last && s[j] == '0') {
                chain++;
                j++;
            }
            x += chain / 3;
            i = j;
        }
        x += (n - 1 - last + 1) / 3;
        ans += x;
        cout << ans << "\n";
    }
    return 0;
}

    