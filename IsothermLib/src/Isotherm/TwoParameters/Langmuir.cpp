//==============================================================================
// Name        : Langmuir.cpp
// Author      : Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
//               Iasmim Barboza Storck
// Version     : 1.0
// Description : Classe com as equacoes da isoterma de Langmuir
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

#include <iostream>

//==============================================================================
// includes da lib IsothermLib
//==============================================================================

#include <Error/IsoException.h>
#include <Isotherm/TwoParameters/Langmuir.h>

namespace ist {

//==============================================================================
// Variaveis estaticas
//==============================================================================

VecPairString       detailsLangmuir
    {
        PairString  ( "Qmax"
                    , "Capacidade maxima de adsorcao")
    ,   PairString  ( "K1"
                    , "Constante de equilibrio de Langmuir")
    };

template<>
VecPairString IsothermTemplate < Langmuir >::infoIsotherm = detailsLangmuir;

//==============================================================================
// Funcoes da classe
//==============================================================================


#undef  __FUNCT__
#define __FUNCT__ "Langmuir :: Langmuir (const Real&, const Real&)"
Langmuir :: Langmuir    (   const Real&     _qmax
                        ,   const Real&     _k1
                        )
                        :   TwoParameters(_qmax, _k1)
{


    try {

            if (_qmax <= 0.0)  throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadQmaxLEZero
                                    );

            if (_k1 <= 0.0)  throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadK1LEZero
                                    );

    } catch (const IsoException& _isoExcept) {

        std::cout << _isoExcept << "\n";
exit(EXIT_FAILURE);
    }

    setup = true;

    }

//==============================================================================
// Construtores
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "Real Langmuir ::  Qe (const Real&, const Real&) const "
Real Langmuir ::  Qe    (   const Real& _ce
                        ,   const Real&
                        ) const 
{

    try {

        if (!setup) throw
                IsoException    (   IST_LOC
                                ,   className()
                                ,   BadCoefficient
                                );

        if (_ce <= 0.0)  throw
                IsoException    (   IST_LOC
                                ,   className()
                                , BadCeLTZero
                                );

    } catch (const IsoException& _isoExcept) {

        std::cout   << _isoExcept 
                    << "\n";
        exit(EXIT_FAILURE);
    }

auto    ptrValue    = std::begin(coeffValue);
auto    auxi        = *(ptrValue + 1) * _ce;
auto    value       = *ptrValue * auxi / (1.0 + auxi);

    return  (value >= ZERO ? value : 0.0);

}

}