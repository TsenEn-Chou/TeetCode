#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans(1);
        vector<int> cur(1);
        sort(nums.begin() ,nums.end());
        
        for(int i = 0 ; i <= nums.size() ; i++)
            dfs(nums, i, 0, ans, cur);
        
        return ans;
    }
private:
    void dfs(const vector<int> &nums, int n, int s, 
            vector<vector<int>> &ans, vector<int> &cur){
        
        if(n == cur.size()){
            ans.push_back(cur);
            return ;
        }
        
        for(int i = s; i < nums.size(); i++){
            cur.push_back(nums[i]);
            dfs(nums, n, i+1, ans, cur);
            cur.pop_back();
            while(i < nums.size() && nums[i+1] == nums[i]) i++;
        }
            
    }
};

int main(){
    Solution sol;
    vector<int> foo{1,1,2};
    vector<vector<int>> ans1;  
    ans1 = sol.subsetsWithDup(foo); 
    return 0;
}