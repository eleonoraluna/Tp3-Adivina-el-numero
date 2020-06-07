#include <iostream>
#include <string>
#include "client_Help.h"
#include "client_Surrender.h"
#include "client_numberCommand.h"
#include "client_Game.h"

const int MAX_NUM=65535;

Game::Game(const std::string &name, const std::string &port):
encoder(name,port),surrender(false),is_playing(true){}

void Game::is_number(){
	 int i=0;
	 while (isdigit(this->input[i])){
		i++;
	 }
	 if ((i==(int)this->input.size())&&(this->input.size()<10)){
		this->check_number();
	 }else{
		std::cout<<"Error: comando inválido. Escriba AYUDA para obtener ayuda"
				 <<std::endl;
	 }
}

void Game::check_number(){
	 int number=std::stoi(this->input);
	 if (number>MAX_NUM){
		std::cout<<"Error: comando inválido. Escriba AYUDA para obtener ayuda"
				 <<std::endl;
	 }else{
		numberCommand c(number,this->encoder);
		encode(c);
	 }
}

void Game::encode(Command &c){
	 int status=c.encode();
	 if (status==1){
		 this->is_playing=false;
	 }
}

int Game::resolve_command(){
	if(this->input=="AYUDA"){
		return 0;
	}else if (this->input=="RENDIRSE"){
			return 1;
	}else{
		return 2;
	}
}

void Game::check_input(){
	switch(resolve_command()){
		case 0:{
			Help h(this->encoder);
			encode(h);
			break;
		}
		case 1:{
			Surrender s(this->encoder);
			encode(s);
			this->surrender=true;
			break;
		}
		case 2:{
			is_number();
		}
	}
}

void Game::run(){
	 while (!this->surrender && this->is_playing){
	 std::getline(std::cin,this->input);
	 	 if (this->input.find(" ")==std::string::npos){
	 		 this->check_input();
	 	 }else{
	 		 std::cout<<"Error: argumentos inválidos."<<std::endl;
	 	 }
	 }
}

Game::~Game() {}

