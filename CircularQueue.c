#include<stdio.h>
#include<stdlib.h>

struct CirQueue
{
   int size;
   int f;
   int r;
   int *arr;
};

int isEmpty(struct CirQueue *q){
    if(q->f == q->r){
        return 1;
    }else{
        return 0;
    }
}

int isFull(struct CirQueue *q){
    if((q->r + 1) % q->size == q->f){
        return 1;
    }else{
        return 0;
    }
}

void Push(struct CirQueue *q, int val){
    if(isFull(q)){
        printf("Queue is Full");
    }else{
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
    }
}

void Pop(struct CirQueue *q){
    if(isEmpty(q)){
        printf("Queue is NULL\n");
    }else{
        q->f = (q->f + 1) % q->size;
        q->arr[q->f]=0;
    }
}

void Display(struct CirQueue *q){
    for(int i=1;i<q->size;i++){
        printf("%d\n",q->arr[i]);
    }printf("\n");
}

int main(){
    struct CirQueue q;
    q.size = 6;
    q.f = q.r = 0;
    q.arr = (int*)malloc(q.size*sizeof(int));

    printf("CirularQueue is Empty Or Not : %d\n",isEmpty(&q));

    Push(&q,1);
    Push(&q,2);
    Push(&q,3);
    Push(&q,4);
    Push(&q,5);
    //Push(&q,6);
    
    printf("CirularQueue is Empty Or Not : %d\n",isEmpty(&q));
    printf("CircularQueue is Full Or Not : %d\n",isFull(&q));

    Display(&q);
    
    Pop(&q);
    Pop(&q);
    Pop(&q);
    Pop(&q);
    Pop(&q);

    printf("CircularQueue is Empty Or Not : %d\n",isEmpty(&q));
    printf("\n");

    Display(&q);

    Push(&q,6);
    Push(&q,7);
    Push(&q,6);

    Display(&q);

    printf("CircularQueue is Empty Or Not : %d\n",isEmpty(&q));
    return 0;
}