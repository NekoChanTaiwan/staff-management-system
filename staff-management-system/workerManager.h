#pragma once // ������Y�ɭ��ƥ]��
#include <iostream>
#include <fstream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

#define FILENAME "empFile.txt" // �O�s���ɮ�

class WorkerManager {
public:
    // �c�y�禡
    WorkerManager();

    // �R�c�禡
    ~WorkerManager();

    // ��ܿ��
    void showMenu();

    // �h�X�t��
    void exitSystem();

    // �O�s�ɮ�
    void save();

    // �έp�ɮפ�¾�u�H��
    int getFileEmpNum();

    // ��l��¾�u�}�C���w
    void intEmp();

    // ¾�u�O�_�s�b�]�s�b��^���ޭȡA�_�h��^ -1�^
    int isExist(int id);

    // �s�W¾�u
    void addEmp();

    // ���¾�u
    void showEmp();

    // �R��¾�u
    void delEmp();

    // �s��¾�u
    void modEmp();

    // �d��¾�u
    void findEmp();

    // �Ƨ�¾�u
    void sortEmp();

    // �M���ɮ�
    void cleanFile();

    // �s�ɬO�_����
    bool m_fileIsEmpty;

    // ����¾�u�H��
    int m_empNum;

    // ¾�u�}�C���w
    Worker** m_empArray;
};