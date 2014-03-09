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
        printf("i: %d, m: %d\n", i, m); 
        float *d_real = malloc(m * sizeof(float));
        float *d_imag = malloc(m * sizeof(float));
        for (j = 0; j < m; j++) {
            d_real[j] = cos(-2.0 * PI * j / 2 / m);
            d_imag[j] = sin(-2.0 * PI * j / 2 / m);
        }
        for (j = 1; j <= pow(2, kstage - i); j++) {
            int s = (j - 1) * 2 * m; /* start index */
            int e = j * 2 * m - 1; /* end index */
            int r = s + (e - s + 1) / 2; /* middle index */
            /*printf("s: %d, e: %d, r: %d, r-s: %d, e-r+1: %d\n", s, e, r, r - s, e - r + 1);*/
            // calculate top
            float *top_real = malloc((r - s) * sizeof(float));
            float *top_imag = malloc((r - s) * sizeof(float));
            memcpy(top_real, real + s, (r - s) * sizeof(float));
            memcpy(top_imag, imag + s, (r - s) * sizeof(float));
            // calculate bottom
            float *bottom_real = malloc((e - r + 1) * sizeof(float));
            float *bottom_imag = malloc((e - r + 1) * sizeof(float));
            memcpy(bottom_real, real + r, (e - r + 1) * sizeof(float));
            memcpy(bottom_imag, imag + r, (e - r + 1) * sizeof(float));
            // combine
            float *z_real = malloc((e - r + 1) * sizeof(float));
            float *z_imag = malloc((e - r + 1) * sizeof(float));
            for (k = 0; k < m; k++) {
                z_real[k] = d_real[k] * bottom_real[k] - d_imag[k] * bottom_imag[k];
                z_imag[k] = d_real[k] * bottom_imag[k] + d_imag[k] * bottom_real[k];
            }
            // write back
            for (k = 0; k < m; k++) {
                real[s + k] = z_real[k] + top_real[k];
                imag[s + k] = z_imag[k] + top_imag[k];
                real[s + k + m] = -z_real[k] + top_real[k];
                imag[s + k + m] = -z_imag[k] + top_imag[k];
                printf("%f, %f\n", real[s + k], real[s + k + m]);
            }
            free(top_real);
            free(top_imag);
            free(bottom_real);
            free(bottom_imag);
            free(z_real);
            free(z_imag);
        }
        free(d_real);
        free(d_imag);
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
    float imag_image[] = {1, 1, 1, 1, 0, 0, 0, 0};
    show("Data: ", real_image, imag_image);
    fft(real_image, imag_image, 8);
    show("FFT: ", real_image, imag_image);
    ifft(real_image, imag_image, 8);
    show("IFFT: ", real_image, imag_image);
    return 0;
}
