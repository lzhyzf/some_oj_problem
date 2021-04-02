#include <stdio.h>
#include <stdlib.h>

struct student
{ char number[9];
  char name[10];
  float subject1, subject2, subject3, ave, sum;
}stu[5];

int main()
{ int i,j,max=0, cnt;

  for(i=0;i<5;i++){
    scanf("%s%s%f%f%f",stu[i].number,stu[i].name,&stu[i].subject1,&stu[i].subject2,&stu[i].subject3);
    stu[i].sum = stu[i].subject1 + stu[i].subject2 + stu[i].subject3;
    stu[i].ave = stu[i].sum / 3;
    if(max < stu[i].sum) { max = stu[i].sum; cnt = i;}
  }
  printf("姓名 总分 平均成绩\n");
  for(i=0;i<5;i++)
    printf("%s %f. %.1f\n",stu[i].name,stu[i].sum,stu[i].ave);
    printf("总分数最高的学生信息如下：\n");
    printf("%s %s %.f %.f %.f\n",stu[cnt].number,stu[cnt].name,stu[cnt].subject1,stu[cnt].subject2,stu[cnt].subject3);
    return 0;
}
