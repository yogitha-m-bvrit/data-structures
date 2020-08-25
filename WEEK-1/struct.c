#include<stdio.h>
struct student 
{
	char name[40];
        char roll[10];
	float marks;
}s;
int main( )
{
	printf("enter name: ");
	fgets(s.name, sizeof(s.name), stdin);
	
	printf("enter roll number: ");
	fgets(s.roll, sizeof(s.roll),stdin);

	printf("enter marks: ");
	scanf("%f", &s.marks);

	printf("name: ");
	printf("%s", s.name);
	printf("roll number: %d\n", s.roll);
	printf("marks: %.1f\n", s.marks);
	return 0;
}
