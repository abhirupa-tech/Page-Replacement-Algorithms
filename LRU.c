#include<stdio.h>
int main()
{
	int n,k,l, page[50], frame[10],i,j,no;
	int frame_copy[10];
	int count=0;
	printf("Enter the no. of pages:");
	scanf("%d",&n);
	printf("Enter the page number:\n");
	for(int i=0;i<n;i++)
		scanf("%d", &page[i]);
	printf("Enter the  no. of frames:");
	scanf("%d",&no);
	for(int j=0;j<no;j++)
		frame[j]=-1; //Denotes that the particular frame is empty
	printf("Ref String\t\tPage Frames\n");
	printf("__________\t\t___________\n\n");
	for(i=0;i<n;i++)
	{
		int item = page[i];
		int flag=0;
		for(j=0;j<no;j++)
		{
			if(frame[j]==item)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			for(k=0; k<no;k++)
				frame_copy[k]=frame[k];
			count=0;
			for(k=i-1;k>=0;k--)
			{
				for(l=0;l<no;l++)
				{
					if(frame_copy[l]==page[k])
					{
						frame_copy[l]=-1;
						count++;
					}
				}
					
				if (count==no-1)
					break;
			}

		}
		printf("%d\t\t",item);
		for(int j=0;j<no;j++)
		{
			if(frame[j]==-1)
				printf("X\t\t");
			else
				printf("%d\t\t",frame[j]);
		}
		printf("\n");

	}
	return 0;
}


