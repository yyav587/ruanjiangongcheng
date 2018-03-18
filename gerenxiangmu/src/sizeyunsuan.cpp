#include <stdio.h>
#include <stdlib.h>
#include<time.h>
//函数原型
int getChoice();
void showMenu();
void doExercise(int);
int test(int);
/*
	功能：用户选择功能
	返回：用户的功能选择
	1、加法		2、减法		3、乘法		4、除法		0、退出
*/
int getChoice()
{
	int choice;
	scanf("%d",&choice);
	return choice;
}

/*
	功能：显示功能的菜单
*/

void showMenu()
{
	printf("---------------------------------\n");
	printf("\n欢迎使用四则运算练习软件\n");
	printf("\t1、加法练习\t2、减法练习\n");
	printf("\t3、乘法练习\t4、除法练习\n");
	printf("\t5、综合练习\t0、退出系统\n");
	printf("请输入你的选择（0--5）：\n");
	printf("\n-------------------------------\n");
}

/*
	功能：计分器
*/
void doExercise(int n)
{
	int score=0;		//练习得分，初始化为0
	int i=0;			//练习题数的计数器

	for(i=1;i<=10;i++)
	{
		score=score+test(n);//间接递归调用test(n)
	}
	printf("本次练习十道题，你做对了%d道\n",score);
	printf("本次练习得分为%d\n",score*10);
}

/*
	功能：进行一道题的测试过程
*/
int test(int n)
{
	int ranswer=0;			//正确答案
	int uanswer=0;			//用户输入的答案
	int t=0;				//临时变量
	char operation;			//运算类别
	int num1=0;				//操作数1
	int num2=0;				//操作数2

	srand(time(NULL));		//初始化随机数种子
	num1=rand()%100;			//取0—100之间的随机数
	num2=rand()%100;

	//进入程序功能，如果选择5就随机产生1-4所代表的每一种运算方式
	if(n==5)
	{
		n=rand()%4+1;
	}

	switch(n)
	{
		case 1:
			operation='+';
			break;

		case 2:
			operation='-';
			break;

		case 3:
			operation='*';
			break;

		case 4:
			operation='/';
			break;
	}

//加入一条防止“不够减”的语句，当选择减法且num1小于num2时不够减
//不够减的时候，用临时变量交换两个操作数
	if((operation=='-') && (num1<num2))
	{
		t=num1;
		num1=num2;
		num2=t;
	}

//防止“除数为0”的程序漏洞
//当num2被随机取值到0时，就将num2强制置为1
//做除法时，将num1的值强制赋值给num1*num2，防止不能整除
	if(operation=='/')
	{
		if(num2==0)
		{
			num2=1;
		}
		num1=num1*num2;			//防止num1不能被num2整除的语句
	}

//输出测试题本身、提示用户输入
	printf("%d%c%d= ",num1,operation,num2);
	scanf("%d",&uanswer);

//程序计算正确结果
	switch(operation)
	{
		case '+':
		ranswer=num1+num2;
		break;

		case '-':
		ranswer=num1-num2;
		break;

		case '*':
		ranswer=num1*num2;
		break;

		case '/':
		ranswer=num1/num2;
		break;
	}
//评判，做对返回1，做错返回0
	if(uanswer==ranswer)
	{
		printf("RIGHT！\n");
		return 1;
	}
	else 
	{
		printf("WRONG！\n");
		return 0;
	}
}


//主函数
int main(void)
{
	int choice=0;		//接收用户的选择
	
	
	
	//循环开始功能，本次用do……while循环
	do
	{
		showMenu();				//显示菜单
		choice=getChoice();		

		//控制choice的范围
		if(choice<0 || choice>5)
		{
			choice=1;			//强制做加法
		}
		if(choice==0)
		{
			break;					//用户选择0，退出循环（退出系统）
		}

		doExercise(choice);		//做什么练习，并启动评分
	}while(choice!=0);

	printf("欢迎使用，再见！\n");
	return 0;
}