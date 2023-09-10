#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// #include<ctype.h>

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

int prec(char ch){
    if(ch == '^')
     return 3;

    else if(ch == '/' || ch == '*')
     return 2;

    else if(ch == '+' || ch == '-')
     return 1;

    else
      return 0;
    
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

int Pop(struct Stack *st){
    if(isEmpty(st)){
        printf("Stack Underflow\n");
        return -1;
    }
    else{
        int temp =st->arr[st->top];
        st->arr[st->top] = 0;
        st->top--;
        return temp;
    }
}

int isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '^'){
        return 1;
    }
    return 0;
}

int getTop(struct Stack *st){
    return st->arr[st->top];
}

char *infixtoPostfix(char *infix){
    struct Stack *sp =( struct Stack *)malloc(sizeof(struct Stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr; /*= (char *)malloc((sp->size)*sizeof(char));*/
    // sp->arr;
    char* postfix = (char* )malloc((strlen(infix) + 1)*sizeof(char));
    int i=0;
    int j=0;
    while(infix[i] != '\0'){
        if(!isOperator(infix[i])){
            postfix[j++] = infix[i++];
        }
        else{
            if(prec(infix[i])>prec(getTop(sp))){
                Push(sp,infix[i++]);
            }else{
                postfix[j++] = Pop(sp);
            }
        }
    }
    while(!isEmpty(sp)){
        postfix[j++] = Pop(sp);
    }
    postfix[j] = '\0';
    return postfix;
}

int main() {
    char *infix = "a-b+c/d";
    printf("Postfix  Expression  of  Following  Infix Expression  is %s",infixtoPostfix(infix));
    return 0;
}