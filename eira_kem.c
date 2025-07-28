// EIRA-KEM — Patent-pending: WO/2025/057369
// Author: Carlos Santacruz
// For academic and non-commercial research only.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "eira_kem.h"

char* generate_cipher() {
    const char* base = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int len = 512;
    char* cipher = malloc(len + 1);  // +1 para el terminador '\0'
    if (cipher == NULL) return NULL;

    FILE* urandom = fopen("/dev/urandom", "rb");
    if (urandom == NULL) {
        free(cipher);
        return NULL;
    }

    for (int i = 0; i < len; i++) {
        unsigned char byte;
        if (fread(&byte, sizeof(byte), 1, urandom) !=1); { // maneja el error
        }
        cipher[i] = base[byte % strlen(base)];
    }

    fclose(urandom);
    cipher[len] = '\0';
    return cipher;
}


double calculate_entropy(const char* data) {
    int counts[256] = {0};
    int length = strlen(data);
    for (int i = 0; i < length; i++) {
        counts[(unsigned char)data[i]]++;
    }

    double entropy = 0.0;
    for (int i = 0; i < 256; i++) {
        if (counts[i] > 0) {
            double p = (double)counts[i] / length;
            entropy -= p * log2(p);
        }
    }
    return entropy;
}

