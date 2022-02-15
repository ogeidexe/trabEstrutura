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
<<<<<<< HEAD
}Player;


typedef struct node
{   
    struct Player player;
=======
} player;

typedef struct node
{
    struct player player;
>>>>>>> d8c8a6f67f1fcd80c0c96974afc0a43741b4cf06
    int position;
    struct node *left;
    struct node *right;
} node;

//---------------------------- Functions ----------------------//

// Defalt Binarye Tree operatios
<<<<<<< HEAD
node insertNode(node **root, Player player); // insert ordering nodes OK
node deleteNode(Player player, node **root); // Delete nodes on tree diferent cases 
node *searchNode(int moedas, node *root); // izi dude OK
=======
node insertNode(node **root, player player); // insert ordering nodes OK
void deleteNode(node **root, player player); // Delete nodes on tree diferent cases
node *searchNode(int moedas, node *root);    // izi dude OK
>>>>>>> d8c8a6f67f1fcd80c0c96974afc0a43741b4cf06

int swapNodes(node whereNode, node fromNode); /// BOSS****

// Custom Operatios
int sumCoins(char *playerName, int coinsToSum);
int rmCoins(char *playerName, int coinsToRemove);
void printTree(node *root); //  mostrar arvore em ERD
node *calcPositions(node *root);
node *obteMenorNo(node *no);

// Implementatios

node insertNode(node **root, player player)
{

<<<<<<< HEAD
node insertNode(node **root,Player player){
    if(*root == NULL){        
        node *temp = NULL;
        temp  = (node *)malloc(sizeof(struct node));
        temp->left = NULL; 
        temp->right = NULL;
=======
    node *temp = NULL;
    if (*root == NULL)
    {
        temp = (node *)malloc(sizeof(struct node));
        temp->left = temp->right = NULL;
>>>>>>> d8c8a6f67f1fcd80c0c96974afc0a43741b4cf06
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

<<<<<<< HEAD
node deleteNode(Player player, node **root){
    node *parent = NULL;
    node *current = *root;
    //numero de moedas
    parent  = searchNode(player.coin,*root);
    //Caso  1 onde o no não tem filhos
    //teste da arvore
    if (current == NULL) {
        return;
    }  

    if(current->left  ==  NULL && current->right ==  NULL){
        printf(">%s:%s<",parent->player.name,(*root)->player.name);
        if(current != *root){
            if(parent->left == current)
                parent->left =  NULL;
            else
                parent->right = NULL;
        }else{
            root = NULL;
        }
        free(current);  
    //Caso  2 onde o no tem dois filhos
    }else if(current->left && current->right){
        // encontrar o sucessor na ordem -
        node *sucessor =  obteMenorNo(current->right);
        // guardar o valor do sucessor
        Player playerTmp = sucessor->player;
        //remove sucessor da arvore   
        deleteNode(sucessor->player, root);
        
        current->player =  playerTmp;
    //Caso 3 o no tem apenas um filho
    }else{
        node*  chlid =  (current->left) ? current->left : current->right;
        //Se o no não for o no root defina o como um de seus filhos
        if(current != *root){
            if (current == parent->left){
                parent->left =  chlid;
            }else{
                parent->right=  chlid;
            }

        }else{
            *root =  chlid;
        }
        free(current);
    }

}

node *searchNode(int moedas , node *root){
    if(root != NULL) {
        if(root->player.coin ==  moedas){
=======
node *searchNode(int moedas, node *root)
{
    if (root != NULL)
    {
        if (root->player.coin == moedas)
        {
>>>>>>> d8c8a6f67f1fcd80c0c96974afc0a43741b4cf06
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

<<<<<<< HEAD
void printTree (node *root) {
   if (root != NULL) {
		printTree (root->left);  
		printf("**********    Player   *******\n");
		printf ("Posicao: %d\n", root->position);
		printf ("Nome: %s\n", root->player.name); 
		printf ("Pontos: %d\n", root->player.coin);
		printf("\n****************************\n");  
        
		printTree (root->right);     
   }
=======
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
>>>>>>> d8c8a6f67f1fcd80c0c96974afc0a43741b4cf06
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

<<<<<<< HEAD
node *obteMenorNo(node * no){
    while (no->left != NULL)
    {
        no = no->left;
    }
    return no;
} 
=======
void deleteNode(node **root, player player)
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
>>>>>>> d8c8a6f67f1fcd80c0c96974afc0a43741b4cf06
