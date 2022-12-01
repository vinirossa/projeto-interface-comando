#include <stdio.h>
#include <stdlib.h>

// Função para remover espaços em branco do início e final da string
void trim(char *p_str) {
    char *p_newstr = p_str;
    int length = strlen(p_newstr);

    // Itera sobre o início e final da string, removendo os espaços em branco
    while(isspace(p_newstr[length - 1])) p_newstr[--length] = 0;
    while(*p_newstr && isspace(*p_newstr)) ++p_newstr, --length;

    // Atualiza a string informada com a string sanitizada
    memmove(p_str, p_newstr, length + 1);
}  