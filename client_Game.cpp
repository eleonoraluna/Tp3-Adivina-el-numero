#include <iostream>
#include <string>
#include "client_Help.h"
#include "client_Surrender.h"
#include "client_numberCommand.h"
#include "client_Game.h"

const int MAX_NUM=65535;

Game::Game(const std::string &name, const std::string &port):
encoder(name,port),surrender(false),is_playing(true){}

void Game::encode(Command &c){
	 if (c.encode()==1){
		 this->is_playing=false;
	 }
}

void Game::check_number(){
	 int number=std::stoi(this->input);
	 //si número es > a uno que pueda representarse en un unsigned de 2 bytes
	 if (number>MAX_NUM){
		std::cout<<"Error: comando inválido. Escriba AYUDA para obtener ayuda"
				 <<std::endl;
	 }else{
		 //lo codifico y lo envío
		numberCommand c(number,this->encoder);
		encode(c);
	 }
}

void Game::is_number(){
	 int i=0;
	 while (isdigit(this->input[i])){
		i++;
	 }
	 if ((i==(int)this->input.size())&&(this->input.size()<10)){
		this->check_number();
	 }else{// es una mezcla entre números y letras o un num demasiado grande
		std::cout<<"Error: comando inválido. Escriba AYUDA para obtener ayuda"
				 <<std::endl;
	 }
}

enum Game::Commands Game::resolve_command(){
	 if (this->input=="AYUDA"){
		 return HELP;
	 }else if (this->input=="RENDIRSE"){
			   return SURRENDER;
	 }else{
		return OTHER;
	 }
}

void Game::check_input(){
	switch(resolve_command()){
		case HELP:{
			 Help h(this->encoder);
			 encode(h);
			 break;
		}
		case SURRENDER:{
			 Surrender s(this->encoder);
			 encode(s);
			 break;
		}
		case OTHER:{
			 is_number();
		}
	}
}

void Game::run(){
	 while (this->is_playing){
	     std::getline(std::cin,this->input);
	 	 if (this->input.find(" ")==std::string::npos){
	 		 this->check_input();
	 	 }else{
	 		 std::cout<<"Error: argumentos inválidos."<<std::endl;
	 	 }
	 }
}

Game::~Game() {}

