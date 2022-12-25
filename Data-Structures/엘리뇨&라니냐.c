#include <stdio.h>
int main() {
	int max=0,min=0,ma,mi;
	float a[11];
	float enso[11][2] = { {1990, 0.6}, 
											  {1991, 0.2}, 
												{1992, 1.1}, 
											  {1993, 0.5}, 
											  {1994, 0.1}, 
											  {1995, 1.2}, 
											  {1996, -0.3},
											  {1997, -0.1},
											  {1998, 2.2}, 
											  {1999, -0.7},
											  {2000, -1.1} };
	printf("엘리뇨 : ");
	for(int i=0;i<=10;i++){
		if(enso[i][1]>0){
			printf("%.0f ",enso[i][0]);
		}
		if(enso[i][1]>max){
			max=enso[i][1];
			ma=i;
		}
	}
	printf("\n");
	printf("가장 강한 엘리뇨 : %.0f",enso[ma][0]);
	printf("\n");
	printf("라니냐 : ");
	for(int i=0;i<=10;i++){
		if(enso[i][1]<0){
			printf("%.0f ",enso[i][0]);
		}
		if(enso[i][1]<min){
			min=enso[i][1];
			mi=i;
		}
	}
	printf("\n");
	printf("가장 강한 라니냐 : %.0f",enso[mi][0]);
	printf("\n");
	printf("가장 정상적인 해 :");
	for(int i=0;i<=10;i++){
		if(enso[i][1]<0){
			enso[i][1]*=-1.0;
		}
		a[i]=0-enso[i][1];
		if(a[i]>=-0.1001){
			printf("%.0f ",enso[i][0]);
		}		
	}

	return 0;
}
