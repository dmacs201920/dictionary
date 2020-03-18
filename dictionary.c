<<<<<<< HEAD
#include"headers.h"
void main()
{
    int word_pos,opt;
    char word[25],c,opt2;
    stack*s;
    s=(stack*)malloc(sizeof(stack));
    if(!s)
    {
	printf("malloc failed in main function,s\n");
	exit(0);
    }
    s->top=NULL;
    s=initialise_histack(s);

    char*filename=malloc(10*sizeof(char));
    if(!filename)
    {
	printf("malloc failed in main function,filename\n");
	exit(0);
    }
	printf("\f");
	view_interface();
	printf("\n\tOption>>>");
	scanf("%d",&opt);
	getchar();
	    switch(opt)
	    {
		case 1:
		    {

			printf("\n\t\tENTER>>>");
			gets(word);
			c=init_case(word);
			push(s,word);				   //update the search history stack
			hnode*letter;
			FILE*ft;

			filename[0]=c; filename[1]='\0';
			filename=strcat(filename,"file.txt\0");

			ft=fopen(filename,"r");
			if(ft==NULL)
			{
			    printf("Words starting with %c are not yet in the dictionary.....Sorry\n",c);
			    exit(1);
			}

			letter=(hnode*)malloc(letter_size*sizeof(hnode));
			if(!letter)
			{
			    printf("malloc falied in main function\n");
			    exit(0);
			}
			letter =initialise_array(filename,letter,ft);

			word_pos=search(letter,word);
			if(word_pos!=-1)
			    display_meaning(ft,word_pos);
			suggestion(letter,word);
			update_histfile(s);
			free(letter);
			fclose(ft);
			break;
		    }
		case 2:
		    {
			view_dictionary();
			break;
		    }
		case 3:
		    {
			view_histfile();  
			break;
		    }
		case 4:
		    {
			view_helpfile();
			break;
		    }
		case 5:
		    {
			exit(1);
			break;
		    }
	}
	free(filename);
	free(s);
=======
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"headers.h"
#include<string.h>
#define ready "AJNO"
#define No_of_ready 4
void main()
{
    FILE*fp;
    char word[25],c;
    int word_pos,i;
    stack*s;
    s=(stack*)malloc(sizeof(stack*));
    s->top=NULL;
    s=initialise_histack(s);
    char*filename=malloc(6*sizeof(char));
    if(!filename)
    {
	printf("malloc failed in main function\n");
	exit(0);
    }
    for(i=0;i<No_of_ready;i++)
    {
	filename[0]=ready[i]; filename[1]='\0';
	filename=strcat(filename,"file\0");

	fp=fopen(filename,"r");
	if(fp==NULL)
	{
	    printf("Words starting with %c are not yet in the dictionary.....Sorry\n",ready[i]);
	    exit(1);
	}
	hnode*letter[No_of_ready];
	letter[i]=initialise_array(fp);
    }

    printf("Enter the word you want to look up in the dictionary:\t");
    gets(word);
    c=init_case(word);
    push(s,word);				   //update the search history stack
    i=(int)c-64;

    {
	word_pos=search(letter,word);
	if(word_pos!=-1)
	    display_meaning(fp,word_pos);
	suggestion(letter,word);
    }
    else 
    	printf("Sorry, words starting with %c aren't yet in the dictionary\n");
        
    update_histfile(s);
    view_histfile();  // Mangala, put it in switch case....
    fclose(fp);
    free(s);
>>>>>>> 0608454ffbcce6946a226e19022a0f9ac145c2e3
}
