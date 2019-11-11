#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char contenitProv[100];
    char **vettDinam;
    int nPar;
    do{
        puts("quante parole si vogliono inserire?\n");
        scanf("%d",&nPar);
        fflush(stdin);
    }while(nPar<=0);
    vettDinam=(char **)malloc(nPar*sizeof(char *));
    for(int i=0;i<nPar;i++)
    {
        printf("\ninserire parola %d:\n",i+1);
        scanf("%99s",contenitProv);
        fflush(stdin);
        int lun=strlen(contenitProv)+1;
        char *parola=(char *)malloc(sizeof(char)*lun);
        memcpy(parola,contenitProv,lun);
        vettDinam[i]=parola;
    }
    puts("le parole inserite sono:\n");
    for(int j=0;j<nPar;j++)
    {
        printf("parola %3d:\t%s\n",j+1,*(vettDinam+j));
    }

    return 0;

}


