#include "header.h"


int linSearch(int arr[]) {
    int result = 0;
    for (int i = 0; i < sizeof(arr); i++) {
        if (arr[i] < arr[result]) {
            result = i;
        }

    }
    return result;
}