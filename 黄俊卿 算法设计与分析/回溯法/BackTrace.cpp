#include<stdio.h>
int b[100];   //���ڴ����Ѿ��źõ�����
bool used[100];  // �ж���Щ�����Ѿ��Ź�
int n;     // 1-n ��ȫ����
int sum=0;   // ͳ���ж���������

void output()  // ��ӡ��������
{
	printf("��%d�����:  \t",++sum);
	for(int i=1;i<=n;i++)
	{
		printf("%d",b[i]);
	}
	printf("\n");
}

void solve(int k) // �ӵ�һ������ʼ��
{
	for(int i=1;i<=n;i++)  // �����֣�1-n�������ǰk����
	{
		if(!used[i])
		{
			b[k]=i;
			used[i]=1;
			if(k==n)     // �ݹ����      
			{
				output(); // ��ӡ����
			}  
			else
			{
				solve(k+1);   //û��������n�����֣�����������һ������
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
