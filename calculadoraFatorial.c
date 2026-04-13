#include <stdio.h>

int main() {
    int i, numero, fatorial;
    fatorial, i = 1;
    printf("Digite abaixo um numero inteiro positivo");
    scanf("%d", &numero);
  
    
    while (i <= numero){
        fatorial *= i;
        i++;
    }
    
    printf("O fatorial eh: %d", fatorial);
    return 0;
}
