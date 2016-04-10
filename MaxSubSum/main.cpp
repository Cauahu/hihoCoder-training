#include <iostream>

using namespace std;

/*

���÷���˼�봦������Ӷκ����⡣
������a[1:n]�ֳɳ�����ȵ�����a[1:n/2]��a[n/2+1:n],�ֱ���������ε�����ֶκͣ���a[1:n]������Ӷκ����������Σ�
[1]��a[1:n]������Ӷκ���a[1:n/2]������Ӷκ���ͬ��
[2]��a[1:n]������Ӷκ���a[n/2+1:n]������Ӷκ���ͬ��
[3]��a[1:n]������ֶκ�Ϊ����1<=i<=n/2,n/2+1<=j<=n��
���õݹ鷽���������[1],[2]����������[3],���Կ���a[n/2]��a[n/2+1]�������������С�
��˿�����a[1:n/2]�м����������a[n/2+1:n]�м��������s1+s2��Ϊ��������[3]ʱ������ֵ��
ʱ�临�Ӷ�O(NlogN)

*/

int maxsubsum(int *a, int left, int right)//���η�
{
    int sum = 0;
    if(left == right)
    {
        sum = a[left];
    }
    else
    {
        int mid = (left+right)/2;
        int leftsum = maxsubsum(a,left,mid);//�����������Ӷκ�
        int rightsum = maxsubsum(a,mid+1,right);//�����ұ�����Ӷκ�

        //�����3�����
        int sum1 = -1000000, lefttemp = 0;
        for(int i=mid;i>=left;i--)//����mid��β������Ӷκ�
        {
            lefttemp += a[i];
            if(lefttemp > sum1)
                sum1 = lefttemp;
        }
        int sum2 = -1000000, righttemp = 0;
        for(int i=mid+1;i<=right;i++)//����mid+1��ͷ������Ӷκ�
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
    //��̬�滮��,״̬ת�Ʒ��̣�b[j]=max{b[j-1]+a[j],a[j]},1<=j<=n��
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
