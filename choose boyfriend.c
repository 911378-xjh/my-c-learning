/*小丽选择男朋友的标准有两个：成绩和身高。
首先选择成绩最高的男生，如果有多个男生成绩最高则选择其中身高最高的男生（假设这样的学生是唯一的）。
请你帮她完成该任务。

输入格式:
输入整数n（n小于20），然后输入n个男生信息，包含：
姓名（长度不超过10）
身高（数值在int范围内）
成绩（数值在int范围内）

输出格式:
输出成绩最高的学生，如果有多个男生成绩最高则输出其中身高最高的男生。
信息包括：姓名 身高 成绩，各个信息之间空格隔开。

输入样例:
3
zhang3 185 90
li4 188 60
wang5 175 90
输出样例:
zhang3 185 90
*/
#include <stdio.h>
#include <string.h>
int main()
{
    //定义结构体
    struct student{
        char name[10];
        int height;
        int score;
    };
    int n;
    scanf("%d", &n);
    struct student boys[n];
//循环输入结构体各成员的各项数值
    for(int i = 0; i < n; i++){
        scanf("%s %d %d", boys[i].name, &boys[i].height, &boys[i].score);
    }
//假设最优秀的男生为结构体数组的的第一个，即首个元素
   int best_index = 0;
//遍历数组的每个元素，与第一个假设的男生比较，如果找到更优秀的，就更新best_index的数值
   for(int i = 1; i < n; i++){
    if(boys[i].score > boys[best_index].score){
        best_index = i;
    }else if(boys[i].score == boys[best_index].score){
//如果成绩相同就比较身高，再根据情况更新best_index的数值
        if(boys[i].height > boys[best_index].height){
            best_index = i;
        }
    }
   }
//输出
   printf("%s %d %d", boys[best_index].name, boys[best_index].height, boys[best_index].score);
   return 0;
}