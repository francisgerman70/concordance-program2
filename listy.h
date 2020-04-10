#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#define LIST_MAXLEN_TEXT 100


typedef struct node_t {
    char text[LIST_MAXLEN_TEXT];
    struct node_t  *next;
} node_t;


char * getstring(node_t *head,node_t *head2);
char * getstring1(node_t *head);
node_t *areIdentical(node_t *head, char *text);
void removeDuplicates(node_t *list); 
node_t *new_node(char *);
node_t *add_front(node_t *, node_t *);
node_t *add_end(node_t *, node_t *);
node_t *peek_front(node_t *);
node_t *remove_front(node_t *);
void    apply(node_t *, void(*fn)(node_t *, void *), void *arg);
node_t * add_inorder(node_t *list, node_t *new);
#endif