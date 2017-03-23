#include <stdio.h>
#include <cmath>

//qtcreator

class stack/*TA-DUM-S-S*/{ 
private:
        char capacity;
        float *data;
        char numb;
public:
        stack(const int size): capacity(size), data (new float [capacity]), numb (0) {}
        stack &operator=(const stack &another){
                capacity=another.capacity;
                numb = another.numb;
                for (int i=0; i<numb; ++i)
                        data[i]=another.data[i];
                return *this;
        }

/*         stack(const stack &another){
                *this=another;
        }*/
        ~stack(){
                delete data;
        }

        void push(float a){
                data[numb++]=a;
		if (numb==capacity){
			float* tmp;
			tmp= new float[capacity*2];
			for (int i=0; i<capacity; ++i)
				tmp[i]=data[i];
			data=tmp;
                }
	}
        float pop(){
		if (!numb){
			printf("ERROR! STACK IS EMPTY!\n");
			return 0;
		}
		else{
			float a = data[--numb];
        	        data[numb]=0;
        	        return a;
        	}
	}
        void swap (stack &another){
                stack tmp(0);
                tmp=*this;
                *this=another;
                another=tmp;
        }
	bool empty (){
		if (numb) 
			return true;
		else return 0;
	}
	char size(){
		return numb;
	}
	void free (){
		while (numb>0)
			pop();
	}
};    



class CPU/*TU-DU-DU-DU-TU-DU*/{
private:
	stack DATA;
	int ax, bx, cx, dx;
	int sp, bp; // pointers (stack pionter & ..?)
//TODO: jump 
public:
	CPU(int a): DATA(a), ax(0), bx(0), cx(0), dx(0){};
	
	void push (float a){
		DATA.push(a);
	}
	float pop (){
		return DATA.pop();
	}
	void sum(){
		DATA.push(DATA.pop()+DATA.pop());
	}
	void sub(){
		DATA.push(DATA.pop()-DATA.pop());
	}
	void mul(){
		DATA.push(DATA.pop()*DATA.pop());
	}
	void div(){
		DATA.push(DATA.pop()/DATA.pop());
	}
	void mcos(){
		DATA.push(cos(DATA.pop()));
	}
	void msqrt(){
		DATA.push(sqrt(DATA.pop()));
	}
	void deg(){
		float a = DATA.pop();
		float p = DATA.pop();
		float res = 1;
		for (int i=0; i<p; ++i)
			res*=a;
		DATA.push(res);
	}
	void pushax(){
		DATA.push(ax);
	}
	void popax(){
		ax = DATA.pop();
	}
	void pushbx(){
		DATA.push(bx);
	}
	void popbx(){
		bx = DATA.pop();
	}
	void pushcx(){
		DATA.push(cx);
	}
	void popcx(){
		cx = DATA.pop();
	}
	void pushdx(){
		DATA.push(dx);
	}
	void popdx(){
		dx = DATA.pop();
	}
	void in(){
		float a;
		printf ("Insert float to push\n");
		scanf ("%f", &a);
		push (a);
	}
	void out(){
		printf("%f\n", pop());
	}
};


/*
push (int)	10
pop		20
pushax		1a
popax		2a
pushbx		1b
popbx		2b
pushcx		1c
popcx		2c
pushdx		1d
popdx		2d
in		12
out		22
sum		1
sub		2
mul		3
div		4
cos		5
sqrt		6
deg		7
halt		0
*/ 

int main(){
	CPU myproc(0);
	FILE *input=NULL;
	char progname[100];
	while (input==NULL){
		printf ("Insert compiled ProgName\n");
		scanf("%s", progname);
		input = fopen (progname, "rb");
		if (input==NULL)
			printf("Wrong FileName! This file don't exist!\n");
	}
	int stop = 0;
	int cmdnum = 0;
	printf("RUNNING\n");
	while ((!feof(input))&&(!stop)){
		++cmdnum;
		int code;
		fscanf(input, "%x", &code);
		switch (code){
			case 0x10:{
				float a;
				fscanf(input, "%f", &a);
				myproc.push(a);
				break;
			}
			case 0x20:{
				printf("%f ", myproc.pop());
				break;
			}
			case 0x1a:{
				myproc.pushax();
				break;
			}
			case 0x2a:{
				myproc.popax();
				break;
			}
			case 0x1b:{
				myproc.pushbx();
				break;
			}
			case 0x2b:{
				myproc.popbx();
				break;
			}
			case 0x1c:{
				myproc.pushcx();
				break;
			}
			case 0x2c:{
				myproc.popcx();
				break;
			}
			case 0x1d:{
				myproc.pushdx();
				break;
			}
			case 0x2d:{
				myproc.popdx();
				break;
			}
			case 0x12:{
				myproc.in();
				break;
			}
			case 0x22:{
				myproc.out();
				break;
			}
			case 0x1:{
				myproc.sum();
				break;
			}
			case 0x2:{
				myproc.sub();
				break;
			}
			case 0x3:{
				myproc.mul();
				break;
			}
			case 0x4:{
				myproc.div();
				break;
			}
			case 0x5:{
				myproc.mcos();
				break;
			}
			case 0x6:{
				myproc.msqrt();
				break;
			}
			case 0x7:{
				myproc.deg();
				break;
			}
			case 0x0:{
				stop=0;
				printf("PROGRAM IS FINISHED\n");
				break;
			}
			default: {
				printf("UNKNOWN COMMAND IN LINE %d", cmdnum);
			}
		}
	}
}
