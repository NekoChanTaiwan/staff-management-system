#pragma once
#include "worker.h"
using namespace std;

// ���u��
class Employee : public Worker {
public:
    // �c�y�禡
    Employee(int id, string name, int deptId);
    // ��ܭӤH�T��
    void showInfo();
    // ���¾�u�^��W��
    string getDeptName();

    // ��|�`�N�G�o�̤��ݭn���Ʃw�q��H�����ܶq
};
