#pragma warning (disable:4996)
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<fstream>
using namespace std;

#define One 49
#define Two 50
#define Three 51
#define Four 52
#define Five 53

char Co[11][16] = { "�������� ����","S1 Movie","MAXIM �Ź�","�� �Ǽ�","�ﺰ ����", "�Ľ���", "��Ű ����", "���߽�", "�� ��ƿ","���� ����" };
int M[10] = { 0,0,0,0,0,0,0,0,0 };
int Money = 10000;
int Asset[10] = { 0,0,0,0,0,0,0,0,0 };
int BM[10] = { 0, };
char S;

void Buy();
void Sell();
void Check();
void MyAsset();
void Start();
void OpenData();
void CloseData();

int main()
{
	char W;
	OpenData();
	std::system("title �а����� �ֽ�");
	std::system("color F0");
	for (;;)
	{
		cout << "������ ���� ������ �ּ���[ 1.���� | 2.�Ǹ� | 3.�ü�(���ݺ���) | 4.�����ֽ� | 5.���� �� ���� ]: ";
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
		else if (W == Five)
		{
			cout << "������ ���� �� ���� �մϴ�." << endl;
			break;
		}
		std::system("cls");
	}
	CloseData();
}

void Check()
{
	srand((int)time(NULL));
	int B = 0;
	for (int i = 0; i <= 9; i++)
	{
		int J = rand() % 2 + 1;
		if (J % 2 == 0)
		{
			B = (rand() % 100 + 1);
			M[i] += round((0.001 * B) * M[i]);
			if (M[i] < 100)
			{
				M[i] = 100;
				B = 0;
			}
			else if (M[i] > 1000000)
			{
				M[i] = 1000000;
				B = 0;
			}
			cout << i << "." << Co[i] << "<" << M[i] << ">" << "(" << "+" << (0.1 * B) << "%" << "[" << round((0.001 * B) * M[i]) << "]" << ")" << endl;
		}
		else
		{
			B = (rand() % 90 + 1);
			M[i] -= ((0.001 * B) * M[i]);
			if (M[i] < 100)
			{
				M[i] = 100;
				B = 0;
			}
			else if (M[i] > 1000000)
			{
				M[i] = 1000000;
				B = 0;
			}
			cout << i << "." << Co[i] << "<" << M[i] << ">" << "(" << "-" << (0.1 * B) << "%" << "[" << round((0.001 * B) * M[i]) << "]" << ")" << endl;
		}
	}
	cout << "�Ѿ���� ���͸� ��������.";
	getchar();
	cin >> S;
}

void MyAsset()
{
	int i;
	int j;
	cout << "�����ݾ�: " << Money << endl;
	for (i = 0; i <= 9; i++)
	{
		j = (Asset[i] * M[i]) - BM[i];
		cout << Co[i] << "  " << Asset[i] << "��" << "[" << j << "]" << endl;
	}
	cout << "�Ѿ���� ���͸� ��������.";
	getchar();
	cin >> S;
}

void Buy()
{
	int B;
	int J;
	cout << "�� �ֽ��� ��ȣ�� �Է��ϼ���: ";
	cin >> B;
	for (int i = 0; i <= 9; i++)
	{
		if (B == i)
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
			BM[i] += M[i] * J;
		}
	}
	cout << "�Ѿ���� ���͸� ��������.";
	getchar();
	cin >> S;
}

void Sell()
{
	int B;
	int J;
	cout << "�� �ֽ��� ��ȣ�� �Է��ϼ���: ";
	cin >> B;
	for (int i = 0; i <= 9; i++)
	{
		if (B == i)
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
			BM[i] = 0;
		}
	}
	cout << "�Ѿ���� ���͸� ��������.";
	getchar();
	cin >> S;
}

void Start()
{
	srand((int)time(NULL));
	for (int i = 0; i <= 9; i++)
	{
		int NUM = (rand() % 3000 + 500);
		M[i] = M[i] + NUM;
	}
}

void OpenData()
{
	ifstream File;
	File.open("Money.dat");
	File >> Money;
	File.close();

	ifstream As;
	As.open("Asset.dat");
	for (int i = 0; i <= 9; i++)
	{
		As >> Asset[i];
	}
	As.close();
	if (M[1] > 0)
	{
		ifstream CM;
		CM.open("CoMoney.dat");
		for (int i = 0; i <= 9; i++)
		{
			CM >> M[i];
		}
		CM.close();
	}
	else if (M[1] == 0)
	{
		Start();
	}

	ifstream B;
	B.open("BuyMoney.dat");
	for (int i = 0; i <= 9; i++)
	{
		B >> BM[i];
	}
	B.close();
}

void CloseData()
{
	ofstream Mo;
	Mo.open("Money.dat");
	Mo << Money;
	Mo.close();

	ofstream As;
	As.open("Asset.dat");
	for (int i = 0; i <= 9; i++)
	{
		As << Asset[i] << endl;;
	}
	As.close();

	ofstream CM;
	CM.open("CoMoney.dat");
	for (int i = 0; i <= 9; i++)
	{
		CM << M[i] << endl;;
	}
	CM.close();

	ofstream B;
	B.open("BuyMoney.dat");
	for (int i = 0; i <= 9; i++)
	{
		B << BM[i] << endl;
	}
	B.close();
}