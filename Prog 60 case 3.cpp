#include <stdio.h>
#include <string.h>
#define ll long long
int main(){
   	int num;
   	scanf("%d", &num);
	int temp = num-1;
	for(int i = 0;i<num-1;i++){
		for(int j=0;j<temp;j++){
			printf("-");
		}
		for(int j=0;j<=i;j++){
			if(j==i){
				printf("*");
			}else{
				printf("* ");
			}
		}
		for(int j=i+1;j<num;j++){
			printf("-");
		}
		temp--;
		puts(" ");
	}
	temp = 0;
	for(int i=num;i>0;i--){
		for(int j=0;j<temp;j++){
			printf("-");
		}
		for(int j = 0;j<i;j++){
			if(j==i-1){
				printf("*");
			}else{
				printf("* ");
			}
		}
		for(int j=i;j<num;j++){
			printf("-");
		}
		temp++;
		puts(" ");
	}

    return 0;
}
