#include <stdio.h>
#include <string.h>

#define MAX 10  // Máximo tamaño para la cadena de salida

// Array de letras del teclado (según cada número)
char *teclado[] = {
    "",     "",     "abc",  "def",  // 0,1,2,3
    "ghi",  "jkl",  "mno",          // 4,5,6
    "pqrs", "tuv",  "wxyz"          // 7,8,9
};

// Función recursiva para generar combinaciones
void generarCombinaciones(char *digits, int index, char *resultado, int len) {
    // Si llegamos al final del número, imprimimos la combinación
    if (index == len) {
        resultado[len] = '\0';  // Agregar terminador de cadena
        printf("%s\n", resultado);
        return;
    }

    // Obtener las letras del número actual
    char *letras = teclado[digits[index] - '0'];

    // Recorrer cada letra y probar combinaciones
    for (int i = 0; letras[i] != '\0'; i++) {
        resultado[index] = letras[i];  // Agregar la letra a la combinación
        generarCombinaciones(digits, index + 1, resultado, len);  // Llamar al siguiente número
    }
}

// Función principal
int main() {
    char digits[MAX];  // Espacio para la entrada del usuario

    printf("Ingresa los numeros (2-9): ");
    scanf("%s", digits);  // Leer la entrada del usuario

    if (strlen(digits) == 0) {
        printf("[]\n");  // Si no hay entrada, devolvemos vacío
        return 0;
    }

    char resultado[MAX];  // Almacena las combinaciones parciales

    printf("Combinaciones posibles:\n");
    generarCombinaciones(digits, 0, resultado, strlen(digits));  // Llamar a la función recursiva

    return 0;
}

