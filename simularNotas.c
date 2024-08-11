#include <stdio.h>
#include <stdlib.h>

float getGrade(const float gradeCap, const char *message);
float get_float(const char *prompt);

int main() {
    printf("Geovane Saraiva da Silva (2024) - Simulador de Notas\nInfo: As notas N1/N2 não devem ultrapassar 4.5\nInfo: A nota PPD não deve ultrapassar 1\n");

    float n1 = getGrade(4.5, "Sua nota N1: ");
    float n2 = getGrade(4.5, "Sua nota N2: ");
    float ppd = getGrade(1, "Sua nota PPD: ");

    float finalGrade = n1 + n2 + ppd;

    if (finalGrade > 7) {
        return printf("\nNota final: %.2f\nSituação: APROVADO(A)\n", finalGrade);
    } else {
        return printf("\nNota final: %.2f\nSituação: REPROVADO(A)\n", finalGrade);
    }
}

float getGrade(const float gradeCap, const char *message) {
    float grade;
    do {
        grade = get_float(message);

        if (grade > gradeCap) {
            printf("A nota ultrapassou o limite!\n");
        }

    } while (grade > gradeCap);

    return grade;
}

float get_float(const char *prompt) {
    float num;
    char line[100];

    printf("\n");
    printf("%s", prompt);

    while (fgets(line, sizeof(line), stdin) != NULL) {
        if (sscanf(line, "%f", &num) == 1) {
            return num;
        } else {
            printf("\n");
            printf("%s", prompt);
        }
    }

    printf("Erro: não foi possível ler a entrada.\n");
    exit(1);
}
