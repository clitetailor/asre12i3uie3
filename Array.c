#include "Array.h"
#include <stdlib.h>
#include <stdio.h>



void initialize(struct Array **aptr, int size)
{
	(*aptr) = (struct Array*) malloc( sizeof(struct Array) );
	
	(*aptr)->Max = (float*) malloc( sizeof(float) * size);
	
	(*aptr)->Count = size;
	
};

void delete(struct Array *a)
{
	free(a->Max);
	free(a);
};



float get(struct Array *a, int i)
{
	if (i > -1 && i < a->Count)
		return a->Max[i];
	else
		return -1;
};

void set(struct Array *a, int i, float data)
{
	if (i > -1 && i < a->Count)
		a->Max[i] = data;
};

void swap(struct Array *a, int i1, int i2)
{
	if (i1 > -1 && i1 < a->Count && i2 > -1 && i2 < a->Count)
	{
		float n = a->Max[i1];
		a->Max[i1] = a->Max[i2];
		a->Max[i2] = n;
	}
};


void print(struct Array *a)
{
	printf("\n");
	int i;
	for (i = 0; i < a->Count; ++i)
	{
		printf("%d: %-5.0f ", i + 1, get(a, i));
	
		if (i % 5 == 4)
			printf("\n");
		else
			printf("| ");
	}
	printf("\n");
}




void insert(struct Array *a, int k, float value) 
{
    int i= k-1;
    while (i > 0 && get(a,i) > value) 
	{
		set(a,i+1,get(a,i));
        i= i - 1;
    }
    set(a,i+1,value);
}

// Sắp xếp chèn
void insertionsort(struct Array *a)				// Sắp xếp chèn
{
    int k= 2,length=1;
    while(get(a,length)!=-1) length++;
    while (k < length) 
	{
        insert(a, k, get(a,k));
        k= k + 1;
    }
};




// Trả về giá trị nhỏ nhất // Mảng minArray dùng để lưu vị trí các phân tử nhỏ nhất
float min(struct Array *a, int **minArray)			// Trả về giá trị nhỏ nhất // Mảng minArray dùng để lưu vị trí các phân tử nhỏ nhất
{
	int i=0,k,j,h,m;
    k=1;h=0,m=get(a,0);
    i=a->Count;
    for(j=0;j<i;++j)
    {
        if(get(a,j)<=m) if(get(a,j)==m) k++;
        else
        {
            k=1;
            m=get(a,j);  
        }
    }
    int f[k];
    for(j=0;j<i;++j) if(get(a,j)==m)
    {
        f[h]=j;
        h++;
    }
    *minArray=f;
    return m;

};