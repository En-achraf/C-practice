#include <stdio.h>

//AND & CHOSE THE TOW SAME NUMBER AND MAKE IT (1 & 1) = 1; (0 & 1) = 0
//OR | CHOSE THE DIFFERENCE AND THE TOW NUMBER AND MAKE IT (1 | 1) = 1; (0 | 1) = 1 (0 |& 0) = 0
//xOR ^ CHOSE THE DIFFERNCE NUMBER .. (1 | 1) = 0; (0 | 1) = 1 (0 |& 0) = 0
//<< LEFT_SHIFT MOVE THE BINARY CODE INTO THE LEFT
//>> RIGHT_SHIFT MOVE THE BINARY CODE INTO THE RIGHT

int main(void) {
    int a = 6;  //00000110
    int b = 12; //00001100
    int result; 

    result = a & b; //00000100 = 4
    printf("AND op : %d\n", result);

    result = a | b; //00001110 = 14
    printf("OR op : %d\n", result);

    result = a ^ b; //00001010 = 10
    printf("XOR op : %d\n", result);

    result = a << 1;//00001100 = 12
    printf("LEFT SHEFT op : %d\n", result);

    result = a >> 1;//00000011 = 3
    printf("RIGHT LEFT op : %d\n", result);
    return 0;
}