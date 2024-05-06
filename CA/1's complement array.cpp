#include <stdio.h>
int main(){
	int n,k;
	printf("Enter the number of bits of binary number=");
	scanf("%d",&n);
	int i[n],j[n];
	printf("\nEnter the binary number=");
	for (k=0;k<n;k++){
		scanf("%d",&i[k]);
	}
	for (k =0;k<n;k++){
		if (i[k]==0){
			j[k]=1;
		}
		else{
			j[k]=0;
		}
	}
	printf("\n1s complement=");
	for(k=0;k<n;k++){
		printf("%d",j[k]);
	}
	return 0;
}


