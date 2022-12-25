#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 20

typedef char element;
//스택 구조체 작성
typedef struct{
	int top;
	element data[STACK_SIZE];
}Stack;

void initStack( Stack *s );
int isFull( Stack *s );
int isEmpty( Stack *s );
void push( Stack *s, element data );
element pop( Stack *s );

int main(){
	int i;
 	Stack s;
	char str[20];
	printf("문자열 입력 : ");
	scanf("%s", str);
	//문자열을 입력받아 거꾸로 출력
	initStack(&s);
	for(int i=0;str[i]!='\0';i++){
		push(&s,str[i]);
	}
	
	for(int i=0;str[i]!='\0';i++){
		printf("%c",pop(&s));
	}
}

void initStack( Stack *s ){
	 s->top=-1;
}
int isFull( Stack *s ){
	 return s->top == STACK_SIZE-1;
}
int isEmpty( Stack *s ){
	return s->top == -1;
}
void push( Stack *s, element c ){
	 if(isFull(s)){
		 printf("Stack is Empty\n");
		 return;
	 }
	s->top++;
	s->data[s->top]=c;
}
element pop( Stack *s ){
	 if(isFull(s)){
		 printf("Stack is Empty\n");
		 return;
	 }
	return s->data[s->top--];
}
