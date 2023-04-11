#include<stdio.h> 
#include<string.h> 

void main() {
    char input[50],search[10]; 
    int flag=0; 
    
    printf("Enter input string: "); 
    fgets(input, sizeof input, stdin); 
    
    printf("Enter search string: ");
    fgets(search, sizeof search, stdin); 
    
    int totalInputCount=0,totalSearchCount=0; 
    
    while(input[totalInputCount] != '\0') {
        totalInputCount++; 
    }
    totalInputCount--; 
    
    while(search[totalSearchCount] != '\0') {
        totalSearchCount++; 
    }
    totalSearchCount--; 
    
    for(int i=0; i<=totalInputCount-totalSearchCount; i++)
	{ 
		for(int j=i; j<i+totalSearchCount; j++)
		{
			flag = 1;
			if (input[j] != search[j-i])
			{
				flag = 0;
			   break;
			}
		}
		if (flag == 1)
			break;
	} 
	
	if (flag == 1) {
		printf("substring exists in the string"); 
	}
	else {
		printf("substring is not exists in the string"); 
	}
}
