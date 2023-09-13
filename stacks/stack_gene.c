#include "stdlib.h"
#include "stdio.h"
#include "stdarg.h"
#include "stack_gene.h"
#define INISIZE 20  


struct stac {  //this is the struct of the generic stack, it has a memsize paramter to keep track of allocated memory available
   void** arrV;
   int top;
   int MemSize;
};

typedef struct stac sta;

typedef enum {
    INT, FLOAT, STRING, CHAR 
} Type;

typedef struct {   //the element struct and type enum are used to create generic types to be used on the stack...
             //this allows for an easier manipulation of stack data such as easier printing/popping
    void* data;
    Type type; 
} Element;


sta* create_stac(int argNum,...){    
    va_list args;
    va_start(args,argNum);

    if (argNum >20){
        printf(" stack init cant support more than 20 args");
        return NULL;
    }

    sta* stac1 = (sta*) malloc(sizeof(sta));
         if(stac1==NULL){exit(1);}

    stac1->arrV = (void**) malloc(sizeof(void*)*INISIZE);
        if(stac1->arrV == NULL) {exit(1);}

    stac1->top = -1;
    stac1->MemSize =20;

    for (int  i = 0; i < argNum; i++)
    {    void* ptr =va_arg(args, void*);
         stac1->arrV[i] = ptr;
         stac1->top+=1;
    }
    va_end(args);
    return stac1;
}

void increase_sta_size(sta** sec_ptr){
    void** new_arr;

    int size = (*sec_ptr)->top;

    new_arr = (void**) realloc((*sec_ptr)->arrV, sizeof(void*)*(size + INISIZE));
             if(new_arr==NULL){exit(1);}

    (*sec_ptr)->MemSize = size+INISIZE;
    (*sec_ptr)->arrV = new_arr;
}

/*void MemPop(sta** sec_ptr){
     int top = (*sec_ptr)->top;
     int memo_size = (*sec_ptr)->MemSize;

     int UnuSpace = memo_size - top;

     for(int i=top+1; i < UnuSpace; i++){
        free((*sec_ptr)->arrV[i]);
        (*sec_ptr)->MemSize --;
     }     
}*/

void push(sta* stac1, void*N){
         if (stac1->MemSize <= stac1->top){
             increase_sta_size(&stac1);
         }        
         stac1->arrV[stac1->top] = N;
         stac1->top++;
}

int empty_sta(sta*stac1){
  if(stac1->top== -1){
    return 1;
  }
  return 0;
}

void print_stack(sta* stac1){
 int size = stac1->top;

 if(!empty_sta(stac1)){
   
    for(int i = size; i >= 0; i--){
     Element* e = (Element*) stac1->arrV[i];

     switch(e->type) {
        case INT:
             printf("int: %d\n", *(int*)e->data);
            break;
        case FLOAT:
            printf("float: %f\n", *(float*)e->data);
            break;
        case STRING:
            printf("string: %s\n", (char*)e->data);
            break;
        case CHAR:
            printf("Char %c \n", *(char*)e->data);
            break;
       }
  }

 }
}

void* pop(sta* stac1){
      void* retu_pointer;
      if(!empty_sta(stac1)){
        retu_pointer = stac1->arrV[stac1->top];
        stac1->top--;
        return retu_pointer;
      }else{
        printf("empty stack \n");
        return NULL;
      }

}

void* check_top(sta*stac1){ 
    if(!empty_sta(stac1)){
        void* retu_pointer = stac1->arrV[stac1->top];
        return retu_pointer;
      }else{
        printf("empty stack \n");
        return NULL;
      }
}


int main(){

int X =5, Y=3;
int* pX=&X;
int* pY=&Y;
char c= 'c';
float F = 4.6;

Element  XE = {pX,INT};
Element YE ={pY,INT};

Element CE = {&c,CHAR};

Element FE = {&F, FLOAT};


sta* stack1 = create_stac(4, &XE, &YE, &CE, &FE);

print_stack(stack1);

/*float* F2 =  pop(stack1);

printf(" float %f \n", *F2);

char* NewC= pop(stack1);

printf(" char %c ", *NewC);*/





}