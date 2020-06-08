#ifndef SERVER_READER_H_
#define SERVER_READER_H_
#include <fstream>
#include <vector>
#include <string>

class Reader {
public:
	explicit Reader(const std::string &file);

	//lanza una excepción si el archivo no se pudo abrir
	void openFile() const;

	bool is_eof();

	//lee los números de la lista y los guarda
	//si los números tienen digitos repetidos,fuera de rango
	//o tiene más de un argumento por linea lanza una excepción
	void readNumbers();

	//devuelve el siguiente número de la lista
	//haciendo round robin
	int nextNumber();

	virtual ~Reader();

private:
	std::ifstream file;
	std::vector <int> numbers;
	int index_number;

	//separa los dígitos de un número y los coloca en un vector
	void separate_digits(int n, std::vector<int> &v) const;

	//chequea si el número tiene dígitos repetidos
	bool no_repeated_digits(int n) const;

	//devuelve true si el número esta dentro del rango y no tiene
	//dígitos repetidos
	bool is_number_valid(int n) const;
};

#endif /* SERVER_READER_H_ */
