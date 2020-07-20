#include <iostream>
#include <cstring>
using namespace std; //自底向上，两个循环，不用递归；

void main()  {
		int n;
		cin>>n;
		int price[11]={0,1,5,8,9,10,17,17,20,23,28};
		int *r=new int [n+1];
		for(int k = 0; k<= n; ++k)
			r[k] = 0; 
		for(int i = 1; i <= n; ++i)
		{          
			int q = INT_MIN;
			for(int j = 1; j <= i; ++j)//计算规模为i的最大收益
			{              
				if(q < (price[j] + r[i-j]))//因为i>i-j，所以当计算r[i]时，r[i-j]已经解决，可以直接用
					q = (price[j] + r[i-j]);  
			}          
			r[i] = q;  //找出i这个位置的最优解；
		}
		cout<<r[n];  //n米长的木头的最大价值。
	} 
