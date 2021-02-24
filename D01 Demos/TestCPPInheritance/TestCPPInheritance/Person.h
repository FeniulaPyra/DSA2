#ifndef PERSON_H
#define PERSON_H

class Person
{
public:
	virtual int getSSN() const { return ssn; }
	virtual void setSSN(int s) { ssn=s; }

private:
	int ssn;
};

#endif
