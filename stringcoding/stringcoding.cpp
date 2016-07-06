#include"stdio.h"
#include<algorithm>
#include"string.h"
using namespace std;
int hufman(int b[],int n){
    int re=0;
    while(n>1){
        sort(b,b+n);
        re+=b[0]+b[1];
        b[0]=b[0]+b[1];
        for(int i=2;i<n;i++){
            b[i-1]=b[i];
        }
        n--;
    }
    return re;
}
int main(){
    int a[256];
    char str[1000];
    while(scanf("%s",str)!=EOF){
        for(int i=0;i<256;i++)
            a[i]=0;
         
        int len=strlen(str);
        for(int i=0;i<len;i++)
            a[(int)str[i]]++;
         
        int cnt=0;
        int b[256];
        for(int i=0;i<256;i++){
            if(a[i]>0){
                b[cnt]=a[i];
                cnt++;
            }
        }
        int re=hufman(b,cnt);
        printf("%d\n",re);
    }
    return 0;
}