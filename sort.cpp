#include <stdio.h>
#include <conio.h>
#include <string.h>

void swap(char *a, char *b)
{	char tmp=*a;
	*a=*b;
	*b=tmp;
	return;
}

void quick1(char *a,int loLimit, int hiLimit){
	int jBig=loLimit+1;
	int jSmall=hiLimit;
	char pivot = a[(jBig+jSmall)/2];
	int recurseLevel;

	printf("%s loLimit=%d hiLimit=%d pivot=%c recurseLevel=%d\n",
	a,loLimit,hiLimit,pivot,recurseLevel);
	if(hiLimit-loLimit<=0)return;
	if(hiLimit-loLimit==1){
		if (a[loLimit]>a[hiLimit])
		swap(&a[loLimit],&a[hiLimit]);
		return; }
	swap(&a[loLimit],&a[(jBig+jSmall)/2]);
	do{
		while((jBig<=jSmall)&&(a[jBig]<pivot))
		jBig++;
		while((jSmall>=jBig)&&(a[jSmall]>=pivot))
		jSmall--;
		if(jBig<jSmall)swap(&(a[jBig]),&(a[jSmall]));
	   } while (jBig<jSmall);
	swap(&a[loLimit],&a[jBig-1]);
	recurseLevel++;
	quick1(a, loLimit, jBig-2);
	quick1(a, jBig, hiLimit);
	recurseLevel--;
	return; }

void quickSort(char *a, int loLimit, int hiLimit){
	int lo = loLimit;
	int hi = hiLimit;
	char pivot =a[(loLimit+hiLimit)/2];
	int recurseLevel;
	
	printf("%s loLimit=%d hiLimit=%d pivot=%c recurseLevel=%d\n",
	a,loLimit,hiLimit,pivot,++recurseLevel);
	while (lo<=hi){
		while ((lo<hiLimit) && (a[lo]<pivot))lo++;
		while ((hi>loLimit) && (a[hi]>pivot))hi--;
		if (lo<=hi){
			swap(&a[lo],&a[hi]);
			lo++;
			hi--;
			}
		}
	if (loLimit<hi)quickSort(a,loLimit,hi);
	if (lo<hiLimit)quickSort(a,lo,hiLimit);
	recurseLevel--;
	return;
}

void selectionSort(char *a, int n){
	int min;
	int j,k;
	char curr;

	for(j=0;j<n;j++){
		min=j;
		for(k=j;k<n;k++)
		if(a[k]<a[min])min=k;
		curr=a[min];
		a[min]=a[j];
		a[j]=curr;
		printf("%2d: %s\n",j,a);
		}
}

void insertionSort(char *a, int n){
	char curr;
	int j,k;

	for(j=0;j<n;j++){
	curr=a[j];
	for(k=j;k>0;k--){
		if(a[k-1]<=curr)break;
		a[k]=a[k-1];
		}
	a[k]=curr;
	printf("%2d: %s\n",j,a);
	}
}

void main()
{	char test[80];
	char choice;
	int n;


	printf("String to sort>> ");
	gets(test);
	n=strlen(test);
	puts("Sort by...");
	puts("\t[S]electionSort");
	puts("\t[I]nsertionSort");
	puts("\t[A]quick1");
	puts("\t[Q]uickSort");
	printf("Choice>> ");
	choice=getchar();
	printf("%s (input string)\n",test);
	switch(choice){
		case 'S' :
		case 's' :
		selectionSort(test,n);
		puts(test);
		break;
		case 'I' :
		case 'i' :
		insertionSort(test,n);
		puts(test);
		break;
		case 'A' :
		case 'a' :
		quick1(test,0,n-1);
		puts(test);
		break;
		case 'Q' :
		case 'q' :
		quickSort(test,0,n-1);
		puts(test);
		break;
		}
}
