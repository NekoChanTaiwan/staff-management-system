#pragma once
#include "worker.h"
using namespace std;

// �g�z��
class Boss : public Worker {
public:
    // �c�y�禡
    Boss(int id, string name, int deptId);
    // ��ܭӤH�T��
    void showInfo();
    // ���¾�u�^��W��
    string getDeptName();
};
