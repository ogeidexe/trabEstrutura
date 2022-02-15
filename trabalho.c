#include "lib.c"

/******************
 *Jeferson Silva
 *Diego Teixeira
 *
 *******************/

int main(int argc, char const *argv[])
{
    node *root = NULL;

    player player1;
    player1.name = "jeronimo";
    player1.coin = 100;
    insertNode(&root, player1);

    player player2;
    player2.name = "JOAO";
    player2.coin = 101;
    insertNode(&root, player2);

    player player3;
    player3.name = "medonho";
    player3.coin = 99;
    insertNode(&root, player3);

    player player4;
    player4.name = "Jefim";
    player4.coin = 200;
    insertNode(&root, player4);

    player player5;
    player5.name = "Diego";
    player5.coin = 20;
    insertNode(&root, player5);

    // printf("%s\n",root->player.name);
    // printf("%s\n",root->left->player.name);
    // printf("%s\n",root->right->player.name);

    root = calcPositions(root);
    deleteNode(&root, player4);
    printTree(root);
    node *temp = (node *)malloc(sizeof(struct node));
    temp = searchNode(99, root);
    // printf("Fulano encontrado: %s\n", temp->player.name);
    return 0;
}
