#include<stdio.h>
#define N 5
int arr[N];
int top = -1;


void push(int arr[],int d){
    if(top < N){
        top++;
        arr[top] = d;
    }else{
        printf("Stack Overflow\n");
    }
}

void pop(int arr[]){
    if(top == -1){
        printf("Stack Underflow\n");
    }else{
        arr[top] = 0;
        top--;
    }
}

void Display(int arr[]){
    printf("Display the Elements of the Stack : \n");
    for(int i = 0;i<N;i++){
        printf("%d ",arr[i]);
    }printf("\n");
}

int peep(int arr[],int index){
    int *p = &arr[top -index];
    return *p;
}

void change(int top,int arr[],int index,int d){
    arr[top-index] = d;
}

int main (){

    push(arr,1);
    push(arr,2);
    push(arr,3);
    push(arr,4);
    push(arr,5);

    Display(arr);

    printf("Address of the Element is : %d\n",peep(arr,1));
    change(top,arr,4,10);

    printf("After changing Element Display the Elements of the Stack :  \n");
    Display(arr);

    pop(arr);
    pop(arr);
    pop(arr);
    pop(arr);
    pop(arr);

    Display(arr);
    Display(arr);

    

    return 0;
}
