#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student
{
    int roll;
    char name[50];
    float cgpa;
};

void addStudent();
void viewStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

int main()
{
    int choice;

    while(1)
    {
        printf("\n========== STUDENT MANAGEMENT SYSTEM ==========\n");

        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                viewStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
void addStudent()
{
    FILE *fp;

    struct Student s;

    fp = fopen("students.dat","ab");

    if(fp==NULL)
    {
        printf("File Error\n");
        return;
    }

    printf("Enter Roll Number: ");
    scanf("%d",&s.roll);

    printf("Enter Name: ");
    scanf(" %[^\n]",s.name);

    printf("Enter CGPA: ");
    scanf("%f",&s.cgpa);

    fwrite(&s,sizeof(struct Student),1,fp);

    fclose(fp);

    printf("Student Added Successfully\n");
}
void viewStudents()
{
    FILE *fp;

    struct Student s;

    fp = fopen("students.dat","rb");

    if(fp==NULL)
    {
        printf("No Records Found\n");
        return;
    }

    printf("\nROLL\tNAME\t\tCGPA\n");

    while(fread(&s,sizeof(struct Student),1,fp))
    {
        printf("%d\t%s\t\t%.2f\n",
               s.roll,
               s.name,
               s.cgpa);
    }

    fclose(fp);
}
void searchStudent()
{
    FILE *fp;

    struct Student s;

    int roll;
    int found=0;

    printf("Enter Roll Number: ");
    scanf("%d",&roll);

    fp=fopen("students.dat","rb");

    if(fp==NULL)
    {
        printf("File Not Found\n");
        return;
    }

    while(fread(&s,sizeof(struct Student),1,fp))
    {
        if(s.roll==roll)
        {
            printf("\nRecord Found\n");

            printf("Roll : %d\n",s.roll);
            printf("Name : %s\n",s.name);
            printf("CGPA : %.2f\n",s.cgpa);

            found=1;
            break;
        }
    }

    if(found==0)
    {
        printf("Record Not Found\n");
    }

    fclose(fp);
}
void deleteStudent()
{
    FILE *fp,*temp;

    struct Student s;

    int roll;
    int found=0;

    printf("Enter Roll Number To Delete: ");
    scanf("%d",&roll);

    fp=fopen("students.dat","rb");

    temp=fopen("temp.dat","wb");

    while(fread(&s,sizeof(struct Student),1,fp))
    {
        if(s.roll==roll)
        {
            found=1;
        }
        else
        {
            fwrite(&s,sizeof(struct Student),1,temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("students.dat");

    rename("temp.dat","students.dat");

    if(found)
        printf("Record Deleted Successfully\n");
    else
        printf("Record Not Found\n");
}
void updateStudent()
{
    FILE *fp,*temp;

    struct Student s;

    int roll;
    int found=0;

    printf("Enter Roll Number To Update: ");
    scanf("%d",&roll);

    fp=fopen("students.dat","rb");

    temp=fopen("temp.dat","wb");

    while(fread(&s,sizeof(struct Student),1,fp))
    {
        if(s.roll==roll)
        {
            found=1;

            printf("Enter New Name: ");
            scanf(" %[^\n]",s.name);

            printf("Enter New CGPA: ");
            scanf("%f",&s.cgpa);
        }

        fwrite(&s,sizeof(struct Student),1,temp);
    }

    fclose(fp);
    fclose(temp);

    remove("students.dat");

    rename("temp.dat","students.dat");

    if(found)
        printf("Record Updated Successfully\n");
    else
        printf("Record Not Found\n");
}
