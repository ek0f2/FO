#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define BOARD_SIZE 2
#define SIZE 12
#define N 4


typedef struct {
    int up;
    int down;
    int left;
    int right;

} ttoken;

typedef struct{
	
	unsigned int x;
	unsigned int y;

}tcoordinate;

void init_matrix(int fil, int col, int matrix[fil][col]);
void print_matrix(int fil, int col, int matrix[fil][col]);
void make_board_game(int size, int board[][size]);
void print_board_game(int size, int board[][size]);
int equal_tokens(ttoken token1, ttoken token2);

//Devuelve un numero entero entre 0 y num. Seed es el parametro que determina como se genera el numero.
//Para probar el programa seed=TRUE, los numeros aleatorios siempre seran los mismos;
int random_num_gen(int seed, int num);

int busca_elemento(int elemento, int m[N][N], int *ppos_i, int *ppos_j);
void intercambia_elemento(tcoordinate pos1, tcoordinate pos2, int m[N][N]);

int i=0,j=0,k=0;

int main() {

    int size = BOARD_SIZE;
    srand (time(NULL));
    //srand(1);
	int m[N][N];
	init_matrix(N,N,m);
	//print_matrix(N,N,m);
	printf("\n");
	/*printf("Introduzca posiciones a intercambiar:\n");
	printf("Ejemplo[A1B2]: ");
	tcoordinate coord1, coord2;
	scanf("[%c%d%c%d]%*c",&coord1.y,&coord1.x,&coord2.y,&coord2.x);
	
	//Esta condicion tiene que arreglarse en funcion del tamanyo del tablero
	if ((char) coord1.y>='A' && (char) coord1.y<='Z'||(char) coord2.y>='A' && (char) coord2.y<='Z' ){
		coord1.y=(char)coord1.y-'A';
		coord2.y=(char)coord2.y-'A';
	}
	else{
		printf("Coordenadas no validas\n");
		return (EXIT_FAILURE);
	}
	intercambia_elemento(coord1,coord2,m);
	print_matrix(N,N,m);
    */
    
     ttoken board[size][size];
     
    for(i=size-1;i>=0;i--){
        for(j=size-1;j>=0;j--){

            board[i][j].up=rand()%10;
           if(i<size-1)
            	board[i][j].down=board[i+1][j].up;
            else
            	board[i][j].down=rand()%10;
			board[i][j].left=rand()%10;
            //if(j!=size)
            board[i][j].right=board[i][j+1].left;
            //else
            //board[i][j].right=10;
            //printf("%d\n",board[i][j+1].right);
        
        }
    }
    board[size-1][size-1].right=rand()%10;
    
    for(j=0;j<size;j++)
		printf("\t  %c",'A'+j);
		printf("\n\n\n");

     for(i=0;i<size;i++){
     	printf(" %d",i);
        for(j=0;j<size;j++){
	        printf("\t/ %d \\",board[i][j].up);                           
    	}
    	printf("\n");
    	for(j=0;j<size;j++){
	     
    	
    	printf("\t %dx%d ",board[i][j].left,board[i][j].right);
    	}
    	printf("\n");
    	for(j=0;j<size;j++){ 
	        printf("\t\\ %d /",board[i][j].down);
    	}
    	
    	printf("\n\n");

    }
    printf("Introduzca posiciones a intercambiar:\n");
	printf("Ejemplo[A1B2]: ");
	tcoordinate coord1, coord2;
	scanf("[%c%d%c%d]%*c",&coord1.y,&coord1.x,&coord2.y,&coord2.x);
	
	//Esta condicion tiene que arreglarse en funcion del tamanyo del tablero
	if ((char) coord1.y>='A' && (char) coord1.y<='Z'||(char) coord2.y>='A' && (char) coord2.y<='Z' ){
		coord1.y=(char)coord1.y-'A';
		coord2.y=(char)coord2.y-'A';
	}
	else{
		printf("Coordenadas no validas\n");
		return (EXIT_FAILURE);
	}
	//intercambia_elemento(coord1,coord2,m);
	printf("\n\n");
	for(j=0;j<size;j++)
		printf("\t  %c",'A'+j);
		printf("\n\n\n");

     for(i=0;i<size;i++){
     	printf(" %d",i);
        for(j=0;j<size;j++){
	        printf("\t/ %d \\",board[i][j].up);                           
    	}
    	printf("\n");
    	for(j=0;j<size;j++){
	     
    	
    	printf("\t %dx%d ",board[i][j].left,board[i][j].right);
    	}
    	printf("\n");
    	for(j=0;j<size;j++){ 
	        printf("\t\\ %d /",board[i][j].down);
    	}
    	
    	printf("\n\n");

    }
    return (EXIT_SUCCESS);
}

int equal_tokens(ttoken token1, ttoken token2){
	if (token1.up == token2.up && token1.down == token2.down 
	&& token1.right == token2.right && token1.left == token2.left)
	
		return TRUE;
		
	else return FALSE;

}

void intercambia_elemento(tcoordinate coord1, tcoordinate coord2, int m[N][N]){
	
	int elemento_aux;
	
	tcoordinate pos_aux;
	
	pos_aux.x=coord2.x;
	pos_aux.y=coord2.y;
	
	elemento_aux=m[coord1.x][coord1.y];
	
	m[coord1.x][coord1.y]=m[coord2.x][coord2.y];
	m[coord2.x][coord2.y]=elemento_aux;
			
}
//Busca un elemento en una matriz y si lo encuentra pasa por referencia la posicion
//i y la posicion j en la que se encuentra el elemento.
int busca_elemento(int elemento, int m[N][N], int *ppos_i, int *ppos_j){
	int encontrado=0;
	
	    for (i=0;i<N;i++){
	    	for(j=0;j<N;j++){
				if (m[i][j]==elemento){
					*ppos_i=i;
					*ppos_j=j;
					encontrado=1;
				}
			}
		}
		return encontrado;
}

void init_matrix(int fil, int col, int matrix[fil][col]) {

    int i = 0, j = 0;

    for (i = 0; i < fil; i++) {
        for (j = 0; j < col; j++) {
            matrix[i][j] = rand()%10;
        }
    }

}

void print_matrix(int fil, int col, int matrix[fil][col]) {
    int i = 0, j = 0;
    for(j=0;j<col;j++)
		printf("\t%c",'A'+j);
		printf("\n\n");
    for (i = 0; i < fil; i++) {
    	printf("%d",i);
        for (j = 0; j < col; j++) {
            printf("\t%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void make_board_game(int size, int board[][size]) {
    init_matrix(size, size, board);
}

void print_board_game(int size, int board[][size]) {
    print_matrix(size, size, board);
}
int random_num_gen(int seed, int num){
	
	if (seed=FALSE)
    	srand (time(NULL));
    else
    	srand(seed);
	
	return rand()%num;
}