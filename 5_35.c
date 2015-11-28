#include <stdio.h>

unsigned long long int fibonacci(unsigned int t);
unsigned long long int maxim_fib();
int main(){
	unsigned int term;
	printf("What term of the Fibonacci sequence would you like to retrieve? ");
	scanf("%u",&term);
	printf("\nTerm %u of the Fibonacci sequence is %llu",term, fibonacci(term));
	maxim_fib();
}

unsigned long long int fibonacci(unsigned int t){
	unsigned long long int _1 = 0;
	unsigned long long int _2 = 1;
	unsigned long long int tmp;
	for(unsigned int i=0;i<t;i++){
		tmp=_2;
		_2+=_1;
		_1=tmp;
	}
	return _2;
}

unsigned long long int maxim_fib(){
	unsigned long long int _1 = 1;
	unsigned long long int _2 = 1;
	unsigned long long int tmp;
	unsigned int i = 0;
	while(_2>=_1){
		tmp=_2;
		_2+=_1;
		_1=tmp;
		i++;
	}
	printf("\n\nThe largest Fibonacci value that can be retrieved with this program is %llu, which is term %u\n",_1,i);
}