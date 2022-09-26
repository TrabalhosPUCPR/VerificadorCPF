#include <stdio.h>

int somaCpf(const char cpf[11], int fator_inicial);

int main() {
    char cpf[11] = "01214508995";
    char ultimos_digitos[2];
    int somacpf = somaCpf(cpf, 10);
    if (somacpf % 11 > 1){
        ultimos_digitos[0] = (char)((11 - (somacpf % 11))+48);
    }else{
        ultimos_digitos[0] = '0';
    }
    somacpf = somaCpf(cpf, 11);
    if (somacpf % 11 > 1){
        ultimos_digitos[1] = (char)((11 - (somacpf % 11))+48);
    }else{
        ultimos_digitos[1] = '0';
    }
    if(cpf[9] == ultimos_digitos[0] && cpf[10] == ultimos_digitos[1]){
        printf("O CPF informado é valido!\n");
    }else{
        printf("O CPF informado é invalido!\n");
    }
    return 0;
}

int somaCpf(const char c[11], int fator_inicial) {
    int soma = 0;
    for(int i = 0, fator; i < fator_inicial - 1; i++){
        fator = fator_inicial - i;
        soma = (fator * ((int)c[i] - 48)) + soma;
    }
    return soma;
}
