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
}
