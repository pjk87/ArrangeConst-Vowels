#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    
    char data;
    struct node *next;
    
}Node;

Node *Top;
Node *Bottom;

void enque(Node *s,int d){
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->data=d;
    temp->next=NULL;
    
    if(Top==NULL){
        
        Top=temp;
        Bottom=temp;
        
    }else{
        
        Bottom->next=temp;
        Bottom=temp;
        
    }
    
}


void arrange(Node *s){
    
    Node *prev,*curr,*Vtop,*Vbot;
    curr=Top;
    prev=NULL;
    Vtop=NULL;
    Vbot=NULL;
    
    while(curr!=NULL){
        
        if(curr->data=='a' || curr->data=='e'|| curr->data=='i'|| curr->data=='o'|| curr->data=='u'){
            
          if(curr==Top){
              
              Top=Top->next;
              curr->next==NULL;
              if(Vtop==NULL){
                  Vtop=curr;
                  Vbot=curr;
                  
              }else{
                  
                  Vbot->next=curr;
                  Vbot=curr;
                  
              }
              
              curr=Top;
              
          }else{
              
              prev->next=curr->next;
              curr->next=NULL;
              if(Vtop==NULL){
                  Vtop=curr;
                  Vbot=curr;
                  
              }else{
                  
                  Vbot->next=curr;
                  Vbot=curr;
                  
              }
              
              curr=prev->next;
              
          }
            
        }else{
            
            prev=curr;
            curr=curr->next;
            
        }
        
        
    }
    
    Vbot->next=Top;
    Top=Vtop;
    
    
    
    
}


int main()
{
    Node *st;
    
    enque(st,'a');
    enque(st,'b');
    enque(st,'c');
    enque(st,'e');
    enque(st,'d');
    enque(st,'o');
    enque(st,'x');
    enque(st,'i');
    arrange(st);
    Node *temp;
    temp=Top;
    
    while(temp!=NULL){
        
        printf("%c\n",temp->data);
        temp=temp->next;
    }
    return 0;
}