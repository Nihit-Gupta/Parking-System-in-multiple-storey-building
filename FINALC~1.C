#include<stdio.h>
#include<string.h>
#include<conio.h>
struct slist
{
	char email[30];
	char password[30];

	struct slist *ptr;

};

struct node1
{
    char name[40];
    char vehicle[40];
    int vnos;
    int floor;
    int pnos;
    struct node1 *link1;
};
typedef struct slist node;
node *head=NULL,*new1,*start,*prev;
void add(struct node1 **);
void print(struct node1 *);
void search(struct node1 **);
void delet(struct node1 **);
void parkingArea();
int arr[3][3] = {0};
void addUser1();
void login();
void main()
{
	int c;
	clrscr();
	while(c!=3){
	printf("\t\t\t==== || PARKING SYSTEM || ====\n");
	printf("1. Create Admin Id\n2.LogIn\n3.Exit\n");
	printf("enter your choice\n");
	scanf("%d",&c);
	switch(c)
	{
	case 1:addUser1();
		break;
	case 2:login();
		clrscr();
	       break;


	}
	}

}
void addUser1()
{
if(head==NULL)
{
head=(node*)malloc(sizeof(node));
printf("Create your Email.Id\n");
scanf("%s",head->email);
printf("Create your password\n");
scanf("%s",head->password);
head->ptr=NULL;
}
else{
printf("login with same id and password you have created\n");
}
}
void login(){
	char e[30],p[30];
	int flag =0,ch2;
	start=head;
	printf("Enter the email \n");
	scanf("%s",e);
	printf("Enter password\n");
	scanf("%s",p);
while(start!=NULL)
{
	if(strcmp(start->email,e)==0){
		if(strcmp(start->password,p)==0){

			printf("***************************************\n");
			printf("login sucessfull\n");flag=1;
			printf("***************************************\n");
			break;
		}
	}
	start=start->ptr;
}       if(flag==0) {
	printf("*******************************************\n");
	printf("login failed\n");
	printf("*******************************************\n");

}
else
{
int c=2,check;
	struct node1 *pp;
	pp=NULL;
	clrscr();
	while(c!=6){
	printf("\t\t\t==== || PARKING SYSTEM || ====\n");
	printf(" 1.add details\n 2.search vehicle\n 3.display details\n 4.remove vehicle\n 5.parking slot details\n 6.Exit\n");
	printf("enter your choice\n");
	scanf("%d",&c);
	switch(c)
	{
	case 1:add(&pp);
		break;
	case 2:search(&pp);
		break;
	case 3:print(pp);
		break;
	case 4:delet(&pp);
		break;
	case 5:parkingArea();
		break;
	}
	}
}
}
void parkingArea()
{
	int i,j;
	printf("The parking slot are\n");
	for(i=0;i<3;i++)
	{
	printf("Floor %d : ",i+1);
	for(j=0;j<3;j++)
	{
		printf("%d\t",arr[i][j]);
	}
		printf("\n");
	}
}
void add(struct node1 **q)
{
	int n,choice,i,j;
	struct node1 *nn=(struct node1*)malloc(sizeof(struct node1));
	printf("The parking slot are\n");
	for(i=0;i<3;i++)
	{
	for(j=0;j<3;j++)
	{
		printf("%d\t",arr[i][j]);
	}
		printf("\n");
	}
	printf("Enter driver name\n");
	scanf("%s",nn->name);
	printf("Enter vehicle name  \n");
	scanf("%s",nn->vehicle);
	printf("Enter vehicle plate number\n");
	scanf("%d",&nn->vnos);
	up:
	printf("Enter your floor\n");
	scanf("%d",&nn->floor);
	printf("Enter parking number\n");
	scanf("%d",&nn->pnos);
	nn->link1=NULL;
	if(*q==NULL)
	{
		*q=nn;
	}
	else
	{
		struct node1 *temp=*q;
		while(temp->link1!=NULL)
		{
			temp = temp->link1;
		}
		temp->link1=nn;
	}
	if(arr[nn->floor-1][nn->pnos-1]==1){
		printf("already occupied\n");
		goto up;
	}
	else{
	  arr[nn->floor-1][nn->pnos-1]=1;
	  printf("sucessfully occupied\n");
	}
}


void search(struct node1 **q)
{
	char e[40];
	struct node1 *cur;
	printf("Enter driver name\n");
	scanf("%s",e);
	printf("NAME\t\tV-NAME\t\tV-NUMBER\tFLOOR\t  P-NUMBER\n");
	cur =*q;
	while(cur!=NULL)
	{
		if(strcmp(cur->name,e)==0)
		{       printf("************************************************************************\n");
			printf("%s\t\t%s\t\t%d\t\t%d\t\t%d\n",cur->name,cur->vehicle,cur->vnos,cur->floor,cur->pnos);
			printf("************************************************************************");
		return;
		}
		cur=cur->link1;
	}
			printf("NOT FOUND \n");

}
void print(struct node1 *q)
{
	struct node1 *start1=q;
	if(start1==NULL)
	{
		printf("Not any parking slot is booked\n");
		return;
	}
	printf("name\t\tvehicle\t\tvehiclenumber\t\tfloor\tparkingnumber\n");
	while(start1!=NULL)
	{

		printf("%s\t\t%s\t\t%d\t\t%d\t\t%d\n",start1->name,start1->vehicle,start1->vnos,start1->floor,start1->pnos);
		start1=start1->link1;
	}
}

void delet(struct node1 **q)
{
	char e[40];
	struct node1 *cur,*pre;
	printf("Enter driver name\n");
	scanf("%s",e);
	cur =*q;
	while(cur!=NULL)
	{
		if(strcmp(cur->name,e)==0 && cur==*q)
		{
			*q=cur->link1;
			arr[cur->floor-1][cur->pnos-1]=0;
			printf("parking is free now\n");
		}
		if(strcmp(cur->name,e)==0)
		{
			pre->link1=cur->link1;
			arr[cur->floor-1][cur->pnos-1]=0;
			printf("parking is free now\n");
			return;
		}
		pre = cur;
		cur=cur->link1;
	}

			printf("Not found\n");

}