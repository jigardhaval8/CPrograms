#include <stdio.h>
#include <stdlib.h>

// This Function will Find Max and Min value in Input Array,
// And here we are passing value by reference so original variable will modified
void MinMaxinArray(int array[],int len, int *min, int *max)
{
    *max=*min=array[0];
    for(int i=0;i<len;i++)
    {
        if(array[i]>*max)
        {
            *max = array[i];
        }
        if(array[i]<*min)
        {
            *min = array[i];
        }
    }
}

int *MidofArry(int array[], int len)
{
    return &array[len/2];
}

void main()
{
    printf("Pointer Code \n");
    int a[] = {1,2,5,8,34,57,3,1,1,356,25,21};
    int length = sizeof(a)/sizeof(a[0]);
    int min_val, max_val;
    min_val = max_val = 0;
    MinMaxinArray(a,length,&min_val, &max_val);
    printf(" Max Value is : %d, Min Value is %d \n", max_val, min_val);

    int *mid=MidofArry(a,length);
    printf(" Mid Value is : %d \n", *mid);

    int *p=&a[1];
    int *q=&a[3];
    printf(" p is : %x, q is : %x, q-p is : %x\n", p,q,q-p);

    printf(" p is %x and value is *p %d\n",p,*p);
    printf(" *p++ is %d \n",*p++);
    printf(" *p++ is %d \n",*p++);
    printf(" *++p is %d \n",*++p);
    printf(" p is %x \n",p);


    int ary[]={3,4,5,6,7,8,9};
    int (*ap)[5]=&ary;
    printf(" Address of ary is: %p \n", ary);
    printf(" Address of ap is: %p \n", ap);
    printf(" Address of *ap is: %p \n", *ap);
    printf(" Address of *ap[1] is: %d \n", *ap[1]);
    printf(" Address of *ap[2] is: %d \n", *ap[2]);
    printf(" Address of *ap[3] is: %d \n", *ap[3]);

}
