#include<stdio.h>
#include<stdlib.h>
typedef long long int lint;
typedef struct node
{
	lint  info;
	struct node *next;
} node;
node *head, *temp, *np;

void  push(lint  n)
{
	np = (node*)malloc(sizeof(node));
	

	if (head == NULL)
	{
		head = np;
		head -> info = n;
	}
	else
	{
		//if (head ->info != n)
		np->next = head;
		head = np;
		head -> info =n;
	}
}

lint pop()
{
	lint n = head -> info;
	head = head -> next;
	
//	printf("popping %lld\n", n );
	return n;
}

void traverse()
{
	temp = head;
	if (temp == NULL)
		return;
	while(temp->next!=NULL)
	{
		printf("%lld    ", temp -> info );
		temp = temp -> next;
	}
		printf("\n");
}
lint a[1000005];
int main()
{
	
	lint n;
	lint max=0,tmp;
	scanf("%lld",&n);
	
	for(lint i=0;i<n;i++)
	{
		scanf("%lld", a+i);
	}
	push(0);
	
	push(a[0]);
	for(lint i=0;i<n;i++)
	{
		
//		printf("$%lld\n",a[i] );
		
		//traverse();
		
		if (head -> info > a[i] && a[i]!=head->info)
			push(a[i]);
		else
		{
			
			temp =head;
			while(a[i] > head->info && head -> info  != 0 )
			{
			
				//printf("hihi%lld %lld\ndumbass ", head -> info, a[i] );
				//traverse();
				pop();

				if (head -> info * a[i] > max)
				{	
//					printf("    ");traverse();
//					printf("yellow%lld %lld\n", head -> info, a[i] );
					max = head -> info * a[i];
				}

				
				
				if(head -> info != a[i])
				//push(a[i]);
				//printf("printing %lld",a[i] );
				temp=temp->next;
//				printf("hi%lld %lld\n", head -> info, a[i] );
			} 
			
			if (a[i]!=head->info)
				push(a[i]);
			
		}
	}
//	traverse();
	printf("%lld\n",max );
	//push(1);push(2);traverse();

}