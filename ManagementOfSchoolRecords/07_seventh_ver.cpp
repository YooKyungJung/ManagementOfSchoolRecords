#include <iostream>
using namespace std;
//전역변수
int sub;
char subject[9][5] = { "국어", "수학", "영어", "과학", "C++", "자바", "OS", "DS", "SB" }; //과목명

struct Student {
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
			//총점 계산
			this->score[sub] += this->score[j];
		}//endOfForJ
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
};

int main() {
	//인원수, 과목 수 입력
	int person;
	cout << "몇 명을 입력하시겠습니까? "; cin >> person;
	cout << "몇 과목을 입력하시겠습니까?"; cin >> sub;
	cout << endl; //줄바꿈

	Student* stu = new Student[person]; //객체 생성

	//점수 입력
	for (int i = 0; i < person; i++) {
		stu[i].score = new int[sub + 1]; //과목수+합계만큼 생성
		stu[i].score[sub] = 0; //총점 초기화
		stu[i].rank = 1; //등수 초기화
		stu[i].input(); //입력함수 호출
		cout << endl; //줄바꿈
		stu[i].process(); //처리함수 호출
	}//endOfFori

	//석차 계산
	for (int i = 0; i < person; i++) {
		for (int j = 0; j < person; j++) {
			if (stu[i].avg < stu[j].avg) stu[i].rank++;
		}
	}

	//과목명 출력
	printf("%8s %8s", "학번", "이름 ");
	for (int i = 0; i < sub; i++) printf("%8s", subject[i]);
	printf("%8s %8s %8s %8s \n", "합계", "평균", "등급", "석차");

	//출력함수 호출
	for (int i = 0; i < person; i++) { stu[i].print(); }

	//소멸
	for (int i = 0; i < person; i++){ delete[] stu[i].score; }
	delete[] stu;

	return 0;
}