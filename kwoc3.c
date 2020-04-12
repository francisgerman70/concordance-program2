/*
 * kwoc3.c
 *
 * 
 * 
 */
#define MAX_NAME_LEN  10000
#define  _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "emalloc.h"
#include "listy.h"
#include <ctype.h>


node_t *head = NULL;
node_t *temp_node = NULL;
node_t *head2 = NULL;
node_t *temp_node2 = NULL;
node_t *temp = NULL;


void num_words(char *array3,char *buffer, int *occur){
    char *t;
    //char temp[MAX_NAME_LEN];
    char *temp =  (char *) malloc(MAX_NAME_LEN); // Allocate row pointers
        
    
    t = strtok(buffer, " \n");
    while(t != NULL){
        strncpy(temp, t, MAX_NAME_LEN);
        if(strncmp(array3, t, MAX_NAME_LEN) == 0){
            *occur = *occur + 1;
        }
        t = strtok(NULL, " \n");
    }
}
void print_output(char **array3, char **line4, int count,int big, int move){
    
    //char buffer[MAX_NAME_LEN];
    char *buffer = (char *) malloc(MAX_NAME_LEN); // Allocate row pointers
        
    int occur = 0;
     big =((big + 2) * -1) ;
    //char upper[MAX_NAME_LEN];
   char *upper = (char *) malloc(MAX_NAME_LEN);

    //convert to uppercase 
    for(int i=0; i<count; i++){	
    	
    	int size = strlen(array3[i]);
    	for(int m=0; m<size; m++){
    		upper[m] = toupper(array3[i][m]);
    	}
    	upper[size] = (char) 0;
        
        

        for(int j=0; j<move; j++){
    		strncpy(buffer, line4[j], MAX_NAME_LEN);
            
    		int line_length = strlen(line4[j]);
    		if(strcmp(&line4[j][line_length-1], "\n") == 0){
    			line4[j][line_length-1] = (char)0;
    		}
            

        num_words(array3[i], buffer, &occur);
    		
    		if(occur == 1){
    			printf("%*s%s (%d)\n",big,upper, line4[j], j+1);
    		} else if (occur > 1){
    			printf("%*s%s (%d*)\n",big,upper , line4[j], j+1);
    		}
    		
    		occur = 0;
    	}
    }
}    
    
    
int compare(const void *s, const void *t)
{
	return strcmp(*(char **)s, *(char **)t);
}

void print_word(node_t *node, void *arg)
{
    char *format = (char *)arg;
    printf(format, node->text);
}


#ifdef DEBUG

/*
 * Just showing the use of the linked-list routines.
 */

void _demo() {
printf("DEBUG: in _demo\n");
    char *words_german[] = {"Der", "Kater", "mit", "Hut."};
    int   words_german_len = 4;

    char *words_english[] = {"The", "cat", "in", "the", "hat."};
    int   words_english_len = 5;

    node_t *temp_node = NULL;
    node_t *head = NULL;

    int i;

    /* Add the words in German, at the front. */
    for (i = 0; i < words_german_len; i++) {
        temp_node = new_node(words_german[i]);
        head = add_front(head, temp_node);
    }

    /* Add the words in English, at the end. */
    for (i = 0; i < words_english_len; i++) {
        temp_node = new_node(words_english[i]);
        head = add_end(head, temp_node);
    }

    /* Print the list of words. */

    apply(head, print_word, "--> %s\n");

    /* Free up the memory. This is done rather deliberately
     * and manually.  Asserts are liberally used here as they
     * express state that *must* be true if all of the code is
     * correctly working.
     */

    temp_node = head;
    while (temp_node != NULL) {
        assert(temp_node != NULL);
        head = remove_front(head);
        free(temp_node);
        temp_node = head;
    }
   
    assert(head == NULL); 
}

#endif



int main(int argc, char *argv[])
{
    char *exception_file = NULL;
    char *input_file = NULL;
    int i;
    FILE *file;
    FILE *exception;
    char *line = NULL;
    char *line2 = NULL;
    size_t len = 0; 
    size_t len2 = 0;
    char *t;
	char rem[] = " \n";
    int num_words,num,move = 0;
    
    char **array1 = malloc(MAX_NAME_LEN * sizeof(char *)); // Allocate row pointers
        for(i = 0; i < MAX_NAME_LEN; i++){
            array1[i] = malloc(MAX_NAME_LEN * sizeof(char));
        }
    char **array2 = malloc(MAX_NAME_LEN * sizeof(char *)); // Allocate row pointers
        for(i = 0; i < MAX_NAME_LEN; i++){
            array2[i] = malloc(MAX_NAME_LEN * sizeof(char));
        }
    char **array3 = malloc(MAX_NAME_LEN * sizeof(char *)); // Allocate row pointers
        for(i = 0; i < MAX_NAME_LEN; i++){
            array3[i] = malloc(MAX_NAME_LEN * sizeof(char));
        }
    char **line4 = malloc(MAX_NAME_LEN * sizeof(char *)); // Allocate row pointers
        for(i = 0; i < MAX_NAME_LEN; i++){
            line4[i] = malloc(MAX_NAME_LEN * sizeof(char));
        }
   
    
    //read file
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-e") == 0 && i+i <= argc) {
            exception_file = argv[i+1];
            input_file = argv[i+2];
            file = fopen(input_file, "r");
            exception = fopen(exception_file, "r");
        
            
            while (getline(&line, &len, file) != -1) {
                char *temp_line = (char *)malloc((strlen(line) + 1) * sizeof(char));
                strncpy(temp_line, line, strlen(line));
                strncpy(line4[move],temp_line,strlen(line));
                move++;
		        t = strtok(temp_line, rem);
		        while (t != NULL){
			//storing the tokens
			    strncpy(array2[num_words], t, strlen(line));
			    num_words = num_words+1;
			    t = strtok(NULL, rem);
		}
            }
            while (getline(&line2, &len2, exception) != -1) {
                char *temp_line2 = (char *)malloc(MAX_NAME_LEN * sizeof(char));
                strncpy(temp_line2, line2, strlen(line2));
		        t = strtok(temp_line2, " \n");
		        while (t != NULL){
                strncpy(array1[num], t, strlen(line2));
                num++;
                t = strtok(NULL, " \n");
            }
            }
                
               
            
        //create node
        for (i = 0; i < num; i++) {
        temp_node2 = new_node(array1[i]);
        head2 = add_end(head2, temp_node2);
    }
        //create node and sort in alphabetical order
        for (i = 0; i <num_words ; i++) {
        temp_node = new_node(array2[i]);
        
        head = add_inorder(head, temp_node);
    }
        //remove duplicates
        removeDuplicates(head);
        //getstring back from linkedlist without exception words
            int count = 0;
        for (temp = head ; temp!=NULL;temp = temp->next){
            array3[count] = getstring(head,head2);
            count++;
            head = remove_front(head);
        }
        int big = strlen(array3[0]);
        for(int n=0; n<count; n++){
		int curr_big = strlen(array3[n]);
		if(big < curr_big){
			big = curr_big;
		}
	}
        
        print_output(array3, line4, count, big, move);
        
         }else {
            input_file = argv[i];
            if (input_file == NULL) {
                    exit(0);
            }
            file = fopen(input_file, "r");
            //exception = fopen(exception_file, "r");
            
            while (getline(&line, &len, file) != -1) {
                char *temp_line = (char *)malloc((strlen(line) + 1) * sizeof(char));
                strncpy(temp_line, line, strlen(line));
                strncpy(line4[move],temp_line,strlen(line));
                move++;
		        t = strtok(temp_line, rem);
		        while (t != NULL){
			//storing the tokens
			    strncpy(array2[num_words], t, strlen(line));
			    num_words = num_words+1;
			    t = strtok(NULL, rem);
		}
            }
        
        for (i = 0; i <num_words ; i++) {
        temp_node = new_node(array2[i]);
        
        head = add_inorder(head, temp_node);
    }
        removeDuplicates(head);
        
            int count = 0;
        for (temp = head ; temp!=NULL;temp = temp->next){
            array3[count] = getstring1(head);
            count++;
            head = remove_front(head);
        }
        int big = strlen(array3[0]);
        for(int n=0; n<count; n++){
		int curr_big = strlen(array3[n]);
		if(big < curr_big){
			big = curr_big;
		}
	}
         
        print_output(array3, line4, count, big, move);
            
         }
    }
    
           
       
/* 
 * Showing some simple usage of the linked-list routines.
 */

#ifdef DEBUG
    //_demo();
#endif

    exit(0);
}
