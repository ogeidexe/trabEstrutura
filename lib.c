#include <stdio.h>
/******************
*Jeferson Silva 
*Diego teixeira
*
*******************/
//---------------------------Data struture--------------------//

typedef struct player
{
    char *name;
    int coin;
}player;


typedef struct node
{   
    struct player player;
    int position;
    struct node *esq;
    struct node *dir;
}node;

//---------------------------- Functions ----------------------//


// Defalt Binarye Tree operatios
int insertNode(player player, node root); // insert ordering nodes
node deleteNode(player player, node root);
node searchNode(player player, node root);

int swapNodes(node whereNode, node fromNode); /// BOSS****

// Custom Operatios
int sumCoins(char* playerName,int coinsToSum);
int rmCoins(char* playerName, int coinsToRemove);
void printTree(node root);//  mostrar arvore em ERD 
node calcPositions(node root);


//Implementatios

int insertNode(player player, node root){

}

node deleteNode(player player, node root){

}

node serachNode(player player, node root){

}



