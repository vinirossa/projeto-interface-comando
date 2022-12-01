#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comandos.c"
#include "extensions/string-extensions.c"

int main()
{
    // Inicializa variáveis
    char cmd[200];
    char dir_atual[PATH_MAX]; // Usa o tamanho máximo como a variável de ambiente PATH_MAX do Windows

    // Encontra diretório atual
    if (getcwd(dir_atual, sizeof(dir_atual)) != 0) 
        printf("Current working dir: %s\n", dir_atual);
    else // Caso não consiga, assume o C: como diretório
        strcpy(dir_atual, "C:\\");

    // Limpa a tela do terminal (para limpar textos padrões do DOS)
    system("cls");

    // Muda cor do texto para ciano
    printf("\033[0;36m");

    // Imprime cabeçalho da interface
    printf("Interface de Comando Windows [versao 1.0.0]\n");
    printf("(c) EEP. Todos os direitos reservados.\n");

    // Muda para cor do texto para o padrão
    printf("\033[0m"); 

    // Imprime instrução inicial de ajuda
    printf("\nPara listar os comandos disponiveis, digite 'help'\n");

    // Loop contínuo que captura os comandos digitados pelo usuário até o programa ser fechado
    while (1)
    {
        // Muda cor do texto para ciano
        printf("\033[0;35m");

        // Imprime caminho atual do terminal, simulando outros prompts como o DOS
        printf("\n%s>", dir_atual);

        // Muda para cor do texto para o padrão
        printf("\033[0m"); 

        // Detecta o comando digitado pelo usuário
        fgets(cmd, sizeof(cmd), stdin);
        fflush(stdin); // Limpa o buffer
        cmd[strcspn(cmd, "\n")] = 0; // Remove quebra-linha final da string
        trim(cmd); // Remove espaços em branco do início e fim da string

        // Interpreta comando digitado e chama sua respectiva função
        // Caso um nenhum comando válido seja selecionado, repete o loop
        if (strcmp(cmd, "help") == 0)
            help();
        else if (strcmp(cmd, "clean") == 0)
            clean();
        else if (strcmp(cmd, "listdir") == 0)
            listdir(dir_atual);
        else if (strstr(cmd, "altdir ") != 0) // Confere se o ínicio da string é igual à "altdir "
        {
            trim(memcpy(cmd, "       ", 7)); // Substitui o trecho "altdir " da string por espaços e recorta, mandando só o diretório
            altdir(cmd, dir_atual);   
        }
        else if (strstr(cmd, "newdir ") != 0) // Confere se o ínicio da string é igual à "newdir "
        {
            trim(memcpy(cmd, "       ", 7)); // Substitui o trecho "newdir " da string por espaços e recorta, mandando só o diretório
            newdir(cmd, dir_atual);   
        }
        else if (strcmp(cmd, "netdata") == 0)
            netdata();
        else if (strcmp(cmd, "matrix") == 0)
            matrix();
        else if (strstr(cmd, "custom ") != 0) // Confere se o ínicio da string é igual à "custom "
        {
            trim(memcpy(cmd, "       ", 7)); // Substitui o trecho "custom " da string por espaços e recorta, mandando só o comando
            customcmd(cmd);
        }
        else if (strcmp(cmd, "close") == 0)
            return 0;
        else
            printf("Comando desconhecido. Digite 'help' para mais informacoes.");

        // Limpa string com comando para não afetar o próximo
        strcpy(cmd, ""); 
    }
}