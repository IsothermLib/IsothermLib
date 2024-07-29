//==============================================================================
// include c++
//==============================================================================

#include <iostream>
#include <sstream>

//==============================================================================
// include da Isotherm++
//==============================================================================

#include <Error/IsothermError.h>

namespace ist {
        

static std::string IsoErrStr[] = {
        "Coeficientes da equacao nao estao definidos.",
};



void ISOTHERM_Err   (   const SourceInfo&       _sloc
                    ,   const std::string&      _classe
                    ,   const IsoErrorIndex&    _index
                    ,   const std::string&      _msg1
                    ,   const std::string&      _msg2
                    ) 
{
    
    
    std::stringstream sstr;

    sstr << "Classe: "   << _classe
         << "\nFuncao: " << _sloc.FunctionName()
         << "\nErro: "   << IsoErrStr[_index]
         << "\n";   
    
    if(!_msg1.empty()){    
        sstr << _msg1 << "\n";
    }
    
    if(!_msg2.empty()){    
        sstr << _msg2 << "\n";
    }   
    
    std::cout << sstr.str();
    
}
        
}
