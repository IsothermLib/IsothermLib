//==============================================================================
// Name        : IsothermID.h
// Author      : Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe para identificacao de cada classe
//
// Copyright   : Copyright (C) <2024>  Joao Flavio Vasconcellos 
//                                      (jflavio at iprj.uerj.br)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//==============================================================================

#ifndef ISOTHERM_ID_H_
#define ISOTHERM_ID_H_

/** @defgroup IsothermID Identificacao da Classe
 *  @ingroup IsothermMisc
 *  @brief Classe ID para identificacao das classes no caso de erro.
 *  @{
 */

/// @file ID.h
/// @brief Contém a definição da classe ID



//==============================================================================
// Include C++
//==============================================================================

#include <string>

//==============================================================================
// Include da biblioteca Isotherm
//==============================================================================

#include <Misc/Configure.h>

namespace ist {

/**
 * @brief Classe ID identifica cada uma das classes da biblioteca.
 */
class ID {

//==============================================================================
// Enum com o nome das classes da biblioteca
//==============================================================================
    
public:
    
  enum {
      
            Isotherm = 0
        ,   OneParameter
        ,   TwoParameters
        ,   ThreeParameters
        ,   FourParameters
        ,   FiveParameters
        ,   Henry = 100
        ,   DubininRadushkevich = 200
        ,   Elovich
        ,   Freundlich
        ,   HarkinsJura
        ,   Halsey
        ,   Jovanovic
        ,   Langmuir
        ,   Temkin
  };    
    
//==============================================================================
// Construtores / destrutora
//==============================================================================

public:
    
    ID() = default;
    ID(const ID&) = default;
    virtual ~ID() = default;
    
//==============================================================================
// Sobrecarga de operadores
//==============================================================================

    ID& operator = (const ID&) = default;
    
//==============================================================================
// Funcoes virtuais
//==============================================================================
    
[[nodiscard]] inline  virtual std::string className() const {return "no class";}
[[nodiscard]] inline  virtual UInt classID() const {return 0;}

};

#define DefineIdentityBase(_name, _id) \
     virtual std::string className() const {return _name;} \
     virtual UInt classID() const {return _id;}

#define DefineIdentity(_name, _id) \
     virtual std::string className() const override  {return _name;} \
     virtual UInt classID() const override {return _id;}

#define DeclareIdentity() \
     const char * className() const; \
     int classID() const

}

#endif /* ISOTHERM_ID_H_ */
        
        
                
/** @} */