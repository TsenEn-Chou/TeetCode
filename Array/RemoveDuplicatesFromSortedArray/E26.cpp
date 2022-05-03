#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
	nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
	return nums.size();
}

int main(int argc , char **argv){
	vector<int> c = {0,0,1,1,1,3,2,3,2,4};
	int i = removeDuplicates(c);
	for(int j = 0  ; j < c.size() ; j++ )
		cout << c[j];
	cout <<" nums.size = "<< i << endl;
}