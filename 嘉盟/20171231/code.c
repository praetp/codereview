#include<stdio.h>
#include<string.h>

#define N 2
#define MAX_LENGTH 32
static float average(int sum);
static int sum(int score[N]);
static void max(int score[N],char name[N][MAX_LENGTH]);
static void mend(int score[N],char name[N][MAX_LENGTH]);
static void search(int score[N],int number[N],char name[N][MAX_LENGTH]);

int main()
{	
	int a; 
	int score[N],number[N];
	char name[N][MAX_LENGTH]; 
	int totalsum;
	printf("请输入姓名,学号,成绩\n");
	for(a=0;a<N;a++)
	{
		scanf("%s",name[a]);      
		scanf("%d",&number[a]);
		scanf("%d",&score[a]);
	} 
	mend(score,name);
	totalsum = sum(score);
	printf("平均分:%.1f,总成绩:%d\n",average(totalsum),totalsum);
	max(score,name);    
    search(score,number,name);
	return 0;
}


static int sum(int score[N]) {

	int i,b;              
	b=0;
	for(i=0;i<N;i++)
	{
		b=score[i]+b;
	}
	return b;
}


static float average(int sum)
{
	return sum * 1.0 / N; 
}


static void max(int score[N],char name[N][MAX_LENGTH])
{
	int j,m,a;
	m=-1;
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



static void mend(int score[N],char name[N][MAX_LENGTH])
	{
	    int a,i;
	    printf("需要修改成绩吗(需要请按1，不需要请按2)\n");
	    scanf("%d",&a);
	    while (a == 1) {
		    printf("请输入你要修改第几个人的成绩\n");
		    scanf("%d",&i); /* 如果输入　100 或者 -1 , 会卡住 ! */
		    if (i > 0 && i <= N) {
			    printf("修改为：\n");
			    scanf("%d",&score[i-1]);
			    printf("需要继续修改成绩吗(需要请按1，不需要请按2)\n");
			    scanf("%d",&a);
		    } else {
			printf("错误 !");
		    }
	    }
	}



static void search(int score[N],int number[N],char name[N][MAX_LENGTH])
{
	int s,d,e,a,b; /* <-- 不清楚 */
	char h,i;
	char xingming[MAX_LENGTH];
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
			scanf("%s",xingming);
			for(b=0;b<N;b++)
			{
				if(0==strcmp(name[b],xingming))
					break;
			}
			if (b == N) {
				printf("没找到\n");
			} else {
				printf("该学生成绩为:%d\n",score[b]);
			}
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
			if (d == N){
				printf("没找到\n");
			} else {
				printf("该学生成绩为:%d\n",score[d]);
			}
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

		
