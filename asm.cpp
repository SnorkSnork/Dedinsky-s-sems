#include<stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>

const int CMDLEN=10;

class comand{
//private:
public:
	char* name;
public:
	comand(const char line[]){
		char* name = new char[CMDLEN];
		for (int i=0; i<CMDLEN; ++i)
			name[i]=line[i];
	}
	~comand(){
		delete name;
	}
	bool operator==(const comand &another){
                bool res=true;
		for (int i=0; i<CMDLEN; ++i)
			if (name[i]!=another.name[i])
				res=false;
		if (res)
			return true;
		else return false;
        }
};

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

	comand push("push      ");
	comand push_ax("pushax    ");
	comand push_bx("pushbx    ");
	comand push_cx("pushcx    ");
	comand push_dx("pushdx");
	comand pop("pop");
	comand pop_ax("popax");
	comand pop_bx("popbx");
	comand pop_cx("popcx");
	comand pop_dx("popdx");
	comand in("in");
	comand out("out");
	comand sum("sum");
	comand sub("sub");
	comand mul("mul");
	comand div("div");
	comand cos("cos");
	comand sqrt("sqrt");
	comand deg("deg");
	comand halt("halt");
	

	while ((!feof(input))&&!(stop)) {
		++cmdnum;
		char* cmd=new char[CMDLEN];
		fscanf(input, "%s ", cmd);
		comand going(cmd);
printf ("%s\n", cmd);
printf ("%s\n", going.name);
		delete cmd;
		if (push==going){
			int* numb=new int;
			fscanf(input, "%d ", numb);
			fprintf (prog, "10 %d ", *numb);
			delete numb;
		}
		else if (going==push_ax)
			fprintf (prog, "1a ");
		else if (pop_ax==going)
			fprintf (prog, "2a ");
		else if (push_bx==going)
			fprintf (prog, "1b ");
		else if (pop_bx==going)
			fprintf (prog, "2b ");
		else if (push_cx==going)
			fprintf (prog, "1c ");
		else if (pop_cx==going)
			fprintf (prog, "2c ");
		else if (push_dx==going)
			fprintf (prog, "1d ");
		else if (pop_dx==going)
			fprintf (prog, "2d ");
		else if (pop==going)
			fprintf (prog, "20 ");
		else if (going==in)
			fprintf (prog, "12 ");
		else if (going==out)
			fprintf (prog, "22 ");
		else if (going==sum)
			fprintf (prog, "1 ");
		else if (going==sub)
			fprintf (prog, "2 ");
		else if (going==mul)
			fprintf (prog, "3 ");
		else if (going==div)
			fprintf (prog, "4 ");
		else if (going==cos)
			fprintf (prog, "5 ");
		else if (going==sqrt)
			fprintf (prog, "6 ");
		else if (going==deg)
			fprintf (prog, "7 ");
		else if (going==halt){
			fprintf (prog, "0 ");
			stop=1;
		}
		else printf ("\tWARNING! \nUNKNOWN COMMAND in line %d\n", cmdnum);
	}
	fclose (prog);
	fclose (input);
	printf ("COMPILATION FINISHED\n");
}
