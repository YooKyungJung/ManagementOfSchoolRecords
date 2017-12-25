#include <iostream>
using namespace std;
//��������
int sub;
char subject[9][5] = { "����", "����", "����", "����", "C++", "�ڹ�", "OS", "DS", "SB" }; //�����


struct Student {
	char number[5];
	char name[10];
	int * score;
	double avg;
	char grade;
	int rank;

	//�Է� �Լ�
	void input() {
		//�й�, �̸� �Է�
		cout << "�й�: ";
		cin >> this->number;
		cout << "�̸�: ";
		cin >> this->name;

		//���� �� ���� �Է�
		for (int j = 0; j < sub; j++) {
			do{
				cout << subject[j] << "����: ";
				cin >> this->score[j];
				if (this->score[j] < 0 || this->score[j] > 100) {
					cout << "�߸��� ���� �Դϴ�." << endl;
				}
			} while (this->score[j] < 0 || this->score[j] > 100);
			//���� ���
			this->score[sub] += this->score[j];
		}//endOfForJ
	}
};

int main() {
	//�ο���, ���� �� �Է�
	int person;
	cout << "�� ���� �Է��Ͻðڽ��ϱ�? "; cin >> person;
	cout << "�� ������ �Է��Ͻðڽ��ϱ�?"; cin >> sub;
	cout << endl; //�ٹٲ�

	//��ü ����
	Student* stu = new Student[person];

	//���� �Է�
	for (int i = 0; i < person; i++) {
		stu[i].score = new int[sub + 1]; //�����+�հ踸ŭ ����

		stu[i].score[sub] = 0; //���� �ʱ�ȭ
		stu[i].rank = 1; //��� �ʱ�ȭ

		stu[i].input(); //�Է��Լ� ȣ��

		cout << endl; //�ٹٲ�

		stu[i].avg = stu[i].score[sub] / sub; //��� ���

		//��� ���
		switch ((int)stu[i].avg / 10) {
		case 10: case 9: stu[i].grade = 'A'; break;
		case 8: stu[i].grade = 'B'; break;
		case 7: stu[i].grade = 'C'; break;
		case 6: stu[i].grade = 'D'; break;
		default: stu[i].grade = 'F'; break;
		} //endOfSwitch

	}//endOfFori

	//���� ���
	for (int i = 0; i < person; i++) {
		for (int j = 0; j < person; j++) {
			if (stu[i].avg < stu[j].avg) stu[i].rank++;
		}
	}

	//���� ���
	printf("%8s %8s", "�й�", "�̸� ");
	for (int i = 0; i < sub; i++) printf("%8s", subject[i]);
	printf("%8s %8s %8s %8s \n", "�հ�", "���", "���", "����");

	//���� ���
	for (int i = 0; i < person; i++) {
		printf("%8s %8s", stu[i].number, stu[i].name);
		for (int j = 0; j <= sub; j++){
			printf("%8d", stu[i].score[j]);
		}
		printf(" %8.2f %8c %8d\n", stu[i].avg, stu[i].grade, stu[i].rank);
	}

	//�Ҹ�
	for (int i = 0; i < person; i++)
	{
		delete[] stu[i].score;
	}
	delete[] stu;

	return 0;
}