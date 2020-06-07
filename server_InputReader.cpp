#include <iostream>
#include <string>
#include "server_InputReader.h"

Input_Reader::Input_Reader(const std::string &port,const std::string &filename):
manager(port,filename,this->statistics),printer(this->statistics){}

void Input_Reader::run(){
	 this->manager.start();
	 char exit=0;
	 while (exit!='q'){
		std::cin>>exit;
	 }
	 this->manager.stop();
	 this->manager.join();
	 this->printer.print();
}

void Input_Reader::operator()(){
	 this->run();
}

Input_Reader::~Input_Reader() {}

