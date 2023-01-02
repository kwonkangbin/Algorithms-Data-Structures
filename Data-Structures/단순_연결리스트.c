// 동적으로 구조체 생성하기
//연결 리스트와 배열 부분 중요함,추상데이터 타입,
#include<stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct Node{
	element data;
	struct Node *next;
}Node;
int main(){
	 Node *n1, *n2 ,*n3, *head;
    n1 = (Node *)malloc(sizeof(Node));
    n2 = (Node *)malloc(sizeof(Node));
		n3 = (Node *)malloc(sizeof(Node));
 		n1->data=10;
		n1->next=n2;
		n2->data = 20;
		n2->next = n3;
		n3->data=30;
		// n3->next=NULL;printf("%p %p %p\n",n1,n2,n3);
    head = n1;//8)n1의 주소 저장(참조)
    while( head != NULL ){
        printf("%d->", head->data);
				head = head->next;			  
    }
}
