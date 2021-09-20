#include <iostream>
#include<iomanip>
#include <stdlib.h>
#include<fstream>

using namespace std;

void GPA_Transcript_Console(double GPA, int subjects, string subname[], double marks[], double credithours[], string grade[])
{
    cout << endl;
    cout <<  setw(65) << right << "TRANSCRIPT " << endl;
    cout << endl;
    cout << "\t\t  " << left << setw(20) <<"SUBJECT\t" << left << setw(20) << "MARKS" << left << setw(25) << "CREDIT HOURS " << left << setw(25) << "Grade" << endl;

    for (int index =0; index < subjects; index++)
        cout << "\t\t  " << left << setw(27) << subname[index] << left << setw(25) << marks[index]  << left << setw(21) << credithours[index] << left << setw(25) << grade[index] << endl;

    cout << endl;
    cout << endl;
    cout <<"GPA = " << fixed << setprecision(2) << GPA << endl;

    //STATUS CHECKS
    if (GPA<2.00 && GPA>=1.70)
        cout << "Status : Probation" << endl;

    else if (GPA>=2.00 )
        cout << "Status : Congrats you are Passed" << endl;
    else if (GPA<1.70 )
        cout << "Status : Fail. Better luck next time" << endl;

    cout << endl;

}

void GPA_Transcript_File(string rollno, string name, int semester, double GPA, int subjects, string subname[], double marks[], double credithours[], string grade[])
{
    string file = rollno + "_gpa.rtf";
    ofstream gpa_file(file.c_str(), ios::app);

    gpa_file << left << "Name: " << name << "\t\t\t\t\t\t" << left << "Roll no: " << rollno << endl << endl;

    gpa_file <<  setw(45) << right << "TRANSCRIPT SEMESTER " << semester << endl;
    gpa_file << "-------------------------------------------------------------------------" << endl;

    gpa_file << left << setw(25) <<"SUBJECT\t" << left << setw(15) << "MARKS" << left << setw(24) << "CREDIT HOURS " << left << setw(10) << "Grade" << endl;
    gpa_file << "-------------------------------------------------------------------------"<< endl;

    for (int index =0; index<subjects; index++)
    {
        gpa_file << left << setw(30) << subname[index] << left << setw(18) << marks[index]  << left << setw(21) << credithours[index] << left << setw(10) << grade[index] << endl;

    }
    gpa_file << "-------------------------------------------------------------------------" << endl;
    gpa_file <<"GPA = " << fixed << setprecision(2) << GPA << endl;

    if (GPA<2.00 && GPA>=1.70)
        gpa_file << "Status: Probation" << endl;

    else if (GPA>=2.00 )
        gpa_file << "Status: Congrats you are Passed" << endl;

    else if (GPA<1.70 )
        gpa_file << "Status: Fail. Better luck next time" << endl;

    gpa_file << "-------------------------------------------------------------------------" << endl << endl << endl;
    gpa_file.close();


}

void GPA()
{
    double sumch, sumqp,qualitypoints,GPA; // marks= marks, credithours= credit hours, subjects= no of subjects, sumch = sum credit hours, qualitypoints = quality points, sumqp = sum quality points
    int subjects, index=0;
    int want;
    string name, rollno;
    int semester;

    cout << "Do you want to save your transcript?\n\t.1 for YES\n\t.2 for NO\nEnter : ";
    cin >> want;
    if (want == 1)
    {

        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter your roll no: ";
        getline(cin, rollno);
        cout << endl;
        cout << "Enter your Semester: ";
        cin >> semester;
        cout << endl;

    }

    cout << "Enter No of Subjects : ";
    cin >> left >> subjects;

    string subname[subjects];
    double marks[subjects];
    double credithours[subjects];
    string grade[subjects];
    cout << endl;

    sumch = 0; // sumch = sum credit hours
    sumqp = 0; // sumqp = sum quality points

    for(index = 0; index < subjects; index++)
    {
        cout << "Enter subject name : ";
        cin.ignore();
        getline(cin,subname[index]);
        cout << "Enter Marks of " << subname[index] << ": ";
        cin >> left >> marks[index];
        cout << "Credit Hours of " << subname[index] << ": ";
        cin >> left >> credithours[index];
        cout << endl;

        sumch = sumch + credithours[index]; //sumch = sum credit hours,

        if (marks[index]<=100 && marks[index]>=85){
            qualitypoints = 4 * credithours[index];
            grade[index] = "A";
        }

        else if (marks[index]<85 && marks[index]>=80){
            qualitypoints = 3.70 * credithours[index];
            grade[index] = "A-";
        }

        else if (marks[index]<80 && marks[index]>=75){
            qualitypoints = 3.30 * credithours[index];
            grade[index] = "B+";
        }

        else if (marks[index]<75 && marks[index]>=70){
            qualitypoints = 3.00 * credithours[index];
            grade[index] = "B";
        }

        else if (marks[index]<70 && marks[index]>=65){
            qualitypoints = 2.70 * credithours[index];
            grade[index] = "B-";
        }

        else if (marks[index]<65 && marks[index]>=61){
            qualitypoints = 2.30 * credithours[index];
            grade[index] = "C+";
        }

        else if (marks[index]<61 && marks[index]>=58){
            qualitypoints = 2.00 * credithours[index];
            grade[index] = "C";
        }

        else if (marks[index]<58 && marks[index]>=55){
            qualitypoints = 1.70 * credithours[index];
            grade[index] = "C-";
        }

        else if (marks[index]<55 && marks[index]>=50){
            qualitypoints = 1.00 * credithours[index];
            grade[index] = "D";
        }

        else if (marks[index]<50 && marks[index]>=0){
            qualitypoints = 0.00 * credithours[index];
            grade[index] = "F";
        }


        sumqp = sumqp + qualitypoints; // sumqp = sum quality points
    }

    GPA = sumqp / sumch; // Gpa = sum quality points / sum credit hours.


    GPA_Transcript_Console(GPA, subjects,subname, marks, credithours, grade);
    // FOR SAVING TRANSCRIPT IN A FILE
    if(want == 1)
    {
        GPA_Transcript_File(rollno,name,semester,GPA, subjects,subname, marks, credithours, grade);
    }


}

void CGPA_Transcript_Console(double CGPA, int semesters, double gpa[], double credithours[], string grade2)
{
    cout << endl;
    cout << "\t\t\t\t TRANSCRIPT " << endl << endl;
    cout << "\t\tSEMESTER\t GPA\t\t  CREDIT HOURS " << endl;

    for (int index =1; index<=semesters; index++)
        cout << "  \t\t  " << index << "\t\t " << gpa[index] << "\t\t\t " << credithours[index] << endl;

    cout << endl << endl;
    cout << fixed << setprecision(2) << "Your CGPA is : " << CGPA << endl;

    cout << "Your Grade is ' " << grade2 << " '" << endl;

    //STATUS CHECKS
    if (CGPA<2.00 && CGPA>=1.70)
        cout << "Status : Probation" << endl;

    else if (CGPA>=2.00 )
        cout << "Status : Congrats you are Passed" << endl;

    else if (CGPA<1.70 )
        cout << "Status : Fail. Better luck next time" << endl;

    cout << endl;

}

void CGPA_Transcript_File(string rollno, string name, int semesters, double gpa[], double credithours[], string grade2, double CGPA)
{
    string file = rollno + "_cgpa.rtf";
    ofstream cgpa_file(file.c_str(), ios::app);

    cgpa_file << left << "Name: " << name << "\t\t\t\t\t\t" << left << "Roll no: " << rollno << endl << endl;
    cgpa_file <<  setw(44) << right << "TRANSCRIPT "<< endl;
    cgpa_file << "-------------------------------------------------------------------------" << endl;
    cgpa_file << setw(30) << left << "SEMESTER" << setw(25) << left << "GPA" << left << "CREDIT HOURS " << endl;
    cgpa_file << "-------------------------------------------------------------------------" << endl;
    for (int index =1; index<=semesters; index++)
    {
        cgpa_file << "   " << setw(27) << left << index << setw(30) << left << gpa[index] << credithours[index] << endl;

    }
    cgpa_file << "-------------------------------------------------------------------------" << endl;
    cgpa_file << fixed << setprecision(2) << "Your CGPA is: " << CGPA << endl;
    cgpa_file << "Your Grade is ' " << grade2 << " '" << endl;

    // STATUS CHECKS
    if (CGPA<2.00 && CGPA>=1.70)
        cgpa_file << "Status: Probation" << endl;

    else if (CGPA>=2.00 )

        cgpa_file << "Status: Congrats you are Passed" << endl;

    else if (CGPA<1.70 )

        cgpa_file << "Status: Fail. Better luck next time" << endl;

    cgpa_file << "-------------------------------------------------------------------------" << endl << endl << endl;
    cgpa_file.close();

}

void CGPA()
{
    string grade2;
    double sumcredithours, sumGPA, CGPA;
    int  semesters, index=1;
    sumcredithours = 0;
    sumGPA = 0;


    int want;
    string name, rollno;

    cout << "Do you want to save your transcript?\n\t.1 for YES\n\t.2 for NO\nEnter : ";
    cin >> want;
    if (want == 1)
    {

        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter your roll no: ";
        getline(cin, rollno);
        cout << endl;
    }


    cout << "Enter no of semesters : ";
    cin >> left >> semesters;

    double  credithours[semesters];
    double  gpa[semesters];
    cout << endl;

    while (index <= semesters)
    {
        cout << "Enter GPA semester " << index << " : ";
        cin >> gpa[index];
        cout << "Enter Credit Hours semester " << index << " : ";
        cin >> credithours[index];
        cout <<  endl;
        sumcredithours = sumcredithours + credithours[index];
        sumGPA = sumGPA + (gpa[index]*credithours[index]);
        index ++;
    }
    CGPA = sumGPA / sumcredithours;

    // TRANSCRIPT

    if(CGPA>=0.00 && CGPA<=0.99)
        grade2 = "F";
    else if(CGPA>=1.00 && CGPA<=1.69)
        grade2 = "D";
    else if(CGPA>=1.70 && CGPA<=1.99)
        grade2 = "C-";
    else if(CGPA>=2.00 && CGPA<=2.29)
        grade2 = "C";
    else if(CGPA>=2.30 && CGPA<=2.69)
        grade2 = "C+";
    else if(CGPA>=2.70 && CGPA<=2.99)
        grade2 = "B-";
    else if(CGPA>=3.00 && CGPA<=3.29)
        grade2 = "B";
    else if(CGPA>=3.30 && CGPA<=3.69)
        grade2 = "B+";
    else if(CGPA>=3.70 && CGPA<=3.99)
        grade2 = "A-";
    else if(CGPA>=4.00)
        grade2 = "A";

    CGPA_Transcript_Console(CGPA, semesters, gpa, credithours, grade2);

    // FOR SAVING TRANSCRIPT IN A FILE
    if(want == 1)
    {
        CGPA_Transcript_File(rollno, name, semesters,gpa, credithours,grade2,CGPA);
    }

}

void welcome()
{
    cout << "\t\t\t\tGPA / CGPA CALCULATOR WITH TRANSCRIPT" << endl << endl;
}

int main()
{

    int cal = 100;

    while (cal != 99)
    {
        welcome();
        cout << "Select An Option Form Menu Below : " << endl;
        cout << "\t1. GPA\n\t2. CGPA\n\t99.QUIT\n";
        cout << "Enter: ";
        cin >> cal;
        cout << endl;

        if (cal == 1)
            GPA();
        else if(cal == 2)
            CGPA();
        else if(cal == 99)
            break;
        else
            cout << "Invalid Input Please Enter From options. " << endl;

        system ("pause");
        system("cls");

    }
    cout << "-------------- " << endl;
    cout << "PROGRAM ENDED  " << endl;
    cout << "-------------- " << endl;
    cout << "Developed by Muhammad Yasir" << endl << endl;



    return 0;
}
