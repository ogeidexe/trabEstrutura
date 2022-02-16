#include "lib.c"

/******************
 *Jeferson Silva
 *Diego Teixeira
 *
 *******************/
Player getPlayer(){
    puts("Digite os dados do player");
    Player playerTmp25;
    int coin;
    char plnm[1000];
    printf("Digite o nome player:");
    fflush(stdin);
    setbuf(stdin, NULL);
    scanf("%s",plnm);
    printf("Digite as moedas do player:");
    scanf("%d",&coin);
    playerTmp25.name = plnm;
    playerTmp25.coin = coin;
    return playerTmp25;
}


int menu(){
    int op = 1;
    puts("-------------------");
    puts("1 - LISTAR PLAYERS ");
    puts("2 - INSERIR PLAYER ");
    puts("3 - REMOVER PLAYER ");
    puts("4 - LUTAR          ");
    puts("0 - SAIR           ");
    puts("-------------------");
    scanf("%d",&op);
    return op;
}


int main(int argc, char const *argv[])
{
    node *root = NULL;

    Player player1;
    player1.name = "jeronimo";
    player1.coin = 100;
    insertNode(&root, player1);

    Player player2;
    player2.name = "JOAO";
    player2.coin = 101;
    insertNode(&root, player2);

    Player player3;
    player3.name = "medonho";
    player3.coin = 99;
    insertNode(&root, player3);

    Player player4;
    player4.name = "Jefim";
    player4.coin = 200;
    insertNode(&root, player4);

    Player player5;
    player5.name = "Diego";
    player5.coin = 20;
    insertNode(&root, player5);
    int op = 1;
    while (op != 0){
        op =  menu();
        switch (op)
        {
        case 1:
            printTree(root);
            break;
        case 2:
            insertNode(&root,getPlayer());
            break;
        case 3:
            deleteNode(&root,getPlayer());
            break;
        case 4:
            puts("Digite os dados do players");
            puts("Digite o nome player vencedor");
            Player playerTmp1 = getPlayer();
            puts("Digite o nome player perdedor");
            Player playerTmp2 = getPlayer();
            fight(&root,playerTmp1,playerTmp2);
            break;
        }
    };
    return 0;
}
