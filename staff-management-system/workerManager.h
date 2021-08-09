#pragma once // 防止標頭檔重複包函
#include <iostream>
#include <fstream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

#define FILENAME "empFile.txt" // 保存的檔案

class WorkerManager {
public:
    // 構造函式
    WorkerManager();

    // 析構函式
    ~WorkerManager();

    // 顯示選單
    void showMenu();

    // 退出系統
    void exitSystem();

    // 保存檔案
    void save();

    // 統計檔案中職工人數
    int getFileEmpNum();

    // 初始化職工陣列指針
    void intEmp();

    // 職工是否存在（存在返回索引值，否則返回 -1）
    int isExist(int id);

    // 新增職工
    void addEmp();

    // 顯示職工
    void showEmp();

    // 刪除職工
    void delEmp();

    // 編輯職工
    void modEmp();

    // 查找職工
    void findEmp();

    // 排序職工
    void sortEmp();

    // 清空檔案
    void cleanFile();

    // 存檔是否為空
    bool m_fileIsEmpty;

    // 紀錄職工人數
    int m_empNum;

    // 職工陣列指針
    Worker** m_empArray;
};