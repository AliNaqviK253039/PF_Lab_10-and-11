#include <stdio.h>

int sum(int num){
	if(num==0) return 0;
	else
     return (num % 10) + sum(num / 10);
}
int main(){
	int num;
	printf("Enter num:");
	scanf("%d", &num);
	printf("Sum is %d", sum(num));
	return 0;
}
