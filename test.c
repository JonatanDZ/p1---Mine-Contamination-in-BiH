#include <stdio.h>
#include <stdlib.h>





typedef enum {
    mine = 00,
    water = 00,
    asphalt = 10,
    city = 12,
    field = 15,
    forest = 20,
    mountain1 = 22,
    mountain2 = 27
} moveValue;

int main(){

int arr1[] =                                     {mountain2, mountain2, mountain1, forest, forest, city, city, city, city, city, asphalt, asphalt, city, city, city, water, water, asphalt, asphalt, city, city, city, field, field, field, mine, forest, forest, forest, forest, mountain1, mountain1, mountain1};

int length = sizeof(arr1)/sizeof(int);    
printf("%d", length); 
return 0;
}

