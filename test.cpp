#include "dump.hpp"

int main(int argc, char *argv[])
{
	d::dump( "should be \'a\'", 'a' );	

	std::pair<char,char> abPair( 'a', 'b' );
	d::dump( "printing a pair", abPair );

	std::vector<char> abc = {'a','b','c'};
	d::dump( "printing a vector", abc );
	

	std::vector<char*> abcPtrs = {new char('a'), new char('b'), new char('c')};
	d::dump( "printing a vector of pointers", abcPtrs );
	delete abcPtrs[0];
	delete abcPtrs[1];
	delete abcPtrs[2];
	return 0;
}
