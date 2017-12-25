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

	//�Է��Լ�
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

	//����Լ�
	void print(){
		printf("%8s %8s", this->number, this->name);
		for (int i = 0; i <= sub; i++){
			printf("%8d", this->score[i]);
		}
		printf(" %8.2f %8c %8d\n", this->avg, this->grade, this->rank);
	}

	//ó���Լ�
	void process() {
		this->avg = this->score[sub] / sub; //��� ���

		//��� ���
		switch ((int)this->avg / 10) {
		case 10: case 9: this->grade = 'A'; break;
		case 8: this->grade = 'B'; break;
		case 7: this->grade = 'C'; break;
		case 6: this->grade = 'D'; break;
		default: this->grade = 'F'; break;
		} //endOfSwitch
	}
};

int main() {
	//�ο���, ���� �� �Է�
	int person;
	cout << "�� ���� �Է��Ͻðڽ��ϱ�? "; cin >> person;
	cout << "�� ������ �Է��Ͻðڽ��ϱ�?"; cin >> sub;
	cout << endl; //�ٹٲ�

	Student* stu = new Student[person]; //��ü ����

	//���� �Է�
	for (int i = 0; i < person; i++) {
		stu[i].score = new int[sub + 1]; //�����+�հ踸ŭ ����
		stu[i].score[sub] = 0; //���� �ʱ�ȭ
		stu[i].rank = 1; //��� �ʱ�ȭ
		stu[i].input(); //�Է��Լ� ȣ��
		cout << endl; //�ٹٲ�
		stu[i].process(); //ó���Լ� ȣ��
	}//endOfFori

	//���� ���
	for (int i = 0; i < person; i++) {
		for (int j = 0; j < person; j++) {
			if (stu[i].avg < stu[j].avg) stu[i].rank++;
		}
	}

	//����� ���
	printf("%8s %8s", "�й�", "�̸� ");
	for (int i = 0; i < sub; i++) printf("%8s", subject[i]);
	printf("%8s %8s %8s %8s \n", "�հ�", "���", "���", "����");

	//����Լ� ȣ��
	for (int i = 0; i < person; i++) { stu[i].print(); }

	//�Ҹ�
	for (int i = 0; i < person; i++){ delete[] stu[i].score; }
	delete[] stu;

	return 0;
}