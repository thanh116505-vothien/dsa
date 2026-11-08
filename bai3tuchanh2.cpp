#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char ten[50];
    int ma;
    float d1,d2,d3;
}SV;

int main(){
    int n;
    printf("So luong sv: ");
    scanf("%d",&n);
    SV *ds=(SV*)malloc(n*sizeof(SV));
    if(ds==NULL){
        printf("Khong du bo nho");
        return 1;
    }
    for(int i=0;i<n;i++){
    	fflush(stdin);
        printf("Ho ten: ");
        fgets((ds+i)->ten,sizeof(ds+i)->ten,stdin);
        (ds+i)->ten[strcspn((ds+i)->ten,"\n")]='\0';
        printf("Ma SV: ");
        scanf("%d",&(ds+i)->ma);
        printf("Diem 1: ");
        scanf("%f",&(ds+i)->d1);
        printf("Diem 2: ");
        scanf("%f",&(ds+i)->d2);
        printf("Diem 3: ");
        scanf("%f",&(ds+i)->d3);
    }
    printf("\n%s\t\t%s\t%s\t%s\t%s\n","Ho ten","Ma SV","Diem 1","Diem 2","Diem 3");
    for(int i=0;i<n;i++){
        printf("%s\t%d\t%.2f\t%.2f\t%.2f\n",(ds+i)->ten,(ds+i)->ma,(ds+i)->d1,(ds+i)->d2,(ds+i)->d3);
    }
    free(ds);
    return 0;
}
