#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#define REG(X) (*(uint8_t *)&X)
void dec2bin(int num);

typedef struct {
    uint8_t dier: 1;
    uint8_t egr : 3;
    uint8_t ldr : 4;
} _8bit_register;

int main() {
    _8bit_register a_reg = {0b1, 0b000, 0b1001};
    dec2bin(REG(a_reg)); // 1001 000 1 => ldr = 0b1001, egr = 0b000, dier = 0b1 
    a_reg.egr = 0b111; 
    printf("\n");
    dec2bin(REG(a_reg)); // 1001 111 1 => ldr = 0b1001, egr = 0b111, dier = 0b1
    return 0;
}



void dec2bin(int num) {   
    if (num == 0) {
        printf("0");
        return;
    }
   int b_num[32];
   int i=0;
   
   for ( ;num > 0; ){
      b_num[i++] = num % 2;
      num /= 2;
   }
   for (int j = i-1; j >= 0; j--)
      printf("%d", b_num[j]);
}
