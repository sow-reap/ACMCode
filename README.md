# ACMCode
#ACM试题与代码分享
#题目：
#给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。

#注意：答案中不可以包含重复的三元组。

 

 

#首先运用排序算法对给定的数组进行排序，方便后续的双指针的查找符合条件的三元组
#然后创建一个容器去存放符合条件的三元组
#然后使用一个 for 循环遍历数组，先选出第一个数，判断如果i=0，则不跳过当前循环，如果i！=0并且num[i]==nums[i-1]就跳过本次循环，因为重复了没必要再查找一次nums[j]和nums[k]
#让j指向i+1的位置，k指向最后一个数的位置，当j<k的时候，先求出nums[j]+nums[k]的和，去和nums[i]作比较，如果sum==-nums[i]则符合三数求和，存储到容器ans内
#然后调整j和k的指向的位置，当然在调整之前仍然可以进行去重的操作，条件是当j<k && nums[j]==nums[j+1]时j++;，当nums[k]==nums[k-1]k--;在进行这两个条件判断之前要比较j是否小于k，保证代码的逻辑正确
#当判断出sum<-nums[i]，j指针可以向右移去寻找符合条件的数，另外一种情况sum>-nums[i]，就让k指针向左移动，也就是k--；前提是数组已经排过序；


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            if(i && nums[i]==nums[i-1]) continue;
            int j=i+1,k=nums.size()-1;
            while(j<k){
                int sum=nums[j]+nums[k];
                if(sum==-nums[i]){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[j]==nums[j+1]) j++;
                    while(j<k && nums[k]==nums[k-1]) k--;
                    j++;
                    k--;
                }else if(sum<-nums[i]){
                    j++;

                }else{
                    k--;
                }

            }
        }
        return ans;
    }

};
