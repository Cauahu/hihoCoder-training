#include <iostream>

using namespace std;

/*

利用分治思想处理最大子段和问题。
将序列a[1:n]分成长度相等的两段a[1:n/2]和a[n/2+1:n],分别求出这两段的最大字段和，则a[1:n]的最大子段和有三中情形：
[1]、a[1:n]的最大子段和与a[1:n/2]的最大子段和相同；
[2]、a[1:n]的最大子段和与a[n/2+1:n]的最大子段和相同；
[3]、a[1:n]的最大字段和为，且1<=i<=n/2,n/2+1<=j<=n。
可用递归方法求得情形[1],[2]。对于情形[3],可以看出a[n/2]与a[n/2+1]在最优子序列中。
因此可以在a[1:n/2]中计算出，并在a[n/2+1:n]中计算出。则s1+s2即为出现情形[3]时的最优值。
时间复杂度O(NlogN)

*/

int maxsubsum(int *a, int left, int right)//分治法
{
    int sum = 0;
    if(left == right)
    {
        sum = a[left];
    }
    else
    {
        int mid = (left+right)/2;
        int leftsum = maxsubsum(a,left,mid);//计算左边最大子段和
        int rightsum = maxsubsum(a,mid+1,right);//计算右边最大子段和

        //处理第3种情况
        int sum1 = -1000000, lefttemp = 0;
        for(int i=mid;i>=left;i--)//求以mid结尾的最大子段和
        {
            lefttemp += a[i];
            if(lefttemp > sum1)
                sum1 = lefttemp;
        }
        int sum2 = -1000000, righttemp = 0;
        for(int i=mid+1;i<=right;i++)//求以mid+1开头的最大子段和
        {
            righttemp += a[i];
            if(righttemp > sum2)
                sum2 = righttemp;
        }
        sum = sum1+sum2;
        if(sum < leftsum)
            sum = leftsum;
        if(sum < rightsum)
            sum = rightsum;
    }
    return sum;
}


int main()
{
    //int a[] = {-2,11,-4,13,-5,-2};
    int a[] = {-9,-2,-3,-5,-3,-7};
    //cout << maxsubsum(a,0,5) << endl;
    //动态规划法,状态转移方程：b[j]=max{b[j-1]+a[j],a[j]},1<=j<=n。
    int sum = a[0], b = a[0];
    for(int i=1;i<6;i++)
    {
        if(b+a[i] > a[i])
            b += a[i];
        else
            b = a[i];
        if(b > sum)
            sum = b;
        //cout << b << endl;
    }
    cout << sum ;
    return 0;
}
