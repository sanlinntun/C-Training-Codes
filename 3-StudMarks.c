#include <stdio.h>

char findGrade(int total_marks);
int subjMarks();

// Create the student structure
struct Student {
    int stud_roll; //student's roll number
    char stud_ftname[50]; //student's first name
    int s1, s2, s3, s4, s5, s6, total_marks;
    int id;
}s[100];

int main() {

    int numStudents = 0;
    char grade; // student's grade
    
    printf("Enter Information of Students.\n");

    printf("Enter the number of Students: ");
    scanf("%d", &numStudents);

    // Input marks for each student
    for (int i = 0; i < numStudents; i++) {

        printf("Enter the student roll number : ");
        scanf("%d", &s[i].stud_roll);

        printf("Enter the student Name : ");
        scanf("%s", &s[i].stud_ftname);

        printf("\n****************************************************\n\n");

        printf("Information of Student Record.\n");

        printf("The student roll number is %d. \n", s[i].stud_roll);
        printf("The student name is %s. \n", s[i].stud_ftname);

        // total subjects' marks
        int total = subjMarks();
        printf("%s got a total of %d marks in 6 Subjects. \n", s[i].stud_ftname, total);

        // find grade
        grade = findGrade(total);

        // display grade
        if(grade=='\0'){
            printf("Invalid! \n");
        }
        else{
            printf("%s's grade is %c. \n", s[i].stud_ftname, grade);
        }
        
        printf("\n#####################################################\n\n");

    }

    return 0;
}

int subjMarks(){

    // int s1, s2, s3, s4, s5, s6 = 0;
    printf("Enter marks obtained in 6 subjects: ");
    scanf("%d %d %d %d %d %d", &s[0].s1, &s[0].s2, &s[0].s3, &s[0].s4, &s[0].s5, &s[0].s6);
    // int total_marks = s1 + s2 + s3 + s4 + s5 + s6;

    s[0].total_marks = s[0].s1 + s[0].s2 + s[0].s3 + s[0].s4 + s[0].s5 + s[0].s6; 
    
}

char findGrade(int total_marks){
    if(total_marks<0) {
     return '\0';
    }

    if(total_marks >= 80){
        return'D'; // Destination
    }
    else if(total_marks >= 70 && total_marks < 80){
        return'M'; // Merit
    }
    else if(total_marks >= 40 && total_marks < 69){
        return 'P'; // Pass
    }
    else{
        return 'R'; // Retake
    }
                    
}