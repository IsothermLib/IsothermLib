//==============================================================================
// Name        : Elovich.cpp
// Authors     : Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
//               Iasmim Barboza Storck
// Version     : 1.0
// Description : Classe com as equacoes da isoterma de Elovich
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
// includes da lib IsothermLib
//==============================================================================

#include <cmath>                    // exp
#include <iostream>                 // std::cout

//==============================================================================
// includes da lib IsothermLib
//==============================================================================

#include <Error/IsoException.h>
#include <Isotherm/TwoParameters/Elovich.h>
#include <Misc/NewtonRaphson.h>


namespace ist {

//==============================================================================
// Variaveis estaticas
//==============================================================================

VecPairString       detailsElovich
    {
        PairString  ( "Qmax"
                    , "Capacidade maxima de adsorcao")
    ,   PairString  ( "K1"
                    , "Constante da isoterma de Elovich")
    };

template<>
VecPairString IsothermTemplate < Elovich >::infoIsotherm = detailsElovich;


//==============================================================================
// Construtora com dois parametros
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "Elovich :: Elovich (const Real&, const Real&)"
Elovich :: Elovich  (   const Real& _qmax
                    ,   const Real& _k1
                    )
                    :   TwoParameters(  _qmax, _k1)
{

    try {
            if (_qmax <= 0.0)  throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadQmaxLEZero);

            if (_k1 <= 0.0)  throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadK1LEZero);

    } catch (const IsoException& _isoExcept) {

        std::cout   << _isoExcept 
                    << "\n";
        exit(EXIT_FAILURE);

    }

    setup = true;

}

//==============================================================================
// Concentracao Qe
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "Real Elovich ::  Qe (const Real&, const Real&) "
Real
Elovich ::  Qe (   const Real& _ce
               ,   const Real& ) const
{

    try {

        if (!setup) throw
            IsoException    (   IST_LOC
                            ,   className()
                            ,   BadCoefficient);

        if (_ce <= 0.0)  throw
                IsoException    (   IST_LOC
                                ,   className()
                                ,   BadCeLEZero);

    } catch (const IsoException& _isoExcept) {

        std::cout   << _isoExcept 
                    << "\n";
        exit(EXIT_FAILURE);;
    }


const_cast<Real&>(auxiCe) = _ce * this->K1();
auto fp    = std::bind(&Elovich::FQe, *this, std::placeholders::_1);
auto theta = NewtonRaphson (fp, 0.5);
auto value =  theta * Qmax();

    return  (value >= ZERO ? value : 0.0);

}

#undef  __FUNCT__
#define __FUNCT__ "Real  Elovich ::  FQe (const Real&) const"
Real
Elovich ::  FQe (const Real& _theta) const
{

    return _theta - auxiCe * exp (- _theta);

}

}
