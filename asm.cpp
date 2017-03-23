#include<stdio.h>

const int CMDLEN=10;


bool same (char one[], char another[]){
	int i=0;
	int j=0;
	for (; one[i]!='\0'; ++i);
	for (; another[j]!='\0'; ++j);
	if (i!=j) 
		return false;
	for (i=0; i<j; ++i)
		if (one[i]!=another[i])
			return false;
	return true;
}

int main(){
	FILE *input=NULL;
	char filename[100];
	while (input==NULL){
		printf ("Insert compiling FileName\n");
		scanf("%s", filename);
		input = fopen (filename, "rb");
		if (input==NULL)
			printf("Wrong FileName! This file don't exist!\n");
	}
	printf ("Insert compiled ProgName\n");
	char progname[100];
	scanf ("%s", progname);
	FILE *prog;
	prog = fopen (progname, "wb");
	printf ("COMPILATION\n");
	int cmdnum=0;
	int stop=0;

	char push[]{'p','u','s','h','\0'};
	char push_ax[]{'p','u','s','h','a','x','\0'};
	char push_bx[]{'p','u','s','h','b','x','\0'};
	char push_cx[]{'p','u','s','h','c','x','\0'};
	char push_dx[]{'p','u','s','h','d','x','\0'};
	char pop[]{'p','o','p','\0'};
	char pop_ax[]{'p','o','p','a','x','\0'};
	char pop_bx[]{'p','o','p','b','x','\0'};
	char pop_cx[]{'p','o','p','c','x','\0'};
	char pop_dx[]{'p','o','p','d','x','\0'};
	char in[]{'i','n','\0'};
	char out[]{'o','u','t','\0'};
	char sum[]{'s','u','m','\0'};
	char sub[]{'s','u','b','\0'};
	char mul[]{'m','u','l','\0'};
	char div[]{'d','i','v','\0'};
	char cos[]{'c','o','s','\0'};
	char sqrt[]{'s','q','r','t','\0'};
	char deg[]{'d','e','g','\0'};
	char halt[]{'h','a','l','t','\0'};
	
//TODO:jump

	while ((!feof(input))&&!(stop)) {
		++cmdnum;
		char* cmd=new char[CMDLEN];
		fscanf(input, "%s", cmd);
		if (same(cmd, push)){
			float numb;
			fscanf(input, "%f", &numb);
			fprintf (prog, "10 %f ", numb);
		}
		else if (same(cmd, push_ax))
			fprintf (prog, "1a ");
		else if (same(cmd, pop_ax))
			fprintf (prog, "2a ");
		else if (same(cmd, push_bx))
			fprintf (prog, "1b ");
		else if (same(cmd, pop_bx))
			fprintf (prog, "2b ");
		else if (same(cmd, push_cx))
			fprintf (prog, "1c ");
		else if (same(cmd, pop_cx))
			fprintf (prog, "2c ");
		else if (same(cmd, push_dx))
			fprintf (prog, "1d ");
		else if (same(cmd, pop_dx))
			fprintf (prog, "2d ");
		else if (same(cmd, pop))
			fprintf (prog, "20 ");
		else if (same(cmd, in))
			fprintf (prog, "12 ");
		else if (same(cmd, out))
			fprintf (prog, "22 ");
		else if (same(cmd, sum))
			fprintf (prog, "1 ");
		else if (same(cmd, sub))
			fprintf (prog, "2 ");
		else if (same(cmd, mul))
			fprintf (prog, "3 ");
		else if (same(cmd, div))
			fprintf (prog, "4 ");
		else if (same(cmd, cos))
			fprintf (prog, "5 ");
		else if (same(cmd, sqrt))
			fprintf (prog, "6 ");
		else if (same(cmd, deg))
			fprintf (prog, "7 ");
		else if (same(cmd, halt)){
			fprintf (prog, "0 ");
			stop=1;
		}
		else printf ("\tWARNING! \nUNKNOWN COMMAND in line %d\n", cmdnum);
		delete cmd;
	}
	fclose (prog);
	fclose (input);
	printf ("COMPILATION FINISHED\n");
}
