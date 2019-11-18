#include "Observer.h"

void Database::registerObserver(IObserver* o)
{
	mObservers.push_back(o);
}

void Database::removeObserver(IObserver* o)
{
	auto observer = find(mObservers.begin(), mObservers.end(), o);
	if (observer != mObservers.end()) {
		mObservers.erase(observer, observer + 1); // xóa observer từ mObservers
	}
}

void Database::editRecord(string operation, string record)
{
	mOperation = operation;
	mRecord = record;
	notifyObservers();
}

void Database::notifyObservers()
{
	for (auto& o : mObservers) {
		o->update(mOperation, mRecord);
	}
}


void Developer::update(string operation, string record)
{
	cout << "Developer: " << operation << " opeation was performed on " << record << endl;
}

void Boss::update(string operation, string record)
{
	cout << "Boss: " << operation << " opeation was performed on " << record << endl;
}
