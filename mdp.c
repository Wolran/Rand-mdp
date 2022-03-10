#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char removeStr(char* a, int size, int pos) {

    int var = 0;
    var = a[pos];
    for (; pos < size-1; pos++)
        a[pos] = a[pos + 1];
    return var;
}

int replace(char* a, char* b, int size) {
    for (int i = 0; i < size; i++) {
        int j = 0;
        j = rand() % (size - i);

        b[i] = removeStr(a, size, j);
    }
    return 0;
}
int main()
{
    srand(time(NULL));
    int taille = 0;
    int nmbtemp = 0;
    int couter = 0;
	FILE *fp = fopen("fichier.txt", "w");
	
	
	char maj[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char min[] = "abcdefghijklmnopqrstuvwxyz";
    char num[] = "0123456789";

    printf("Nombre de caractere du mdp : ");
	scanf("%d", &taille);
    printf("Nombre de mdp afficher : ");
    scanf("%d", &nmbtemp);
    char* temp = NULL;
    char* mdp = NULL;
    temp = (char*)malloc(taille+1);
    temp[taille] = 0;
    mdp = (char*)malloc(taille+1);
    mdp[taille] = 0;
    
    for (int yes = 1; yes >= 1;)
	{
		
        for (int j = 0; j < nmbtemp; j++)
        {
            couter++;
            for (int i = 0; i < (taille * 0.25); i++) {
                temp[i] = maj[rand() % 26];
            }
            for (int i = (taille * 0.25); i < (taille * 0.75); i++) {
                temp[i] = min[rand() % 26];
            }
            for (int i = (taille * 0.75); i < taille; i++) {
                temp[i] = num[rand() % 10];
            }

            replace(temp, mdp, taille);
            printf("%d : %s\n",couter, mdp);
			fprintf(fp,"%d : %s\n",couter, mdp);
        }
	
        printf("press '1' pour en avoir %d mdp de plus\n", nmbtemp);
        printf("press '0' pour fermer le programe : ");
        scanf("%d", &yes);
		
        if (yes != 1)
            return 0;
    }
    free(mdp);
    free(temp);
	fclose(fp);
}