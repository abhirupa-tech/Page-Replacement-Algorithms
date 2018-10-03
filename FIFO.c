#include<stdio.h>

int main()
{
	int n, page[50], frame[10],i,j,no;
	printf("Enter the no. of pages:");
	scanf("%d",&n);
	printf("Enter the page number:");
	for(int i=0;i<n;i++)
		scanf("%d", &page[i]);
	printf("Enter the  no. of frames:");
	scanf("%d",&no);
	for(int j=0;j<no;j++)
		frame[i]=-1; //Denotes that the particular frame is empty
	printf("Ref String\t\tPage Frames\n");
	printf("__________\t\t___________\n\n");
	for(i=0;i<n;i++)
	{
		int item = page[i];
		int flag=0;
		for(j=0;j<no;j++)
		{
			if(frame[i]==item)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			frame[(i%no)]=item;
		}
		printf("%d\t\t",item);
		for(int j=0;j<no;j++)
			printf("%d\t",frame[j]);
		printf("\n");
	}
	return 0;
}
	

		
