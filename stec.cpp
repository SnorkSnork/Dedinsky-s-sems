class stack{
private:
        char capacity;
        int *data;
        char numb;
public:
        stack(int size){			//constructs new stack with this capacity
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

        stack(const stack &another){		//constructs new stack, the same as another one
                *this=another;
        }
        ~stack(){
                delete data;
        }

        void push(int a){			//inputs new integer ino a stack
                data[numb++]=a;
		if (numb==capacity){
			int* tmp;
			tmp= new int[capacity*2];
			for (int i=0; i<capacity; ++i)
				tmp[i]=data[i];
			data=tmp;
                }
	}
        int pop(){				//returns last integer put in the stack
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
        void swap (stack &another){		//swaps two stacks
                stack tmp(0);
                tmp=*this;
                *this=another;
                another=tmp;
        }
	bool empty (){				//checks if stack is empty
		if (numb) 
			return true;
		else return 0;
	}
	char size(){				//returns the current size of stack
		return numb;
	}
	void free (){				//makes the stack empty deleting all the elements
		while (numb>0)
			pop();
	}
};   
