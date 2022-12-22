#include <iostream> 
#include <fstream> 
#include <string>
#include <iomanip>

using namespace std;

struct Student
{
	string   prizv;
	string   init;
		double physic;
		double math;
		double prog;
		double num;
		double ped;

};

void Create(Student* s, int& N) {
	for (int i = 0; i < N; i++) {
		cout << "Student number " << i + 1 << " : " << endl;
		cin.get();
		cin.sync();

		cout << "    Surname: "; getline(cin, s[i].prizv);
		cout << "    Initials: "; getline(cin, s[i].init);
		cout << " Assessment in physics : "; cin >> s[i].physic;
		cout << " Assessment in math : "; cin >> s[i].math;
		cout << " Assessment in programmingі : "; cin >> s[i].prog;
		cout << " Assessment in pedagogyі : "; cin >> s[i].ped;
		cout << " Assessment in numerical methodsі : "; cin >> s[i].num;

	}
}
void Print(Student* s, int N) {

	cout << "=============================================================================================================="
		<< endl;
	cout << "|  №  |   Surname   |   Initials   |   Physics   |   Math   |   Programming   |   Pedagogy   |   Numerical   |"
		<< endl;
	cout << "--------------------------------------------------------------------------------------------------------------"
		<< endl;

	for (int i = 0; i < N; i++) {
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(13) << s[i].prizv
			<< "| " << setw(14) << left << s[i].init
			<< "| " << setw(10) << s[i].physic
			<< "| " << setw(10) << s[i].math
			<< "| " << setw(16) << s[i].prog
			<< "| " << setw(14) << s[i].ped
			<< "| " << setw(16) << s[i].num << "|";
		cout << endl;
	}
	cout << "=============================================================================================================="
		<< endl;
	cout << endl;
}
void All5(Student* s, int N,int& index) {
	cout << "student who have all 5 :";
	for (int i = 0; i < N; i++) {
		if (s[i].physic == 5 && s[i].math == 5 && s[i].prog == 5 && s[i].num == 5 && s[i].ped == 5) {
			cout <<s[i].prizv<<" " << s[i].init<<", ";
		}
		index = i;
	}

}
void Atleast3(Student* s, int N) {
	cout << "student who have 3 :";
	for (int i = 0; i < N; i++) {
		if (s[i].physic == 3 || s[i].math == 3|| s[i].prog == 3 || s[i].num == 3 || s[i].ped == 3) {
			cout << s[i].prizv << " " << s[i].init << ", ";
		}
	}

}
void Atleast2(Student*& s, int& N) {
	cout << "student who have 2 :";
	int count = 0;
	int t = 0;
	for (int i = 0; i < N; i++) {
		if (s[i].physic == 2) {
			count++;
		}
		if (s[i].math== 2) {
			count++;
		}
		if (s[i].prog == 2) {
			count++;
		}
		if (s[i].num == 2) {
			count++;
		}
		if (s[i].ped == 2) {
			count++;
		}
		if (count == 1) {
			cout << s[i].prizv << " " << s[i].init << ", " << endl;
		}
		if (count >= 2) {
			t++;
		}
		count = 0;
	}
	count = 0;
	int K = N - t;
	Student* m = new Student[K];
	int j = 0;
	for (int i = 0; i < K; i++) {
		if (s[i].physic == 2) {
			count++;
		}
		if (s[i].math == 2) {
			count++;
		}
		if (s[i].prog == 2) {
			count++;
		}
		if (s[i].num == 2) {
			count++;
		}
		if (s[i].ped == 2) {
			count++;
		}
		if (count < 2) {
			m[j++] = s[i];
		}
		count = 0;
	}
	s = m;
	N = K;

}
void SaveToFile(Student* s, const int N, const char* filename) {
	ofstream fout(filename, ios::binary);
	fout.write((char*)&N, sizeof(N));
	for (int i = 0; i < N; i++)
		fout.write((char*)&s[i], sizeof(Student));
	fout.close();
}
void LoadFromFile(Student*& s, int& N, const char* filename) {
	delete[] s;
	ifstream fin(filename, ios::binary);
	fin.read((char*)&N, sizeof(N));
	s = new Student[N];
	for (int i = 0; i < N; i++)
		fin.read((char*)&s[i], sizeof(Student));
	fin.close();
}

int main() {

	int N;
	cout << "Input count of student N: "; cin >> N;
	Student* s = new Student[N];

	int ispecurs;
	int found;
	int isspec;
	string   prizv;
	char fname[100]{};
	int index;
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "Select an action:" << endl << endl;
		cout << " [1] - entering data from the keyboard" << endl;
		cout << " [2] - display of data on the screen" << endl;
		cout << " [3] - the list of students who passed exams only on 5;" << endl;
		cout << " [4] - list of students who have 3" << endl;
		cout << " [5] - list of students who have 2" << endl;
		cout << " [6] - writing data to a file" << endl;
		cout << " [7] - reading data from a file" << endl;

		cout << " [0] - exit" << endl << endl;
		cout << "Input value: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(s, N);
			break;
		case 2:
			Print(s, N);
			break;
		case 3:
			All5(s, N,index);
			break;
		case 4:
			Atleast3(s, N);
			break;
		case 5:
			Atleast2(s, N);
			Print(s, N);
			break;
		case 6:
			cin.get(); 
			cin.sync();
			cout << "Input file name: "; cin.getline(fname, 99);
			SaveToFile(s, N, fname);
			break;
		case 7:
			cin.get();
			cin.sync();
			cout << "Input file name: "; cin.getline(fname, 99);
			LoadFromFile(s, N, fname);
			break;
		}
	} while (menuItem != 0);


	return 0;
}