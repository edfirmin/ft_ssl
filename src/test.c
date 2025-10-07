/*
 * Implémentation MD5 basée sur la RFC 1321
 * Compile avec : gcc -O2 -Wall md5.c -o md5
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#define LEFTROTATE(x, n) (((x) << (n)) | ((x) >> (32-(n))))

static const uint32_t r[64] = {
    7,12,17,22,7,12,17,22,7,12,17,22,7,12,17,22,
    5,9,14,20,5,9,14,20,5,9,14,20,5,9,14,20,
    4,11,16,23,4,11,16,23,4,11,16,23,4,11,16,23,
    6,10,15,21,6,10,15,21,6,10,15,21,6,10,15,21
};

uint32_t fonc_K(int i){
    double v = fabs(sin(i + 1));
    return (4294967296 * v);// 4294967296 == 2^32
}

void md5(const uint8_t *msg, size_t len, uint8_t digest[16]) {
    uint32_t a0 = 0x67452301;// valeur arbitaire du RFC
    uint32_t b0 = 0xefcdab89;// pareil
    uint32_t c0 = 0x98badcfe;// pareil
    uint32_t d0 = 0x10325476;// pareil

    size_t new_len = len + 1;//
    while (new_len % 64 != 56) new_len++;// pour setup les remplissage de "0" 
    uint8_t *msg_pad = calloc(new_len + 8, 1);//

    memcpy(msg_pad, msg, len);
    msg_pad[len] = 0x80;  // pour mettre un "1" devant

    uint64_t bits_len = (uint64_t)len * 8;
    memcpy(msg_pad + new_len, &bits_len, 8);

    /* Traitement par blocs de 512 bits */
    for (size_t offset = 0; offset < new_len; offset += 64) {
        uint32_t *w = (uint32_t*)(msg_pad + offset);

        uint32_t A = a0, B = b0, C = c0, D = d0;

        for (int i = 0; i < 64; i++) {
            uint32_t F, g;
            if (i < 16) {
                F = (B & C) | ((~B) & D);
                g = i;
            } else if (i < 32) {
                F = (D & B) | ((~D) & C);
                g = (5*i + 1) % 16;
            } else if (i < 48) {
                F = B ^ C ^ D;
                g = (3*i + 5) % 16;
            } else {
                F = C ^ (B | (~D));
                g = (7*i) % 16;
            }
            uint32_t tmp = D;
            D = C;
            C = B;
            B = LEFTROTATE(F + A + fonc_K(i) + w[g], r[i]) + B;
            A = tmp;
        }  
        a0 += A;
        b0 += B;
        c0 += C;
        d0 += D;
    }

    free(msg_pad);
    memcpy(digest, &a0, 4);
    memcpy(digest + 4, &b0, 4);
    memcpy(digest + 8, &c0, 4);
    memcpy(digest+12, &d0, 4);
}

int main() {
    const char *msg = "42 is nice\n";
    uint8_t result[16];

    md5((const uint8_t*)msg, strlen(msg), result);

    printf("MD5(\"%s\") = ", msg);
    for (int i = 0; i < 16; i++)
        printf("%02x", result[i]);
    printf("\n");

    return (0);
}
