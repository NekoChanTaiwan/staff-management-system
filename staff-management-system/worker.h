#pragma once
#include <iostream>
using namespace std;

class Worker {
public:
    // 顯示個人訊息
    virtual void showInfo() = 0;
    // 獲取職工崗位名稱
    virtual string getDeptName() = 0;

    // 職工編號
    int m_id = 0;
    // 職工姓名
    string m_name;
    // 部門編號
    int m_deptId = 0;
};