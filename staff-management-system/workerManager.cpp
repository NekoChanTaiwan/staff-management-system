#include "workerManager.h"

WorkerManager::WorkerManager() {
	ifstream ifs(FILENAME, ios::in); // 讀

	// 檔案不存在
	if (!ifs.is_open()) {
		// cout << "檔案不存在" << endl; // for debug

		this->m_empNum = 0;
		this->m_empArray = NULL;
		this->m_fileIsEmpty = true;

		ifs.close();
		return;
	}

	// 檔案存在，數據為空
	char ch;
	ifs >> ch; // 讀取一個字符
	if (ifs.eof()) { // 判斷是否為空
		// cout << "檔案存在，數據為空" << endl; // for debug

		this->m_empNum = 0;
		this->m_empArray = NULL;
		this->m_fileIsEmpty = true;

		ifs.close();
		return;
	}

	// 檔案存在，數據也存在，保存數據
	int num = this->getFileEmpNum();
	//cout << "職工人數為 : " << num << endl; // for debug
	this->m_empNum = num; // 更新職工人數
	this->m_empArray = new Worker * [num]; // 開闢空間
	this->intEmp(); // 將檔案中的數據，存到 m_empArray

	//for (int i = 0; i < num; i++) {  // for debug
	//	cout << "職工編號 :" << this->m_empArray[i]->m_id
	//		 << " 職工名稱 : " << this->m_empArray[i]->m_name
	//		 << " 職位 : " << this->m_empArray[i]->m_deptId << endl;
	//}
}

WorkerManager::~WorkerManager() {
	if (this->m_empArray != NULL) {
		for (int i = 0; i < this->m_empNum; i++) {
			if (this->m_empArray[i] != NULL) {
				delete this->m_empArray[i];
			}
		}

		delete[] this->m_empArray;
		this->m_empArray = NULL;
	}
}

void WorkerManager::showMenu() {
	cout << "****************************************" << endl;
	cout << "*******  歡迎使用職工管理系統！ ********" << endl;
	cout << "****************************************" << endl;
	cout << "*************  0.退出系統  *************" << endl;
	cout << "*************  1.新增職工  *************" << endl;
	cout << "*************  2.顯示職工  *************" << endl;
	cout << "*************  3.刪除職工  *************" << endl;
	cout << "*************  4.編輯職工  *************" << endl;
	cout << "*************  5.查找職工  *************" << endl;
	cout << "*************  6.編號排序  *************" << endl;
	cout << "*************  7.清空所有  *************" << endl;
	cout << "****************************************" << endl << endl;
}

void WorkerManager::exitSystem() {
	cout << "歡迎再次使用！" << endl << endl;
	system("pause");
	exit(0); // 退出程式
}

void WorkerManager::save() {
	ofstream ofs(FILENAME, ios::out);

	// 將每個人的數據寫入到檔案中
	for (int i = 0; i < this->m_empNum; i++) {
		ofs << this->m_empArray[i]->m_id << " "
			<< this->m_empArray[i]->m_name << " "
			<< this->m_empArray[i]->m_deptId << endl;
	}

	ofs.close();
}

int WorkerManager::getFileEmpNum() {
	ifstream ifs(FILENAME, ios::in); // 讀

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId) {
		num++;
	}

	ifs.close();

	return num;
}

void WorkerManager::intEmp() {
	ifstream ifs(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> dId) {
		Worker* worker = NULL;

		switch (dId) {
		case 1:
			worker = new Employee(id, name, dId);
			break;
		case 2:
			worker = new Manager(id, name, dId);
			break;
		case 3:
			worker = new Boss(id, name, dId);
			break;
		}

		this->m_empArray[index] = worker;

		index++;
	}

	ifs.close();
}

int WorkerManager::isExist(int id) {
	int index = -1;

	if (id < 0) {
		return index;
	}

	for (int i = 0; i < this->m_empNum; i++) {
		if (this->m_empArray[i]->m_id == id) {
			index = i;

			break;
		}
	}

	return index;
}

void WorkerManager::addEmp() {
	int inputAddNum = 1;

	while (true) {
		cout << "請輸入新增職工的數量（-69 返回） : " << endl;
		cin >> inputAddNum;
		cout << endl;

		if (inputAddNum == -69) {
			cout << "返回至主選單。" << endl;
			return;
		}

		if (inputAddNum < 0) {
			cout << "請輸入正確的數量！（大於 0）" << endl << endl;
			continue;
		}

		break;
	}

	// 計算新空間的人數
	int newEmpNum = this->m_empNum + inputAddNum; // 新空間 = 原人數 + 新增人數

	// 開闢新空間
	Worker** newSpace = new Worker* [newEmpNum];

	// 將原來空間下的資料複製到新空間
	if (this->m_empArray != NULL) {
		for (int i = 0; i < this->m_empNum; i++) {
			newSpace[i] = this->m_empArray[i];
		}
	}

	// 批量新增新數據
	for (int i = 0; i < inputAddNum; i++) {
		int id; // 職工編號
		string name; // 職工姓名
		int dSelect; // 部門選擇

		cout << "請輸入第 " << i + 1 << " 位職工的編號：" << endl;
		cin >> id;

		cout << "請輸入第 " << i + 1 << " 位職工的姓名：" << endl;
		cin >> name;

		cout << "請輸入第 " << i + 1 << " 位職工的崗位：" << endl;
		cout << "1. 員工" << endl;
		cout << "2. 經理" << endl;
		cout << "3. 老闆" << endl;
		cin >> dSelect;

		cout << endl;

		Worker* worker = NULL;

		switch (dSelect) {
		case 1:
			worker = new Employee(id, name, dSelect);
			break;
		case 2:
			worker = new Manager(id, name, dSelect);
			break;
		case 3:
			worker = new Boss(id, name, dSelect);
			break;
		}

		// 將創件的職工職責 保存到陣列中
		newSpace[this->m_empNum + i] = worker;
	}

	// 釋放原有空間
	delete[] this->m_empArray;

	// 更改新空間的指向
	this->m_empArray = newSpace;

	// 更新職工人數
	this->m_empNum = newEmpNum;

	// 更新檔案不為空
	this->m_fileIsEmpty = false;

	// 保存數據到檔案中
	this->save();

	cout << "成功新增 " << inputAddNum << " 位職工。" << endl << endl;
}

void WorkerManager::showEmp() {
	if (this->m_fileIsEmpty) {
		cout << "檔案為空" << endl;
	}
	else {
		for (int i = 0; i < this->m_empNum; i++) {
			this->m_empArray[i]->showInfo();
		}
	}
}

void WorkerManager::delEmp() {
	if (this->m_fileIsEmpty) {
		cout << endl << "檔案不存在或數據為空。" << endl;
		return;
	}

	int inputId = 0;
	int index = 0;

	while (true) {
		cout << "請輸入要刪除的職工編號 （-69 返回）: " << endl;
		cin >> inputId;
		cout << endl;

		if (inputId == -69) {
			cout << "返回至主選單。" << endl;
			return;
		}

		index = this->isExist(inputId);

		if (index == -1) {
			cout << "找不到要刪除的職工。" << endl << endl;
			continue;
		}

		break;
	}

	for (int i = index; i < this->m_empNum; i++) {
		this->m_empArray[i] = this->m_empArray[i + 1];
	}

	this->m_empNum--;

	this->save();

	cout << "職員編號 " << inputId << " 刪除成功！" << endl;
}

void WorkerManager::modEmp() {
	if (this->m_fileIsEmpty) {
		cout << endl << "檔案不存在或數據為空。" << endl;
		return;
	}

	int inputId = 0;
	int index = 0;

	while (true) {
		cout << "請輸入要編輯的職工編號 （-69 返回）: " << endl;
		cin >> inputId;
		cout << endl;

		if (inputId == -69) {
			cout << "返回至主選單。" << endl;
			return;
		}

		index = this->isExist(inputId);

		if (index == -1) {
			cout << "找不到要編輯的職工。" << endl << endl;
			continue;
		}

		break;
	}

	delete this->m_empArray[index];

	int id; // 職工編號
	string name; // 職工姓名
	int dSelect; // 部門選擇

	cout << "請輸入新的職工的編號：" << endl;
	cin >> id;

	cout << "請輸入新的職工的姓名：" << endl;
	cin >> name;

	cout << "請輸入新的職工的崗位：" << endl;
	cout << "1. 員工" << endl;
	cout << "2. 經理" << endl;
	cout << "3. 老闆" << endl;
	cin >> dSelect;

	cout << endl;

	Worker* worker = NULL;

	switch (dSelect) {
	case 1:
		worker = new Employee(id, name, dSelect);
		break;
	case 2:
		worker = new Manager(id, name, dSelect);
		break;
	case 3:
		worker = new Boss(id, name, dSelect);
		break;
	}

	this->m_empArray[index] = worker;

	this->save();

	cout << "修改成功！" << endl;
}

void WorkerManager::findEmp() {
	if (this->m_fileIsEmpty) {
		cout << endl << "檔案不存在或數據為空。" << endl;
		return;
	}

	cout << "請輸入要查找的方式：" << endl;
	cout << "1. 編號" << endl;
	cout << "2. 姓名" << endl;

	int select = 0;
	cin >> select;
	cout << endl;

	if (select == 1) { // 編號
		int inputId = 0;
		int index = 0;

		while (true) {
			cout << "請輸入要查找的職工編號 （-69 返回）: " << endl;
			cin >> inputId;
			cout << endl;

			if (inputId == -69) {
				cout << "返回至主選單。" << endl;
				return;
			}

			index = this->isExist(inputId);

			if (index == -1) {
				cout << "找不到要查找的職工。" << endl << endl;
				continue;
			}

			break;
		}

		this->m_empArray[index]->showInfo();
	}
	else if (select == 2) { // 姓名
		string inputName;
		cout << "請輸入要查找的姓名：" << endl;
		cin >> inputName;
		cout << endl;

		bool findFlag = false;

		for (int i = 0; i < this->m_empNum; i++) {
			if (this->m_empArray[i]->m_name == inputName) {
				this->m_empArray[i]->showInfo();
				findFlag = true;
			}
		}

		if (!findFlag) {
			cout << "查無此人。" << endl;
		}

		return;
	}
}

void WorkerManager::sortEmp() {
	if (this->m_fileIsEmpty) {
		cout << endl << "檔案不存在或數據為空。" << endl;
		return;
	}

	cout << "請選擇排序方式：" << endl;
	cout << "1. 編號升序" << endl;
	cout << "2. 編號降序" << endl;

	int select = 0;
	cin >> select;
	cout << endl;

	for (int i = 0; i < this->m_empNum; i++) {
		int minOrMax = i;

		for (int j = i + 1; j < this->m_empNum; j++) {
			if (select == 1) { // 升序
				if (this->m_empArray[minOrMax]->m_id > this->m_empArray[j]->m_id) {
					minOrMax = j;
				}
			}
			else { // 降序
				if (this->m_empArray[minOrMax]->m_id < this->m_empArray[j]->m_id) {
					minOrMax = j;
				}
			}
		}

		if (minOrMax != i) {
			Worker* temp = this->m_empArray[i];
			this->m_empArray[i] = this->m_empArray[minOrMax];
			this->m_empArray[minOrMax] = temp;
		}
	}

	this->save();

	this->showEmp();

	cout << endl << "排序完成！" << endl;
}

void WorkerManager::cleanFile() {
	cout << "確認是否清空？" << endl;
	cout << "1. 確認" << endl;
	cout << "0. 返回" << endl;

	int select = 0;
	cin >> select;
	cout << endl;

	if (select == 0) {
		cout << "返回至主選單。" << endl;
		return;
	}

	ofstream ofs(FILENAME, ios::trunc); // 刪除檔案後重新創建
	ofs.close();

	if (this->m_empArray != NULL) {
		for (int i = 0; i < this->m_empNum; i++) {
			if (this->m_empArray != NULL) {
				delete this->m_empArray[i];
				this->m_empArray[i] = NULL;
			}
		}

		delete[] this->m_empArray;
		this->m_empArray = NULL;
		this->m_empNum = 0;
		this->m_fileIsEmpty = true;
	}

	cout << "清空成功！" << endl;
}