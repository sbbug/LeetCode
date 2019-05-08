class Solution {
public:
    int reverse(int x) {

        // 如果传入的x超出下限直接返回
        if(x<=INT_MIN) return 0;

        //判断是否为负数
        bool flag = true;
        if(x<0){
            x = -x;
            flag = false;
        }

        //定义为长整型
        long res = 0;
        while(x){

            int a = x % 10;
            x = (x - a)/10;

            res = res + a;
            res = res*10;


        }
        res = res/10;

        //如果最后的长整型超出32整型最大值
        if(res>=INT_MAX) return 0;

        //考虑负数
        if(flag==false) res = res * -1;



        return res;
    }


};