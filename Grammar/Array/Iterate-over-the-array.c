#include <stdio.h>

int arr[]={1,3,4,5};

int main(void)
{
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        printf("%d",arr[i]);
    }
    
}