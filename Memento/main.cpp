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

	Text _txt(val); // create Text class with initial string of val
	cout << _txt.getText() <<std::endl; // begin
	CareTaker::getInstance()->_textMemento = _txt.createMemento(); // save the initial string to a memento

	/**
	 * Save state
	 */
	val = "changed"; // change the string of val
	_txt.setText(val); // set the modified val to txt object
	cout << _txt.getText() <<std::endl; // changed

	/**
	 * Restore state
	 */
	TextMemento txtMem = _txt.createMemento(); // store the modified txt state to a temp memento
	_txt.reinstateMemento(CareTaker::getInstance()->_textMemento); // reinstate the txt to previous state
	CareTaker::getInstance()->_textMemento = txtMem; // store the temp memento to a caretaker
	cout << _txt.getText() << std::endl; // begin

	return 0;
}
