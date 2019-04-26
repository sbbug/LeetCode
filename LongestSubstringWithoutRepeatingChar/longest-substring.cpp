class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int i,j;
        int max=0;
        int start=0;

        //只有大于1时才进入
        if(s.size()>1){
             max=1; // 最糟糕的情况全部相同
             for(i=1;i<s.size();i++){
                   for(j=start;j<i;j++){
                           if(s[i]!=s[j]){
                              if ((j+1-start+1)>max)
                               {
                                   max = j+1-start+1;
                               }
                           }else{
                               start=j+1;
                           }
                   }
             }

        }else if(s.size()==1){
           max=1;
        }
        return max;
    }
};