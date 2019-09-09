#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<pair<int,int>> intervals;
        vector<int> results;
        for(int i=0; i<n; i++){
            int start , end;
            cin >> start >> end;
            intervals.push_back(make_pair(start,end));
           
        }
        sort(intervals.begin(),intervals.end());
        while(m--)
        {
            int curr_time;
            cin >> curr_time;
            int position = lower_bound(intervals.begin(), intervals.end(), make_pair(curr_time, 0)) - intervals.begin();
            if(position==0){
                int ans = intervals[0].first - curr_time;
                // results.push_back(ans);
                cout << ans << endl;
            }
            else {
                int ans = -1;
                if(intervals[position-1].second > curr_time){
                    ans=0;
                }
                else if(position<intervals.size()){
                    ans = intervals[position].first - curr_time;
                }
                // results.push_back(ans);
                cout << ans << endl;

            }

        }
        // for(int i=0; i<n; i++){
        //     cout << results[i] << endl;
        // }
    }

}

