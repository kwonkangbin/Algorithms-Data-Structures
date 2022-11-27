#include <stdio.h>
#include <stdlib.h>
//배열 이름은 주소 상수 
void outputArray(int a[],int k);
int inputArray(int a[]);

int main(){
	int a[100];
	int i,size =0;
	size = inputArray(a);
	outputArray(a,size);
	return 0;
} 
	
	
int inputArray(int a[]){
	int i;
	for(i=0;i<99;i++){
		scanf("%d",&a[i]);	
		if(a[i]==0){
			break;
		}
	}
	return i-1;
}

void outputArray(int a[],int k){
	for(int i=k;i>=0;i--){
		printf("%d ",a[i]);
	}
}
