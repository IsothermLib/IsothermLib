//==============================================================================
// Name        : DubininRadushkevich.cpp
// Authors     : Lara Botelho Brum
//               Iasmim Barboza Storck
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equacoes da isoterma de Dubinin-Radushkevich
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

#include <cmath>                    // Para o log
#include <iostream>                 // Para o std::cout

//==============================================================================
// includes da lib IsothermLib
//==============================================================================

#include <Error/IsoException.h>
#include <Isotherm/TwoParameters/DubininRadushkevich.h>


namespace ist {

//==============================================================================
// Variaveis estaticas
//==============================================================================

VecPairString       detailsDubininRadushkevich                      
    {
        PairString  ( "Qmax"
                    , "Constante de equiibrio de Dubinin-Radushkevich")
    ,   PairString  ( "K1"
                    , "Coeficiente associado a energia de adsorcao")};

template<>
VecPairString IsothermTemplate < DubininRadushkevich >::infoIsotherm = detailsDubininRadushkevich; 

//==============================================================================
// Construtora com dois parametros
//==============================================================================


#undef  __FUNCT__
#define __FUNCT__ "DubininRadushkevich :: DubininRadushkevich (const Real&, const Real&, const Real&)"
DubininRadushkevich :: DubininRadushkevich  (   const Real&         _qmax
                                            ,   const Real&         _k1
                                            ,   const Real&         _rgas)
                                            :   TwoParameters ( _qmax,  _k1 )
                                            ,   RGAS (_rgas )
{

    try {

        if (_qmax <= 0.0) {
            throw IsoException  (   IST_LOC
                                ,   className()
                                ,   BadQmaxLEZero
                                );
        }

        if (_k1 <= 0.0) {
            throw IsoException  (   IST_LOC
                                ,   className()
                                ,   BadK1LEZero
                                );
        }

        if (_rgas <= 0.0) {
            throw IsoException  (   IST_LOC
                                ,   className()
                                ,   BadRGasLEZero
                                );
        }

    } catch (const IsoException& _isoExcept) {

        std::cout   << _isoExcept 
                    << std::flush;
        exit(EXIT_FAILURE);
 }

    setup = true;

}

//==============================================================================
// Concentracao de equilibro Qe
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "DubininRadushkevich :: DubininRadushkevich (const Real&, const Real&) const"
Real
DubininRadushkevich ::  Qe  (   const Real&     _ce
                            ,   const Real&     _temp) const
{

    try {

        if (!setup) {
            throw IsoException  (   IST_LOC
                                ,   className() 
                                ,   BadCoefficient
                                );
        }

        if (_ce <= 0.0) {
            throw IsoException  (   IST_LOC
                                ,   className()
                                ,   BadCeLEZero
                                );
        }

        if (_temp <= 0.0) {
            throw IsoException  (   IST_LOC
                                ,   className()
                                ,   BadTempLEZero
                                );
        }

    } catch (const IsoException& _isoExcept) {

        std::cout   << _isoExcept 
                    << "\n";
        exit(EXIT_FAILURE);

    }

auto    ptrValue    = std::begin(coeffValue);
auto    eps         = RGAS * _temp * log(1.0 + (1.0 / _ce));
auto    value       = *ptrValue * exp( - (*(ptrValue + 1) * eps * eps));

    return  (value >= ZERO ? value : 0.0);

}

}