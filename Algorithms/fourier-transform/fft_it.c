/*
 * vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PI 3.14159265

/* bit reversal */
void bitreversal(float *x, int n) {
    float *y = malloc(n * sizeof(float));
    int i, j, k;
    for (i = 0; i < n; i++) {
        /* reverse bits */
        k = 0;
        int radix = log(n) / log(2);
        for (j = 0; j < radix; j++) {
            k |= ((i >> j) & 1) << (radix - j - 1);
        }
        /*printf("%d, %d\n", k, i);*/
        y[k] = x[i];
    }
    memcpy(x, y, n * sizeof(float));
    free(y);
}

void printarray(float *x, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%f ", x[i]);
    }
    printf("\n");
}

void fft(float *real, float *imag, int n) {
    bitreversal(real, n);
    bitreversal(imag, n);
    int i, j, k;
    int kstage = log(n) / log(2);
    for (i = 1; i <= kstage; i++) {
        int m = pow(2, i - 1);
        /*printf("i: %d, m: %d\n", i, m); */
        for (j = 1; j <= pow(2, kstage - i); j++) {
            int s = (j - 1) * 2 * m; /* start index */
            int e = j * 2 * m - 1; /* end index */
            int r = s + (e - s + 1) / 2; /* middle index */
            /*printf("s: %d, e: %d, r: %d, r-s: %d, e-r+1: %d\n", s, e, r, r - s, e - r + 1);*/
            for (k = 0; k < m; k++) {
                /*printf("%d, %d\n", s + k, r + k);*/
                float last_real = real[s + k];
                float last_imag = imag[s + k];
                float cosine = cos(-2.0 * PI * k / 2 / m);
                float sine = sin(-2.0 * PI * k / 2 / m);
                float t_real = cosine * real[r + k] - sine * imag[r + k];
                float t_imag = cosine * imag[r + k] + sine * real[r + k];
                real[s + k] = last_real + t_real;
                imag[s + k] = last_imag + t_imag;
                real[r + k] = last_real - t_real;
                imag[r + k] = last_imag - t_imag;
                /*printf("%f, %f\n", real[s + k], real[r + m]);*/
            }
        }
    }
}

/* calculate inverse fft  */
void ifft(float *real_image, float *imag_image, int n) {
    for (int i = 0; i < n; i++) {
        imag_image[i] = -imag_image[i];
    }
    fft(real_image, imag_image, n);
    for (int i = 0; i < n; i++) {
        real_image[i] /= 8;
        imag_image[i] = -imag_image[i] / 8;
    }
}

void show(char *s, float *real_image, float *imag_image) {
    printf("%s", s);
    for (int i = 0; i < 8; i++) {
        printf("(%g, %g) ", real_image[i], imag_image[i]);
    }
    printf("\n");
}

int main() {
    float real_image[] = {1, 1, 1, 1, 0, 0, 0, 0};
    float imag_image[] = {0, 0, 0, 0, 0, 0, 0, 0};
    show("Data: ", real_image, imag_image);
    fft(real_image, imag_image, 8);
    show("FFT: ", real_image, imag_image);
    ifft(real_image, imag_image, 8);
    show("IFFT: ", real_image, imag_image);
    return 0;
}
