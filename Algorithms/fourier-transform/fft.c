/*
 * =====================================================================================
 *
 *       Filename:  fft.c
 *
 *        Version:  1.0
 *        Created:  02/24/2014 21:58:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

void fft(double *real_image, double *imag_image, int n) {
    if (n <= 1) return;

    // divide
    double *even_real = malloc(sizeof(double) * n / 2);
    double *even_imag = malloc(sizeof(double) * n / 2);
    double *odd_real = malloc(sizeof(double) * n / 2);
    double *odd_imag = malloc(sizeof(double) * n / 2);

    for (int i = 0; i < n / 2; i++) {
        even_real[i] = real_image[2 * i];
        even_imag[i] = imag_image[2 * i];
        odd_real[i] = real_image[2 * i + 1];
        odd_imag[i] = imag_image[2 * i + 1];
    }

    // conquer
    fft(even_real, even_imag, n / 2);
    fft(odd_real, odd_imag, n / 2);

    // combine
    double cosine, sine, t_real, t_imag;
    for (int i = 0; i < n / 2; i++) {
        cosine = cos(-2.0 * PI * i / n);
        sine = sin(-2.0 * PI * i / n);
        t_real = odd_real[i] * cosine - odd_imag[i] * sine;
        t_imag = odd_real[i] * sine + odd_imag[i] * cosine;
        real_image[i] = even_real[i] + t_real;
        imag_image[i] = even_imag[i] + t_imag;
        real_image[i + n / 2] = even_real[i] - t_real;
        imag_image[i + n / 2] = even_imag[i] - t_imag;
    }

    // free the memory we allocate
    free(even_real);
    free(even_imag);
    free(odd_real);
    free(odd_imag);
}

/* calculate inverse fft  */
void ifft(double *real_image, double *imag_image, int n) {
    for (int i = 0; i < n; i++) {
        imag_image[i] = -imag_image[i];
    }
    fft(real_image, imag_image, n);
    for (int i = 0; i < n; i++) {
        real_image[i] /= n;
        imag_image[i] = -imag_image[i] / n;
    }
}

void show(char *s, double *real_image, double *imag_image) {
    printf("%s", s);
    for (int i = 0; i < 8; i++) {
        printf("(%g, %g) ", real_image[i], imag_image[i]);
    }
    printf("\n");
}

int main() {
    double real_image[] = {1, 1, 1, 1, 0, 0, 0, 0};
    double imag_image[] = {0, 0, 0, 0, 0, 0, 0, 0};
    show("Data: ", real_image, imag_image);
    fft(real_image, imag_image, 8);
    show("FFT: ", real_image, imag_image);
    ifft(real_image, imag_image, 8);
    show("IFFT: ", real_image, imag_image);
    return 0;
}
