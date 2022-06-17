/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int camera;
    int minCameraCover(TreeNode* root) {
        camera=0;
        pair<bool,bool> tmp=cnt_cam(root);
        if(!tmp.second)
        {
            camera++;
        }
        return camera;
    }
    pair<bool,bool> cnt_cam(TreeNode* root)
    {
        if(root==NULL){
            return {false,true};
        }
        pair<bool,bool> L= cnt_cam(root->left);
        pair<bool,bool> R=cnt_cam(root->right);
        bool has_cam=false,monitored=false;
        if(L.first || R.first)
        {
            monitored=true;
        }
        if(!L.second || !R.second)
        {
            has_cam=true;
            monitored=true;
            camera++;
        }
        return {has_cam,monitored};
    }
};