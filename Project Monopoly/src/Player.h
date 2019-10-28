#include <iostream>
#include <string>
#include "GL/glew.h"	// Important - this header must come before glfw3 header
#include "glm/glm.hpp"

using namespace std;


class Player
{
public:

	static int uID;
	Player();
	Player(string name, bool human, int token, int money, glm::vec3 loc);
	~Player();
	void setName(string n);
	void setIsHuman(bool h);
	void setID(int id);
	void setToken(int t);
	void setMoney(int m);
	void setPosition(int p);
	void setProperties(int p);
	void setJailTime(int j);
	void setVacationState(bool vac);
	void setCardOutJail(int c);
	void setRoundCount(int r);
	void setSumLoan(int r);
	void setTakeLoan(bool loan);
	void setLoanCurrentRound(int round);
	void setTrivia(int t);
	void setPLoc(glm::vec3 loc);
	void setMinusCount(int m);
	int updateMoney(int m);
	int updateProperty(char op);
	int updateJailCard(char op);


	string getName();
	bool getIsHuman();
	int getID();
	int getToken();
	int getMoney();
	int getPosition();
	int getJailTime();
	int getCardOutJail();
	int getRoundCount();
	int getSumLoan();
	int getLoanCurrentRound();
	int getTrivia();
	int getProperties();
	int getMinusCount();
	bool getVacationState();
	bool getTakeLoan();
	glm::vec3 getPLoc();

	
private:

	glm::vec3 location;
	string name;
	bool ishuman;
	int id;
	int token;
	int money;
	int position;
	int properties;
	int jailtime;
	int cardoutjail;
	int roundCount;
	int sumloan;
	int loancurrentround;
	int trivia;
	int minusCount;
	bool vacationstate;
	bool takeloan;
};