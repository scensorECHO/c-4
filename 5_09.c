#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int num_customers = 3;
double INVALID_ERR = -3.14;
typedef struct{
	int custNum;
	double hours;
	double charge;
} ParkingEntry;
double totalHours=0.0;
double totalCharges=0.0;
ParkingEntry *entries;

double calculateCharges(double h);
void displayEntries();
int main(){

	entries = (ParkingEntry*)realloc(entries,(num_customers * sizeof(ParkingEntry)));

	for(int p=0; p<num_customers; p++){
		entries[p].custNum=p+1;
		printf("Please enter the number of hours you were parked (X.XX): ");
		scanf("%lf",&entries[p].hours);
		entries[p].charge=calculateCharges(ceil(entries[p].hours)); //
		if(entries[p].charge==INVALID_ERR){
			printf("The value you entered for customer %d was invalid. Please try again:\n",
				(p--)+1); // decrement and user friendly customer numbering
		} else {
			totalHours+=entries[p].hours;
			totalCharges+=entries[p].charge;
		}
	}
	displayEntries();
}

double calculateCharges(double h){
	if(h<=3.0&&h>0.0){
		return 2.0;
	}
	else if(h>3.0&&h<=11.0){
		return ((h-3.0)+2.0);
	}
	else if(h>11.0&&h<=24.0){ 
		return 10.0;
	}
	else{
		return INVALID_ERR; // error, not a valid number for function
	}
}

void displayEntries(){
	printf("%10s\t%10s\t%10s\n","Car","Hours","Charge");
	for(int p=0; p<num_customers; p++)
		printf("%10d\t%9.1lf\t%8.2lf\n",entries[p].custNum,entries[p].hours,entries[p].charge);
	printf("%10s\t%9.1lf\t%8.2lf\n","TOTAL",totalHours,totalCharges);
}
