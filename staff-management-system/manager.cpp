#include "manager.h"

// 構造函式
Manager::Manager(int id, string name, int deptId) {
    this->m_id = id;
    this->m_name = name;
    this->m_deptId = deptId;
}

// 顯示個人訊息
void Manager::showInfo() {
    cout << "職工編號 : " << this->m_id
        << "\t職工姓名 : " << this->m_name
        << "\t崗位 : " << this->getDeptName()
        << "\t職責 : 完成老闆交給的任務，並且下發任務給員工" << endl;
}

// 獲取職工崗位名稱
string Manager::getDeptName() {
    return string("經理");
}
