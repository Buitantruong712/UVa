#include <bits/stdc++.h>

using namespace std;
const int Maxn = 6100 + 7;

string s1, s2;
int n1, n2;
int t, ca = 1;

void solve() {
    // this array use for counting neccessary characters --> the shortest string
    // include two subsequence is two initial strings
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
    // this array use for counting number of the shortest string string include
    // two subsequence is two initial strings
    vector<vector<long long>> way(n1 + 1, vector<long long>(n2 + 1));
    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            if (i == 0 || j == 0) {
                // it mean one string empty
                dp[i][j] = i + j;
                way[i][j] = 1;
            } else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                way[i][j] = way[i - 1][j - 1];
            } else {
                //s1[i - 1] != s2[j - 1] --> we have 2 case:
                //  first, this is dp[i - 1][j], charater s1[i - 1] hasn't appeared
                //  second, this is dp[i][j - 1], character s2[j - 1] hasn't appeared
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                if(dp[i][j] == dp[i - 1][j] + 1)
                    way[i][j] += way[i - 1][j];
                if(dp[i][j] == dp[i][j - 1] + 1)
                    way[i][j] += way[i][ j -1];
            }
        }
    }

    cout << "Case " << ca++ << ": " << dp[n1][n2] << " " << way[n1][n2] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> s1 >> s2;
        n1 = s1.size(), n2 = s2.size();
        solve();
    }

    return 0;
}
