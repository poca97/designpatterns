#include<iostream>
#include"Observer.h"
using namespace std;
int main() {
	// Định nghĩa: Observer là design pattern dùng để tạo ra mối quan hệ 1-n giữa các đối tượng 
	//,khi một đối tượng thay đổi trạng thái, tất cả các phụ thuộc của nó sẽ được thông báo và cập nhật tự động.

	Database db;
	Developer dev;
	Boss boss;
	db.registerObserver(&dev);
	db.registerObserver(&boss);
	// Thay đổi thông tin(xóa)
	db.editRecord("delete", "database 1");
	// Sau khi thay đổi thông tin(xóa) database 1 thì server sẽ lập tức gửi những thay đổi đó cho Boss biết
	system("pause");
	return 0;
}