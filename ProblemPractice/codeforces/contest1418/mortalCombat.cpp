#include "/Users/gbatra/ProblemPractice/stdc++.h"
using namespace std;
    
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
 
const int INF = 1e9 + 5;
 
void run_case() {
    int N;
    cin >> N;
    vector<int> A(N);
 
    for (auto &a : A)
        cin >> a;
 
    vector<array<int, 2>> dp(N + 1, {INF, INF});
    dp[0][1] = 0;
 
    for (int i = 0; i < N; i++)
        for (int who = 0; who < 2; who++)
            for (int fight = 1; fight <= min(N - i, 2); fight++) {
                int hard = A[i] + (fight > 1 ? A[i + 1] : 0);
                dp[i + fight][!who] = min(dp[i + fight][!who], dp[i][who] + who * hard);
            }
 
    cout << min(dp[N][0], dp[N][1]) << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif
 
    int tests;
    cin >> tests;
 
    while (tests-- > 0)
        run_case();
}