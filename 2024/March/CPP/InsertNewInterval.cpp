

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        int i=0;
        vector<vector<int>> res;
        // intervals = [[1,3],[6,9]], newInterval = [2,5]
        // Output: [[1,5],[6,9]]
        // 3 < 2 -> then res=[[1,3]] -> but condition not true
        while(i<n && intervals[i][1]<newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }
        //5>1
        while(i<n && newInterval[1]>=intervals[i][0]){
            newInterval[0]=min(newInterval[0], intervals[i][0]); // (2,)
            newInterval[1]=max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        while(i<n){
            res.push_back(intervals[i]);
            i++;
        }
        return res;
        
    }
};