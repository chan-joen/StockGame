#pragma warning (disable:4996)
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;

#define One 49
#define Two 50
#define Three 51
#define Four 52

char Co[11][16] = { "������������","S1 Movie","" };
int M[10] = { 0,0,0,0,0,0,0,0,0 };
int Money = 0;
int Asset[10] = { 0,0,0,0,0,0,0,0,0 };

void Buy();
void Sell();
void Check();
void MyAsset();
void Start();

int main()
{
	char W;
	Start();
	for (;;)
	{
		cout << "������ ���� ������ �ּ���[1.����|2.�Ǹ�|3.�ü�(���ݺ���)|4.�����ֽ�]: ";
		cin >> W;
		if (W == One)
		{
			Buy();
		}
		else if (W == Two)
		{
			Sell();
		}
		else if (W == Three)
		{
			cout << "���� �ֽ� �ü�" << endl;
			Check();
		}
		else if (W == Four)
		{
			MyAsset();
		}
	}
}

void Check()
{
	srand((int)time(NULL));
	int B = 0;
	for (int i = 0; i <= 9; i++)
	{
		int J = rand() % 2 + 1;
		if (J % 2 == 0 && M[i] <= 1000)
		{
			B = (rand() % 100 + 1);
			M[i] += ((B / 100) * M[i]);
			cout << Co[i] << "<" << M[i] << ">" << "(" << "+ %" << B << ")" << endl;
		}
		else if (M[i] >= 1000 || M[i] <= 100000)
		{
			B = (rand() % 90 + 1);
			M[i] -= ((B / 100) * M[i]);
			cout << Co[i] << "<" << M[i] << ">" << "(" << "- %" << (rand() % 90 + 1) << ")" << endl;
		}
	}
}

void MyAsset()
{
	int i;
	cout << "�����ݾ�: " << Money << endl;
	for (i = 0; i <= 9; i++)
	{
		cout << Co[i] << "  " << Asset[i] << "��" << endl;
	}
}

void Buy()
{
	char* B = {};
	int J;
	cout << "�� �ֽ��� �̸��� �Է��ϼ���: ";
	cin >> B;
	fflush(stdin);
	for (int i = 0; i <= 9; i++)
	{
		if (strcmp(B, Co[i]) == 0)
		{
			cout << "�� �ָ� ���� �Ͻðڽ��ϱ�?: ";
			cin >> J;
			if (Money <= 0 || Money - J * M[i] <= 0)
			{
				cout << "���� ���ڶ� �� �� �����ϴ�." << endl;
				break;
			}
			Asset[i] = Asset[i] + J;
			Money -= J * M[i];
		}
	}
}

void Sell()
{
	char* B = {};
	int J;
	cout << "�� �ֽ��� �̸��� �Է��ϼ���: ";
	cin >> B;
	for (int i = 0; i <= 9; i++)
	{
		if (strcmp(B, Co[i]) == 0)
		{
			cout << "�� �ָ� �Ǹ� �Ͻðڽ��ϱ�?: ";
			cin >> J;
			if (J > Asset[i])
			{
				cout << "���� ������ �ʰ��� �ִ� �� �� �����ϴ�." << endl;
				break;
			}
			Asset[i] = Asset[i] - J;
			Money += J * M[i];
		}
	}
}

void Start()
{
	srand((int)time(NULL));
	for (int i = 0; i <= 9; i++)
	{
		int NUM = (rand() % 100000);
		M[i] = M[i] + NUM;
	}
}