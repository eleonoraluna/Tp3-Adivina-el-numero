#include <iostream>
#include <vector>
#include <string>
#include "server_Reader.h"
#include "server_FileErrorException.h"

Reader::Reader(const std::string &file):file(file),index_number(0){}

bool Reader::is_eof(){
	return(this->file.peek()==EOF);
}

void Reader::openFile() const{
	if (!this->file){
		throw FileErrorException();
	}
}

int Reader::nextNumber(){
	int next_number=this->numbers.at(this->index_number);
	if(this->index_number==(int)this->numbers.size()-1){
		this->index_number=0;
	}else{
		this->index_number++;
	}
	return next_number;
}

void Reader::separate_digits(int n, std::vector<int> &v) const{
	for (int i=2; i>=0; i--){
			 v[i]=n%10;
			 n/=10;
	}
}

bool Reader::no_repeated_digits(int n) const{
	 std::vector<int> num(3,0);
	 this->separate_digits(n,num);
		 for (int i=0; i<2; i++){
			 for (int j=i+1; j<3; j++){
				 if (num[i]==num[j]){
					 return false;
				 }
			 }
		 }
	 return true;
}

bool Reader::is_number_valid(int n) const{
	 bool isvalid=true;
	 if (n<100||n>999){
		std::cerr<<"Error: archivo con números fuera de rango"<<std::endl;
		return false;
	 }else{
		isvalid=this->no_repeated_digits(n);
	 }
	 if (!isvalid){
		std::cerr<<"Error: formato de los números inválidos"<<std::endl;
	 }
	 return isvalid;
}

void Reader::readNumbers(){
	std::string line;
	int number;
	while(!this->is_eof()){
		std::getline(this->file,line);
		number=std::stoi(line);
		if (!this->is_number_valid(number)){
		   throw FileErrorException();
		}
		this->numbers.push_back(number);
	}
}

Reader::~Reader() {}

