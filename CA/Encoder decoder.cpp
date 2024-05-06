#include <stdio.h>

void encoder(int input[2], int output[4]) {
    output[0] = !(input[0] | input[1]);
    output[1] = input[0] & !input[1];
    output[2] = !input[0] & input[1];
    output[3] = input[0] & input[1];
}

void decoder(int input[4], int output[2]) {
    output[0] = input[0] | input[2] | input[3];
    output[1] = input[1] | input[3];
}

int main() {
    int input_encoder[2] = {1, 0}; 
    int output_encoder[4]; 

    encoder(input_encoder, output_encoder);

    printf("Encoder Output: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", output_encoder[i]);
    }
    printf("\n");

    int input_decoder[4] = {0, 0, 1, 0}; 
    int output_decoder[2]; 

    decoder(input_decoder, output_decoder);

    printf("Decoder Output: ");
    for (int i = 0; i < 2; i++) {
        printf("%d ", output_decoder[i]);
    }
    printf("\n");

    return 0;
}

