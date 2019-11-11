#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
    bool primo;
    int cont=0;
    int valore;
    puts("inserire valore max");
    scanf("%d",&valore);
    int *ptrDin;

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
            //printf("%d(OK)\n",cont*sizeof(int));
            int *contProvvisorio=((int*) malloc(sizeof(int)*cont));
            //printf("%d(MEM)\n",sizeof(contProvvisorio));
            if(cont==1)
            {
                *contProvvisorio=valore;
            }
            else
            {
                memcpy(contProvvisorio,ptrDin,sizeof(int)*(cont-1));
                contProvvisorio[cont-1]=valore;
                free(ptrDin);
            }
            ptrDin=((int*)malloc(sizeof(int)*cont));
            memcpy(ptrDin,contProvvisorio,sizeof(int)*cont);
            free(contProvvisorio);
        }
        valore--;
    }
    for(int j=0;j<cont;j++)
    {
        printf("%d\n",ptrDin[j]);
    }
}
