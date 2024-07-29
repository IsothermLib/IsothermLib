//==============================================================================
// Name        : Jovanovic.cpp
// Author      : Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
//               Iasmim Barboza Storck
// Version     : 1.0
// Description : Classe com as equacoes da isoterma de Jovanovic
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


//==============================================================================
// includes lib c++
//==============================================================================

#include<cmath>             // exp
#include <iostream>         // std::cout

//==============================================================================
// includes da lib IsothermLib
//==============================================================================

#include <Error/IsoException.h>
#include <Isotherm/TwoParameters/Jovanovic.h>

namespace ist {

//==============================================================================
// Variaveis estaticas
//==============================================================================

VecPairString       detailsJovanovic
    {
        PairString  ( "Qmax"
                    , "Capacidade maxima de adsorcao")
    ,   PairString  ( "K1"
                    , "Constante da isoterma de Jovanovic")
    };

template<>
VecPairString IsothermTemplate < Jovanovic >::infoIsotherm = detailsJovanovic;


//==============================================================================
// Funcoes da classe
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "Jovanovic :: Jovanovic (const Real&, const Real&)"
Jovanovic :: Jovanovic  (   const Real&     _qmax
                        ,   const Real&     _k1
                        ) 
                        :   TwoParameters (_qmax, _k1)
{


    try {
            if (_k1 <= 0.0)  throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadK1LEZero
                                    );

            if (_qmax <= 0.0)  throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadQmaxLEZero
                                    );

    } catch (const IsoException& _isoExcept) {

        std::cout   << _isoExcept 
                    << "\n";
        exit(EXIT_FAILURE);

    }

    setup = true;

}

//==============================================================================
// Concentracao de equilibrio Q
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "Real Jovanovic ::  Qe (const Real&, const Real&) "
Real
Jovanovic ::  Qe    (   const Real&     _ce
                    ,   const Real& 
                    ) const {

    try {

        if (!setup) throw
            IsoException    (   IST_LOC
                            ,   className()
                            ,   BadCoefficient
                            );

        if (_ce <= 0.0)  throw
                IsoException    (   IST_LOC
                                ,   className()
                                ,   BadCeLEZero
                                );

    } catch (const IsoException& _isoExcept) {

        std::cout   << _isoExcept
                    << "\n"
                    << std::flush;
        exit(EXIT_FAILURE);
    }

auto    ptrValue = std::begin(coeffValue);
auto    value    = *(ptrValue) * exp(- *(ptrValue + 1) * _ce) ;

    return  (value >= ZERO ? value : 0.0);

}

}