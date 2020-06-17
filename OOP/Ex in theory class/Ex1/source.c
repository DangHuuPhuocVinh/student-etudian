#include "header.h"

//Import fraction
ps Import()
{
   ps p;
   
   printf("\ttu: ");
   scanf("%d", &p.tu);
   temp.mau = 0;
   
   while(p.mau == 0)
   {
      printf("\tMau: ");
      scanf("%d", &p.Mau);
   }
   
   return p;
}

//Import many fractions
ps Imports(int n) 
{
   ps p = (ps)malloc(sizeof(PhanSo)*n);
   
   for(int i = 0; i<n;i++)
   {
      printf("Phan so %d\n", i);
      array[i] = Import();
   }
   
   return p;
}

//Print fraction
void Print(PhanSo p) 
{
   printf("%d/%d", p.tu, p.mau);
}

//Print many fractions
void Prints(ps p, int n) 
{
   int i;
   
   printf("\nDay phan so la:\n\t");
   for(i = 0; i < n-1; i++)
   {
      Xuat(p[i]);
      printf(",");
   } 
   
   Print(p[n-1]);
}

//Swap position of fractions
void swap(int a, int b)
{
	int temp;
	
	temp = a;
	a = b;
	b = temp; 
}
template<class T> //T de tham so hoa kieu du lieu
//ham partition(phan hoach) chon phan tu pivot la phan tu dau tien cua day
void Partition(T a[], T left, T right)
{
	int p = array[left];//phan tu chot(pivot)
	last_S = left;//bat dau cua day S
	first_U = left + 1;//bat dau cua day Unknown, tam goi la day chua nhung con so khong biet cho sort
	
	while(first_U <= right)
	{
		if (array[first_U] < p)
			{
				swap(a[first_U], a[last_S + 1]);
				last_S + 1;
			}
			
		first_U++;
	}
	
	swap(array[left], array[last_S]);
}

//dung quick sort de sap xep tu nho den lon
T QuickSort(T array[], T left, T right)
{
	if(left == right)
		return;
	int pivotIndex = Partition(a[], left, right);
	QuickSort(array[], left, pivotIndex - 1);
	QuickSort(array[], pivotIndex + 1, right);
	
	return 0;
}

template<class T> //T de tham so hoa kieu du lieu
//dung selection sort de sap xep tu lon den nho
void SelectionSort(T array[], T n)
{
	int i, j, pos, n;
	
	while(i < n-1)
		{
			pos = n-1;
			for(j = i; j < n; j--)
				{
					if(a[j] > a[pos])
							pos = j;
					if(i != pos)
							swap(a[i], a[pos]);
				}
		i++;
		}
}


