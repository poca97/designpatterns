#include "Mediator.h"
#include <iostream>
#include <string>
using namespace std;
Colleage::Colleage(Mediator * pMediator)
{
	this->_mediator = pMediator;
}
Colleage::~Colleage()
{
}
void Colleage::setMediator(Mediator * pMediator)
{
	this->_mediator = pMediator;
}
ColleageA::ColleageA(Mediator * pMediator) : Colleage(pMediator)
{
}
ColleageA::~ColleageA()
{
}
void ColleageA::sendMessage(string msg)
{
	this->_mediator->sendMessage(msg, this);
}
void ColleageA::getMessage(string msg)
{
	cout << "ColleageA receive: " << msg << endl;
}
ColleageB::ColleageB(Mediator * pMediator) : Colleage(pMediator)
{
}
ColleageB::~ColleageB()
{
}
void ColleageB::sendMessage(string msg)
{
	this->_mediator->sendMessage(msg, this);
}
void ColleageB::getMessage(string msg)
{
	cout << "ColleageA receive: " << msg << endl;
}
Mediator::Mediator()
{}
Mediator::~Mediator()
{}
concreteMediator::concreteMediator()
{}
concreteMediator::~concreteMediator()
{}
void concreteMediator::setColleageA(Colleage * p)
{
	this->mColleageA = p;
}
void concreteMediator::setColleageB(Colleage * p)
{
	this->mColleageB = p;
}
void concreteMediator::sendMessage(string msg, Colleage * p)
{
	if (p == this->mColleageA)
		{
			this->mColleageB->getMessage(msg);
		}
	else if (p == this->mColleageB)
		{
		    this->mColleageA->getMessage(msg);
		}
}