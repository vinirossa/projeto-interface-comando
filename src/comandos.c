#include <stdio.h>
#include <stdlib.h>

void help()
{
    // Muda cor do texto para amarelo
    printf("\033[0;33m");

    printf("help\t\tImprime os comandos disponiveis e suas descricoes.");
    printf("\nclean\t\tLimpa a tela, apagando tudo o que estiver escrito.");
    printf("\nlistdir\t\tLista as pastas e arquivos presentes no diretorio atual.");
    printf("\nnewdir\t\tCria um nova pasta no diretorio atual com o nome digitado.");
    printf("\nnetdata\t\tLista as configuracoes da rede de internet e da maquina.");
    printf("\nmatrix\t\tAtiva modo matrix (vai explodir sua mente!).");
    printf("\ncustom\t\tExecuta o comando digitado apos a palavra no MSDOS.");
    printf("\nclose\t\tEncerra a interface, fechando o programa.");

    // Muda para cor do texto para o padrão
    printf("\033[0m"); 
}

void clean()
{
    system("cls");
}

void listdir()
{
    system("dir");
}

void newdir()
{
    
}

void netdata()
{
    system("ipconfig");
}

void matrix()
{
    system("start ..\\assets\\matrix.bat");
}

void customcmd(char *cmd)
{
    system(cmd);
}