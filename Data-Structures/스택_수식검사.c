#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 20
typedef char element;
//스택 구조체 정의
typedef struct{
	element data[STACK_SIZE];
	int top;
}Stack;

int checkTest(char expr[]);
void initStack( Stack *s );
int isFull( Stack *s );
int isEmpty( Stack *s );
void push( Stack *s, element data );
element pop( Stack *s );

int main(){
	int i;
	Stack s;
	char expr[20];
	
	printf("괄호포함 수식 입력 : ");
	scanf("%s", expr);
	if (checkTest(expr)) printf("성공");
	else printf("실패");
	return 0;
	
}
void initStack( Stack *s ){
	//초기화코드
	s->top = -1;
}
int isFull( Stack *s ){
	return s->top = STACK_SIZE-1;//코드작성
}
int isEmpty( Stack *s ){
	return s->top == -1;//코드작성
}
void push( Stack *s, element c ){
	if(s->top == STACK_SIZE-1){
		printf("stack is full\n");
		return ;
	}
	//push 코드작성
	s->top++;
	s->data[s->top]=c;
}
element pop( Stack *s ){
	if(s->top==-1){
		printf("stack is empty\n");
		return 0 ;
	}
	//pop 코드작성
	return s->data[s->top--];
}
int checkTest(char expr[]){
	int i;
	Stack s;
	initStack(&s);
	char ch,open_ch;
  for(i=0;expr[i]!='\0';i++){
		//코드작성
		ch=expr[i];
		switch(ch){
			case '(': 
			case '[':
			case '{':
			//코드작성
				push(&s,ch);
				break;
			case ')':
			case ']':
			case '}':	
				if (isEmpty(&s)) return 0;
				open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')') ||
					  (open_ch == '[' && ch != ']') ||
					  (open_ch == '{' && ch != '}') ) {
					return 0;
				}
				// printf("open_ch=%c\n",open_ch);
				break;
		}
	}
	if (!isEmpty(&s)) return 0;
	return 1;
}
