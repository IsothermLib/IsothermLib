//=====================================================================================
// Name        : Freundlich.cpp
// Authors     : Aline Zuliani Lunkes
//               Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equacoes da isoterma de Freundlich
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

//==============================================================================
// includes lib c++
//==============================================================================

#include <cfenv>                    // std::feclearexcept
#include <cmath>                    // pow
#include <iostream>                 // std::cout

#pragma STDC FENV_ACCESS on

//==============================================================================
// includes da lib IsothermLib
//==============================================================================

#include <Error/IsoException.h>
#include <Isotherm/TwoParameters/Freundlich.h>

namespace ist {

//==============================================================================
// Variaveis estaticas
//==============================================================================

VecPairString       detailsFreundlich
    {
        PairString  ( "K1"
                    , "Coeficiente de distribuicao")
    ,   PairString  ( "K2"
                    , "Fator de correcao")};

template<>
VecPairString IsothermTemplate < Freundlich >::infoIsotherm = detailsFreundlich;


//==============================================================================
// Construtora com dois parametros
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "Freundlich (const Real&, const Real&)"
Freundlich :: Freundlich    (   const Real&         _k1
                            ,   const Real&         _k2)
                            :   TwoParameters(_k1, _k2)
{

    try {
        
            if (_k1 <= 0.0)  throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadK1LEZero
                                    );

            if (_k2 <= 0.0)  throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadK2LEZero
                                    );

    } catch (const IsoException& _isoExcept) {

        std::cout   << _isoExcept 
                    << "\n";
        exit(EXIT_FAILURE);

    }

    invK2 = 1.0 /  _k2;
    setup = true;


    }

//==============================================================================
// Concentracao de Equiibrio Qe
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "Real Qe (const Real&, const Real& = 0) const"
Real
Freundlich ::  Qe   (   const Real&         _ce
                    ,   const Real&            
                    ) const
{

Real    expValue;
auto    ptrValue = std::begin(coeffValue);

    try {

        if (!setup) throw
            IsoException    (   IST_LOC
                            ,   className()
                            ,   BadCoefficient
                            );

        if (_ce < 0.0)  throw
                IsoException    (   IST_LOC
                                ,   className()
                                , BadCeLTZero
                                );

        std::feclearexcept(FE_ALL_EXCEPT);
        expValue = pow(_ce, invK2);

        if(std::fetestexcept(FE_OVERFLOW)) throw
                IsoException    (   IST_LOC
                                ,   className()
                                ,   BadOverFlow
                                );

    } catch (const IsoException& _isoExcept) {

        std::cout   << _isoExcept 
                    << "\n";
        exit(EXIT_FAILURE);
        
    }


auto    value    = *ptrValue * expValue ;

    return (value >= ZERO ? value : 0.0) ;

}

}