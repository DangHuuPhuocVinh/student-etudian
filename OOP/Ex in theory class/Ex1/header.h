#include "conio.h"
#include "stdio.h"
#include "math.h"
#include "malloc.h"

struct PhanSo{
   int tu;
   int mau;
};
typedef struct PhanSo *ps;

ps Import();
ps Imports(int n);
void Print(PhanSo p);
void Prints(ps p, int n);
void swap(int a, int b);
void Partition(T a[], T left, T right);
T QuickSort(T array[], T left, T right);
void SelectionSort(T array[], T n);
