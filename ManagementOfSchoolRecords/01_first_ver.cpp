#include <iostream>
#define person 2
using namespace std;
int main() {
	//��� �Ҽ��� �й� �̸�
	//int kor, eng, math, pg, sum = 0; //���� ���� ���� ���� �հ�
	int score[person][5];
	//double avg; //���;
	double avg[person];
	//int person; //�� �� �Է¹��� ��
	char grade[person];
	char subject[4][5] = { "����", "����", "����", "����" };
	//cout << "�� ���� �Է��Ͻðڽ��ϱ�? ";
	//cin >> person;
	//char number[5];
	char number[person][10];
	//char name[10]; 
	char name[person][10];


	for (int i = 0; i < person; i++) {
		cout << "�й�>> ";
		cin >> number[i];

		cout << "�̸�>> ";
		cin >> name[i];
		for (int j = 0; j < 4; j++) {
			do{
				cout << subject[j] << "����>> ";
				cin >> score[i][j];
				if (score[i][j] < 0 || score[i][j] > 100) {
					cout << "�߸��� ���� �Դϴ�." << endl;
				}
			} while (score[i][j] < 0 || score[i][j] > 100);
		}

		/*	do{
		cout << "���� ����>> ";
		cin >> score[i][1];
		if (score[i][1] < 0 || score[i][1] > 100) {
		cout << "�߸��� ���� �Դϴ�." << endl;
		}
		} while (score[i][1] < 0 || score[i][1] > 100);

		do{
		cout << "���� ����>> ";
		cin >> score[i][2];
		if (score[i][2] < 0 || score[i][2] > 100) {
		cout << "�߸��� ���� �Դϴ�." << endl;
		}
		} while (score[i][2] < 0 || score[i][2] > 100);

		do{
		cout << "���� ����>> ";
		cin >> score[i][3];
		if (score[i][3] < 0 || score[i][3] > 100) {
		cout << "�߸��� ���� �Դϴ�." << endl;
		}
		} while (score[i][3] < 0 || score[i][3] > 100);*/

		score[i][4] = 0;
		score[i][4] = score[i][0] + score[i][1] + score[i][2] + score[i][3];
		avg[i] = score[i][4] / 4.0;

		//���
		switch ((int)avg[i] / 10) {
		case 10:
		case 9: grade[i] = 'A'; break;
		case 8: grade[i] = 'B'; break;
		case 7: grade[i] = 'C'; break;
		case 6: grade[i] = 'D'; break;
		default: grade[i] = 'F'; break;
		}
	}
	printf("\n%8s %8s %8s %8s %8s %8s %8s %8s %8s\n", "�й�", "�̸�", "����", "����", "����", "����", "�հ�", "���", "���");
	for (int i = 0; i < person; i++) {
		printf("%8s %8s %8d %8d %8d %8d %8d %8.2f %8c \n", number[i], name[i], score[i][0], score[i][1], score[i][2], score[i][3], score[i][4], avg[i], grade[i]);
	}
	return 0;
}