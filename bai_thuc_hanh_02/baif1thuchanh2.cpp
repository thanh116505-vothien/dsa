#include "stdio.h"
#include "stdlib.h"

int main(){
	int n;
	scanf("%d",&n);
	float *arr=(float*)malloc(n*sizeof(float));
	if(arr==NULL){
	printf("Ko du bo nho!");
	return 1;
	}
	for(int i=0;i<n;i++){
		scanf("%f",arr+i);
	}
	for(int i=0;i<n;i++){
		printf("%.2f ",*(arr+i));
	}
	printf("\n");
	free(arr);
	return 0;
}
