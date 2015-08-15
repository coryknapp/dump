#ifndef DUMP_HPP_BIF3W8QM
#define DUMP_HPP_BIF3W8QM

#include <iostream>
#include <vector>
#include <typeinfo>

namespace d {

namespace details{
    typedef char oddType[7];
    template<typename T> oddType& operator << ( std::ostream&, const T&);

    template <typename T>
    struct leftarrowleftarrow{
    	enum{
			value = (sizeof(*(T*)(0) == *(T*)(0)) != sizeof(oddType))
		};
    };

}//namespace details
		
template<typename T,
	typename std::enable_if<
	(!std::is_pointer<T>{} &&
		( std::is_arithmetic<T>{} || details::leftarrowleftarrow<T>::value ) )
			>::type* = nullptr>
void dump( const T& thing,
		   std::ostream &out = std::cout,
		   const std::string &terminator = "\n"){
	//out <<"as "<<typeid(T).name() <<" "<< thing << terminator;
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
	out << "as a vector of " << typeid(T).name() << "...\n";
	for (auto &i : thing) {
		dump( i, out );
	}
}
	
template<typename T>
void dump( const T * thing,
		   std::ostream &out = std::cout){
	dump( *thing, out );
}

template<typename T>
void dump( const std::vector<T*> &thing, std::ostream &out = std::cout ){
	out << "as a vector of " << typeid(T).name() << " pointers...\n";
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
