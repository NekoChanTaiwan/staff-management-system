#include "employee.h"

// �c�y�禡
Employee::Employee(int id, string name, int deptId) {
    this->m_id = id;
    this->m_name = name;
    this->m_deptId = deptId;
}

// ��ܭӤH�T��
void Employee::showInfo() {
    cout << "¾�u�s�� : " << this->m_id
         << "\t¾�u�m�W : " << this->m_name
         << "\t�^�� : " << this->getDeptName()
         << "\t¾�d : �����g�z�浹������" << endl;
}

// ���¾�u�^��W��
string Employee::getDeptName() {
    return string("���u");
}
