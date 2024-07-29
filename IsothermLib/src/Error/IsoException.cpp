//==============================================================================
// include c++
//==============================================================================

#include <iostream>

//==============================================================================
// include da Isotherm++
//==============================================================================

#include <Error/IsoException.h>
#include <Misc/Misc.h>


namespace ist {

static std::string IsoExceptionStr[] = 
    {
            "Coeficientes da isoterma indefinidos."                    // BadCoefficient
    ,       "Ce menor ou igual a zero."                                // BadCeLEZero
    ,       "Ce menor do que zero."                                    // BadCeLTZero    
    ,       "Ce maior ou igual a 1."                                    // BadCeLTZero    
    ,       "Ce maior ou igual a K2."                                  //BadCeGTK2  
    ,       "K1 menor ou igual a zero."                                // BadK1LEZero
    ,       "K1 menor do que zero."                                    // BadK1LTZero
    ,       "K2 menor ou igual a zero."                                // BadK2LEZero
    ,       "K2 menor do que zero."                                    // BadK2LTZero   
    ,       "K3 menor ou igual a zero."                                // BadK3LEZero
    ,       "K3 menor do que zero."                                    // BadK3LTZero  
    ,       "K4 menor ou igual a zero."                                // BadK4LEZero
    ,       "K4 menor do que zero."                                    // BadK4LTZero  
    ,       "K1 menor do que 1."                                       // BadK1LTOne
    ,       "K2 menor ou igual a 1."                                   // BadK2LEOne
    ,       "K3 maior do que 1."                                       // BadK3GTOne     
    ,       "K3 maior ou igual a 1."                                   // BadK3GEOne     
    ,       "Qmax menor ou igual a zero."                              // BadQmaxLEZero 
    ,       "Temperatura menor ou igual a zero."                       // BadTempLEZero
    ,       "Constante universal dos gases menor ou igual a zero."     // BadRGasLEZero
    ,       "Resultado inconsistente para o modelo."                   // BadResult
    ,       "Overflow de operacao matematica."                         // BadOverFlow
    ,       "O valor de log(C) maior que K_2."                         // BadLogCeGTK2
    ,       "Problema de convergencia do metodo iterativo."            // ConvergenceProblem
    ,       "O valor de theta maior ou igual a 1."                     // BadThetaGEOne
    ,       "O valor de theta menor ou igual a 0."                     // BadThetaLEZero
    ,       "O valor de K_1 C menor ou igual a 1."                     // BadKCeK1LEOne
};


IsoException :: IsoException    (   const SourceInfo&           _sourceInfo
                                ,   const std::string&          _classe 
                                ,   const IsoExceptionIndex&    _isoIndex
                                ,   const std::string&          _msg1
                                ,   const std::string&          _msg2   
                                ) 
                                :   sourceInfo (_sourceInfo)
                                ,   classe(_classe)
                                ,   isoExceptionIndex(_isoIndex)
                                ,   msg1(_msg1)
                                ,   msg2(_msg2) 
{
        
}
        
        
std::ostream& operator <<   (   std::ostream&           _os 
                            ,   const IsoException&     _isoException) 
{
    
    _os << "\n\n";
    PrintLine(_os);   
    _os     << "Erro:    " 
            << IsoExceptionStr[_isoException.isoExceptionIndex] 
            << "\nClasse:  " 
            << _isoException.classe 
            << "\nFuncao:  " 
            << _isoException.sourceInfo.FunctionName() 
            << "\nArquivo: " 
            << _isoException.sourceInfo.FileLocation() 
            << "\nLinha:   " 
            << _isoException.sourceInfo.LinePosition() 
            << "\n";
    
    if (!_isoException.msg1.empty()) {
        _os     << "Msg:     " 
                << _isoException.msg1 
                << "\n";        
    
        if (!_isoException.msg2.empty()) {
            _os     << "         " 
                    << _isoException.msg2 
                    << "\n";        
        }
    }
    
    std::cout << "Execucao cancelada\n";
    PrintLine(_os);           
    
    return _os;
    
}

}