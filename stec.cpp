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
};   
