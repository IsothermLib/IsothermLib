//=====================================================================================
// Name        : Temkin.cpp
// Authors     : Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
//               Iasmim barboza Storck
// Version     : 1.0
// Description : Classe com as equacoes da isoterma de Temkin
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
#include <cmath>                    // log
#include <iostream>

//==============================================================================
// includes da lib IsothermLib
//==============================================================================

#include <Error/IsoException.h>
#include <Isotherm/TwoParameters/Temkin.h>

namespace ist {

//==============================================================================
// Variaveis estaticas
//==============================================================================

VecPairString       detailsTemkin
    {
        PairString  ( "K1"
                    , "Constante da isoterma de Temkin")
    ,   PairString  ( "K2"
                    , "Constante de ligacao de equiibrio isotermica")
    };

template<>
VecPairString IsothermTemplate < Temkin >::infoIsotherm = detailsTemkin;



//==============================================================================
// Construtora com dois parametros
//==============================================================================


#undef  __FUNCT__
#define __FUNCT__ "Temkin :: Temkin (const Real&, const Real&, const Real&)"
Temkin :: Temkin    (   const Real&     _k1
                    ,   const Real&     _k2
                    ,   const Real&     _rgas
                    ) : TwoParameters(_k1, _k2), RGAS(_rgas) {

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

            if (_rgas <= 0.0)  throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadRGasLEZero
                                    );

        } catch (const IsoException& _isoExcept) {

            std::cout   << _isoExcept 
                        << "\n";
            exit(EXIT_FAILURE);
    }

    setup = true;


    }

//==============================================================================
// Concentracao de Equiibrio Q
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "Real Temkin ::  Qe (const Real&, const Real&) const  "
Real
Temkin ::  Qe   (   const Real&     _ce
                ,   const Real&     _temp) const
{

auto    ptrValue = std::begin(coeffValue);

        try {

            if (!setup) throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadCoefficient
                                    );

            if (_ce <= 0)  throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadCeLEZero
                                    );

            if (_temp <= 0)  throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadTempLEZero
                                    );

            if ((_ce * (*ptrValue)) <= 1)  throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadKCeK1LEOne
                                    );

        } catch (const IsoException& _isoExcept) {

        std::cout   << _isoExcept 
                    << "\n";
        exit(EXIT_FAILURE);
    
    }

auto    auxi = log(_ce * (*ptrValue));
auto    value =  (RGAS * _temp * auxi) / (*(ptrValue + 1));

    return  (value >= ZERO ? value : 0.0);

}

}