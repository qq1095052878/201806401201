#include<stdio.h>
int b[100];   //用于储存已经排好的序列
bool used[100];  // 判断哪些数字已经排过
int n;     // 1-n 的全排列
int sum=0;   // 统计有多少排列数

void output()  // 打印好排列数
{
	printf("第%d个组合:  \t",++sum);
	for(int i=1;i<=n;i++)
	{
		printf("%d",b[i]);
	}
	printf("\n");
}

void solve(int k) // 从第一个数开始排
{
	for(int i=1;i<=n;i++)  // 把数字：1-n，填到数组前k个中
	{
		if(!used[i])
		{
			b[k]=i;
			used[i]=1;
			if(k==n)     // 递归层数      
			{
				output(); // 打印出来
			}  
			else
			{
				solve(k+1);   //没有排列满n个数字，继续排列下一个数字
			}
			used[i]=0;
		}
	}
}

int main()
{
    n=4;     
	solve(1);
	printf("ok\n");
	return 0;
}
