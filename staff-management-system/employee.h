#pragma once
#include "worker.h"
using namespace std;

// 員工類
class Employee : public Worker {
public:
    // 構造函式
    Employee(int id, string name, int deptId);
    // 顯示個人訊息
    void showInfo();
    // 獲取職工崗位名稱
    string getDeptName();

    // 踩坑注意：這裡不需要重複定義抽象類的變量
};
