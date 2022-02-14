#include <stdio.h>
#include <stdlib.h>
/******************
*Jeferson Silva 
*Diego teixeira
*
*******************/
//---------------------------Data structure--------------------//

typedef struct player
{
    char *name;
    int coin;
}player;


typedef struct node
{   
    struct player player;
    int position;
    struct node *left;
    struct node *right;
}node;

//---------------------------- Functions ----------------------//


// Defalt Binarye Tree operatios
node insertNode(node **root, player player); // insert ordering nodes
node deleteNode(player player, node *root);
node searchNode(player player, node *root);

int swapNodes(node whereNode, node fromNode); /// BOSS****

// Custom Operatios
int sumCoins(char* playerName,int coinsToSum);
int rmCoins(char* playerName, int coinsToRemove);
void printTree(node root);//  mostrar arvore em ERD 
node calcPositions(node root);


//Implementatios

node insertNode(node **root,player player){
    
    node *temp = NULL;
    if(*root == NULL){        
        temp  = (node *)malloc(sizeof(struct node));
        temp->left = temp->right = NULL;
        temp->position = 1;
        temp->player = player;
        *root =  temp;
    }else  if((*root)->player.coin < player.coin){
        insertNode(&(*root)->left, player);
    }else  if((*root)->player.coin > player.coin){
        insertNode(&(*root)->right,player);
    }
    //if(player.coin == 100) { (*root)->position = 1;};
    //if(player.coin == 101) { (*root)->position = 2;};
    //if(player.coin == 99) { (*root)->position = 3;};
}

node deleteNode(player player, node *root){

}

node serachNode(player player, node root){

}



