#include<stdio.h>
#include<stdlib.h>


struct Queue
{
   int size;
   int f;
   int r;
   int *arr;
};

int isEmpty(struct Queue *q){
    if(q->f == q->r){
        return 1;
    }else{
        return 0;
    }
}

int isFull(struct Queue *q){
    if(q->r == q->size-1){
        return 1;
    }else{
        return 0;
    }
}

void Push(struct Queue *q, int val){
    if(isFull(q)){
        printf("Queue is Full");
    }else{
        q->r++;
        q->arr[q->r] = val;
    }
}

void Pop(struct Queue *q){
    if(isEmpty(&q)){
        printf("Queue is NULL");
    }else{
        q->f++;
        q->arr[q->f]=0;
    }
}

void Display(struct Queue *q){
    for(int i=0;i<q->size;i++){
        printf("%d\n",q->arr[i]);
    }printf("\n");
}


int main() {
    struct Queue q;
    q.size = 5;
    q.f = q.r = -1;
    q.arr = (int*)malloc(q.size*sizeof(int));

    printf("Queue is Empty Or Not : %d\n",isEmpty(&q));
    Push(&q,1);
    Push(&q,2);
    Push(&q,3);
    Push(&q,4);
    Push(&q,5);
    printf("Queue is Empty Or Not : %d\n",isEmpty(&q));
    printf("Queue is Full Or Not : %d\n",isFull(&q));
    Display(&q);
    Pop(&q);
    Pop(&q);
    Pop(&q);
    Pop(&q);
    Pop(&q);
    printf("Queue is Empty Or Not : %d\n",isEmpty(&q));




    return 0;
}
