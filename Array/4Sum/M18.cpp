#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        set<vector<int> > sans;
        vector<vector<int> > vans;
        if (nums.size() < 4)
            return vans;
        
        sort(nums.begin(),nums.end());
        
        // w + x + y + z = target
        for(int w = 0 ; w < nums.size() ; w++){
            int tar_xyz = target - nums[w];
            
            for(int x = w + 1 ; x < nums.size() ; x++){
                
                int tar_yz = tar_xyz - nums[x];
                int y = x+1;
                int z = nums.size()-1;
                
                while(y < z){
                    int yz = nums[y] + nums[z];
                    
                    if(yz > tar_yz) z--;
                    else if(yz < tar_yz) y++;
                    else{
                        vector<int> a(4, 0);
                        a[0] = nums[w];
                        a[1] = nums[x];
                        a[2] = nums[y];
                        a[3] = nums[z];
                        sans.insert(a);
                        
                        //while (y < z && nums[y] == a[2]) ++y;
                        //while (y < z && nums[z] == a[3]) --z;
                    }
                }
                 //while(x + 1 < nums.size() && nums[x + 1] == nums[x]) ++x;
            } 
            //while(w + 1 < nums.size() && nums[w + 1] == nums[w]) ++w;
        }
        
        for(auto p: sans) vans.push_back(p); 
        
        return vans;
        
    }
};

int main(){
    vector<int> nums(5,2);
    Solution *a = new Solution;
    vector<vector<int> > ans = a->fourSum(nums,8);
    return 0;
}
