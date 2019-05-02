class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {


        int count1 = nums1.size();
        int count2 = nums2.size();
        int all = (count1+count2);


        vector<int> res(all);

        int i=0;
        int j=0;
        double median = 0.0;
        int n=0;
        while(i<count1 && j<count2){


            if(nums1[i]<nums2[j]){
                res[n] = nums1[i];
                i++;
            }else{
                res[n] = nums2[j];
                j++;
            }
            n=n+1;
        }

        while(i<count1){
            res[n] = nums1[i];
            i++;
            n=n+1;
        }
        while(j<count2){
            res[n] = nums2[j];
            j++;
            n=n+1;
        }

        if(all%2!=0){
            median = res[all/2];
        }
        else{
            median = (res[all/2]+res[all/2-1])/2.0;
        }
        return median;
        /*

        考虑这么几种情况
        1.在两个数据中遍历，比较的过程中找到median
        2.其中一个已经遍历结束，还未找到




        int count1 = nums1.size();
        int count2 = nums2.size();
        int all = (count1+count2);
        int mid = all/2;
        double max=-1;
        double old_max = -1;

        int i=0;
        int j=0;

        int n=0;

        while(i<count1 && j<count2){

            if(n == mid){

                if(all%2!=0){ //总长度是奇数时
                    max = max;
                }else{
                    max = (max+old_max)/2;
                }


                break;
            }

            n=n+1;

            if(nums1[i]>=nums2[j]){ //nums1[i]大，此时i不动，j移动
                max = nums1[i];
                old_max = max;
                j++;
            }else{
                max = nums2[j]; //与之相反
                old_max = max;
                i++;
            }

        }

        if(n<mid){

            if(i<count1){
                   if(all%2!=0){
                       max = nums1[mid-count2];
                   }else{
                       max = (nums1[mid-count2]+nums1[mid-count2-1])/2;
                   }
            }

            if(j<count2){
                   if(all%2!=0){
                       max = nums2[mid-count1];
                   }else{
                       max = (nums2[mid-count1]+nums2[mid-count1-1])/2;
                   }
            }

        }

        return max;
        */
    }
};