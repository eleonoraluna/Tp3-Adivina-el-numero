#include "server_FileErrorException.h"

FileErrorException::FileErrorException() {}

const char* FileErrorException:: what() const throw(){
	  return "File error";
}

FileErrorException::~FileErrorException() {}

