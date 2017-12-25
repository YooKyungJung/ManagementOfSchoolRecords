#include <iostream>
using namespace std;
#define sub 5
struct Student {
	char number[5];
	char name[10];
	int score[sub + 1];
	double avg;
	char grade;
	int rank;
};

int main() {
	//인원수, 과목 수
	int person;
	cout << "몇 명을 입력하시겠습니까? ";
	cin >> person;
	//cout << "몇 과목을 입력하시겠습니까?";
	//cin >> sub;
	cout << endl; //줄바꿈

	Student* stu = new Student[person]; //생성

	//과목명
	char subject[9][5] = { "국어", "수학", "영어", "과학", "C++", "자바", "OS", "DS", "SB" }; //과목

	//점수 입력
	for (int i = 0; i < person; i++) {
		stu[i].score = new int[sub + 1];
		//합계, 석차 값 초기화
		stu[i].score[sub] = 0;
		stu[i].rank = 1;

		//학번, 이름
		cout << "학번: ";
		cin >> stu[i].number;
		cout << "이름: ";
		cin >> stu[i].name;

		//과목 별 점수
		for (int j = 0; j < sub; j++) {
			do{
				cout << subject[j] << "점수: ";
				cin >> stu[i].score[j];
				if (stu[i].score[j] < 0 || stu[i].score[j] > 100) {
					cout << "잘못된 점수 입니다." << endl;
				}
			} while (stu[i].score[j] < 0 || stu[i].score[j] > 100);
			//총점
			stu[i].score[sub] += stu[i].score[j];
		}//endOfForJ
		cout << endl; //줄바꿈
		//평균
		stu[i].avg = stu[i].score[sub] / sub;

		//등급
		switch ((int)stu[i].avg / 10) {
		case 10:
		case 9: stu[i].grade = 'A'; break;
		case 8: stu[i].grade = 'B'; break;
		case 7: stu[i].grade = 'C'; break;
		case 6: stu[i].grade = 'D'; break;
		default: stu[i].grade = 'F'; break;
		} //endOfSwitch

	}//endOfFori

	//석차2
	for (int i = 0; i < person; i++) {
		for (int j = 0; j < person; j++) {
			if (stu[i].avg < stu[j].avg) stu[i].rank++;
		}
	}

	//과목 출력
	printf("%8s %8s", "학번", "이름 ");
	for (int i = 0; i < sub; i++) printf("%8s", subject[i]);
	printf("%8s %8s %8s %8s \n", "합계", "평균", "등급", "석차");

	//점수 출력
	for (int i = 0; i < person; i++) {
		printf("%8s %8s", stu[i].number, stu[i].name);
		for (int j = 0; j <= sub; j++){
			printf("%8d", stu[i].score[j]);
		}
		printf(" %8.2f %8c %8d\n", stu[i].avg, stu[i].grade, stu[i].rank);
	}

	return 0;
}