/*Approach 1 : Pick or Not Pick
Recursion :
For the given element that is passed in the current recursion call, we travel across all the other elements using a for loop.

In the for loop : We check if an element is already picked or not. If it is not picked, we add it to our current answer and 
then mark it as picked and create another recursion call for the next element.

Base Case :
Whenever the number of elements in our current answer curr become equal to the number of elements is original array nums we have 
a permutation. We then push it to our main ans. */

Code
class Solution {
public:
    void calculate(vector<int>& nums,vector<vector<int>>& ans,int check[],vector<int>&curr){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=0; i<nums.size();i++){
            if(!check[i]){
                check[i]=1;
                curr.push_back(nums[i]);
                calculate(nums,ans,check,curr);
                curr.pop_back();
                check[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        int check[nums.size()];
        for(int i=0; i<nums.size(); i++)    check[i]=0;
        calculate(nums,ans,check,curr);
        return ans;
    }
};
/*Approach 2 : Swapping Elements
Recursion :
We are trying that every number gets to be at every index to generate a new permutation. In order to do that, we fix the first element into 
the current permutation curr and then swap the elements on the right of it. We keep on doing this fixing and swapping the rightward elements
( swap index with every element from index -> nums.size()-1 ) recursively till we reach the end of the nums array.

Base Case :
Whenever the number of elements in our current answer curr become equal to the number of elements is original array nums we have a permutation. 
We then push it to our main ans.*/

Code
class Solution {
public:
    void solve (int index, vector<int>& nums, vector<vector<int>>& ans) {
        if( index == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            solve (index+1, nums, ans);
            swap(nums[index], nums[i]);         
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> ans;
       vector<int> curr;
       solve(0, nums, ans); 
       return ans; 
    }
};