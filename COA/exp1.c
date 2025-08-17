#include <ctype.h>
#include <math.h>
#include <stdio.h>

int hexToDec(char*);
int octToDec(int);
int binToDec(int);
void decToBase(int, int, char*);

int main() {
    int choice;
    do {
        printf("\n--- Conversion Menu ---\n");
        printf("1. Hexadecimal to Decimal\n");
        printf("2. Octal to Decimal\n");
        printf("3. Binary to Decimal\n");
        printf("4. Decimal to Hexadecimal\n");
        printf("5. Decimal to Octal\n");
        printf("6. Decimal to Binary\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char hex_value[20];
                printf("Enter Hex Value: ");
                scanf("%s", hex_value);
                printf("Decimal: %d\n", hexToDec(hex_value));
                break;
            }
            case 2: {
                int oct_value;
                printf("Enter Octal Value: ");
                scanf("%d", &oct_value);
                printf("Decimal: %d\n", octToDec(oct_value));
                break;
            }
            case 3: {
                int bin_value;
                printf("Enter Binary Value: ");
                scanf("%d", &bin_value);
                printf("Decimal: %d\n", binToDec(bin_value));
                break;
            }
            case 4: {
                int dec_value;
                char out[20];
                printf("Enter Decimal Value: ");
                scanf("%d", &dec_value);
                decToBase(16, dec_value, out);
                printf("Hexadecimal: %s\n", out);
                break;
            }
            case 5: {
                int dec_value;
                char out[20];
                printf("Enter Decimal Value: ");
                scanf("%d", &dec_value);
                decToBase(8, dec_value, out);
                printf("Octal: %s\n", out);
                break;
            }
            case 6: {
                int dec_value;
                char out[20];
                printf("Enter Decimal Value: ");
                scanf("%d", &dec_value);
                decToBase(2, dec_value, out);
                printf("Binary: %s\n", out);
                break;
            }
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}

int hexToDec(char* hex_value) {
    for(int i = 0; hex_value[i]!='\0'; i++) 
        hex_value[i] = tolower(hex_value[i]);
    int integer = 0;
    int i = 0;
    for(; hex_value[i] != '\0'; i++);
    int j = 0;
    i -= 1;
    while(i > -1) {
        if(hex_value[i] >= 'a' && hex_value[i] <= 'f') {
            integer += (hex_value[i] - 'a' + 10) * pow(16, j);
        } else if(hex_value[i] >= '0' && hex_value[i] <= '9') {
            integer += (hex_value[i] - '0') * pow(16, j);
        }
        i--;
        j++;
    }
    return integer;
}

int octToDec(int oct_value) {
    int temp = 0;
    int dec = 0;
    int i = 0;
    while (oct_value != 0) {
        temp = oct_value % 10;
        dec += (temp * pow(8, i));
        i++;
        oct_value /= 10;
    }
    return dec;
}

int binToDec(int bin_value) {
    int temp = 0;
    int dec = 0;
    int i = 0;
    while (bin_value != 0) {
        temp = bin_value % 10;
        dec += (temp * pow(2, i));
        i++;
        bin_value /= 10;
    }
    return dec;
}

void decToBase(int base, int dec, char out[20]) {
    char temp[20];
    int index = 0;
    if (dec == 0) {
        out[0] = '0';
        out[1] = '\0';
        return;
    }
    while (dec > 0) {
        int remainder = dec % base;
        if (remainder < 10)
            temp[index++] = '0' + remainder;
        else
            temp[index++] = 'A' + (remainder - 10);
        dec /= base;
    }
    for (int i = 0; i < index; i++) {
        out[i] = temp[index - i - 1];
    }
    out[index] = '\0';
}
