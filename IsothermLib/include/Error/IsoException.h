//==============================================================================
// Name        : IsoException.h
// Authors     : Aline Zuliani Lunkes
//               Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               João Flávio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe para tratar as exceções do programa
//
// Copyright   : Copyright (C) <2024>  João Flávio Vasconcellos 
//                                      (jflavio at iprj.uerj.br)
//
// This program é software livre: você pode redistribuí-lo e/ou modificá-lo
// sob os termos da GNU General Public License conforme publicada pela
// Free Software Foundation, tanto a versão 3 da Licença.
//
// Este programa é distribuído na esperança de que seja útil,
// mas SEM QUALQUER GARANTIA; sem mesmo a garantia implícita de
// COMERCIABILIDADE ou ADEQUAÇÃO A UM DETERMINADO FIM. Veja a
// GNU General Public License para mais detalhes.
//
// Você deve ter recebido uma cópia da GNU General Public License
// junto com este programa. Se não, veja <http://www.gnu.org/licenses/>.
//==============================================================================

/** 
 * @defgroup IsoException Exceções
 * @ingroup IsothermException
 * @brief Classe IsoException para o gerenciamento das exceções.
 * @{
 */

/// @file IsoException.h
/// @brief Contém a definição da classe IsoException



#ifndef __ISOEXCEPTION_H__
#define __ISOEXCEPTION_H__

//==============================================================================
// Inclusões C++
//==============================================================================

#include <exception>
#include <string>
#include <ostream>

//==============================================================================
// Inclusões da Isotherm++
//==============================================================================

#include <Misc/Configure.h>
#include <Misc/SourceInfo.h>

namespace ist {

    /**
 * @brief enum para padronizar as exceções.
 */
    
enum IsoExceptionIndex {
    // Erros Gerais
    BadCoefficient = 0,
    BadCeLEZero,
    BadCeLTZero,
    BadK1LEZero,
    BadK2LEZero,
    BadK2LTZero,
    BadQmaxLEZero,
    BadTempLEZero,
    BadRGasLEZero,
    BadOverFlow,
    BadLogCeGTK2,
    ConvergenceProblem,
    BadKCeK1LEOne
};


/**
 * @brief Classe para o gerenciamento das exceções.
 */
class IsoException : public std::exception {
public:    
    friend std::ostream& operator<<(std::ostream&, const IsoException&);
    
public:
    IsoException(const SourceInfo&,
                 const std::string&, 
                 const IsoExceptionIndex&, 
                 const std::string& = "",
                 const std::string& = "");

    IsoException(const std::string& _msg,
                 const std::string& _funct,
                 const std::string& _arquivo,
                 const UInt& _linha);

    IsoException(const IsoException&) = default;              
    virtual ~IsoException() = default;

    virtual const char* what() const noexcept override {
        return msg.c_str();
    }

private:
    SourceInfo              sourceInfo;
    std::string             classe;
    IsoExceptionIndex       isoExceptionIndex;
    std::string             msg1;
    std::string             msg2;
    std::string             msg;
};

} // namespace ist

#endif /* __ISOEXCEPTION_H__ */

/** @} */
