#include "stdio.h"
#include "stdlib.h"

int main(){
	int h,c;
	scanf("%d%d",&h,&c);
	float **arr=(float**)malloc(h*sizeof(float*));
	if(arr==NULL){
		printf("Ko du bo nho!");
		return 1;
	}
	for(int i=0;i<h;i++){
		arr[i]=(float*)malloc(c*sizeof(float));
		if(arr[i]==NULL){
			printf("Ko du bo nho!");
			return 1;
		}
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<c;j++){
			scanf("%f",&arr[i][j]);
		}
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<c;j++){
			printf("%.2f\t",arr[i][j]);
		}
		printf("\n");
	}
	for(int i=0;i<h;i++){
		free(arr[i]);
	}
	free(arr);
	return 0;
}
