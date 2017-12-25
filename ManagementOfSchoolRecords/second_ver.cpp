#include <iostream>
//#define person 5
using namespace std;

int main() {
	//인원수 체크
	int person, sub; //인원 수
	cout << "몇 명을 입력하시겠습니까? ";
	cin >> person;
	cout << "몇 과목을 입력하시겠습니까?";
	cin >> sub;

	//동적할당
	char **name = new char*[person]; //이름
	char **number = new char*[person]; //학번
	int **score = new int*[person]; //점수

	for (int i = 0; i < person; i++)  {
		name[i] = new char[10]; //이름
		number[i] = new char[5]; //학번
		score[i] = new int[sub + 1]; //점수+합계
	}

	double *avg = new double[person]; // 평균
	char *grade = new char[person]; // 등급
	int *rank = new int[person]; // 등수
	char subject[9][5] = { "국어", "수학", "영어", "과학", "C++", "자바", "OS", "DS", "SB" }; //과목

	for (int i = 0; i < person; i++) {
		//합계, 석차 값 초기화
		score[i][sub] = 0;
		rank[i] = 1;

		//학번, 이름 입력
		cout << "학번>> ";
		cin >> number[i];
		cout << "이름>> ";
		cin >> name[i];

		//점수 입력, 총점, 평균
		for (int j = 0; j < sub; j++) {
			do{
				cout << subject[j] << "점수>> ";
				cin >> score[i][j];
				if (score[i][j] < 0 || score[i][j] > 100) {
					cout << "잘못된 점수 입니다." << endl;
				}
			} while (score[i][j] < 0 || score[i][j] > 100);
			score[i][sub] += score[i][j];
		}//endOfForJ

		avg[i] = score[i][sub] / sub;

		//등급
		switch ((int)avg[i] / 10) {
		case 10:
		case 9: grade[i] = 'A'; break;
		case 8: grade[i] = 'B'; break;
		case 7: grade[i] = 'C'; break;
		case 6: grade[i] = 'D'; break;
		default: grade[i] = 'F'; break;
		} //endOfSwitch

	}//endOfFori

	//석차2
	for (int i = 0; i < person; i++) {
		for (int j = 0; j < person; j++) {
			if (avg[i] < avg[j]) rank[i]++;
		}
	}

	//과목 출력
	printf("%8s %8s", "학번", "이름 ");
	for (int i = 0; i < sub; i++) printf("%8s", subject[i]);
	printf("%8s %8s %8s %8s \n", "합계", "평균", "등급", "석차");

	//점수 출력
	for (int i = 0; i < person; i++) {
		printf("%8s %8s", number[i], name[i]);
		for (int j = 0; j <= sub; j++){
			printf("%8d", score[i][j]);
		}
		printf(" %8.2f %8c %8d\n", avg[i], grade[i], rank[i]);
	}

	//배열 제거
	for (int i = 0; i < person; i++) {
		delete[] number[i];
		delete[] name[i];
		delete[] score[i];
	}
	delete[] name; delete[] number; delete[] score;
	delete[] avg; delete[] grade; delete[] rank;

	return 0;
}