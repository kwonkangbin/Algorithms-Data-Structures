#include <stdio.h>
#define MAX 300
typedef  int element;
typedef struct{
	element data[300];
	int top;
}Stack;
Stack s;
void initStack(Stack* s){
	s->top=-1;
}
int isEmpty(Stack* s){
	 return s->top==-1;
}
int isFull(Stack* s){
	 return s->top==MAX-1;
}
void push(Stack* s, element c){
	if(isFull(&s)){
  	printf("FULL");
 }
 else{
	  s->top++;
		s->data[s->top]=c;
 }
}
element pop(Stack* s ){
	int d;
 	if(isEmpty(&s)){
		printf("EMPTY");
		return 0;
 	}
	d = s->data[s->top];
  s->top--;
	return d;
}
int main(){
	char expr[300];
	int d,n1,n2;
	Stack s;
	gets(expr);
	for(int i=0;expr[i]!='\0';i=i+2){
		if(expr[i]!='+' && expr[i]!='*' && expr[i]!='-' && expr[i]!=' '){
			push(&s,expr[i]-'0');
		}
		else{
			n1 = pop(&s);
			n2 = pop(&s);
			switch(expr[i]){
				case '+': d = n1 + n2; break;
				case '*': d = n1 * n2; break;
				case '-': d = n2 - n1; break;	
			}
			push(&s,d);
		}
	}
	printf("%d",d);
	return 0;
}

