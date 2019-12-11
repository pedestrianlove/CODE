#include <stdio.h>
#include <string.h>

typedef struct {
	int year;
	int month;
	int date;
}date;
struct quiz {
	int mathGrade;
	int englishGrade;
};
struct student {
	int stdId;
	char name[20];
	date birthday;
	struct quiz grade;
};

int main ()
{
	struct student std1;
	struct student std2 = {1302, "小龍女", {1997, 12, 12}, {65, 88}};
	int sum;
	std1.stdId = 1301;
	strcpy (std1.name, "陳允傑");
	std1.grade.mathGrade = 90;
	std1.grade.englishGrade = 77;
	std1.birthday = std2.birthday;

	// Output
	printf ("學號: %d\n", std1.stdId);
	printf ("生日: %d/%d/%d\n", std1.birthday.year, std1.birthday.month, std1.birthday.date);
	printf ("姓名: %s\n", std1.name);
	sum = std1.grade.mathGrade + std1.grade.englishGrade;
	printf ("成績總分: %d\n", sum);
	printf ("成績平均: %.2f\n", sum/2.0);
	printf ("----------------------\n");
	printf ("學號: %d\n", std2.stdId);
	printf ("生日: %d/%d/%d\n", std2.birthday.year, std2.birthday.month, std2.birthday.date);
	printf ("姓名: %s\n", std2.name);
	sum = std2.grade.mathGrade + std2.grade.englishGrade;
	printf ("成績總分: %d\n", sum);
	printf ("成績平均: %.2f\n", sum/2.0);

	return 0;
}
