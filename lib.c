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
}Player;


typedef struct node
{   
    struct Player player;
    int position;
    struct node *left;
    struct node *right;
}node;

//---------------------------- Functions ----------------------//


// Defalt Binarye Tree operatios
node insertNode(node **root, Player player); // insert ordering nodes OK
node deleteNode(Player player, node **root); // Delete nodes on tree diferent cases 
node *searchNode(int moedas, node *root); // izi dude OK

int swapNodes(node whereNode, node fromNode); /// BOSS****

// Custom Operatios
int sumCoins(char* playerName,int coinsToSum);
int rmCoins(char* playerName, int coinsToRemove);
void printTree(node *root);//  mostrar arvore em ERD 
node *calcPositions(node *root);
node *obteMenorNo(node *no);


//Implementatios

node insertNode(node **root,Player player){
    if(*root == NULL){        
        node *temp = NULL;
        temp  = (node *)malloc(sizeof(struct node));
        temp->left = NULL; 
        temp->right = NULL;
        temp->position = 1;
        temp->player = player;
        *root =  temp;
    }else  if((*root)->player.coin < player.coin){
        insertNode(&(*root)->left, player);
    }else  if((*root)->player.coin > player.coin){
        insertNode(&(*root)->right,player);
    }
}

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

node *obteMenorNo(node * no){
    while (no->left != NULL)
    {
        no = no->left;
    }
    return no;
} 
