#ifndef ISOTHERM_SOURCE_INFO_H_
#define ISOTHERM_SOURCE_INFO_H_

/**
 * @defgroup SourceInfo Informações sobre as classes
 * @ingroup IsothermMisc
 * @brief Classe com informações sobre outras classes para fins de identificação e localização de erros.
 * @{
 */

/// @file SourceInfo.h
/// @brief Define as informações sobre outras classes para fins de identificação e localização de erros



//==============================================================================
// Includes
//==============================================================================

#include <string>

//==============================================================================
// Include da biblioteca Isotherm
//==============================================================================
#include <Misc/Configure.h>

namespace ist {

    /**
 * @brief Classe SourceInfo  identifica qual classe causou uma exceção.
 */
class SourceInfo {
    
//==============================================================================
// Construtores / destrutora
//==============================================================================

public:
    
    SourceInfo() = default;
    SourceInfo(const SourceInfo&) = default;
    virtual ~SourceInfo() = default;
    SourceInfo(const std::string&, const long&, const std::string&);
    
//==============================================================================
// Funções inline
//==============================================================================
    
    /**
     * @brief Retorna a localização do arquivo.
     * @return Localização do arquivo.
     */
    [[nodiscard]] inline std::string FileLocation() const { return fileLocation; };
    
    /**
     * @brief Retorna a posição da linha.
     * @return Posição da linha.
     */
    [[nodiscard]] inline long LinePosition() const { return lineLocation; };
    
    /**
     * @brief Retorna o nome da função.
     * @return Nome da função.
     */
    [[nodiscard]] inline std::string FunctionName() const { return functionName; };
    
//==============================================================================
// Dados da classe
//==============================================================================
    
private :
    
    std::string fileLocation;
    long lineLocation = 0;
    std::string functionName;
    
};

#define IST_LOC SourceInfo(__FILE__, __LINE__, __func__)

}
        
#endif  /* ISOTHERM_SOURCE_INFO_H_ */
        
/** @} */
