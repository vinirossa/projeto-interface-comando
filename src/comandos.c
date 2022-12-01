#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

// Função que lista os comandos disponíveis
void help() 
{
    // Muda cor do texto para amarelo
    printf("\033[0;33m");

    printf("help\t\t\tImprime os comandos disponiveis e suas descricoes.");
    printf("\nclean\t\t\tLimpa a tela, apagando tudo o que estiver escrito.");
    printf("\nlistdir\t\t\tLista as pastas e arquivos presentes no diretorio atual.");
    printf("\naltdir DIR\t\tAlterar o diretorio atual para o informado, caso exista.");
    printf("\nnewdir DIR\t\tCria uma nova pasta no diretorio atual com o nome digitado.");
    printf("\nnetdata\t\t\tLista as configuracoes da rede de internet e da maquina.");
    printf("\nmatrix\t\t\tAtiva modo matrix (vai explodir sua mente!).");
    printf("\ncustom CMD\t\tExecuta o comando digitado apos a palavra no MSDOS.");
    printf("\nclose\t\t\tEncerra a interface, fechando o programa.");

    // Muda para cor do texto para o padrão
    printf("\033[0m"); 
}

// Função para limpar a tela do terminal
void clean()
{
    system("cls");
}

// Função para listar as arquivos e pastas do diretório atual 
void listdir(char *dir_atual)
{
    char cmd[PATH_MAX];
    snprintf(cmd, sizeof(cmd), "cd %s && dir", dir_atual); // Interpola a string assim como um printf
    system(cmd);
}

// Função para alterar o diretório atual para o informado 
void altdir(char *ndir, char *dir_atual)
{         
    DIR *dir = opendir(ndir);
    if (dir) // Diretório existe
    { 
        closedir(dir);
        strcpy(dir_atual, ndir); // Atualiza variável de diretório atual
    } 
    else if (ENOENT == errno) // Diretório não existe
        printf("O diretorio informado nao existe.");
    else // Erro ao abrir diretório
        printf("Falha ao abrir diretorio informado.");
}

// Função para criar pasta nova no diretório atual
void newdir(char *dir_novo, char *dir_atual)
{
    char cmd[PATH_MAX];
    snprintf(cmd, sizeof(cmd), "cd %s && mkdir %s", dir_atual, dir_novo); // Interpola a string assim como um printf
    system(cmd);
}

// Função para imprimir as configurações da rede e IP
void netdata() 
{
    system("ipconfig");
}

// Função para abrir tela de matrix
void matrix()
{
    // Abre arquivo batch matrix.bat que exibe um prompt do filme Matrix
    system("start ..\\assets\\matrix.bat");
}

// Função que recebe um comando customizado e o executa diretamente no DOS
void customcmd(char *cmd)
{
    system(cmd);
}