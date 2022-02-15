#include <stdio.h>
#include <stdlib.h>
/******************
 *Jeferson Silva
 *Diego teixeira
 *
 *******************/
//---------------------------Data structure--------------------//

typedef struct Player
{
    char *name;
    int coin;
} Player;

typedef struct node
{
    struct Player player;
    int position;
    struct node *left;
    struct node *right;
} node;

//---------------------------- Functions ----------------------//

// Defalt Binarye Tree operatios
void deleteNode(node **root, Player player); // Delete nodes on tree diferent cases
node *searchNode(int moedas, node *root);    // izi dude OK

int swapNodes(node whereNode, node fromNode); /// BOSS****

// Custom Operatios
int sumCoins(char *playerName, int coinsToSum);
int rmCoins(char *playerName, int coinsToRemove);
void printTree(node *root); //  mostrar arvore em ERD
node *calcPositions(node *root);
node *obteMenorNo(node *no);

// Implementatios

node insertNode(node **root, Player player)
{

    node *temp = NULL;
    if (*root == NULL)
    {
        temp = (node *)malloc(sizeof(struct node));
        temp->left = temp->right = NULL;
        temp->position = 1;
        temp->player = player;
        *root = temp;
    }
    else if ((*root)->player.coin < player.coin)
    {
        insertNode(&(*root)->left, player);
    }
    else if ((*root)->player.coin > player.coin)
    {
        insertNode(&(*root)->right, player);
    }
}

node *searchNode(int moedas, node *root)
{
    if (root != NULL)
    {
        if (root->player.coin == moedas)
        {
            return root;
        }
        else if (root->player.coin < moedas)
        {
            return searchNode(moedas, root->left);
        }
        else if (root->player.coin > moedas)
        {
            return searchNode(moedas, root->right);
        }
    }
}

void printTree(node *root)
{
    if (root != NULL)
    {
        printTree(root->left);
        printf("**********    Player   *******\n");
        printf("Posicao: %d\n", root->position);
        printf("Nome: %s\n", root->player.name);
        printf("Pontos: %d\n", root->player.coin);
        printf("\n****************************\n");
        printTree(root->right);
    }
}

node *calcPositions(node *root)
{
    if (root == NULL)
    {
        root->position++;
    }
    else if (root->left != NULL)
    {
        calcPositions(root->left);
    }
    else if (root->right != NULL)
    {
        calcPositions(root->right);
    }

    return root;
}

node *MaiorDireita(node **root)
{
    if ((*root)->right != NULL)
        return MaiorDireita(&(*root)->right);
    else
    {
        node *aux = *root;
        if ((*root)->left != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esquerda!
            *root = (*root)->left;
        else
            *root = NULL;
        return aux;
    }
}

void deleteNode(node **root, Player player)
{

    if (*root == NULL)
    { // esta verificacao serve para caso o numero nao exista na arvore.
        printf("Player nao existe na arvore!");
        return;
    }
    if (player.coin > (*root)->player.coin)
        deleteNode(&(*root)->left, player);
    else if (player.coin < (*root)->player.coin)
        deleteNode(&(*root)->right, player);
    else
    { // se nao eh menor nem maior, logo, eh o player que estou procurando! :)
        node *pAux = *root;
        if (((*root)->left == NULL) && ((*root)->right == NULL))
        { // se nao houver filhos...
            free(pAux);
            (*root) = NULL;
        }
        else
        { // so tem o filho da direita
            if ((*root)->left == NULL)
            {
                (*root) = (*root)->right;
                pAux->right = NULL;
                free(pAux);
                pAux = NULL;
            }
            else
            { // so tem filho da esquerda
                if ((*root)->right == NULL)
                {
                    (*root) = (*root)->left;
                    pAux->left = NULL;
                    free(pAux);
                    pAux = NULL;
                }
                else
                {
                    pAux = MaiorDireita(&(*root)->left);
                    pAux->left = (*root)->left;
                    pAux->right = (*root)->right;
                    (*root)->left = (*root)->right = NULL;
                    free((*root));
                    *root = pAux;
                    pAux = NULL;
                }
            }
        }
    }
}
