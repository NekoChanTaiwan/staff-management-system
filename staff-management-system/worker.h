#pragma once
#include <iostream>
using namespace std;

class Worker {
public:
    // ��ܭӤH�T��
    virtual void showInfo() = 0;
    // ���¾�u�^��W��
    virtual string getDeptName() = 0;

    // ¾�u�s��
    int m_id = 0;
    // ¾�u�m�W
    string m_name;
    // �����s��
    int m_deptId = 0;
};