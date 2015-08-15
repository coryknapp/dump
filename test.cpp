#include "dump.hpp"

int main(int argc, char *argv[])
{
	d::dump("printing a char", 'a' );	

	d::dump("printing a string", "I am a string");

	char * charPtr = new char('a');
	d::dump( charPtr );
	//d::dump("printing a pointer to a char", charPtr );
	delete charPtr;	

	std::pair<char,char> abPair( 'a', 'b' );
	d::dump( "printing a pair", abPair );

	std::vector<char> abc = {'a','b','c'};
	d::dump( "printing a vector", abc );
	

	std::vector<char*> abcPtrs = {new char('a'), new char('b'), new char('c')};
	d::dump( "printing a vector of pointers", abcPtrs );
	delete abcPtrs[0];
	delete abcPtrs[1];
	delete abcPtrs[2];

	std::vector<std::pair<char,char>> pairs = {
		std::pair<char,char>('a','b'),
		std::pair<char,char>('c','d'),
		std::pair<char,char>('e','f')
	};
	d::dump( "printing a vector of pairs", pairs );

	std::vector<std::pair<char,char>*> pairPtrs = 
		{	new std::pair<char,char>( 'a', 'b' ),
			new std::pair<char,char>( 'c', 'd' ),
			new std::pair<char,char>( 'e', 'f' ) };

	d::dump( "printing a vector of pointers to pairs", pairPtrs );
	delete pairPtrs[0];
	delete pairPtrs[1];
	delete pairPtrs[2];
	return 0;
}
