#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#define REG(X) (*(uint8_t *)&X)
void decimalToBinary(int num);

typedef struct {
    uint8_t dier: 1;
    uint8_t egr : 3;
    uint8_t ldr : 4;
} MyStruct;

int main() {
    MyStruct my_struct = {0b1, 0b000, 0b1001};
    decimalToBinary(REG(my_struct)); // 1001 000 1 => ldr = 0b1001, egr = 0b000, dier = 0b1 
    my_struct.egr = 0b111; 
    printf("\n");
    decimalToBinary(REG(my_struct)); // 1001 111 1 => ldr = 0b1001, egr = 0b111, dier = 0b1
    return 0;
}









void decimalToBinary(int num) {   
    if (num == 0) {
        printf("0");
        return;
    }
   
   // Stores binary representation of number.
   int binaryNum[32]; // Assuming 32 bit integer.
   int i=0;
   
   for ( ;num > 0; ){
      binaryNum[i++] = num % 2;
      num /= 2;
   }
   
   // Printing array in reverse order.
   for (int j = i-1; j >= 0; j--)
      printf("%d", binaryNum[j]);
}
