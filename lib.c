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
node insertNode(node **root, player player); // insert ordering nodes OK
node deleteNode(player player, node *root); // Delete nodes on tree diferent cases 
node *searchNode(int moedas, node *root); // izi dude OK

int swapNodes(node whereNode, node fromNode); /// BOSS****

// Custom Operatios
int sumCoins(char* playerName,int coinsToSum);
int rmCoins(char* playerName, int coinsToRemove);
void printTree(node *root);//  mostrar arvore em ERD 
node *calcPositions(node *root);


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
}

node deleteNode(player player, node *root){

}

node *searchNode(int moedas , node *root){
    if(root != NULL) {
        if(root->player.coin ==  moedas){
            return root;
        }else if(root->player.coin <  moedas){
           return searchNode(moedas, root->left);
        }else if(root->player.coin >  moedas){
            return searchNode(moedas,root->right);
        }
    }
}

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
}

node *calcPositions(node *root ){
    if(root == NULL) {
        root->position++;
    }
	else if (root->left != NULL) {
	   calcPositions(root->left);
   }else if(root->right != NULL){
       calcPositions(root->right);
   }
   
   return root; 	
}

