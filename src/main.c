#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comandos.c"
#include "extensions/string-extensions.c"

int main()
{
    // Inicializa variáveis
    char cmd[200];
    char dir_atual[200] = "C:\\";

    system("cls");//Limpa tela

    // Muda cor do texto para ciano
    printf("\033[0;36m");

    printf("Interface de Comando Windows [versao 1.0.0]\n");
    printf("(c) EEP. Todos os direitos reservados.\n");

    // Muda para cor do texto para o padrão
    printf("\033[0m"); 

    printf("\nPara listar os comandos disponiveis, digite 'help'\n");

    // Muda o diretorio para raiz da maquina
    system("cd \\");

    while (1)
    {
        // Muda cor do texto para ciano
        printf("\033[0;35m");

        printf("\n%s>", dir_atual);

        // Muda para cor do texto para o padrão
        printf("\033[0m"); 

        fgets(cmd, sizeof(cmd), stdin);
        fflush(stdin); // Limpa o buffer
        cmd[strcspn(cmd, "\n")] = 0; // Remove quebra-linha final da string
        trim(cmd); // Remove espaços em branco do início e fim da string


        //compara as strings digitadas, se forem iguais executa determinada funcao
        if (strcmp(cmd, "help") == 0)
            help();
        else if (strcmp(cmd, "clean") == 0)
            clean();
        else if (strcmp(cmd, "listdir") == 0)
            listdir();
        else if (strcmp(cmd, "netdata") == 0)
            netdata();
        else if (strcmp(cmd, "matrix") == 0)
            matrix();
        else if (strcmp(cmd, "newdir") == 0)
            newdir();
        else if (strcmp(cmd, "close") == 0)
            return 0;

        strcpy(cmd, "");//limpa barra de digitacao do cmd
    }
}