#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <set>
#include <algorithm>
#include <deque>
#include <iomanip>
#include "competitor.h"
using namespace std;

#define COMPETITOELISTPATH "competitorList.txt"

class speechManager
{
private:
    vector<int> vPreContest;    // 参赛人员名单
    vector<int> vFirstGroup;    // 第一轮第一组人员名单
    vector<int> vSecondGroup;   // 第一轮第二组人员名单
    vector<int> vIntermediaryHeat;  // 第二轮人员名单
    vector<int> vVictory;   // 最终获胜人员名单
    map<int, Competitor> mSpeaker;  // 存放参赛ID和人员信息
    int competitorNum;  // 参赛人数
    int turn;   // 比赛轮次
    bool fileIsEmpty;   // 存放数据文件是否为空
    map<int, vector<string> > m_Record;     // 存放从文件读取的数据

    void getCompetitorNum();    // 获取参赛人数
    void test();
    void initSys(); // 系统初始化
    void createCompetitor();    // 创建安参赛员工
    void drawLosts();   // 第一轮比赛抽签
    void getKeyboard(); // 等待键盘输入
    double computeScore(); // 计算得分
    void giveAMark(vector<int> & vCP);  // 打分
    void printResult(vector<int> & vCP);    // 打印成绩
    void printCompetitorId(vector<int> & vCP);  // 打印参赛选手ID
    void promoted(vector<int> & contestant, vector<int> & vV);  // 晋级
    void writeCSV();    // 写入本地文件保存

public:
    speechManager(/* args */);
    void showMenu();
    void exitSys();
    void startCompetition();
    void loadRecord();
    void clearFile();
    ~speechManager();
};

// 创建仿函数用于排序
class MyCompare
{
public:
    bool operator()(const Competitor &p1, const Competitor &p2)
    {
        return p1.score > p2.score;
    }
};


