/******************************************************************************

Jogo do Forca

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


int main()
{
    char matriz[5][10] = {
    "banana",
    "morango",
    "framboesa",
    "melancia",
    "acerola"
    };
    
    int totalPalavras = sizeof(matriz) / sizeof(matriz[0]);
    
    srand(time(NULL));
    int indice = rand() % totalPalavras;
    char palavraSecreta[30];
    strcpy(palavraSecreta, matriz[indice]);
    printf("Dica! É uma fruta:\n");
    
    int tamanho = strlen(palavraSecreta);
    char tentativa;
    int acertos = 0, erros = 0;
    int letrasCorretas[30] = {0};
    
    printf("==== JOGO DA FORCA ====\n");
    printf("A palavra tem %d letras\n\n", tamanho);
    
    while (erros < 6 && acertos < tamanho) {
        printf("Palavra: ");
        for (int i = 0; i < tamanho; i++) {
            if (letrasCorretas[i]) {
                printf("%c ", palavraSecreta[i]);
            } else {
                printf("_ ");
            }
        }
        
        printf("\nTentativas restantes: %d\n", 6-erros);
        printf("Digite uma letra: ");
        scanf(" %c", &tentativa);
        tentativa = tolower(tentativa);
        
        int acertou = 0;
        for (int i = 0; i < tamanho; i++) {
            if (palavraSecreta[i] == tentativa && !letrasCorretas[i]) {
                letrasCorretas[i] = 1;
                acertos++;
                acertou = 1;
            }
        }
        
        if (!acertou) {
            erros++;
            printf("Letra incorreta!\n");
        }
        else {
            printf("Letra correta!\n");
        }
        printf("\n");
    }
    
    if (acertos == tamanho) {
        printf("Acertou! Você adivinhou a palavra: %s\n", palavraSecreta);
    } else {
        printf("Game over! A palavra era: %s\n", palavraSecreta);
    }
    
    return 0;
}
