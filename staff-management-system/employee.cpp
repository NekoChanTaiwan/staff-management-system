#include "employee.h"

// 構造函式
Employee::Employee(int id, string name, int deptId) {
    this->m_id = id;
    this->m_name = name;
    this->m_deptId = deptId;
}

// 顯示個人訊息
void Employee::showInfo() {
    cout << "職工編號 : " << this->m_id
         << "\t職工姓名 : " << this->m_name
         << "\t崗位 : " << this->getDeptName()
         << "\t職責 : 完成經理交給的任務" << endl;
}

// 獲取職工崗位名稱
string Employee::getDeptName() {
    return string("員工");
}
