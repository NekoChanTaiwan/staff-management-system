#pragma once
#include "worker.h"
using namespace std;

// 經理類
class Boss : public Worker {
public:
    // 構造函式
    Boss(int id, string name, int deptId);
    // 顯示個人訊息
    void showInfo();
    // 獲取職工崗位名稱
    string getDeptName();
};
