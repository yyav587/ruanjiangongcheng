#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<vector>
#include<fstream>
using namespace std;
#define MAX 10
/*
���û��ݷ���������
*/

const int SIZE = 9;

vector<vector <int> > num(SIZE, vector<int>(SIZE));
class IsS{
public:
	bool IsSuitable(int row, int col);
};


class Gen {
public:
	bool generate(int row, int col);
};


IsS IsSu;
Gen Gene;
ofstream ocout;													//�����������һ������


bool IsS::IsSuitable(int row, int col) {
	int n = num[row][col];
	for (int i = 0; i < row; i++) {
		if (num[i][col] == n) return false;
	}   														//�ж�n�Ƿ��Ѿ����������� 
	for (i = 0; i < col; i++) {
		if (num[row][i] == n) return false;
	}  															//�ж�n�Ƿ��Ѿ����������� 
	int RowStart = row / 3;
	RowStart *= 3;
	int RowEnd = RowStart + 2;
	int ColStart = col / 3;
	ColStart *= 3;
	int ColEnd = ColStart + 2;
	i = RowStart;
	int j = ColStart;  											//RowStart,RowEnd,ColStart,ColEnd��־��λ�����ڵľŹ������ʼ	

	for (int k = 1; k <= 8; k++) {
		if (row != i || col != j) {
			if (num[i][j] == n) return false;
		}
		else  break;											//�б����������Ƿ���Ź����е����ִ��ڳ�ͻ 
		if (j == ColEnd) {
			j = ColStart;
			i++;
		}
		else {
			j++;
		}
	}  return true;
}  																//�б�������ڸ�λ���Ƿ���� 

bool Gen::generate(int row, int col) {
	int nextrow, nextcol;
	vector<int> number;
	for (int i = 1; i <= 9; i++)
			number.push_back(i);								//��1-9װ������ 
	while (!number.empty()) {
		int randindex = rand() % number.size();  				//�������1-9��� 1 �� ����num
		int randnum = number[randindex];
		number.erase(number.begin() + randindex);  				//ɾ������λ�õ����� 
		num[row][col] = randnum;  								//���������ڵ�row�У���col�� 
		if (!IsSu.IsSuitable(row, col))
			continue;  											//��� randnum��������number[row][col]���λ�ã������ѭ����һ�����ʵ��� 
		if (row == SIZE - 1 && col == SIZE - 1) {
			return true;
		}  														//��������½ǵĿ�Ҳ�����ˣ�����ture���ɹ�������������  
		if (col == SIZE - 1) {
			nextrow = ++row;
			nextcol = 0;
		}  														//���̽�������һ�У����� 
		else {
			nextrow = row;
			nextcol = ++col;
		}  														//nextrow��nextcolָ����һ���ո� 
		bool next = generate(nextrow, nextcol);					//�ݹ����������������  
		if (next)  return true; 								 //������tureʱ ����ɹ�����
	}	
		return false;											//���ɵ�ʱ��ס�˱������һ�� 

}

//��ӡ������ն�
void outputTocmd() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf(" %d", num[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
}
//��ӡ�������Ļ
void outputTotext() {


	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			ocout << num[i][j] << " ";
		}
		ocout << "\n";
	}
	ocout << "\n";
	
}
//��ӡ������ļ�

int main() {

	clock_t start, finish;

	double totaltime;

	start = clock();

	int N;
	ocout.open("data.txt");
	printf("��������Ҫ���ɵ������������:\n");
	int CharJduge = scanf("%d", &N);
	if (!CharJduge) {
		printf("����ֻ��Ϊ����,����������\n");
		system("pause");
		return 0;
	}
	//srand((unsigned)time(NULL));

	ocout << "����������ɵ�" << N << "�����������������:" << endl;
	srand( (unsigned)time( NULL ) );											//srand()��������һ���Ե�ǰʱ�俪ʼ���������.Ӧ�÷���for��ѭ�����ǰ�� ��ȻҪ�ܳ�ʱ��ȴ�
	
	for (int i = 0; i<N; i++) {
		//num[0][0] = rand()%MAX;
		Gene.generate(0, 0); 													//��0,0λ�ÿ�ʼ������������������� 
		outputTotext();
		outputTocmd();
	}
	ocout.close();

	finish = clock();

	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;

	cout << "\n�˳��������ʱ��Ϊ" << totaltime<<endl;

	system("pause");

	return 0;
}