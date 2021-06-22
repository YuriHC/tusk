#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int cont=0;

struct Jogador{

    int id;
    char nome[50];
    int dataFimContrato;
    int ativo;
    char apelido[50];
    int dataInicioContrato;
    int numeroGolos;



};


struct Equipa
{
    int id;
    char nome[50];
    struct Jogador cadastroJogador;


};

void menu(){
    int op;
    printf("\n1-Cadastrar\n2-Listar\n3-Eliminar\n0-Sair\n");
    scanf("%d", &op);
    getchar();
    switch(op){
        case 1:
            cadastrar();
            break;
        case 2:
            listar();
            break;
        case 3:
            eliminar();
            break;
        case 0:
            break;
        default:
            printf("Digitou uma opcao incorrecta!\n");

    }


}

void cadastrar(){
    FILE* arquivo;
    arquivo=fopen("Arquivo.txt", "a+");
    struct Equipa cadastro;
    int novo;


    do{
        fflush(stdin);
        printf("Digite ID da equipa: ");
        scanf("%d", &cadastro.id);
        getchar();
        printf("Digite o ID do jogador: ");
        scanf("%d", &cadastro.cadastroJogador.id);
        getchar();
        fflush(stdin);
        printf("\nDigite o nome da equipa: ");
        fgets(cadastro.nome,50,stdin);
        getchar();
        printf("Digite o nome do jogador: ");
        fgets(cadastro.cadastroJogador.nome, 50, stdin);
        fflush(stdin);
        printf("Digite a data do contracto: ");
        scanf("%d", &cadastro.cadastroJogador.dataInicioContrato);
        printf("Digite a data do fim do contrato: ");
        scanf("%d", &cadastro.cadastroJogador.dataFimContrato);
        printf("Digite o Apelido do jogador: ");
        scanf("%s", &cadastro.cadastroJogador.apelido);
        printf("Digite o numero de golos: ");
        scanf("%d", cadastro.cadastroJogador.numeroGolos);


        fwrite(&cadastro, sizeof(struct Equipa), 1, arquivo);
        if(ferror(arquivo)){
            printf("\nerro\n");
        }else{
            printf("\ngravado com sucesso\n");
            cont++;
        }
        printf("Novo-1/ 2-Sair");
        scanf("%d", &novo);

        printf("\n");

    }while(novo==1);


    fclose(arquivo);

}


void listar(){

    FILE* arquivo;
    arquivo=fopen("Arquivo.txt", "r");
    struct Equipa lista;

    while(fread(&lista, sizeof(struct Equipa), 1, arquivo)==1){
        printf("ID da equipa=%d\n", lista.id);
        printf("ID do jogador=%d\n", lista.cadastroJogador.id);
        printf("Nome da equipa=%s\n", lista.nome);
        printf("Nome do jogador=%s\n", lista.cadastroJogador.nome);
        printf("Inicio do contrato=%d\n", lista.cadastroJogador.dataInicioContrato);
        //scanf("%d", &cadastro.cadastroJogador.dataInicioContrato);
        printf("Fim do contrato=%d\n", lista.cadastroJogador.dataFimContrato);
        printf("Apelido=%s\n", lista.cadastroJogador.apelido);
        printf("Numero de golos=%d\n", lista.cadastroJogador.numeroGolos);


    }



    fclose(arquivo);
    system("pause");

}

void eliminar(){
    FILE* arquivo, *temporario;
    arquivo=fopen("Arquivo.txt", "r+");
    temporario=fopen("temp.txt", "w");
    struct Equipa lista;
    int novo;
    int id;
    printf("Digite o ID do jogador que pretende excluir: ");
    scanf("%d", &lista.cadastroJogador.id);
    while(fread(&lista, sizeof(struct Equipa), 1, arquivo)==1){
        if(cont==lista.cadastroJogador.id){
            fwrite(&lista, sizeof(struct Equipa), 1, temporario);

        }


    }

    if(ferror(temporario)){
        printf("\nerro\n");
    }else{
        printf("\nEliminado com sucesso!\n");
           }

    fclose(temporario);
    fclose(arquivo);
    remove("temp.txt");
    rename("temp.txt","Arquivo.txt");
    system("pause");


}


int main()
{
    menu();
    //cadastrar();
    //listar();
    //eliminar();

    return 0;
}
