#include"stdlib.h"
#include "stdio.h"

typedef struct{
    int adm;
    char name;
    float gpa;
} student;
void print_std_info(student *std);


int main(){
student std1;
std1.adm = 10;
std1.name ='C';
std1.gpa= 3.9;

student *pStudent = &std1;

print_std_info(pStudent);


}


void print_std_info(student *std){
printf("%d \n", std->adm);
printf("%c \n", std->name);
printf("%f \n", std->gpa);

}