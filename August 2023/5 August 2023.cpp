class Solution {
public:
    vector<TreeNode*> buildTrees(int l, int r)
    {
      if(l > r) return {nullptr};
      vector<TreeNode*> ans;

      for(int i=l; i<=r; i++)
      {
        vector<TreeNode*> left = buildTrees(l, i-1);
        vector<TreeNode*> right = buildTrees(i+1, r);

        for(int j=0; j<left.size(); j++)
        {
          for(int k=0; k<right.size(); k++)
          {
            ans.push_back(new TreeNode(i, left[j], right[k]));
          }
        }
      }
      return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return buildTrees(1,n);
    }
};