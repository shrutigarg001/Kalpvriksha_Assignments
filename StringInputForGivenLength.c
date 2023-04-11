#include<stdio.h> 
#include<string.h> 

int main() {
   char input[8];
	printf("Enter a string with a maximum of 8 characters: ");
	scanf("%8s", input);
	printf("You entered: %s\n", input);
   return 0;
} 