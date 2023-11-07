class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int start = 0;
        int end = nums.size() - 1;
        while((end-start)>=2){
            int a = nums[start];
            int b = nums[end];
            if((a+b)<0){
                if(start==0 || (a!=nums[start-1] && b!=nums[end+1])){
                    int pointer = start + 1;
                    while(((a+b+nums[pointer])<=0) && (start<pointer) && (pointer<end)){
                        if((a+b+nums[pointer])==0){
                            vector<int> arr{a, nums[pointer], b};
                            result.push_back(arr);
                            break;
                        }
                        pointer++;
                    }
                }
                start++;
            }
            else{
                if(end==(nums.size()-1) || b!=nums[end+1]){
                    int pointer = end - 1;
                    while(((a+b+nums[pointer])>=0) && (start<pointer) && (pointer<end)){
                        if((a+b+nums[pointer])==0){
                            vector<int> arr{a, nums[pointer], b};
                            result.push_back(arr);
                            break;
                        }
                        pointer--;
                    }
                }
                end--;
            }
        }
        return result;
    }
};