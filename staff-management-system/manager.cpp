#include "manager.h"

// �c�y�禡
Manager::Manager(int id, string name, int deptId) {
    this->m_id = id;
    this->m_name = name;
    this->m_deptId = deptId;
}

// ��ܭӤH�T��
void Manager::showInfo() {
    cout << "¾�u�s�� : " << this->m_id
        << "\t¾�u�m�W : " << this->m_name
        << "\t�^�� : " << this->getDeptName()
        << "\t¾�d : ��������浹�����ȡA�åB�U�o���ȵ����u" << endl;
}

// ���¾�u�^��W��
string Manager::getDeptName() {
    return string("�g�z");
}
