#include "lib.c"

/******************
 *Jeferson Silva
 *Diego Teixeira
 *
 *******************/
int menu(){
    int op = 1;
    puts("-------------------");
    puts("1 - LISTAR PLAYERS ");
    puts("2 - INSERIR PLAYER ");
    puts("3 - REMOVER PLAYER ");
    puts("4 - LUTAR          ");
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

    // printf("%s\n",root->player.name);
    // printf("%s\n",root->left->player.name);
    // printf("%s\n",root->right->player.name);
    int op =  menu();
    switch (op)
    {

    case 1:
        printTree(root);
        break;
    case 2:
        puts("Digite os dados do player");
        Player playerTmp25;
        printf("Digite o nome player");
        scanf("%s",playerTmp25.name);
        printf("Digite as moedas do player");
        scanf("%d",&playerTmp25.coin);
        insertNode(&root,playerTmp25);
        break;
    case 3:
        puts("Digite os dados do player");
        Player playerTmp;
        puts("Digite o nome player");
        scanf("%[^\n]",&playerTmp.name);
        puts("Digite as moedas do player");
        scanf("%d",&playerTmp.coin);
        deleteNode(&root,playerTmp);
        break;
    case 4:
        puts("Digite os dados do players");
        Player playerTmp1;
        puts("Digite o nome player vencedor");
        scanf("%[^\n]",&playerTmp1.name);
        puts("Digite as moedas do player");
        scanf("%d",&playerTmp1.coin);
        
        Player playerTmp2;
        puts("Digite o nome player perdedor");
        scanf("%[^\n]",&playerTmp2.name);
        puts("Digite as moedas do player");
        scanf("%d",&playerTmp2.coin);
        fight(&root,playerTmp1,playerTmp2);
        break;
    }

    deleteNode(&root, player4);
    
    fight(&root,player2,player3);

    
    printTree(root);
    node *temp = (node *)malloc(sizeof(struct node));
    temp = searchNode(99, root);

    // printf("Fulano encontrado: %s\n", temp->player.name);
    return 0;
}
