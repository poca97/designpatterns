#pragma once
#include<string>
#include<iostream>
#include<vector>
using namespace std;
class IObserver;
class ISubject
{
public:
	virtual void registerObserver(IObserver*) = 0;
	virtual void removeObserver(IObserver*) = 0;
	virtual void notifyObservers() = 0;
};
 // Tạo observer interface
class IObserver
{
public:
	virtual void update(string operation, string record) = 0;
};

// Tạo subject class
// Subject phải cho phép các observer có thể đăng ký và nhận thông báo khi có sự kiện xảy ra
class Database : public ISubject
{
private:
	vector<IObserver*> mObservers;
	string mOperation;
	string mRecord;
public:
	Database() {
	}
	// Đăng ký observer nhận thông báo từ server
	void registerObserver(IObserver*);

	// Khi muốn xóa một observer đã đăng ký thì tìm pointer của observer đó trong mObservers và xóa nó đi
	void removeObserver(IObserver*);
	// Thay đổi thông tin các observer
	void editRecord(string, string);

	// Thông báo những thay đổi của observer
	void notifyObservers();
};
class Developer : public IObserver
{
public:
	Developer(){
	}
	void update(string, string);
};

class Boss : public IObserver
{
public:
	Boss() {
	}
	void update(string, string);
};