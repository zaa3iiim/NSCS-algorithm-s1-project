#include<stdio.h>
#include"NSCSproject.h"

    int main() {
    int   matrix[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    } ;
    printf("%d",determinantMatrix(9,matrix));

    }