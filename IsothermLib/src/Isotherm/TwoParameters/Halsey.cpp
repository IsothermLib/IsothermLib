//==============================================================================
// Name        : Halsey.cpp
// Authors     : Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
//               Iasmim Barboza Storck
// Version     : 1.0
// Description : Classe com as equacoes da isoterma de Halsey
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

#include <cfenv>                    // std::feclearexcept
#include <cmath>                    // pow
#include <iostream>                 // std::cout


#pragma STDC FENV_ACCESS on

//==============================================================================
// includes da lib IsothermLib
//==============================================================================

#include <Error/IsoException.h>
#include <Isotherm/TwoParameters/Halsey.h>

namespace ist {

//==============================================================================
// Variaveis estaticas
//==============================================================================

VecPairString       detailsHalsey
    {
        PairString  ( "K1"
                    , "Constante da isoterma de Halsey")
    ,   PairString  ( "K2"
                    , "Constante de ligacao de equiibrio isotermica")
    };

template<>
VecPairString IsothermTemplate < Halsey >::infoIsotherm = detailsHalsey;


#undef  __FUNCT__
#define __FUNCT__ "Halsey :: Halsey (const Real&, const Real&)"
Halsey :: Halsey    (   const Real& _k1
                    ,   const Real& _k2)
                    : TwoParameters (_k1, _k2)
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

    setup = true;

}

//==============================================================================
// Concentracao de Equilibrio Q
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "Halsey ::  Qe (const Real&, const Real&) const "
Real
Halsey ::  Qe (const Real& _ce, const Real& _temp) const  {

auto    ptrValue = std::begin(coeffValue);
Real    value;

    try {

        if (!setup) throw
            IsoException    (   IST_LOC
                            ,   className()
                            ,   BadCoefficient
                            );

        if (_ce <= 0.0)  throw
                IsoException    (  IST_LOC
                                ,   className()
                                ,   BadCeLEZero
                                );

        std::feclearexcept(FE_ALL_EXCEPT);
        value =  pow( *ptrValue / _ce, 1.0 / *(ptrValue + 1));

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

    return  (value >= ZERO ? value : 0.0);


}

}