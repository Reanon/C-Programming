// week3_014.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
#define WARRIOR_NUM 5
/*
char * CWarrior::names[WARRIOR_NUM] = { "dragon","ninja","iceman","lion","wolf" };
红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序制造武士。
蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序制造武士。
*/
class CHeadquarter;
class CWarrior
{
private:
	CHeadquarter * pHeadquarter;
	int kindNo; //武士的种类编号 0 dragon 1 ninja 2 iceman 3 lion 4 wolf
	int nNo;	//该阵营的第几个战士
public:
	static char * names[WARRIOR_NUM];		  //输入生命值的顺序 d、n、i、l、w
	static int InitialLifeValue[WARRIOR_NUM]; // 每个武士的初始生命值
	CWarrior(CHeadquarter * p, int nNo_, int kindNo_);
	void PrintResult(int nTime);              //打印生成战士的信息
};
class CHeadquarter  //大本营
{
private:
	int totalLifeValue;
	bool bStopped;       //判断是否停止制造武士
	int totalWarriorNum; //总武士数量
	int color;			 //；不同大本营的颜色
	int curMakingSeqIdx; //当前要制造的武士是制造序列中的第几个
	int warriorNum[WARRIOR_NUM]; //存放每种武士的数量
	CWarrior * pWarriors[1000];
public:
	friend class CWarrior;
	static int makingSeq[2][WARRIOR_NUM]; //武士的制作顺序序列，全局变量初始化
	void Init(int color_, int lv);        //初始化某大本营的总生命值、停止标志设为false、从一个序号开始制作士兵、将该大本营的全部种类士兵设为0。
	~CHeadquarter();					  //当大本营解散时，释放所有士兵所占用的空间。
	int Produce(int nTime);				  //生成武士
	void GetColor(char * szColor);        //初始化该大本营的颜色
};

void CWarrior::PrintResult(int nTime)
{
	char szColor[20];
	pHeadquarter->GetColor(szColor);
	printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n", //03d:用0补齐;
		nTime, szColor, names[kindNo], nNo, InitialLifeValue[kindNo],
		pHeadquarter->warriorNum[kindNo], names[kindNo], szColor);
}


int CWarrior::InitialLifeValue[WARRIOR_NUM];
char * CWarrior::names[WARRIOR_NUM] = { "dragon","ninja","iceman","lion","wolf" };
CWarrior::CWarrior(CHeadquarter * p, int nNo_, int kindNo_) :nNo(nNo_), kindNo(kindNo_), pHeadquarter(p) { }
int CHeadquarter::makingSeq[2][WARRIOR_NUM] = { { 2,3,4,1,0 },{ 3,0,1,2,4 } }; //两个司令部武士的制作顺序序列
void CHeadquarter::Init(int color_, int lv) //初始化某大本营的总生命值、停止标志设为false、从一个序号开始制作士兵、将该大本营的全部种类士兵设为0。
{
	color = color_;
	totalLifeValue = lv;
	totalWarriorNum = 0;
	bStopped = false;
	curMakingSeqIdx = 0;
	for (int i = 0; i < WARRIOR_NUM; i++)
		warriorNum[i] = 0;
}
CHeadquarter::~CHeadquarter() //当大本营解散时，释放所有士兵所占用的空间。
{        
	for (int i = 0; i < totalWarriorNum; i++)  
		delete pWarriors[i];
}   
void CHeadquarter::GetColor(char * szColor)
{
	if (color == 0)
		strcpy(szColor, "red");
	else
		strcpy(szColor, "blue");
}
int CHeadquarter::Produce(int nTime)
{
	if (bStopped)
		return 0;
	int nSearchingTimes = 0;             //该生成的武士序列
	while (CWarrior::InitialLifeValue[makingSeq[color][curMakingSeqIdx]] > totalLifeValue &&
		nSearchingTimes < WARRIOR_NUM) {
		curMakingSeqIdx = (curMakingSeqIdx + 1) % WARRIOR_NUM; //使curMakingSeqIdx不超出序列范围
		nSearchingTimes++;
	}

	int kindNo = makingSeq[color][curMakingSeqIdx];
	if (CWarrior::InitialLifeValue[kindNo] > totalLifeValue) { // 剩余生命值不足以制作武士
		bStopped = true;
		if (color == 0)
			printf("%03d red headquarter stops making warriors\n", nTime);
		else
			printf("%03d blue headquarter stops making warriors\n", nTime);
		return 0;
	}
	totalLifeValue -= CWarrior::InitialLifeValue[kindNo];
	curMakingSeqIdx = (curMakingSeqIdx + 1) % WARRIOR_NUM;
	pWarriors[totalWarriorNum] = new CWarrior(this, totalWarriorNum + 1, kindNo);
	warriorNum[kindNo]++;
	pWarriors[totalWarriorNum]->PrintResult(nTime);
	totalWarriorNum++;
	return 1;
}



int main()
{
	int t;
	int m;
	CHeadquarter RedHead, BlueHead;
	scanf("%d", &t);
	int nCaseNo = 1;
	while (t--) {
		printf("Case:%d\n", nCaseNo++);
		scanf("%d", &m);
		for (int i = 0; i < WARRIOR_NUM; i++)
			scanf("%d", &CWarrior::InitialLifeValue[i]);
		RedHead.Init(0, m);
		BlueHead.Init(1, m);
		int nTime = 0;      //事件的开始时间
		while (true) {
			int tmp1 = RedHead.Produce(nTime); //某一大本营停止制造武士返回值就设为0
			int tmp2 = BlueHead.Produce(nTime);
			if (tmp1 == 0 && tmp2 == 0)
				break;
			nTime++;
		}
	}
	return 0;
}

