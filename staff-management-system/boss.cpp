#include "boss.h"

// �c�y�禡
Boss::Boss(int id, string name, int deptId) {
    this->m_id = id;
    this->m_name = name;
    this->m_deptId = deptId;
}

// ��ܭӤH�T��
void Boss::showInfo() {
    cout << "¾�u�s�� : " << this->m_id
        << "\t¾�u�m�W : " << this->m_name
        << "\t�^�� : " << this->getDeptName()
        << "\t¾�d : �޲z���q�Ҧ��ƪ�" << endl;
}

// ���¾�u�^��W��
string Boss::getDeptName() {
    return string("����");
}
