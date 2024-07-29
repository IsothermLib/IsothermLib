//==============================================================================
// Name        : IsoException.h
// Author      : Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe para tratar as exceptions do programa
//
// Copyright   : Copyright (C) <2022>  Joao Flavio Vasconcellos 
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


/*! \class	IsoException
 *  \brief	Classe para tratar as exceptions do programa
 *  \file	IsoException.h
 *  \author	Joao Flavio Vieira de Vasconcellos
 *  \version	1.0
 *  \date	2022
 *  \bug	Nao ha bugs conhecidos
 */


#ifndef __ISOEXCEPTION_H__
#define __ISOEXCEPTION_H__

//==============================================================================
// include c++
//==============================================================================

#include <exception>
#include <string>

//==============================================================================
// include da Isotherm++
//==============================================================================

#include <Misc/Configure.h>
#include <Misc/SourceInfo.h>


namespace ist {

enum IsoExceptionIndex {
    
//    
//  Erros Gerais
//    
        BadCoefficient = 0
    ,   BadCeLEZero
    ,   BadCeLTZero
    ,   BadCeGEOne
    ,   BadCeGEK2
    ,   BadK1LEZero
    ,   BadK1LTZero
    ,   BadK2LEZero
    ,   BadK2LTZero
    ,   BadK3LEZero
    ,   BadK3LTZero
    ,   BadK4LEZero
    ,   BadK4LTZero
    ,   BadK1LTOne
    ,   BadK2LEOne
    ,   BadK3GTOne                          
    ,   BadK3GEOne                          
    ,   BadQmaxLEZero                
    ,   BadTempLEZero
    ,   BadRGasLEZero                
    ,   BadResult
    ,   BadOverFlow
    ,   BadLogCeGTK2
    ,   ConvergenceProblem        
    ,   BadThetaGEOne
    ,   BadThetaLEZero
    ,   BadKCeK1LEOne

        
};

class IsoException : public std::exception {
    

public:    

    friend std::ostream& operator << (std::ostream&, const IsoException&);
    
public:
        
    IsoException (  const SourceInfo&,
                    const std::string&, 
                    const IsoExceptionIndex&, 
                    const std::string& = "",
                    const std::string& = "");

    IsoException( const std::string& _msg,
                  const std::string& _funct,
                  const std::string& _arquivo,
                  const UInt& _linha)  {};

    IsoException (const IsoException&) = default;              
    virtual ~IsoException() = default;

    virtual const char * what() const throw() {
        return msg.c_str();
    };

private:
        
    SourceInfo              sourceInfo;
    std::string             classe;
    IsoExceptionIndex       isoExceptionIndex;
    std::string             msg1;
    std::string             msg2;
    std::string             msg;

};

}

        
#endif /* __ISOEXCEPTION_H__ */
