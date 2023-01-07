#include<stdio.h>
#include<stdlib.h> 
#define MAX_ELEMENT 200
typedef int element;
typedef struct{
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

HeapType* create(){
	return (HeapType*)malloc(sizeof(HeapType));
}
void init(HeapType* h){
	h->heap_size=0;//
}
//현재 요소의 개수가 heap_size인 히프 h에 item 삽입 
void insert_max_heap(HeapType* h, element item){
    int i;
    i = ++(h->heap_size);//
    //트리를 거슬러 올라가면서 부모노드와 비교하는 과정
    while((i!=1) && (item  > h->heap[i/2])){
       h->heap[i] = h->heap[i/2];  //부모노드를 삽입위치로 교환
			 i = i/2;//i는 부모노드 위치
    }
    h->heap[i]=item;//  //새로운 노드를 삽입
}
//삭제함수 
element delete_max_heap(HeapType* h){
    int parent, child;
    element item, temp;
    item = h->heap[1];//루트
	  temp = h->heap[h->heap_size];//후계자
    parent = 1;//
	  child = 2;//
    while(child <=h->heap_size){
       if ((child < h->heap_size) && 
           (h->heap[child]) <h->heap[child+1]) //현재노드 자식 중 더 큰 자식노드를 검색
           child++;
       if (temp >= h->heap[child]) break;
       h->heap[parent] = h->heap[child];// //한단계 아래 이동
       parent = child;//;
       child *= 2;//
    }
    h->heap[parent]=temp;//
	return item;
}
//우선순위 큐인 히프를 이용한 정렬
void heap_sort(element a[], int n){
	int i;
	HeapType* h = create();//힙 생성
	h->heap_size = 0;
	for(i=0;i<n;i++){
		insert_max_heap(h,a[i]);//최대힙에 삽입하는 함수 호출
	}
	for(i=n-1;i>=0;i--){
		a[i]=delete_max_heap(h);//최대힙 삭제
	}
	free(h);
	
} 
#define SIZE 8
int main(){
	element list[SIZE]={23,56,11,9,56,99,27,34};
	heap_sort(list,SIZE);
	for(int i =0;i<SIZE;i++){
		printf("%d ",list[i]);
	}
	printf("\n");
	return 0;
} 


