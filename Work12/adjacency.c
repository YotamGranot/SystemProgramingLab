#include "adjacency.h"


int path(adjmat, int, int);/*function that return true if there is path between two given args*/
void getMat(adjmat);/*func that scan for matrix values*/
void printMat(adjmat);/*function that prints matrix*/
int isValid(int ,int);/*function that return true uf bote given indexes are in the given matrix*/
int main() {
    adjmat mat;
    int indexU, indexV;
    int isPath;
    getMat(mat);
    printMat(mat);
    printf("please enter two indexes\n");
    scanf("%d%d",&indexU,&indexV);
    while(!((indexU==EOF||indexV==EOF)||(indexU==-1&&indexV==-1))) {
	/*while the given indexes arent -1,-1*/
        isPath = path(mat, indexU, indexV);
        printf("\nthe first index is: %d\nthe second index is: %d\n", indexU, indexV);
        if (isPath) {
            printf("\nthere is path between %d and %d", indexU, indexV);
        } else {
            printf("\nthere isn't path between %d and %d", indexU, indexV);
        }
        printf("\nplease enter two indexes\n");
        scanf("%d%d", &indexU, &indexV);
    }
    puts("");
    return 0;
}
int path(adjmat mat, int u, int v){
    int i, isPath=FALSE;
    if(!isValid(u, v)){
	/*check if both indexes valid*/
        return FALSE;
    }
    if(u==v)
	return TRUE; 
    if(mat[u][v]==1){
	/*if u is parent of v*/
        return TRUE;
    }
    for(i=0;i<N;i++) {
	/*for each of u's children check if there is path between them and v*/
        if (mat[u][i] == 1) {
            if (path(mat, i, v))
                isPath = TRUE;
        }
    }
    return isPath;
}
void getMat(adjmat mat){
    int i,j;
    i=j=0;
    printf("matrix's size is %dx%d\n",N,N);
    printf("please enter each row of the matrix in different line, each number separated by a space\n");
    while(i<N){
	/*modify for different sizes*/
        scanf("%d",&(mat[i][0]));
	scanf("%d",&(mat[i][1]));
	scanf("%d",&(mat[i][2]));
        i++;
    }
    return;
}
void printMat(adjmat mat){
    int i,j;
    for (i = 0; i < N; i++)
    { for (j = 0; j < N; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    return;

}
int isValid(int u, int v){
    if((u>-1&&u<N)&&(v>-1&&v<N)){
        return TRUE;
    }
    return FALSE;
}
