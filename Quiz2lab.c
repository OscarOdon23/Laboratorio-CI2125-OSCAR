#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_polynomials, max_degree;
    
    // Read the number of polynomials and the maximum degree
    printf("Enter the number of polynomials: ");
    scanf("%d", &num_polynomials);
    printf("Enter the maximum degree accepted for the polynomials: ");
    scanf("%d", &max_degree);
    
    // Create a matrix to store coefficients of the polynomials
    int coefficients[num_polynomials][max_degree + 1];
    
    // Initialize the matrix with 0s
    for (int i = 0; i < num_polynomials; i++) {
        for (int j = 0; j <= max_degree; j++) {
            coefficients[i][j] = 0;
        }
    }
    
    // Read and define the polynomials
    for (int i = 0; i < num_polynomials; i++) {
        printf("Enter the coefficients for polynomial %c:\n", 'a' + i);
        for (int j = max_degree; j >= 0; j--) {
            printf("Coefficient of x^%d: ", j);
            scanf("%d", &coefficients[i][j]);
        }
    }
    
    // Display the entered polynomials
    printf("\nPolynomials entered:\n");
    for (int i = 0; i < num_polynomials; i++) {
        printf("Polynomial %c: ", 'a' + i);
        for (int j = max_degree; j >= 0; j--) {
            if (coefficients[i][j] != 0) {
                if (j == max_degree) {
                    printf("%dx^%d ", coefficients[i][j], j);
                } else if (j == 0) {
                    printf("%d\n", coefficients[i][j]);
                } else {
                    printf("%+dx^%d ", coefficients[i][j], j);
                }
            }
        }
    }

    // Sum the polynomials
    int result[max_degree + 1];
    
    // Initialize result array with 0s
    for (int i = 0; i <= max_degree; i++) {
        result[i] = 0;
    }

    // Sum the coefficients of the polynomials
    for (int i = 0; i < num_polynomials; i++) {
        for (int j = 0; j <= max_degree; j++) {
            result[j] += coefficients[i][j];
        }
    }

    // Display the sum of the polynomials
    printf("\nSum of Polynomials:\n");
    for (int j = max_degree; j >= 0; j--) {
        if (result[j] != 0) {
            if (j == max_degree) {
                printf("%dx^%d ", result[j], j);
            } else if (j == 0) {
                printf("%d\n", result[j]);
            } else {
                printf("%+dx^%d ", result[j], j);
            }
        }
    }

    return 0;
}