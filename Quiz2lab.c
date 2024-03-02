#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_polynomials, max_degree;
    
    // Leer el número de polinomios y el grado máximo.
    printf("Introduce cuantos polinomios vas a sumar: ");
    scanf("%d", &num_polynomials);
    printf("Introduce el mayor coeficiente de todos los polinomios: ");
    scanf("%d", &max_degree);
    
    // Crear una matriz para almacenar coeficientes de los polinomios.
    int coefficients[num_polynomials][max_degree + 1];
    
    // Inicializar la matriz con 0
    for (int i = 0; i < num_polynomials; i++) {
        for (int j = 0; j <= max_degree; j++) {
            coefficients[i][j] = 0;
        }
    }
    
    // Leer y definir los polinomios.
    for (int i = 0; i < num_polynomials; i++) {
        printf("Introduce los coeficientes de los polinomios %c:\n", 'a' + i);
        for (int j = max_degree; j >= 0; j--) {
            printf("Coeficiente de x^%d: ", j);
            scanf("%d", &coefficients[i][j]);
        }
    }
    
    // Mostrar los polinomios ingresados
    printf("\nPolinomios Introducidos:\n");
    for (int i = 0; i < num_polynomials; i++) {
        printf("Polinomio %c: ", 'a' + i);
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

    // Suma de Polinomios
    int result[max_degree + 1];
    
    // Inicializar la matriz de resultados con 0
    for (int i = 0; i <= max_degree; i++) {
        result[i] = 0;
    }

    // Sumar los coeficientes de los polinomios.
    for (int i = 0; i < num_polynomials; i++) {
        for (int j = 0; j <= max_degree; j++) {
            result[j] += coefficients[i][j];
        }
    }

    // Mostrar la suma de los polinomios.
    printf("\nSuma de polinomios:\n");
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