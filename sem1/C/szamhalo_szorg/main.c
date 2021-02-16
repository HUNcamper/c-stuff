#include <stdio.h>

// Exponential function
int exponential(int num, int amount) {
    if(amount == 0) return 1;

    int initial = num;

    for (int i = 1; i < amount; i++) {
        num *= initial;
    }
    return num;
}

// Convert a char array to an integer
int strToInt(char* inputStr) {
    int num = 0;    // return num
    int strLen = 0; // string length

    while(inputStr[strLen] != '\0') strLen++;

    for (int i = 0; i < strLen; i++) {
        int posNotation = exponential(10, strLen-i-1); // the digit's positional notation. eg. in 1234, 1 is 1000, 2 is 200, 3 is 30, 4 is 4
        int currentDigit = inputStr[i] - '0';

        num += currentDigit * posNotation;
    }

    return num;
}

// Convert an IPv4 string to an octet array
void strToOctets(char* inputStr, int* octetsOut) {
    int octet_i = 0;

    char currOctet[4]; // including the \0 on the end
    int currOctet_i = 0;

    for (int i = 0; ; i++) {
        // Check if current octet ended with a . or the string ends
        if(inputStr[i] == '.' || inputStr[i] == '\0') {
            // End string and restart
            currOctet[currOctet_i] = '\0';
            currOctet_i = 0;

            // Add octet to array
            octetsOut[octet_i++] = strToInt(currOctet);
        } else {
            // Add character to the current octet string
            currOctet[currOctet_i++] = inputStr[i];
        }

        if(inputStr[i] == '\0') break;
    }
}

//  1     2     4   8	16	32	64	128
//  256   128   64  32  16  8   4   2

/*
 * 2: 255.255.255.128
 * 4: 255.255.255.64
 * 8: 255.255.255.32
 * 16: 255.255.255.16
 * 32: 255.255.255.8
 * 64: 255.255.255.4
 *
 */

int subnetAmount[] = {2, 4, 8, 16, 32, 64};

void splitToSubnets(int* octets, int n) {
    if(n > 32) {
        
    }
}

int main() {
    char ipv4_addr[15];
    int subnet_num = 0;

    printf("IPv4 Address:\n");
    scanf("%s", &ipv4_addr);

    printf("Desired amount of subnetworks:\n");
    scanf("%d", &subnet_num);

    printf("Address: %s\nSubnets: %d\n", ipv4_addr, subnet_num);

    int octets[4];
    strToOctets(ipv4_addr, octets);

    printf("%d %d %d %d", octets[0], octets[1], octets[2], octets[3]);

    return 0;
}
