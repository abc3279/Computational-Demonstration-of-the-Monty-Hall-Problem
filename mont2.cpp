// �ȹٲٴ� �� �� 
#include <iostream>
#include <random>
#include <ctime>
#include <windows.h>

using namespace std;
 
int main(void) 
{
	int user, random, user2; //user: ù��° ���� ����, user2: �ι�° ���� ����, random :  ����ī ��ġ ���� 
	bool one = false, two = false, three = false; // ����ī ��ġ���� 
	float cnt = 0, correct = 0, wrong = 0; //cnt: �� Ƚ��, correct: ���� ����, wrong: Ʋ������ 
	int i = 0;
	
	random_device rd; //
	mt19937 gen(rd());//
	uniform_int_distribution<int> dis(0, 2); // ������ ����ϱ� ���� �ʱ�ȭ ���� 
 
	while(i < 1000000) //100���� ���� 
	{
		cnt++;
		
		one = false;
		two = false;
		three = false;//�ʱ�ȭ
 
		random = dis(gen)+1; // �����ϰ� 1��, 2��, 3�� �� �� ��� ���� ����ī�� ������ ����
 
		switch (random) // random�� ������ ���� 
		{
			case 1:
				one = true;
				break;
			case 2:
				two = true;
				break;
			case 3:
				three = true;
				break;
		}
		
		user = dis(gen)+1; //ù��° ���� ���� 
 		user2 = user; //�ι�° ������ ����� 
 		
		if (one == false && user != 1) //ù��°�� ����ī�� �ƴϰ�, ù��° ������ ù��°�� �ƴҶ� 
		{
			cout << "1�� ����\n"; //=> 1���� ���Ұ� ���� 

			if ((user2 == 1 && one == true)||(user2 == 2 && two == true)||(user2 == 3 && three == true)) 
			{
				correct++; //�ι�° ������ ����ī ��ȣ�� �����ߴٸ� ���� 
			}
			else 
			{
				wrong++; //�ι�° ������ ����ī ��ȣ�� �������� �ʾҴٸ� Ʋ��. 
			}
		}
		else if (two == false && user != 2) //�ι�°�� ����ī�� �ƴϰ�, ù��° ������ �ι�°�� �ƴҶ� 
		{
			cout << "2�� ����\n";//=> 2���� ���Ұ� ���� 

			if ((user2 == 1 && one == true)||(user2 == 2 && two == true)||(user2 == 3 && three == true)) 
			{
				correct++;//�ι�° ������ ����ī ��ȣ�� �����ߴٸ� ���� 
			}
			else 
			{
				wrong++;//�ι�° ������ ����ī ��ȣ�� �������� �ʾҴٸ� Ʋ��. 
			}
		}
		else if (three == false && user != 3) //����°�� ����ī�� �ƴϰ�, ù��° ������ ����°�� �ƴҶ� 
		{
			cout << "3�� ����\n";//=> 3���� ���Ұ� ���� 

			if ((user2 == 1 && one == true)||(user2 == 2 && two == true)||(user2 == 3 && three == true)) 
			{
				correct++;//�ι�° ������ ����ī ��ȣ�� �����ߴٸ� ���� 
			}
			else 
			{
				wrong++;//�ι�° ������ ����ī ��ȣ�� �������� �ʾҴٸ� Ʋ��. 
			}
		}
 
		/*����� ����մϴ�.*/
		cout << "�õ� Ƚ�� : " << cnt << "\n";
		cout << "���� Ƚ�� : " << correct << "\n";
		cout << "Ʋ�� Ƚ�� : " << wrong << "\n";
		cout << "���ݱ��� ���� Ȯ�� " << (correct / cnt) * 100 << "%\n\n\n";
		
		i++;
	}
}
