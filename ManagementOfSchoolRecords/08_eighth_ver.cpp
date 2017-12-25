#include <iostream>
using namespace std;

//��������
int sub;
char subject[9][5] = { "����", "����", "����", "����", "C++", "�ڹ�", "OS", "DS", "SB" }; //�����

class Student {
public:
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
			this->score[sub] += this->score[j]; //���� ���
		}//endOfForJ

		cout << endl; //�ٹٲ�
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

	//������
	Student() {
		printf("������");
		this->score = new int[sub + 1]; //�����+�հ踸ŭ ����
		this->score[sub] = 0; //���� �ʱ�ȭ
		this->rank = 1; //���� �ʱ�ȭ
	}

	//�Ҹ���
	~Student() {
		delete[] score;
		printf("�Ҹ���");
	}
};

Student* stu = 0; //���������� ������

//���� �Լ�
void ranking(int person) {
	for (int i = 0; i < person; i++) {
		for (int j = 0; j < person; j++) {
			if (stu[i].avg < stu[j].avg) stu[i].rank++;
		}
	}
}

int main() {
	//�ο���, ���� �� �Է�
	int person;
	cout << "�� ���� �Է��Ͻðڽ��ϱ�? "; cin >> person;
	cout << "�� ������ �Է��Ͻðڽ��ϱ�?"; cin >> sub;
	cout << endl; //�ٹٲ�

	stu = new Student[person]; //��ü ����

	//�Է�, ó���Լ� ȣ��
	for (int i = 0; i < person; i++) { stu[i].input(); stu[i].process(); }
	ranking(person); //�����Լ� ȣ��

	//����� ���
	printf("%8s %8s", "�й�", "�̸� ");
	for (int i = 0; i < sub; i++) printf("%8s", subject[i]);
	printf("%8s %8s %8s %8s \n", "�հ�", "���", "���", "����");

	for (int i = 0; i < person; i++) { stu[i].print(); } //����Լ� ȣ��

	delete[] stu; //�Ҹ�

	return 0;
}