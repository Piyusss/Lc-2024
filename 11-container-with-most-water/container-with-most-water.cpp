class Solution {
public:
    int maxArea(vector<int>& height){
        int n=height.size();

        int left=0;
        int right=n-1;
        int maxi=0;

        while(left<right){

            int w=right-left;
            int h=min(height[left],height[right]);
            int area=h*w;

            maxi=max(maxi,area);
            if(height[left]<height[right])left++;
            else if(height[right]<height[left])right--;
            else{
                left++;
                right--;
            }

        }
        
        return maxi;
    }
};