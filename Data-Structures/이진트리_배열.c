#include<stdio.h>
//시험 순회 나옴!!!!(중위 순회!!)
void preorder( char t[], int i, int size ){
		if(size<i || t[i] == NULL){
			return;
		}
		printf("%c ",t[i]);
		preorder(t,2*i,size);
		preorder(t,2*i+1,size);
}
void inorder( char t[], int i, int size ){
		if(size<i || t[i] == NULL){
			return;
		}
		inorder(t,2*i,size);
		printf("%c ",t[i]);
		inorder(t,2*i+1,size);
}
void postorder( char *t, int i, int size ){
		if(size<i || t[i] == NULL){
			return;
		}
		postorder(t,2*i,size);
		postorder(t,2*i+1,size);
		printf("%c ",t[i]);
}
int main(){
	char tree[]= {0,'A','B','C','D','E','F','G',0,0,'H','I',0,'J','K','L'/*이진트리노드를 배열요소로 저장*/};
	int size=16;
	printf("\n<<전위 탐색>>\n");
	preorder( tree, 1, size );
	printf("\n<<중위 탐색>>\n");
	inorder( tree, 1, size );
	printf("\n<<후위 탐색>>\n");
  postorder( tree, 1, size );
	
}
