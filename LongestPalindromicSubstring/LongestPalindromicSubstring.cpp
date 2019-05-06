class Solution {
public:


    string getHuiWen(string str){

        int N = str.size();
        N = 2*N + 1;
        int L[N];
        L[0] = 0;
        L[1] = 1;
        int center = 1;

        int i = 0;
        int iMirror;
        int expand = -1;
        int diff = -1;
        int max_r = 0;
        int max_i = 0;
        int start = -1;
        int end = -1;

    for (i = 2; i < N; i++)
    {

        iMirror  = 2*center-i; //获取对称点

        expand = 0;
        diff = L[center] - i; //距离

        if(diff > 0)
        {
            if(L[iMirror] < diff)
                L[i] = L[iMirror];
            else if(L[iMirror] == diff && i == N-1)
                L[i] = L[iMirror];
            else if(L[iMirror] == diff && i < N-1)
            {
                    L[i] = L[iMirror];
                    expand = 1;
            }
            else if(L[iMirror] > diff)
            {
                L[i] = diff;
                expand = 1;
            }
        }
        else
        {
            L[i] = 0;
            expand = 1;
        }

        //是否扩张
        if (expand == 1)
        {

            while(  ((i + L[i]) < N && (i - L[i]) > 0) &&
                ( ((i + L[i] + 1) % 2 == 0) ||
                (str[(i + L[i] + 1)/2] == str[(i-L[i]-1)/2] )))
            {
                L[i]++;
            }
        }

        // 寻找最长回文串
        if(L[i] > max_r)
        {
            max_r = L[i];
            max_i = i;
        }

        // 寻找最大中心位置
        if (i + L[i] > L[center])  center = i;

    }

        for(int h=0;h<N;h++)cout<<L[h];

        start = (max_i - max_r)/2;
        end = start + max_r;
        return str.substr(start,end-start);
    }




    string longestPalindrome(string s) {

        int n = s.size();

        if(n==0 || n==1)
            return s;

        string res = getHuiWen(s);

        return res;

    }
};