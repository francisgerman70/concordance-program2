/*
 * linkedlist.c
 *
 * Based on the implementation approach described in "The Practice 
 * of Programming" by Kernighan and Pike (Addison-Wesley, 1999).
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "emalloc.h"
#include "listy.h"

//typedef char (*arr_ptr)[LIST_MAXLEN_TEXT];
char * getstring(node_t *head , node_t *head2){
    int call=0;
    node_t *curr;
    node_t *temp;
    node_t *curr2 = head;
        while(head != NULL){
            for (curr= head2; curr != NULL ; curr = curr->next){
                //while(head2 != NULL){
                if(strcmp(head->text, curr->text)==0){
                    call++;
                    temp = curr2->next; 
                    free(curr2);
                    curr2 = temp;
                }
                
            }
            
         
        return head->text;
        
        }
    
    /* Ungraceful error handling, but gets the point across. */
fprintf(stderr, "delitem: %s not in list", head->text);
exit(1);
    //return array3;
}

char * getstring1(node_t *head){
    //int call=0;
    //node_t *curr;
    //node_t *temp;
    //node_t *curr2 = head;
        while(head != NULL){
            //for (curr= head2; curr != NULL ; curr = curr->next){
                //while(head2 != NULL){
               // if(strcmp(head->text, curr->text)==0){
                   // call++;
                    //temp = curr2->next; 
                    //free(curr2);
                    //curr2 = temp;
               // }
                
            
            
         
        return head->text;
        
        }
    
    /* Ungraceful error handling, but gets the point across. */
fprintf(stderr, "delitem: %s not in list", head->text);
exit(1);
    //return array3;
}
void removeDuplicates(node_t *head){
    /* Pointer to traverse the linked list */
    //struct Node* current = head; 
    node_t *curr = head;
    node_t *next_next;
    
  
    /* Pointer to store the next pointer of a node to be deleted*/
    //struct Node* next_next;  
    
    /* do nothing if the list is empty */
    if (curr == NULL){
       return;  
    }
    /* Traverse the list till last node */
    while (curr->next != NULL)  
    { 
       /* Compare current node with next node */
       if (strcmp(curr->text,curr->next->text)== 0)  
       { 
            /* The sequence of steps is important*/               
           next_next = curr->next->next; 
           free(curr->next); 
           curr->next = next_next;   
       } 
       else /* This is tricky: only advance if no deletion */
       { 
          curr = curr->next;  
       } 
    
    } 
    
}

node_t *new_node(char *text) {
    assert( text != NULL);

    node_t *temp = (node_t *)emalloc(sizeof(node_t));

    strncpy(temp->text, text, LIST_MAXLEN_TEXT);
    temp->next = NULL;

    return temp;
}


node_t *add_front(node_t *list, node_t *new) {
    new->next = list;
    return new;
}


node_t *add_end(node_t *list, node_t *new) {
    node_t *curr;

    if (list == NULL) {
        new->next = NULL;
        return new;
    }

    for (curr = list; curr->next != NULL; curr = curr->next);
    curr->next = new;
    new->next = NULL;
    return list;
}


node_t *peek_front(node_t *list) {
    return list;
}


node_t *remove_front(node_t *list) {
    if (list == NULL) {
        return NULL;
    }

    return list->next;
}


void apply(node_t *list,
           void (*fn)(node_t *list, void *),
           void *arg)
{
    for ( ; list != NULL; list = list->next) {
        (*fn)(list, arg);
    }
}
node_t * add_inorder(node_t *list, node_t *new){
    node_t * curr = list;
    node_t * prev = NULL;

   for (curr = list ; curr != NULL; curr = curr->next){
	if(strncmp(new->text, curr->text, 20) > 0) {
	    prev = curr;
	} else{
	    break;
	}
}
	if (prev ==NULL){
	new->next = curr;
	return new;
	}else{
	    new->next = curr;
	    prev->next = new;
	    return list;
}
}  
node_t *areIdentical(node_t *head, char *text) 
{ 
    node_t *curr, *prev;
    prev = NULL;
for (curr = head; curr != NULL; curr = curr-> next) {
if (strcmp(text, curr->text) == 0) {
if (prev == NULL) {
head = curr->next;
} else {
prev->next = curr->next;
}
free(curr);
return head;
}
prev = curr;
}
/* Ungraceful error handling, but gets the point across. */
fprintf(stderr, "delitem: %s not in list", text);
exit(1);
}