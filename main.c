// EIRA-KEM — Patent-pending: WO/2025/057369
// Author: Carlos Santacruz
// For academic and non-commercial research only.
// Comercial use phorbidden without licence.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "eira_kem.h"  // Incluye tu header real con prototipos


#define RUNS 1000 // Número de ejecuciones para medir el promedio

int main() {
char *cipher;
double entropy;
clock_t start, end;

start = clock();
for (int i = 0; i < RUNS; i++) {
cipher = generate_cipher(); // Función principal de EIRA-KEM
free(cipher); // Liberamos para evitar acumulación de memoria
}
end = clock();

// Generamos una vez para mostrar el resultado
cipher = generate_cipher();
    cipher = generate_cipher();
    if (cipher == NULL) {
        fprintf(stderr, "Error: Cipher generation failed.\n");
        return 1;
    }
entropy = calculate_entropy(cipher);

printf("Cipher: %s\n", cipher);
printf("Entropy: %.4f\n", entropy);

double total_time = ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
double avg_time = total_time / RUNS;
printf("Average execution time over %d runs: %.6f ms\n", RUNS, avg_time);

free(cipher);
return 0;
}