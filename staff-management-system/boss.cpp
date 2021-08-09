#include "boss.h"

// 構造函式
Boss::Boss(int id, string name, int deptId) {
    this->m_id = id;
    this->m_name = name;
    this->m_deptId = deptId;
}

// 顯示個人訊息
void Boss::showInfo() {
    cout << "職工編號 : " << this->m_id
        << "\t職工姓名 : " << this->m_name
        << "\t崗位 : " << this->getDeptName()
        << "\t職責 : 管理公司所有事物" << endl;
}

// 獲取職工崗位名稱
string Boss::getDeptName() {
    return string("老闆");
}
