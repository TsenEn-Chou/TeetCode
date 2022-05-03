#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
	vector<int> :: iterator it;
	it = nums.begin();
	for(int i = 0  ; i < nums.size() ; i++ ){
		cout <<" i = " << i <<endl;;
		if(nums[i] == val){
			nums.erase(it);
			i--;
			it--;
		}
		for(int j = 0  ; j < nums.size() ; j++ )
			cout << nums[j];
		cout << endl;
		it++;

	}
	return nums.size();
}

int main(int argc,char **argv){
	vector<int> c = {0, 1, 2, 3, 4, 1, 5, 6, 7, 8};
	int i = removeElement(c,1);
	cout <<" nums.size = "<< i << endl;
}