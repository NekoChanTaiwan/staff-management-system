#include <iostream>

#include "workerManager.h" // 管理類

#include "worker.h" // 職工抽象類
#include "employee.h" // 員工類
#include "manager.h" // 經理類
#include "boss.h" // 老闆類

using namespace std;

int main() {
    system("title 職工管理系統");

    WorkerManager wm;

    int select = 0; // 用戶輸入

    while (true) {
        wm.showMenu();

        cout << "請輸入選項（0 ~ 7）：";
        cin >> select;

        system("cls");

        switch (select) {
        case 0: // 退出系統
            wm.exitSystem();
            break;
        case 1: // 新增職工
            wm.addEmp();
            break;
        case 2: // 顯示職工
            wm.showEmp();
            break;
        case 3: // 刪除職工
            wm.delEmp();
            break;
        case 4: // 編輯職工
            wm.modEmp();
            break;
        case 5: // 查找職工
            wm.findEmp();
            break;
        case 6: // 排序職工
            wm.sortEmp();
            break;
        case 7: // 清空檔案
            wm.cleanFile();
            break;
        default:
            cout << "請輸入有效數值（0 ~ 7）。" << endl << endl;
            break;
        }

        cout << endl;
        system("pause");
        system("cls");
    }

    return 0;
}