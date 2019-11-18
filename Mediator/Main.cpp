#include<iostream>
#include"Mediator.h"
using namespace std;
int main() {
	// John trò chuyện với Jerry thông qua cổng Mediator
	concreteMediator* pMediator = new concreteMediator();
	Colleage * p1 = new ColleageA(pMediator);
	Colleage * p2 = new ColleageB(pMediator);
	pMediator->setColleageA(p1);
	pMediator->setColleageB(p2);
    p1->sendMessage("Hello, John");
	p2->sendMessage("Hi, Jerry");
	system("pause");
	return 0;
}