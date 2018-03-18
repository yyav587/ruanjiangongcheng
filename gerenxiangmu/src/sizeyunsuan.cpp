#include <stdio.h>
#include <stdlib.h>
#include<time.h>
//����ԭ��
int getChoice();
void showMenu();
void doExercise(int);
int test(int);
/*
	���ܣ��û�ѡ����
	���أ��û��Ĺ���ѡ��
	1���ӷ�		2������		3���˷�		4������		0���˳�
*/
int getChoice()
{
	int choice;
	scanf("%d",&choice);
	return choice;
}

/*
	���ܣ���ʾ���ܵĲ˵�
*/

void showMenu()
{
	printf("---------------------------------\n");
	printf("\n��ӭʹ������������ϰ���\n");
	printf("\t1���ӷ���ϰ\t2��������ϰ\n");
	printf("\t3���˷���ϰ\t4��������ϰ\n");
	printf("\t5���ۺ���ϰ\t0���˳�ϵͳ\n");
	printf("���������ѡ��0--5����\n");
	printf("\n-------------------------------\n");
}

/*
	���ܣ��Ʒ���
*/
void doExercise(int n)
{
	int score=0;		//��ϰ�÷֣���ʼ��Ϊ0
	int i=0;			//��ϰ�����ļ�����

	for(i=1;i<=10;i++)
	{
		score=score+test(n);//��ӵݹ����test(n)
	}
	printf("������ϰʮ���⣬��������%d��\n",score);
	printf("������ϰ�÷�Ϊ%d\n",score*10);
}

/*
	���ܣ�����һ����Ĳ��Թ���
*/
int test(int n)
{
	int ranswer=0;			//��ȷ��
	int uanswer=0;			//�û�����Ĵ�
	int t=0;				//��ʱ����
	char operation;			//�������
	int num1=0;				//������1
	int num2=0;				//������2

	srand(time(NULL));		//��ʼ�����������
	num1=rand()%100;			//ȡ0��100֮��������
	num2=rand()%100;

	//��������ܣ����ѡ��5���������1-4�������ÿһ�����㷽ʽ
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

//����һ����ֹ��������������䣬��ѡ�������num1С��num2ʱ������
//��������ʱ������ʱ������������������
	if((operation=='-') && (num1<num2))
	{
		t=num1;
		num1=num2;
		num2=t;
	}

//��ֹ������Ϊ0���ĳ���©��
//��num2�����ȡֵ��0ʱ���ͽ�num2ǿ����Ϊ1
//������ʱ����num1��ֵǿ�Ƹ�ֵ��num1*num2����ֹ��������
	if(operation=='/')
	{
		if(num2==0)
		{
			num2=1;
		}
		num1=num1*num2;			//��ֹnum1���ܱ�num2���������
	}

//��������Ȿ����ʾ�û�����
	printf("%d%c%d= ",num1,operation,num2);
	scanf("%d",&uanswer);

//���������ȷ���
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
//���У����Է���1��������0
	if(uanswer==ranswer)
	{
		printf("RIGHT��\n");
		return 1;
	}
	else 
	{
		printf("WRONG��\n");
		return 0;
	}
}


//������
int main(void)
{
	int choice=0;		//�����û���ѡ��
	
	
	
	//ѭ����ʼ���ܣ�������do����whileѭ��
	do
	{
		showMenu();				//��ʾ�˵�
		choice=getChoice();		

		//����choice�ķ�Χ
		if(choice<0 || choice>5)
		{
			choice=1;			//ǿ�����ӷ�
		}
		if(choice==0)
		{
			break;					//�û�ѡ��0���˳�ѭ�����˳�ϵͳ��
		}

		doExercise(choice);		//��ʲô��ϰ������������
	}while(choice!=0);

	printf("��ӭʹ�ã��ټ���\n");
	return 0;
}