#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

int isFull(struct Stack *st){
    if(st->top == st->size - 1){
        return 1;
    }
    return 0;
}

int isEmpty(struct Stack *st){
    if(st->top == -1){
        return 1;
    }
    return 0;
}

void Peep(struct Stack *st,int index){
    printf("%d\n",&st->arr[st->top - index + 1]);
}

void Change(struct Stack *st,int index,int val){
    st->arr[st->top - index + 1]= val;
}

void Push(struct Stack *st,int val){
    if(isFull(st)){
        printf("Stack Overflow\n");
    }
    else{
        st->top++;
        st->arr[st->top] = val;
    }
}

void Pop(struct Stack *st){
    if(isEmpty(st)){
        printf("Stack Underflow\n");
    }
    else{
        st->arr[st->top] = 0;
        st->top--;
    }
}

void Display(struct Stack *st){
    printf("Printing Elements Of The Stack : \n");
    for(int i=0;i<st->size - 1;i++){
        printf("%d\n",st->arr[i]);
    }printf("\n");
}


int main () {
    // struct Stack *st = (struct Stack *) malloc(sizeof(struct Stack));
    struct Stack st;
    st.size=5;
    st.top=-1;
    st.arr=(int* )malloc(st.size*sizeof(int));

    printf("Stack is Empty Or Not : %d\n",isEmpty(&st));
    Push(&st,1);
    Push(&st,2);
    Push(&st,3);
    Push(&st,4);
    Push(&st,5);
    printf("Stack is Empty Or Not : %d\n",isEmpty(&st));
    printf("Stack is Full Or Not : %d\n",isFull(&st));

    Display(&st);

    Peep(&st, 2);
    Display(&st);

    printf("\n");

    Change(&st, 4, 7);
    Display(&st);

    Pop(&st);
    Pop(&st);
    Pop(&st);

    Display(&st);

    Pop(&st);
    Pop(&st);

    printf("Stack is Empty Or Not : %d\n",isEmpty(&st));
    printf("Stack is Full Or Not : %d\n",isFull(&st));

    
    
    return 0;
}