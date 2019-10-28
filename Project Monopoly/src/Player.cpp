#include "Player.h"

int Player::uID = 1;

Player::Player()
{

}

Player::Player(string name, bool human, int token, int money, glm::vec3 loc)
{
	setPLoc(loc);
	setName(name);
	setIsHuman(human);
	setToken(token);
	setMoney(money);
	setID(uID);
	setPosition(1);
	setJailTime(0);
	setVacationState(false);
	setCardOutJail(0);
	setTakeLoan(false);
	setRoundCount(1);
	setSumLoan(0);
	setTrivia(0);
	setLoanCurrentRound(0);
	setMinusCount(0);
	this->properties = 0;
	uID++;
}

Player::~Player() {

}

void Player::setPLoc(glm::vec3 loc) {
	this->location = loc;
}

void Player::setName(string n) {
	this->name = n;
}

void Player::setIsHuman(bool h) {
	this->ishuman = h;
}

void Player::setID(int id) {
	this->id = id;
}

void Player::setToken(int t) {
	this->token = t;
}

void Player::setMoney(int m) {
	this->money = m;
}

int Player::updateMoney(int m) {
	this->money += m;

	if (this->money <= 0)
		return -1;
	else 
		return 1;
}

int Player::updateProperty(char op) {
	if (op == '-') {
		if (this->properties > 0) {
			this->properties--;
			return 1;
		}
	}
	else if (op == '+') {
		this->properties++;
		return 1;
	}

	return -1;
}

int Player::updateJailCard(char op) {
	if (op == '-') {
		if (this->cardoutjail > 0) {
			this->cardoutjail--;
			return 1;
		}
	}
	else if (op == '+') {
		this->cardoutjail++;
		return 1;
	}

	return -1;
}

void Player::setPosition(int p) { 
	this->position = p;
}

void Player::setProperties(int p) {
	this->properties = p;
}

void Player::setJailTime(int j) {
	this->jailtime = j;
}

void Player::setVacationState(bool vac) {
	this->vacationstate = vac;
}

void Player::setCardOutJail(int c) {
	this->cardoutjail = c;
}

void Player::setSumLoan(int r) {
	this->sumloan = r;
}

void Player::setRoundCount(int r) {
	this->roundCount = r;
}

void Player::setTakeLoan(bool loan) {
	this->takeloan = loan;
}

void Player::setLoanCurrentRound(int round) {
	this->loancurrentround = round;
}

void Player::setTrivia(int t) {
	this->trivia = t;
}

void Player::setMinusCount(int m) {
	this->minusCount = m;
}

string Player::getName() {
	return this->name;
}

bool Player::getIsHuman() {
	return this->ishuman;
}

int Player::getID() {
	return this->id;
}

int Player::getToken() {
	return this->token;
}

int Player::getMoney() {
	return this->money;
}

int Player::getPosition() {
	return this->position;
}

int Player::getProperties() {
	return this->properties;
}

int Player::getJailTime() {
	return this->jailtime;
}

int Player::getCardOutJail() {
	return this->cardoutjail;
}

int Player::getRoundCount() {
	return this->roundCount;
}

int Player::getSumLoan() {
	return this->sumloan;
}

int Player::getLoanCurrentRound() {
	return this->loancurrentround;
}

int Player::getTrivia() {
	return this->trivia;
}

bool Player::getVacationState() {
	return this->vacationstate;
}

bool Player::getTakeLoan() {
	return this->takeloan;
}

int Player::getMinusCount() {
	return this->minusCount;
}

glm::vec3 Player::getPLoc() {
	return this->location;
}
 