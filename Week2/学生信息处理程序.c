// week2_005.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
//#pragma warning(disable: 4996)
#include <iostream>
using namespace std;
#include <string>
#include<cstring>
#include <cstdio>
#include <cstdlib>
class Student
{
private:
	char name[20];
	int id;
	int age;
	int score[4];
	double average;
public:
	void input() {
		char buf[200];
		cin.getline(buf, 200);//好几次数组越界，但是VS判不出来……
		char *p = strtok(buf, ",");
		strcpy(name,p);
		p = strtok(NULL, ",");
		age = atoi(p);
		p = strtok(NULL, ",");
		id = atoi(p);
		for (int i = 0; i < 4; i++)
		{
			p = strtok(NULL, ",");
			score[i] = atoi(p);
		}
		}
	void calculate() {
		double sum=0;
		for (int i = 0; i < 4; i++)
		{
			sum += score[i];
		}
		average = sum / 4;
	}
	void output() {
		cout << name << "," << age << "," << id << "," << average << endl;
	}
};
int main() {
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
}

