#include <iostream>
using namespace std;

//��������
int sub;
char subject[9][5] = { "����", "����", "����", "����", "C++", "�ڹ�", "OS", "DS", "SB" }; //�����

class Student {
public:
	friend ostream& operator<<(ostream &ost, Student &st);
	friend void ranking(int person);
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

ostream& operator<<(ostream &ost, Student &st) {
	//st.print();
	/*
	printf("%8s %8s", st.number, st.name);
	for (int i = 0; i <= sub; i++){
	printf("%8d", st.score[i]);
	}
	printf(" %8.2f %8c %8d\n", st.avg, st.grade, st.rank);
	*/
	st.print();
	return ost;
}

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
	int person;
	//�ο���, ���� �� �Է�
	int num = 0;
	do {
		cout << "����ó�� ���α׷�";
		cout << " 1. �Է�";
		cout << "2. ���";
		cout << "3. ����";
		cin >> num;
	} while (num != 1 && num != 2 && num != 3);

	switch (num) {
	case 1:
		system("cls");
		//�ο���, ���� �� �Է�
		cout << "�� ���� �Է��Ͻðڽ��ϱ�? "; cin >> person;
		cout << "�� ������ �Է��Ͻðڽ��ϱ�?"; cin >> sub;
		cout << endl; //�ٹٲ�
		stu = new Student[person]; //��ü ����
		for (int i = 0; i < person; i++) { stu[i].input(); stu[i].process(); }//�Է�, ó���Լ� ȣ��
		ranking(person); //�����Լ� ȣ��
		do {
			cout << "�޴� 1, ���� 2";
			cin >> num;
		} while (num != 1 && num != 2 && num != 3);
		break;
	case 2:
		system("cls");
		//����� ���
		printf("%8s %8s", "�й�", "�̸� ");
		for (int i = 0; i < sub; i++) printf("%8s", subject[i]);
		printf("%8s %8s %8s %8s \n", "�հ�", "���", "���", "����");

		//����Լ� ȣ��
		for (int i = 0; i < person; i++) {
			cout << stu[i]; //cout.operator<<(stu[i]);
			//stu[i].print(); 
		}
		delete[] stu; //�Ҹ�
	case 3:
		system("cls");
		cout << "���α׷��� ����Ǿ����ϴ�";
	}

	return 0;
}