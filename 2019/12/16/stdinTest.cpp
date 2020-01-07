#include <stdio.h>
#include <stdlib.h>

int a[100];
int n;

struct student
{
    int gradeA, gradeB, gradeC;
    double ave;
    char num[100], name[100];
} stu[100];

void ver1()
{
    freopen("out", "w", stdout);
	scanf("%d",&n);
	//FILE *fp;
	for ( int i = 0; i < n; i ++ )
	{
		scanf("%s", stu[i].num);
		scanf("%s", stu[i].name);
		scanf("%d %d %d", &stu[i].gradeA, &stu[i].gradeB, &stu[i].gradeC);
		stu[i].ave = ( stu[i].gradeA + stu[i].gradeB + stu[i].gradeC ) / 3;
	}
	//fp = fopen( "stud", "w" );
	//freopen("stud", "w", stdout);
	for ( int i = 0; i < n; i ++ )
	{
		//fread( &stu[i], sizeof(student), 1, fp );
		printf("%s ", stu[i].num);
		printf("%s ", stu[i].name);
		printf("%d %d %d %lf\n",stu[i].gradeA, stu[i].gradeB, stu[i].gradeC, stu[i].ave );
	}
	//fclose(fp);
	fclose(stdout);
}

int main()
{
    FILE *fp;
    char filename[10], ch;
    scanf("%s",filename);
    getchar();
    if ( ( fp = fopen(filename, "w") ) == NULL )
    {
        printf("error\n");
        exit(0);
    }
    scanf("%d",&n);
    //printf("%d",n);
    fread(&n, sizeof(int), 1, fp);
    printf("%d\n",n);
    for ( int i = 0; i < n; i ++ )
	{
		scanf("%s", stu[i].num);
		scanf("%s", stu[i].name);
		scanf("%d %d %d", &stu[i].gradeA, &stu[i].gradeB, &stu[i].gradeC);
		stu[i].ave = ( stu[i].gradeA + stu[i].gradeB + stu[i].gradeC ) / 3;
	}

    for ( int i = 0; i < n; i ++ )
    {
        fread(&stu[i], sizeof(struct student), 1, fp);
        printf("%s ", stu[i].num);
		printf("%s ", stu[i].name);
		printf("%d %d %d %lf\n",stu[i].gradeA, stu[i].gradeB, stu[i].gradeC, stu[i].ave );
    }

    fclose(fp);
    printf("\n"); 
    printf("hello");
    
    return 0;
}
