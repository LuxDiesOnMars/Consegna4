#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
    bool primo;
    int cont=0;
    int valore;
    printf("inserisci valore max:");
    scanf("%d",&valore);
    int *ptrDin;
    int *contProvvisorio=(int *)malloc(sizeof(int));

    while(valore!=1)
    {
        primo=true;
        for(int i=valore-1;i>1;i--)
        {
            if(valore%i==0)primo=false;
        }
        if(primo==true)
        {
            ++cont;

            if(cont==1)
            {
                ptrDin=(int *) malloc(sizeof(int));
                *ptrDin=valore;
            }
            else
            {
                contProvvisorio=(int *)realloc(contProvvisorio,sizeof(int)*cont);
                memcpy(contProvvisorio,ptrDin,sizeof(int)*(cont-1));
                contProvvisorio[cont-1]=valore;
                ptrDin=(int *)realloc(ptrDin,sizeof(int)*cont);
                memcpy(ptrDin,contProvvisorio,sizeof(int)*cont);
            }

        }
        valore--;
    }
    free(contProvvisorio);
    printf("numeri primi fino a valore inserito:\n");
    for(int j=cont-1;j>=0;j--)
    {
        printf("%d\n",ptrDin[j]);
    }
    free(ptrDin);
    return 0;
}
