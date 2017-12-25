#include <iostream>
//#define person 5
using namespace std;

int main() {
	//�ο��� üũ
	int person, sub; //�ο� ��
	cout << "�� ���� �Է��Ͻðڽ��ϱ�? ";
	cin >> person;
	cout << "�� ������ �Է��Ͻðڽ��ϱ�?";
	cin >> sub;

	//�����Ҵ�
	char **name = new char*[person]; //�̸�
	char **number = new char*[person]; //�й�
	int **score = new int*[person]; //����

	for (int i = 0; i < person; i++)  {
		name[i] = new char[10]; //�̸�
		number[i] = new char[5]; //�й�
		score[i] = new int[sub + 1]; //����+�հ�
	}

	double *avg = new double[person]; // ���
	char *grade = new char[person]; // ���
	int *rank = new int[person]; // ���
	char subject[9][5] = { "����", "����", "����", "����", "C++", "�ڹ�", "OS", "DS", "SB" }; //����

	for (int i = 0; i < person; i++) {
		//�հ�, ���� �� �ʱ�ȭ
		score[i][sub] = 0;
		rank[i] = 1;

		//�й�, �̸� �Է�
		cout << "�й�>> ";
		cin >> number[i];
		cout << "�̸�>> ";
		cin >> name[i];

		//���� �Է�, ����, ���
		for (int j = 0; j < sub; j++) {
			do{
				cout << subject[j] << "����>> ";
				cin >> score[i][j];
				if (score[i][j] < 0 || score[i][j] > 100) {
					cout << "�߸��� ���� �Դϴ�." << endl;
				}
			} while (score[i][j] < 0 || score[i][j] > 100);
			score[i][sub] += score[i][j];
		}//endOfForJ

		avg[i] = score[i][sub] / sub;

		//���
		switch ((int)avg[i] / 10) {
		case 10:
		case 9: grade[i] = 'A'; break;
		case 8: grade[i] = 'B'; break;
		case 7: grade[i] = 'C'; break;
		case 6: grade[i] = 'D'; break;
		default: grade[i] = 'F'; break;
		} //endOfSwitch

	}//endOfFori

	//����2
	for (int i = 0; i < person; i++) {
		for (int j = 0; j < person; j++) {
			if (avg[i] < avg[j]) rank[i]++;
		}
	}

	//���� ���
	printf("%8s %8s", "�й�", "�̸� ");
	for (int i = 0; i < sub; i++) printf("%8s", subject[i]);
	printf("%8s %8s %8s %8s \n", "�հ�", "���", "���", "����");

	//���� ���
	for (int i = 0; i < person; i++) {
		printf("%8s %8s", number[i], name[i]);
		for (int j = 0; j <= sub; j++){
			printf("%8d", score[i][j]);
		}
		printf(" %8.2f %8c %8d\n", avg[i], grade[i], rank[i]);
	}

	//�迭 ����
	for (int i = 0; i < person; i++) {
		delete[] number[i];
		delete[] name[i];
		delete[] score[i];
	}
	delete[] name; delete[] number; delete[] score;
	delete[] avg; delete[] grade; delete[] rank;

	return 0;
}