#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Insert_a(int arr[],int len){ //��������
	int i,j,value;
	for(i=0;i<len-1;i++){
		value=arr[i+1];
		for(j=i+1;j>0 && value<arr[j-1];j--){    //����valueֵ�����Ԫ�غ���
			arr[j]=arr[j-1];
		}
		arr[j]=value;
	}

}

void QuickSort(int arr1[], int low, int high){  //�������� 
	if (low < high)    
	{    int i = low;
	     int j = high;
	     int k = arr1[low];   
      while (i < j)       
	  {            
		 while(i < j && arr1[j] >= k)     // ���������ҵ�һ��С��k����                                   100�����Ŀ�������Ͳ��������ʱ��Ա�
		 { 
			 j--;  
		 }  
		    if(i < j) 
			{
                arr1[i++] = arr1[j];
            }
			while(i < j && arr1[i] < k)      // ���������ҵ�һ�����ڵ���k����
            {
                i++;
            }
			if(i < j)
            {
                arr1[j--] = arr1[i];
            }
	 }
	 arr1[i] = k;         // �ݹ����
	 QuickSort(arr1, low, i - 1);     // ����k���
	 QuickSort(arr1, i + 1, high);    // ����k�ұ�
    }
	}
void display(int arr2[],int len){   //�������

	for(int i=0;i<=len-1;i++)
	printf("%d  ",arr2[i]);

    printf("\n");
}
void main(){
	int i=0,j=100;
	int a[100];
	int b[100];
	clock_t begin,stop;
	clock_t begin2,stop2;
	for(;i<j;i++)      //�����������a��b
		b[i]=a[i]=rand()%1000;
    printf("����ǰ������:\n");
	display(a,j);
	begin=clock();
	Insert_a(a,j);
	stop=clock();
    printf("��������������:\n");
	display(a,j);
	printf("������������ʱ�䣺%ld\n",(stop-begin/CLOCKS_PER_SEC));
	begin2=clock();
    QuickSort(b,0,j-1);
	stop2=clock();
	printf("��������������:\n");
	display(b,j);
	printf("������������ʱ�䣺%ld\n",(stop2-begin2/CLOCKS_PER_SEC));
}
