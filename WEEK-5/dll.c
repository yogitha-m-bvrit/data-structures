#include<stdio.h>	
#include<stdlib.h>
struct node
{
	float data;
	struct node*prev;
	struct node*next;
};
struct node *head=NULL,*tail=NULL,*cur,*t1,*t2;
void create()
{
	int n;
	printf("Enter the number of nodes\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		cur=(struct node*)malloc(sizeof(struct node));
		printf("enter current node data\n");
		scanf("%f",&(cur->data));
		cur->prev=NULL;
		cur->next=NULL;
		if(head==NULL)
			head=tail=cur;
		else
		{
		tail->next=cur;
		cur->prev=tail;
		tail=cur;
		}
	}
}

void insert_at_begin()
{
	cur=(struct node*)malloc(sizeof(struct node));
	printf("Enter current node data\n");
	scanf("%f",&(cur->data));
	cur->prev=NULL;
	cur->next=head;
	head->prev=cur;
	head=cur;
}

void insert_at_end()
{
	cur=(struct node*)malloc(sizeof(struct node));
	printf("Enter current node data\n");
	scanf("%f",&(cur->data));
	cur->next=NULL;
	cur->prev=tail;
	tail->next=cur;
	tail=cur;
}

void insert_at_pos()
{
	int c=1,pos;
	cur=(struct node*)malloc(sizeof(struct node));
	printf("Enter current node data\n");
	scanf("%f",&(cur->data));
	printf("Enter position");
	scanf("%d",&pos);
	t1=head;
	while(c<pos && t1!=NULL)
	{
		t2=t1;
		t1=t1->next;
		c++;
	}
	t2->next=cur;
	cur->prev=t2;
	cur->next=t1;
	t1->prev=cur;
}

void insert_before()
{
	int value;
	cur=(struct node*)malloc(sizeof(struct node));
	printf("Enter current node data\n");
	scanf("%f",&(cur->data));
	printf("Enter the data before which node we need to insert:");
	scanf("%d",&value);
	t1=head;
	while(t1!=NULL && t1->data!=value)
	{
		t2=t1;
		t1=t1->next;
	}
	t2->next=cur;
	cur->prev=t2;
	cur->next=t1;
	t1->prev=cur;
}

void insert_after()
{
	int value;
	cur=(struct node*)malloc(sizeof(struct node));
	printf("Enter current node data\n");
	scanf("%f",&(cur->data));
	printf("Enter the data after which node we need to insert:");
	scanf("%d",&value);
	t1=head;
	while(t1!=NULL && t1->data!=value)
	{
		t1=t1->next;
	}
	t2=t1->next;
	cur->next=t2;
	t2->prev=cur;
	t1->next=cur;
	cur->prev=t1;
}
	
void del_begin()
{
	cur=head;
	head=head->next;
	head->prev=NULL;
	cur->next=NULL;
	printf("Deleted element %f",cur->data);
	free(cur);
}

void del_end()
{
	cur=tail;
	tail=tail->prev;
	tail->next=NULL;
	cur->prev=NULL;
	printf("Deleted element %f",cur->data);
	free(cur);
}

void del_at_pos()
{
	int c=1,pos;
	printf("Enter the pos of deletion:");
	scanf("%d",&pos);
	t1=head;
	while(c<pos  &&  t1!=NULL)
	{
		t2=t1;
		t1=t1->next;
		c++;
	}
	t2->next=t1->next;
	t1->next->prev=t2;
	printf("Deleted data is %f",t1->data);
	free(t1);
}

void del_before()
{
	float value;
	printf("Enter the data to delete before\n");
	scanf("%f",&value);
	t1=head;
	while(t1->next->data!=value  &&  t1->next!=NULL)
	{
		t2=t1;
		t1=t1->next;
	}
	t2->next=t1->next;
	t1->next->prev=t2;
	printf("Deleted element %f",t1->data);
	free(t1);	
}

void del_after()
{
	float value;
	t1=head;
	printf("Enter the data of a node to perform deletion:");
	scanf("%f",&value);
	while(t1!=NULL && t1->data!=value)
	{
		t1=t1->next;
	}
	t2=t1->next;
	t1->next=t2->next;
	t2->next->prev=t1;
	printf("Deleted element %f",t2->data);
	free(t2);
}

void display_forward()
{
	if(head==NULL)
	printf("DLL is empty");
	else
	{
		cur=head;
		printf("Elements of DLL are\n");
		while(cur!=NULL)
		{
			printf("%f<->",cur->data);
			cur=cur->next;
		}
		printf("NULL");
	}
}	
	
void display_reverse()
{
	if(head==NULL)
	printf("DLL is empty");
	else
	{
		cur=tail;
		while(cur!=NULL)
		{
			printf("%f<->",cur->data);
			cur=cur->prev;
		}
	}
}

void searching()
{
	int flag=0;
	float value;
	printf("enter value to be searched:");
	scanf("%f",&value);
	int c=1;
	t1 = head;
	while(t1!=NULL)
	{
		if(t1->data==value)
		{
			flag =1;
			break;
		}
		t1=t1->next;
		c++;
	}
	if(flag==1)
	{
		printf("Element present in the list at %d position",c);
	}
	else
		printf("Element not present in the list");
}	
	
void sorting()
{
	struct node*p1,*p2,*last=NULL;
	int i,c,t;
	do
	{
	c=0;
	p1=head;
	while(p1->next!=last)
	{
		if(p1->data>p1->next->data)
		{
			t=p1->data;
			p1->data=p1->next->data;
			p1->next->data=t;
		}
	p1=p1->next;
	}
	last=p1;
	}while(c);

}

int main()
{
	int ch;
	while(1)
	{
		printf("--------------------------------------------------\n");
		printf("program for double linked list\n");
		printf("1-create\n2-insert at begin\n3-insert at end\n4-insert at position\n5-insert before");
		printf("\n6-insert after\n7-del at begin\n8-del at end\n9-del at pos\n10-del before\n");
		printf("\n11-del after\n12-display in forward\n13-display in reverse\n14-search\n15-sort\n16-exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:create();
				break;
			case 2:insert_at_begin();
				break;
			case 3:insert_at_end();
				break;
			case 4:insert_at_pos();
				break;
			case 5:insert_before();
				break;
			case 6:insert_after();
				break;
			case 7:del_begin();
				break;
			case 8:del_end();
				break;
			case 9:del_at_pos();
				break;
			case 10:del_before();
				break;
			case 11:del_after();
				break;
			case 12:display_forward();
				break;
			case 13:display_reverse();
				break;
			case 14:searching();
				break;
			case 15:sorting();
				break;
			case 16:exit(0);
		}
	}
	return 0;
}
