#include<stdio.h>
typedef struct hnode
{
    char word[25];
    int wpos;
    struct hnode*next;
}hnode;

typedef struct word_mean
{
    char word[25];
    int wpos;
}word_mean;

typedef struct snode
{
    char word[25];
    struct snode*prev;
}snode;

typedef struct stack
{
    struct snode*top;
}stack;

snode*createsnode(char* );
stack*push(stack*,char* );
void display_stack(stack*);
char*pop(stack*);


int sum_ascii(char*word);
hnode*createnode(char*,int);
void display(hnode*);
hnode*insertEnd(hnode*,char*,int);
void display_meaning(FILE*,int);
int find(hnode*,char*);
void display_array(hnode*,int*);
hnode*initialise_array(FILE*);
int search(hnode*,char*);
char init_case(char*);
void suggestion(hnode*,char*);
void update_history(char*);
stack*initialise_histack(stack*);
void update_histfile(stack*);
void view_histfile(void);
stack*insert_bottom(stack*s,char*word);
