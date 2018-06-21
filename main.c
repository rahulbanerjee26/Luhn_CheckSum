#include <stdio.h>
#include <math.h>

int SUM(int digit){
	int sum=0;
	if(digit<10)
		return digit;
	else{
		sum+=digit%10;
		digit=digit/10;
		sum+=digit;
	}
	if(digit==10)
		return 1;
	return sum;
}
int main(int argc, char **argv)
{
	int identificationNumber; 
	printf("Enter the identification number: \n");
	scanf("%d",&identificationNumber);
	int temp1=identificationNumber;
	int length=0;
	while(temp1>0){
		length++;
		temp1/=10;
	}
	double temp=identificationNumber/(pow(10,length-1));
	printf("%lf  \n",temp);
	int SumOfDigits=0;
	int i = 1;
	while(temp<=identificationNumber){
		int digit = fmod(temp,10);
		if(i%2!=0)
			SumOfDigits+=digit;
		else{
			digit=digit*2;
			SumOfDigits+=SUM(digit);
		}
		printf("The digit is %d and the current sum is %d \n",digit,SumOfDigits);
		temp*=10;
		i++;
	}
	if(SumOfDigits%10==0)
		printf("VALID. SUM IS %d \n",SumOfDigits);
	else
		printf("INVALID. SUM IS %d \n",SumOfDigits);
	return 0;
}
