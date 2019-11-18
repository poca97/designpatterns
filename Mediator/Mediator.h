#pragma once
#include <string>
using namespace std;
class Mediator;
class Colleage
{
public:
     virtual ~Colleage();
     virtual void setMediator(Mediator*);
     virtual void sendMessage(string) = 0;
     virtual void getMessage(string) = 0;
protected:
    Colleage(Mediator*);
	Mediator* _mediator;
};
class ColleageA : public Colleage
{
public:
	~ColleageA();
	ColleageA(Mediator*);
    virtual void sendMessage(string msg);
	virtual void getMessage(string);
};
class ColleageB : public Colleage
{
public:
	~ColleageB();
	ColleageB(Mediator*);
	virtual void sendMessage(string msg);
	virtual void getMessage(string);
};
class Mediator
{
public:
	virtual ~Mediator();
	virtual void sendMessage(string, Colleage*) = 0;
protected:
	Mediator();
};

// concreteMediator sẽ giữ vai trò gửi tin nhắn đến colleage nào
class concreteMediator : public Mediator
{
public:
	concreteMediator();
	~concreteMediator();
	void setColleageA(Colleage*);
	void setColleageB(Colleage*);
	virtual void sendMessage(string msg, Colleage*);
private:
	Colleage* mColleageA;
	Colleage* mColleageB;
};