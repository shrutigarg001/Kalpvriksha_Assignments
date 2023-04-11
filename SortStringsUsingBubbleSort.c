#include<stdio.h> 
#include<string.h> 

void main() {
    char number[10][10],temp[10]; 
    
    int n,i,j; 
    
    printf("Enter number of strings :"); 
    scanf("%d",&n); 
    
    for(i=0; i<=n; i++) {
        fgets(number[i], sizeof number, stdin);
    } 
    
    for(i=1; i<=n; i++) { 
	    for(j=0; j<=n-i; j++) {
	        if(strcmp(number[j], number[j+1]) > 0) { 
                strcpy(temp, number[j]);
	            strcpy(number[j], number[j+1]);
	            strcpy(number[j+1], temp);
	        } 
	    } 
    } 
    
    for(i=0; i<=n; i++) {
        printf("%s",number[i]);
    }
}
