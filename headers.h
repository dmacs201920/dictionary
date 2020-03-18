#include<stdio.h>
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 56fbda92adf9dbb7571ac4e45ac643748e06b8bf
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define ready "JNO"
#define No_of_ready 3
#define letter_size 829
<<<<<<< HEAD
=======
=======
>>>>>>> 0608454ffbcce6946a226e19022a0f9ac145c2e3
>>>>>>> 56fbda92adf9dbb7571ac4e45ac643748e06b8bf
typedef struct hnode
{
    char word[25];
    int wpos;
    struct hnode*next;
}hnode;
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======

>>>>>>> 0608454ffbcce6946a226e19022a0f9ac145c2e3
>>>>>>> 56fbda92adf9dbb7571ac4e45ac643748e06b8bf
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
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 56fbda92adf9dbb7571ac4e45ac643748e06b8bf
hnode*insertEnd(hnode*,char*,int);
void display_meaning(FILE*,int);
int find(hnode*,char*);
void display_array(hnode*);
hnode*initialise_array(char*,hnode*,FILE*);
<<<<<<< HEAD
=======
=======
void display(hnode*);
hnode*insertEnd(hnode*,char*,int);
void display_meaning(FILE*,int);
int find(hnode*,char*);
void display_array(hnode*,int*);
hnode*initialise_array(FILE*);
>>>>>>> 0608454ffbcce6946a226e19022a0f9ac145c2e3
>>>>>>> 56fbda92adf9dbb7571ac4e45ac643748e06b8bf
int search(hnode*,char*);
char init_case(char*);
void suggestion(hnode*,char*);
void update_history(char*);
stack*initialise_histack(stack*);
void update_histfile(stack*);
void view_histfile(void);
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 56fbda92adf9dbb7571ac4e45ac643748e06b8bf
void view_dictionary(void);
void view_interface(void);
void view_helpfile(void);

stack*insert_bottom(stack*s,char*word);
void most_searched(void);
<<<<<<< HEAD
=======
=======
stack*insert_bottom(stack*s,char*word);
>>>>>>> 0608454ffbcce6946a226e19022a0f9ac145c2e3
>>>>>>> 56fbda92adf9dbb7571ac4e45ac643748e06b8bf
