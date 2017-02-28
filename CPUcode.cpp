#include <stdio.h>

class stack{
private:
        char capacity;
        int *data;
        char numb;
public:
        stack(int size){
                data = new int[size];
                numb=0;
        }
        stack &operator=(const stack &another){
                capacity=another.capacity;
                numb = another.numb;
                for (int i=0; i<numb; ++i)
                        data[i]=another.data[i];
                return *this;
        }

        stack(const stack &another){
                *this=another;
        }
        ~stack(){
                delete data;
        }

        void push(int a){
                data[numb++]=a;
		if (numb==capacity){
			int* tmp;
			tmp= new int[capacity*2];
			for (int i=0; i<capacity; ++i)
				tmp[i]=data[i];
			data=tmp;
                }
	}
        int pop(){
		if (!numb){
			printf("ERROR! STACK IS EMPTY!\n");
			return 0;
		}
		else{
			int a = data[--numb];
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

class CPU{
private:
	stack DATA;
	int ax, bx, cx, dx;
	



/*
push int	10
pop		20
push ax		11
pop ax		21
sum		1
sub		2
mul		3
div		4
cos		5
sqrt		6
deg		7
*/

public:
	void push (int a){
		DATA.push(a);
	}
	int pop (){
		return DATA.pop()
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
	void cos(){
		DATA.push(cos(DATA.pop()));
	}
	void sqrt(){
		DATA.push(sqrt(DATA.pop()));
	}
	void sum(){
		DATA.push(DATA.pop()+DATA.pop());
	}
	void deg(){
		int a = DATA.pop();
		int p = DATA.pop()
		for (int i=0; i<p; ++i)
			a*=a;
		DATA.push(a);
	}
	void push ax(){
		DATA.push(ax);
	}
	void pop ax(){
		ax = DATA.pop();
	}
		
}
