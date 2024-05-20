class Solution {
private:
    void recursion(int currentXOR, int& total, vector<int> nums, int index){
        if (index == nums.size()) {
            total+= currentXOR;
            return;
        }
        recursion(currentXOR ^ nums[index], total, nums,index+1);

        // Do not include nums[index] in the subset
        recursion(currentXOR, total, nums, index+1);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int result;
        recursion(0,result,nums,0);
        return result;
    }
};