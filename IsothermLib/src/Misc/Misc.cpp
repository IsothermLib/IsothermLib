//============================================================================
// includes da lib c++
//============================================================================

#include <iostream>
#include <iterator>

//============================================================================
// includes da biblioteca isotherm++
//============================================================================


#include <Misc/Misc.h>


void   PrintLine    (   std::ostream&       _os
                    ,   const UInt&         _lsize
                    ) 
{

const char ASCIINUMBER(0x3D);

    std::generate_n ( std::ostream_iterator<char>( _os, ""), 
                      _lsize, 
                      [](){return ASCIINUMBER;});
    
    _os << "\n";
   
}

