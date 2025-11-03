#include <iostream>
#include <string>
using namespace std;

struct studentType{
    string studentFName;
    string studentLName;
    int testScore;
    char Grade;
};

void membaca_data_siswa(studentType students[]);
void menentukan_grade(studentType students[]);
int nilai_tertinggi(studentType students[]);
void siswa_nilai_tertinggi(studentType students[], int max);
void mengisi(studentType students[]);

int main(){
    int max;
    studentType students[20];
    mengisi(students);
    
    menentukan_grade(students);
    max = nilai_tertinggi(students);

    membaca_data_siswa(students);
    cout<<"\nsiswa yang memperoleh nilai tertinggi adalah: \n";
    siswa_nilai_tertinggi(students, max);
    cout<<"nilai yang diperoleh dari siswa yang tertinggi adalah: "<< nilai_tertinggi(students);
        
    return 0;
    }

int nilai_tertinggi(studentType students[]){
    int max = 0;
    for(int i = 0; i < 20 ; i++){
        if(students[i].testScore > max){
            max = students[i].testScore;
        }else if(students[i].testScore == max){
            max = students[i].testScore;
        }
    }
    return max;
}

void membaca_data_siswa(studentType students[]){
    for(int i = 0; i < 20 ; i++){
        cout<< i + 1 <<". "<<"Nama: "<< students[i].studentLName << ", " << students[i].studentFName << endl;
        cout<<"Nilai : "<<students[i].testScore << endl;
        cout<<"Grade : "<<students[i].Grade<<endl; 
    }
}

void siswa_nilai_tertinggi(studentType students[], int max){
    int j = 0;
    for(int i = 0; i < 20 ; i++){
        if(students[i].testScore == max){
            cout<< j + 1 << ". "<< students[i].studentLName << ", "<< students[i].studentFName << endl;
            j++;
        }
    }
}

void menentukan_grade(studentType students[]){
    for(int i = 0 ; i < 20 ; i++){
        if(students[i].testScore <= 100 && students[i].testScore > 80){
            students[i].Grade = 'A';
        }else if(students[i].testScore <= 80 && students[i].testScore > 60){
            students[i].Grade = 'B';
        }else if(students[i].testScore <= 60 && students[i].testScore > 40){
            students[i].Grade = 'C';
        }else if(students[i].testScore <= 40 && students[i].testScore > 20){
            students[i].Grade = 'D';
        }else if(students[i].testScore <= 20 && students[i].testScore >= 0){
            students[i].Grade = 'E';
        }
    }
}

void mengisi(studentType students[]){
    for(int i = 0; i < 20 ; i++){
        cout<<"masukkan nama depan dari siswa ke "<< i + 1 <<": ";
        cin>>students[i].studentFName;
        cout<<"masukkan nama belakang dari siswa: ";
        cin>>students[i].studentLName;
        cout<<"masukkan nilai yang diperoleh dari siswa: ";
        cin>>students[i].testScore;
    }
}