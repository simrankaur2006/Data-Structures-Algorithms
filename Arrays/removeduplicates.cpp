#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums){
    int n = nums.size();

    if(n == 0) return 0;

    int i = 0;
    int j = 1;

    while(j < n){

        if(nums[i] != nums[j]){
            i++;
            nums[i] = nums[j];
        }

        j++;
    }

    return i + 1;
}

int main(){
    vector<int> nums = {5,5,5,13,13,13,15,20,20,25,25,25};

    cout << removeDuplicates(nums) << endl;

    return 0;
}