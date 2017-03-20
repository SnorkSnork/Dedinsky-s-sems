#include<stdio.h>

int main(){
	FILE *input=NULL;
	char filename[100];
	while (input==NULL){
		printf ("Insert decompiling ProgName\n");
		scanf("%s", filename);
		input = fopen (filename, "rb");
		if (input==NULL)
			printf("Wrong FileName! This file don't exist!\n");
	}
	printf ("Insert wanted decompiled FileName\n");
	char progname[100];
	scanf ("%s", progname);
	FILE *prog;
	prog = fopen (progname, "wb");
	printf ("DECOMPILATION\n");
	int cmdnum=0;

	while (!feof(input)) {
		++cmdnum;
		int cmd;
		fscanf(input, "%x", &cmd);
		if (cmd==0x10){
			float numb;
			fscanf(input, "%f", &numb);
			fprintf (prog, "push %f\n", numb);
		}
		else if (cmd==0x1a)
			fprintf (prog, "pushax\n");
		else if (cmd==0x2a)
			fprintf (prog, "popax\n");
		else if (cmd==0x1b)
			fprintf (prog, "pushbx\n");
		else if (cmd==0x2b)
			fprintf (prog, "popbx\n");
		else if (cmd==0x1c)
			fprintf (prog, "pushcx\n");
		else if (cmd==0x2c)
			fprintf (prog, "popcx\n");
		else if (cmd==0x1d)
			fprintf (prog, "pushdx\n");
		else if (cmd==0x2d)
			fprintf (prog, "popdx\n");
		else if (cmd==0x20)
			fprintf (prog, "pop\n");
		else if (cmd==0x12)
			fprintf (prog, "in\n");
		else if (cmd==0x22)
			fprintf (prog, "out\n");
		else if (cmd==0x1)
			fprintf (prog, "sum\n");
		else if (cmd==0x2)
			fprintf (prog, "sub\n");
		else if (cmd==0x3)
			fprintf (prog, "mul\n");
		else if (cmd==0x4)
			fprintf (prog, "div\n");
		else if (0x5==cmd)
			fprintf (prog, "cos\n");
		else if (0x6==cmd)
			fprintf (prog, "sqrt\n");
		else if (0x7==cmd)
			fprintf (prog, "deg\n");
		else if (0x0==cmd){
			fprintf (prog, "halt\n");
		}
		else printf ("\tWARNING! \nUNKNOWN COMMAND in line %d\n", cmdnum);
	}
	fclose (prog);
	fclose (input);
	printf ("DECOMPILATION FINISHED\n");
}
