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

char Co[11][16] = { "찬지리는은행","S1 Movie","" };
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
		cout << "무엇을 할지 선택해 주세요[1.구매|2.판매|3.시세(가격변경)|4.보유주식]: ";
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
			cout << "현재 주식 시세" << endl;
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
	cout << "보유금액: " << Money << endl;
	for (i = 0; i <= 9; i++)
	{
		cout << Co[i] << "  " << Asset[i] << "개" << endl;
	}
}

void Buy()
{
	char* B = {};
	int J;
	cout << "살 주식의 이름을 입력하세요: ";
	cin >> B;
	fflush(stdin);
	for (int i = 0; i <= 9; i++)
	{
		if (strcmp(B, Co[i]) == 0)
		{
			cout << "몇 주를 구입 하시겠습니까?: ";
			cin >> J;
			if (Money <= 0 || Money - J * M[i] <= 0)
			{
				cout << "돈이 모자라 살 수 없습니다." << endl;
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
	cout << "팔 주식의 이름을 입력하세요: ";
	cin >> B;
	for (int i = 0; i <= 9; i++)
	{
		if (strcmp(B, Co[i]) == 0)
		{
			cout << "몇 주를 판매 하시겠습니까?: ";
			cin >> J;
			if (J > Asset[i])
			{
				cout << "보유 갯수를 초과한 주는 팔 수 없습니다." << endl;
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