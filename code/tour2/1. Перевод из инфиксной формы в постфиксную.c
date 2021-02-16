#include <stdio.h>
#include <string.h.>

struct list {
    int data;
    struct list * next;
};

typedef struct stack {
    struct list *top;
} Stack;

Stack * create (){
    Stack * S;
    S = (Stack *) malloc (sizeof (Stack));
    S->top = NULL;
    return S;
}

void makenull (Stack *S){
    while (S->top) {
        struct list *p = S->top;
        S->top = p->next;
        free(p);
    }
}

int empty (Stack *S){
    return (S->top == NULL);
}

int top (Stack *S){
    return (S->top->data);
}

int pop(Stack *S){
    int a;
    struct list *p;
    p = S->top;
    a = p->data;
    S-> top = p->next;
    free(p);
    return a;
}

void push(Stack *S, int a ){
    struct list *p;
    p = (struct list *) malloc ( sizeof (struct list));
    p->data = a;
    p->next = S-> top;
    S->top = p ;
}

const int is_operand(char a){
    if (a == '*' || a == '/' || a == '-' || a == '+')
        return 1;
    else return 0;
}
int priority(char a){
    switch (a) {
        case '(': {
            return 1;
        }
        case ')':{
            return 2;
        }
        case '=':{
            return 3;
        }
        case '+':{
            return 4;
        }
        case '-':{
            return 4;
        }
        case '*':{
            return 5;
        }
        case '/':{
            return 5;
        }
    }
}


int main() {
    char str[1000] = {0};
    //string out;
    Stack *s = create();

    gets(str);
    int n = strlen(str);
    char x;
    for(int i = 0; i < n; i++){
        x = str[i];
        switch (x) {
            case '(':{
                push(s, x);
                break;
            }
            case ')':{
                while (top(s) != '(')
                    printf("%c", pop(s));
                pop(s);
                break;
            }
            case '+':{
                int p = priority(x);
                while (!empty(s) && p <= priority(top(s))) {
                    printf("%c", pop(s));
                }
                push(s, x);
                break;
            }
            case '-':{
                int p = priority(x);
                while (!empty(s) && p <= priority(top(s))) {
                    printf("%c", pop(s));
                }
                push(s, x);
                break;
            }
            case '*':{
                int p = priority(x);
                while (!empty(s) && p <= priority(top(s))) {
                    printf("%c", pop(s));
                }
                push(s, x);
                break;
            }
            case '/':{
                int p = priority(x);
                while (!empty(s) && p <= priority(top(s))) {
                    printf("%c", pop(s));
                }
                push(s, x);
                break;
            }

            default:{
                printf("%c", x);
                break;
            }



        }


    }
    
    while (!empty(s)) {
        printf("%c", pop(s));
    }
    return 0;
}
