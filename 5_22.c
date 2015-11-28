#include <stdio.h>
#include <stdlib.h>

int user_a;
int user_b;

int divide(int _a, int _b);
int remain(int _a, int _b);
int main(){
	printf("Enter an integer\n");
	scanf("%d",&user_a);
	printf("Enter another integer\n");
	scanf("%d",&user_b);
	char* user_a_str;
	sprintf(user_a_str,"%d",user_a);
	printf("The integer quotient of your integers is %d\n",divide(user_a,user_b));
	printf("The integer remainder of your integer is %d\n",remain(user_a,user_b));
	printf("Separating each number in the first entry:");
	for(int x=0; x<sizeof(user_a_str); x++){
		printf("  %c",user_a_str[x]);
	}

}
int divide(int _a, int _b){
	return _a/_b;
}
int remain(int _a, int _b){
	return _a%_b;
}