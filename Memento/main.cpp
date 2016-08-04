//============================================================================
// Name        : MementoTest.cpp
// Author      : Albertus Adityo Wahono
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "inc/Text.hpp"
#include "inc/CareTaker.hpp"

using namespace std;

int main() {
	std::string val = "begin";

	Text _txt(val);
	cout << _txt.getText() <<std::endl;

	/**
	 * Save state
	 */
	CareTaker::getInstance()->_textMemento = _txt.createMemento();
	val = "changed";
	_txt.setText(val);
	cout << _txt.getText() <<std::endl;

	/**
	 * Restore state
	 */
	TextMemento txtMem = _txt.createMemento();
	_txt.reinstateMemento(CareTaker::getInstance()->_textMemento);
	CareTaker::getInstance()->_textMemento = txtMem;
	cout << _txt.getText() << std::endl;

	return 0;
}
