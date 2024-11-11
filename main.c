#include <stdio.h>
int printMap(int* map);

int main(){
    printf("Hello, from p1---Mine-Contamination-in-BiH!\n");
}

int printMap(int* map){
    int length = sizeof(map);
    for (int i = 0; i < length; i++){
        for (int j = 0; j < length; j++){
            printf(" %d ", map[i * length + j]);
        }
        printf("\n");
    }
    return map;
}
