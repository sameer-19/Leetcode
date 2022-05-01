class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int i,left,right;
        
        int n=image.size();
        
        for(i=0;i<n;i++)
        {
            left=0;right=n-1;
            while(left<=right)
            {
                image[i][left]=1-image[i][left];
                
                if(left!=right) image[i][right]=1-image[i][right];
                
                swap(image[i][left],image[i][right]);
                left++;
                right--;
            }
        }
        return image;
    }
};