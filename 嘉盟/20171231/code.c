#include<stdio.h>
#include<string.h>

int average(int score[10]);
void max(int score[10],char name[10][10]);
void mend(int score[10],char name[10][10]);
void search(int score[10],int number[10],char name[10][10]);
#define N 2

int main()
{	
	int a; 
	int score[10],number[10];
	char name[10][10]; 
	printf("请输入姓名,学号,成绩\n");
	for(a=0;a<N;a++)
	{
		scanf("%s",&name[a]);      
		scanf("%d",&number[a]);
		scanf("%d",&score[a]);
	} 
	mend(score,name);
	printf("平均分:%d,总成绩:%d\n",average(score)/N,average(score));
	max(score,name);    
    search(score,number,name);
	return 0;
}



int average(int score[10])
{
	int i,b;              
	b=0;
	for(i=0;i<N;i++)
	{
		b=score[i]+b;
	}
	return(b);
}


void max(int score[10],char name[10][10])
{
	int j,m,a;
	m=0;
	for(j=0;j<N;j++)
	{
		if(m<score[j])
		{
			m=score[j];      
			a=j;    
		}
	}
	printf("最高分是：%d,他是第%d位同学,最高分的同学叫：%s\n",m,a+1,name[a]);
}



void mend(int score[10],char name[10][10])
	{
	    int a,i,c;
		printf("需要修改成绩吗(需要请按1，不需要请按2)\n");
	    scanf("%d",&a);
		for(;;)
		{ 
	        if(a==1)
			{
				printf("请输入你要修改第几个人的成绩\n");
		        scanf("%d",&i);
				printf("修改为：\n");
		        scanf("%d",&score[i-1]);
		        printf("需要继续修改成绩吗(需要请按1，不需要请按2)\n");
		        scanf("%d",&c);
		        if(c==1)
			         continue;
		        else
			         break;
			}
			else if(a==2)
		      break;           
		}  
	}



void search(int score[10],int number[10],char name[10][10])
{
	int s,d,e,a,b;
	char q,h,i;
	printf("查询所有同学成绩按N，查询单个成绩按Y\n");
	scanf("%c",&h);
	scanf("%c",&i);
	if(i=='Y')
	{
		printf("按姓名查询请输入1,按学号查询请输入2\n");
		scanf("%d",&a);
		if(a==1)
		{
			printf("请输入姓名\n");
			scanf("%s",&q);
			for(b=0;b<N;b++)
			{
				if(0==strcmp(name[b],&q))
					break;
			}
			printf("该学生成绩为:%d\n",score[b]);
		}
		else if(a==2)
		{
			printf("请输入学号\n");
			scanf("%d",&s);
			for(d=0;d<=N-1;d++)
			{
				if(s==number[d])
					break;
			}
			printf("该学生成绩为:%d\n",score[d]);
		}
	}

	else if(i=='N')
	{
		for(e=0;e<=N-1;e++)
		{
			if(e==0)
			printf("姓名为：%s\n学号为：%d\n成绩为：%d\n",name[e],number[e],score[e]);
			else
			printf("姓名为：%s\n学号为：%d\n成绩为：%d\n",name[e],number[e],score[e]);
		}
	}
}

		