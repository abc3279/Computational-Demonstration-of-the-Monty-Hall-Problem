// 안바꾸는 경 우 
#include <iostream>
#include <random>
#include <ctime>
#include <windows.h>

using namespace std;
 
int main(void) 
{
	int user, random, user2; //user: 첫번째 선택 변수, user2: 두번째 선택 변수, random :  슈퍼카 위치 변수 
	bool one = false, two = false, three = false; // 슈퍼카 위치유무 
	float cnt = 0, correct = 0, wrong = 0; //cnt: 총 횟수, correct: 맞은 갯수, wrong: 틀린갯수 
	int i = 0;
	
	random_device rd; //
	mt19937 gen(rd());//
	uniform_int_distribution<int> dis(0, 2); // 랜덤을 사용하기 위한 초기화 설정 
 
	while(i < 1000000) //100만번 시행 
	{
		cnt++;
		
		one = false;
		two = false;
		three = false;//초기화
 
		random = dis(gen)+1; // 랜덤하게 1번, 2번, 3번 문 중 어느 곳에 슈퍼카가 있을지 선택
 
		switch (random) // random을 가지고 적용 
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
		
		user = dis(gen)+1; //첫번째 선택 랜덤 
 		user2 = user; //두번째 선택을 고수함 
 		
		if (one == false && user != 1) //첫번째가 슈퍼카가 아니고, 첫번째 선택이 첫번째가 아닐때 
		{
			cout << "1번 염소\n"; //=> 1번에 염소가 있음 

			if ((user2 == 1 && one == true)||(user2 == 2 && two == true)||(user2 == 3 && three == true)) 
			{
				correct++; //두번째 선택이 슈퍼카 번호를 선택했다면 정답 
			}
			else 
			{
				wrong++; //두번째 선택이 슈퍼카 번호를 선택하지 않았다면 틀림. 
			}
		}
		else if (two == false && user != 2) //두번째가 슈퍼카가 아니고, 첫번째 선택이 두번째가 아닐때 
		{
			cout << "2번 염소\n";//=> 2번에 염소가 있음 

			if ((user2 == 1 && one == true)||(user2 == 2 && two == true)||(user2 == 3 && three == true)) 
			{
				correct++;//두번째 선택이 슈퍼카 번호를 선택했다면 정답 
			}
			else 
			{
				wrong++;//두번째 선택이 슈퍼카 번호를 선택하지 않았다면 틀림. 
			}
		}
		else if (three == false && user != 3) //세번째가 슈퍼카가 아니고, 첫번째 선택이 세번째가 아닐때 
		{
			cout << "3번 염소\n";//=> 3번에 염소가 있음 

			if ((user2 == 1 && one == true)||(user2 == 2 && two == true)||(user2 == 3 && three == true)) 
			{
				correct++;//두번째 선택이 슈퍼카 번호를 선택했다면 정답 
			}
			else 
			{
				wrong++;//두번째 선택이 슈퍼카 번호를 선택하지 않았다면 틀림. 
			}
		}
 
		/*결과를 출력합니다.*/
		cout << "시도 횟수 : " << cnt << "\n";
		cout << "맞춘 횟수 : " << correct << "\n";
		cout << "틀린 횟수 : " << wrong << "\n";
		cout << "지금까지 맞춘 확률 " << (correct / cnt) * 100 << "%\n\n\n";
		
		i++;
	}
}
