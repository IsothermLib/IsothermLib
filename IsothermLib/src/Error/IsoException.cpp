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

//==============================================================================
// Mensagens de erro
//==============================================================================

/**
 * @brief Array de mensagens de erro associadas a cada índice de IsoException.
 */
static std::string IsoExceptionStr[] = {
    "Coeficientes da isoterma indefinidos.",                    // BadCoefficient
    "Ce menor ou igual a zero.",                                // BadCeLEZero
    "Ce menor do que zero.",                                    // BadCeLTZero    
    "K1 menor ou igual a zero.",                                // BadK1LEZero
    "K2 menor ou igual a zero.",                                // BadK2LEZero
    "K2 menor do que zero.",                                    // BadK2LTZero   
    "Qmax menor ou igual a zero.",                              // BadQmaxLEZero 
    "Temperatura menor ou igual a zero.",                       // BadTempLEZero
    "Constante universal dos gases menor ou igual a zero.",     // BadRGasLEZero
    "Overflow de operação matemática.",                         // BadOverFlow
    "O valor de log(C) maior que K_2.",                         // BadLogCeGTK2
    "Problema de convergência do método iterativo.",            // ConvergenceProblem
    "O valor de K_1 C menor ou igual a 1."                      // BadKCeK1LEOne
};

//==============================================================================
// Implementação de IsoException
//==============================================================================

/**
 * @brief Construtor da classe IsoException.
 * 
 * @param _sourceInfo Informações sobre a origem da exceção.
 * @param _classe Nome da classe onde a exceção ocorreu.
 * @param _isoIndex Índice da exceção.
 * @param _msg1 Mensagem adicional 1.
 * @param _msg2 Mensagem adicional 2.
 */
IsoException::IsoException(const SourceInfo& _sourceInfo, 
                           const std::string& _classe, 
                           const IsoExceptionIndex& _isoIndex, 
                           const std::string& _msg1, 
                           const std::string& _msg2)
    : sourceInfo(_sourceInfo), classe(_classe), isoExceptionIndex(_isoIndex), msg1(_msg1), msg2(_msg2) {}

//==============================================================================
// Operador de inserção para IsoException
//==============================================================================

/**
 * @brief Sobrecarga do operador de inserção para exibir informações sobre a exceção.
 * 
 * @param _os Stream de saída.
 * @param _isoException Instância de IsoException.
 * @return Referência para o stream de saída.
 */
std::ostream& operator<<(std::ostream& _os, const IsoException& _isoException) {
    _os << "\n\n";
    PrintLine(_os);
    _os << "Erro:    " << IsoExceptionStr[_isoException.isoExceptionIndex] 
        << "\nClasse:  " << _isoException.classe 
        << "\nFunção:  " << _isoException.sourceInfo.FunctionName() 
        << "\nArquivo: " << _isoException.sourceInfo.FileLocation() 
        << "\nLinha:   " << _isoException.sourceInfo.LinePosition() 
        << "\n";

    if (!_isoException.msg1.empty()) {
        _os << "Msg:     " << _isoException.msg1 << "\n";        
    
        if (!_isoException.msg2.empty()) {
            _os << "         " << _isoException.msg2 << "\n";        
        }
    }

    std::cout << "Execução cancelada\n";
    PrintLine(_os);

    return _os;
}

} // namespace ist
