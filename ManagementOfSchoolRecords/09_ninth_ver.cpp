#include <iostream>
using namespace std;

//전역변수
int sub;
char subject[9][5] = { "국어", "수학", "영어", "과학", "C++", "자바", "OS", "DS", "SB" }; //과목명

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

	//입력함수
	void input() {
		//학번, 이름 입력
		cout << "학번: ";
		cin >> this->number;
		cout << "이름: ";
		cin >> this->name;

		//과목 별 점수 입력
		for (int j = 0; j < sub; j++) {
			do{
				cout << subject[j] << "점수: ";
				cin >> this->score[j];
				if (this->score[j] < 0 || this->score[j] > 100) {
					cout << "잘못된 점수 입니다." << endl;
				}
			} while (this->score[j] < 0 || this->score[j] > 100);
			this->score[sub] += this->score[j]; //총점 계산
		}//endOfForJ

		cout << endl; //줄바꿈
	}

	//출력함수
	void print(){
		printf("%8s %8s", this->number, this->name);
		for (int i = 0; i <= sub; i++){
			printf("%8d", this->score[i]);
		}
		printf(" %8.2f %8c %8d\n", this->avg, this->grade, this->rank);
	}

	//처리함수
	void process() {
		this->avg = this->score[sub] / sub; //평균 계산

		//등급 계산
		switch ((int)this->avg / 10) {
		case 10: case 9: this->grade = 'A'; break;
		case 8: this->grade = 'B'; break;
		case 7: this->grade = 'C'; break;
		case 6: this->grade = 'D'; break;
		default: this->grade = 'F'; break;
		} //endOfSwitch
	}
	//생성자
	Student() {
		printf("생성자");
		this->score = new int[sub + 1]; //과목수+합계만큼 생성
		this->score[sub] = 0; //총점 초기화
		this->rank = 1; //석차 초기화
	}

	//소멸자
	~Student() {
		delete[] score;
		printf("소멸자");
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

Student* stu = 0; //전역변수로 빼놓음

//석차 함수
void ranking(int person) {
	for (int i = 0; i < person; i++) {
		for (int j = 0; j < person; j++) {
			if (stu[i].avg < stu[j].avg) stu[i].rank++;
		}
	}
}

int main() {
	int person;
	//인원수, 과목 수 입력
	int num = 0;
	do {
		cout << "성적처리 프로그램";
		cout << " 1. 입력";
		cout << "2. 출력";
		cout << "3. 종료";
		cin >> num;
	} while (num != 1 && num != 2 && num != 3);

	switch (num) {
	case 1:
		system("cls");
		//인원수, 과목 수 입력
		cout << "몇 명을 입력하시겠습니까? "; cin >> person;
		cout << "몇 과목을 입력하시겠습니까?"; cin >> sub;
		cout << endl; //줄바꿈
		stu = new Student[person]; //객체 생성
		for (int i = 0; i < person; i++) { stu[i].input(); stu[i].process(); }//입력, 처리함수 호출
		ranking(person); //석차함수 호출
		do {
			cout << "메뉴 1, 종료 2";
			cin >> num;
		} while (num != 1 && num != 2 && num != 3);
		break;
	case 2:
		system("cls");
		//과목명 출력
		printf("%8s %8s", "학번", "이름 ");
		for (int i = 0; i < sub; i++) printf("%8s", subject[i]);
		printf("%8s %8s %8s %8s \n", "합계", "평균", "등급", "석차");

		//출력함수 호출
		for (int i = 0; i < person; i++) {
			cout << stu[i]; //cout.operator<<(stu[i]);
			//stu[i].print(); 
		}
		delete[] stu; //소멸
	case 3:
		system("cls");
		cout << "프로그램이 종료되었습니다";
	}

	return 0;
}