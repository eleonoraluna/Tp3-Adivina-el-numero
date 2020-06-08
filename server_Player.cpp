#include <utility>
#include <vector>
#include "server_Player.h"

const int MAX_ATTEMPTS=10;

Player::Player(int number,Statistics &statistics,Socket_TCP socket):
number(number),mynumber(3,0),attempts(0),isplaying(true),
statistics(statistics),decoder(std::move(socket)){
	this->separate_digits(this->number,this->mynumber);
}

void Player::run_help() const{
	this->decoder.send_help();
}

void Player::win(){
	 this->decoder.send_win();
	 this->statistics.add_winner();
	 this->isplaying=false;
}

void Player::lose(){
	 this->decoder.send_lose();
	 this->statistics.add_loser();
	 this->isplaying=false;
}

void Player::keep_trying(int n) const{
	 std::vector<int> num(3,0);
	 int good=0,regular=0,bad=0;
	 this->separate_digits(n,num);
	 for (int i=0; i<(int)this->mynumber.size(); i++){
		 for (int j=0; j<(int)this->mynumber.size(); j++)
		 if (this->mynumber[i]==num[j] && i==j){
			 good++;
		 }else if (this->mynumber[i]==num[j] && i!=j){
			 regular++;
		 }
	 }
	 if (good==0 && regular==0){
		 bad=3;
	 }
	 this->decoder.send_next_attempt(good,regular,bad);
}

void Player::separate_digits(int n, std::vector<int> &v) const{
	 for (int i=2; i>=0; i--){
			 v[i]=n%10;
			 n/=10;
	 }
}

void Player::guess_number(int n){
	 if (this->number==n){
		 this->win();
	 }else if (this->attempts==MAX_ATTEMPTS){
		 this->lose();
	 }else{
		 this->keep_trying(n);
	 }
}

bool Player::no_repeated_digits(int n) const{
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

bool Player::is_number_valid(int n) const{
	 bool isvalid=true;
	 if (n<100||n>999){
		return false;
	 }else{
		isvalid=no_repeated_digits(n);
	 }
	 return isvalid;
}

void Player::check_number(){
	 int n=this->decoder.rcv_number();
	 this->attempts++;
	 if (!is_number_valid(n) && this->attempts<MAX_ATTEMPTS){
		 this->decoder.send_error();
	 }else{
		 this->guess_number(n);
	 }
}

void Player::run_command(char type){
	 switch (type){
		case 'h':this->run_help();
				 break;
		case 's':this->lose();
				 break;
		case 'n':this->check_number();
				 break;
	 }
}

void Player::run(){
	 while (this->isplaying){
		 char type=this->decoder.rcv_type();
		 this->run_command(type);
	 }
}

bool Player::is_playing() const{
	 return (this->isplaying);
}

Player::~Player() {}

