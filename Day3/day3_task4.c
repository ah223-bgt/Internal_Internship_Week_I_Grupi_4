#include <stdio.h>

int main() {
    int num = 10;
    double price = 19.99;
    
    // Krijimi i pointerave [cite: 151]
    int *ptrNum = &num;
    double *ptrPrice = &price;
    
    // Shfaqja e vlerave dhe adresave fillestare [cite: 152]
    printf("Initial int value: %d, Address: %p\n", num, (void*)&num);
    printf("Value via pointer: %d\n", *ptrNum);
    
    int oldNum = num; // Ruajmë vlerën e vjetër për krahasim [cite: 153]
    
    // Ndryshimi i vlerës përmes pointerit [cite: 153]
    *ptrNum = 25; 
    
    printf("\nValue after change: %d\n", *ptrNum);
    
    // Kontrolli me if/else [cite: 154]
    if (*ptrNum > oldNum) {
        printf("The value has increased.\n");
    } else if (*ptrNum < oldNum) {
        printf("The value has decreased.\n");
    } else {
        printf("The value remained the same.\n");
    }
    
    return 0;
}
