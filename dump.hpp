#ifndef DUMP_HPP_BIF3W8QM
#define DUMP_HPP_BIF3W8QM

#include <iostream>
#include <vector>

namespace d {
	
template<typename T>
void dump( const T& thing,
		   std::ostream &out = std::cout,
		   const std::string &terminator = "\n"){
	out << thing << terminator;
	out.flush();
}

template<typename T>
void dump( const std::pair<T ,T> &thing, std::ostream &out = std::cout ){
	out << "{ ";
	dump( thing.first, out, "" );
	out << ",\t";
	dump( thing.second, out, "" );
	out << "}" << std::endl;
}

template<typename T>
void dump( const std::vector<T> &thing, std::ostream &out = std::cout ){
	for (auto &i : thing) {
		dump( i, out );
	}
}
	
template<typename T>
void dump( const std::vector<T*> &thing, std::ostream &out = std::cout ){
	for (auto &i : thing) {
		dump( i, out );
	}
}

template<typename T>
void dump( const std::string &message, const T& thing,std::ostream &out = std::cout){
	out << "===" << message << "===\n";
	dump( thing, out );
}

}// namespace d
	
#endif 
