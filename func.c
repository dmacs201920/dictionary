#include"headers.h"


char init_case(char*quest)
{
    int i;
    if( islower(quest[0]))
	quest[0]=quest[0]-32;
    for(i=1;i<=strlen(quest);i++)
    {
	if(isalpha(quest[i])&& isupper(quest[i]))
	    quest[i]=quest[i]+32;
	if(quest[i]=='\n')
	    quest[i]='\0';
    }
    return quest[0];
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////              HASH-TABLE FUNCTIONS		///////////////////////////////////////////////////////////

int sum_ascii(char*word)
{
    int sum=0,i;
    for(i=0;word[i]!='\0';i++)
	sum+=word[i];
    return sum;
}

hnode*createnode(char*word,int x)
{
    hnode*tmp;
    tmp=malloc(sizeof(hnode));
    if(tmp==NULL)
    {
	printf("malloc failed!!\n");
	exit(0);
    }
    tmp->next=NULL;
    tmp->wpos=x;
    strcpy(tmp->word,word);
    return tmp;
}
//insert data at the end of the hash-table list//
hnode*insertEnd(hnode*head,char*word,int x)
{
    hnode*tmp,*t;
    tmp=createnode(word,x);
    if(head==NULL)
    {
	return tmp;
    }
    for(t=head; t->next!=NULL;t=t->next)
    {}

    t->next=tmp;
    return head;
}
//display the whole list.//
void display(hnode*head)
{
    hnode*t=head;
    if(head==NULL)
    {
	printf("list is empty!!\n");
    }
    else
    {
	int i=0;
	while(t!=NULL && i++ <letter_size )
	{
	    printf("%s\n",t->word);
	    t=t->next;
	}
	printf("-=-=-=-=THE END-=-=-=-=-\n");
    }
}

	//search for the word in the linked list, and return its position in the file//
int find(hnode*head,char*word)
{
    hnode*t;
    if(head==NULL)
    {
	return -1;
    }
    for(t=head;t!=NULL;t=t->next)
	if(strcmp(t->word,word)==0)
	{
	    return t->wpos;
	}

    return -1;
}
void display_meaning(FILE*fp,int wpos)
{
    fseek(fp,wpos-1,SEEK_SET);
    char c;

    while((c=fgetc(fp))!='\n' && c!=EOF)
    	printf("%c",c);

    printf("\n");
}

hnode*initialise_array(char*filename,hnode*letter,FILE*fp)
{
/*    fp=fopen(filename,"r");
    if(!fp)
    {
	printf("couldn't open the file %s\n",filename);
	return NULL;
    }*/
    char c,word[25];
    int i,wpos,j=0;

    for(j=0;j<=letter_size;j++)
    {
	strcpy(letter[j].word,"0");
	letter[j].next=NULL;
    }

    while((c=fgetc(fp))!=EOF)
    {
	if(c=='\n')
	{
	    i=0;
	    c=fgetc(fp);
	    wpos=ftell(fp);
	    while(c!='$' && c!=EOF)
	    {   word[i++]=c;
		c=fgetc(fp);
	    }
	    word[i]='\0';
	    j=sum_ascii(word)%letter_size;
	    if(strcmp(letter[j].word,"0")==0)
	    {
		strcpy(letter[j].word,word);
		letter[j].wpos=wpos;
	    }
	    else
	    {
		letter[j].next =insertEnd(letter[j].next,word,wpos);
	    }
	}
    }
//    fclose(fp);
    return letter;
}
int search(hnode*letter,char*string)
{
    int rem=(sum_ascii(string)%letter_size);
    if(strcmp(letter[rem].word,string)==0)
    {
	return letter[rem].wpos;
    }
    else
    {
	return find(letter[rem].next,string);
    }
}


void display_array(hnode*letter)
{
    for(int j=0;j< letter_size ;j++)
    {
	
	if(strcmp(letter[j].word,"0")!=0)
	{
	    printf("%s\n",letter[j].word);
	}
	if(letter[j].next!=NULL)
	{
	    display(letter[j].next);
	    
	}
    }
}

void suggestion(hnode*letter,char*word)
{
    hnode*t ;
    int i,count=0,j;
    if(letter==NULL)
	printf("list is empty, so can't find anything:(\n");
    
    printf("\n\t\t\t\t\t\t*********Suggested words are***********"); 
    printf("\n\t\t\t\t\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\t");

    for(i=0;i<letter_size;i++)
    {
	if((strcmp(letter[i].word,"0")!=0) && (strstr(letter[i].word,word)!=0))
	{
	    if(count==5)
	    {
		printf("\n\t");
		count=0;
	    }
	    printf("%s",letter[i].word);
	    for(j=strlen(letter[i].word);j<27; j++)
		printf(" ");

	    count++;
	}
	    
	for(t=letter[i].next ;t!=NULL; t=t->next)
	{
	    if(strstr(t->word,word)!=0)
	    {
		if(count==5)
		{
		    printf("\n\t");
		    count=0;
		}
		printf("%s",t->word);
		for(j=strlen(t->word);j<27; j++)
		    printf(" ");
		count++;
	    }
	}
    }
    printf("\n");
}/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////			STACK FUNCTIONS			///////////////////////////////////////////////////////////
  
//create a node with an entry and next as NULL //
snode*createsnode(char*word)
{
    snode*tmp;
    tmp=malloc(sizeof(snode));
    if(tmp==NULL)
    {
	printf("malloc failed!!\n");
	exit(0);
    }
    tmp->prev=NULL;
    strcpy(tmp->word,word);
    return tmp;
}
//push data on the top of the stack.//
stack*push(stack*s,char*word)
{
    snode*tmp=createsnode(word);
    if(s->top==NULL)
    {
	s->top=tmp;
	return s;
    }
    tmp->prev=s->top;
    s->top=tmp; 	//tmp is the new s->top.
    return s;
}
//display the whole list.//
void display_stack(stack*s)
{
    if(s->top==NULL)
    printf("Stack is empty!!\n");
    
    else
    {
        snode*t;
	for(t=s->top;t!=NULL;t=t->prev)
	printf("%s",t->word);
	
	printf("-=-=-=-=-=BOTTOM OF THE STACK-=-=-=-=-\n");
    }
}
char*pop(stack*s)
{
    if(s->top==NULL)
    {
	return NULL;
    }
    else 
    {
	snode*tmp=s->top;
	char*topword;
	topword=s->top->word;
	s->top = s->top->prev;
	return topword;
	free(tmp);
    }

}
//insert data at the bottom of the stack.//
stack*insert_bottom(stack*s,char*word)
{
    snode*tmp=createsnode(word);
    if(s->top==NULL)
    {
	s->top=tmp;
	return s;
    }
    snode*t;
    for(t=s->top ;t->prev!=NULL; t=t->prev)
    {}	
    t->prev=tmp;
    return s;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                    SEARCH HISTORY FUNCTIONS			///////////////////////////////////////////

//Insert at the ***BOTTOM***  of the stack,just like a list//
stack*initialise_histack(stack*s)
{
    FILE*fp;
    char word[25],c;
    fp=fopen("search_history","r");
    if(!fp)
    {
        fp=fopen("search_history","a");
	fputc('\n',fp);
	fseek(fp,0,SEEK_SET);
    }
    int i=0;
    while((fscanf(fp,"%s",word))!=EOF)
    {
	s=insert_bottom(s,word);
    }    
    fclose(fp);    
    return s;
}

//Update the history file with the words that are present in the stack//
void update_histfile(stack*s)
{
    FILE*fp;
    char*word;
    remove("search_history");
    fp=fopen("search_history","w");
    if(!fp)
    {
	printf("couldn't open the file in function update_history\n");
	return;
    }
    fputc('\n',fp);
    word=pop(s);
    while(word!=NULL)
    {
	fprintf(fp,"%s\n",word);
        word=pop(s);
    }
    fclose(fp);
}
void view_histfile(void)
{
    FILE*fp;
    fp=fopen("search_history","r");
    if(!fp)
    {
	printf("couldn't open search_history file in view_histfile function\n");
	return;
    }
    char word[25];
    while((fscanf(fp,"%s",word))!=EOF)
    {
	puts(word);
    }
    fclose(fp);
}
void view_helpfile(void)
{
    FILE*fp;char c;
    fp=fopen("help","r");
    if(!fp)
    {
	printf("couldn't open help file\n");
	return;
    }
    c=fgetc(fp);
    while(c!=EOF)
    {
	printf("%c",c);
	c=fgetc(fp);
    }
    fclose(fp);
}
void view_interface(void)
{
    FILE*fp;char c;
    fp=fopen("interface","r");
    if(!fp)
    {
	printf("couldn't open interface file\n");
	return;
    }
    c=fgetc(fp);
    while(c!=EOF)
    {
	printf("%c",c);
	c=fgetc(fp);
    }
    fclose(fp);
}
void view_dictionary(void)
{
    FILE*fp1,*fp2,*fp3;char c;
    fp1=fopen("Jfile.txt","r");
    if(!fp1)
    {
	printf("couldn't open Jfile \n");
	return;
    }
    c=fgetc(fp1);
    while(c!=EOF)
    {
	printf("%c",c);
	c=fgetc(fp1);
    }
    fclose(fp1);

    fp2=fopen("Nfile.txt","r");
    if(!fp2)
    {
	printf("couldn't open Nfile\n");
	return;
    }
    c=fgetc(fp2);
    while(c!=EOF)
    {
	printf("%c",c);
	c=fgetc(fp2);
    }
    fclose(fp2);

    fp3=fopen("Ofile.txt","r");
    if(!fp3)
    {
	printf("couldn't open Ofile\n");
	return;
    }
    c=fgetc(fp3);
    while(c!=EOF)
    {
	printf("%c",c);
	c=fgetc(fp3);
    }
    fclose(fp3);
}

