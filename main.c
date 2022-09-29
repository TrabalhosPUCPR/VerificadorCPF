#include <stdio.h>

int somaCpf(const char cpf[11], int fator_inicial);

int main() {
    char cpf[11] = "12345678903";
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
        printf("O CPF informado e valido!\n");
    }else{
        printf("O CPF informado e invalido!\n");
    }
    return 0;
}

int somaCpf(const char c[11], int fator_inicial) {
    int soma = 0;
    for(int i = 0; i < fator_inicial - 1; i++){
        soma = ((fator_inicial - i) * ((int)c[i] - 48)) + soma;
    }
    return soma;
}
