/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define SIZE_HEAP 1000 //set amount of memory of contiguous allocation

//define structure for metadata-info about the data concerned

struct meta_tag{
 int size; //size of the block concerned
 int flag;// if block free, flag = 1 else 0
 struct meta_tag *prev;// pointer to metadata of prev block
 struct meta_tag *next;// pointer to metadata of next block
}block;


void* initialize_heap(){
    block *head = malloc(SIZE_HEAP); //pointer to main block of memory
    head->size = SIZE_HEAP - sizeof(block); //size of block
    head->next = NULL;
    head->prev = NULL;
    head->flag =1; 
    
}


void split_heap(block *nptr,int siz){
 struct block *new=(void*)((void*)nptr+siz+sizeof(block));
 new->prev = nptr;
 new->next = nptr->next;
 new->size=(nptr->size)-siz-sizeof(struct block);
 new->flag=1;
 nptr->next=new;
  nptr->size=siz;
 nptr->flag=0;
 
}


void *malloc_heap(int siz, void *heap){
 struct block *nptr = heap;
 void *res;
 
 
 while(((nptr->size)<siz)||(curr->flag)==0){
  nptr=nptr->next;
  printf("check for a block done\n");
 }
 if(nptr == NULL){
      printf("No sufficient memory to allocate\n");
 }
 else{
  nptr->flag=0;
  if((nptr->size)-siz > sizeof(struct block))
  {
      split_heap(nptr,siz);
  }
  result=(void*)(++nptr);
  printf("block allocated succesfully with a split of size %d\n",siz);
  
 }
 return nptr;
}
 

block *merge_heap(block *nptr, block *lptr){
 nptr -> next = lptr ->next;
 if(lptr->next){
     lptr->next ->prev=nptr;
     
 }
 nptr->size+=(lptr->size + sizeof(block));
 return nptr;
}


void free_heap(void *nptr, void *heap){
    if(nptr>=heap && nptr<= heap + SIZE_HEAP)
    {
        block *curr = ptr;
        --curr;
        curr-> flag+1;
        int size = curr-> size;
        if(curr -> prev && curr->next && curr-> next -> flag ==1 && curr->prev->flag ==1)
        {
            curr = merge_heap(curr->prev, curr);
        }
        else if (curr->prev->flag ==1)
        {
            merge_heap(curr->prev, curr);
        }
        else if (curr->next->flag ==1)
        {
            merge_heap(curr, curr->next);
        }
        printf("freed memory of size %d\n",size);
    }
    else 
    {
        printf("memory out of bounds");
    }
}



void display_heap(void *heap)
{
    block *nptr = heap;
    printf("\n BLOCK SIZE\tAVAILABILITY\tADDRESS\n");
    while(ptr)
    {
        printf("%d\t\t%d\t\t%p",ptr->size,ptr->flag,ptr);
        ptr=ptr->next;
    }
    
}
void main()
{
    void *initialize_heap();
 
 int *a=(int)malloc_heap(300,heap);
 
 int *b=(int)malloc_heap(200,heap));
 b = NULL;
 char *c=(char)malloc_heap(100,heap);
 free_heap(a);
 char *d=(char)malloc_heap(10);
 free_heap(c);
 display_heap(heap);
 free_heap(heap);
 
 }


























