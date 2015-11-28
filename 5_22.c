#include <stdio.h>
#include <stdlib.h>

int user_a;
int user_b;

int divide(int _a, int _b);
int remain(int _a, int _b);
int get_length(int _a);
int main(){
	
	printf("Enter an integer\n");
	scanf("%d",&user_a);
	printf("Enter another integer\n");
	scanf("%d",&user_b);

	printf("The integer quotient of your integers is %d\n",divide(user_a,user_b));
	printf("The integer remainder of your integer is %d\n",remain(user_a,user_b));
	printf("Separating each number in the first entry:");
	int len = get_length(user_a);
	printf("len is %d",len);
	int separated[len];
	int d=user_a;
	for(int x=len-1; x>=0; x++){
		separated[x]=d%10;
		d/=10;
	}

	for(int y=0; y<len; y++){
		printf("  %1d",separated[y]);
	}
}

int divide(int _a, int _b){
	return _a/_b;
}

int remain(int _a, int _b){
	return _a%_b;
}

int get_length(int _a){
	if(_a==0){
		return 1;
	} else {
		int c = 0;
		while(_a!=0){
			_a/=10;
			c++;
		}
	}
}