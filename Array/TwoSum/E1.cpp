#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int,int> hash;
	for( int i = 0; i<nums.size(); i++ )
		hash[nums[i]] = i;
	
	for(int i = 0; i<nums.size(); i++ ){
		int y = target - nums[i];
		//要有這個 key，並且不可以用重複的 key 
		if(hash.count(y) && hash[y] != i){
			return {i , hash[y]};
		} 
	}
}

int main(int argc, char** argv){
	vector<int> numsA;
	numsA.push_back(3);
	numsA.push_back(2);
	numsA.push_back(4);
	vector<int> result;
	result = twoSum(numsA,6);
	cout << result[0] << "," << result[1] << endl;
	return 0;
}

