//==============================================================================
// Name        : HarkinsJura.cpp
// Authors     : Aline Zuliani Lunkes
//               Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equacoes da isoterma de Harkin-Jura
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

#include <cmath>                // log10 e sqrt
#include <iostream>
#include <sstream>

//==============================================================================
// includes da lib IsothermLib
//==============================================================================

#include <Error/IsoException.h>
#include <Isotherm/TwoParameters/HarkinsJura.h>


namespace ist {

//==============================================================================
// Variaveis estaticas
//==============================================================================

VecPairString       detailsHarkinsJura
    {
        PairString  ( "K1"
                    , "Constante da isoterma de Harkins-Jura")
    ,   PairString  ( "K2"
                    , "Constante da isoterma de Harkins-Jura")
    };

template<>
VecPairString IsothermTemplate < HarkinsJura >::infoIsotherm = detailsHarkinsJura;

//==============================================================================
// Funcoes da classe
//==============================================================================


#undef  __FUNCT__
#define __FUNCT__ "HarkinsJura :: HarkinsJura (const Real&, const Real&)"
HarkinsJura :: HarkinsJura    (   const Real&     _k1
                            ,   const Real&     _k2
                            ) 
                            : TwoParameters(_k1, _k2)
{


    try {

            if (_k1 <= 0.0)  throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadK1LEZero
                                    );

            if (_k2 < 0.0)  throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadK2LTZero
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
#define __FUNCT__ "HarkinsJura ::  Qe (const Real&, const Real&)"
Real
HarkinsJura ::  Qe   ( const Real& _ce
                    , const Real&
                    ) const  
{

    try {

        if (!setup) throw
            IsoException    (   IST_LOC
                            ,   className()
                            ,   BadCoefficient
                            );
        
        if (_ce <= 0.0)  throw
            IsoException    (  IST_LOC
                            , className()
                            , BadCeLEZero
                            );

    } catch (const IsoException& _isoExcept) {

        std::cout   << _isoExcept 
                    << "\n";
        exit(EXIT_FAILURE);

    }

auto    ptrValue = std::begin(coeffValue);
auto    logCe    = log10(_ce);

    try {

        if (logCe > (*(ptrValue + 1))) {

            std::stringstream   sstr;
            sstr    << "C = "
                    << _ce
                    << " e K_2 = "
                    << *(ptrValue + 1)
                    << " e log(C) = "
                    << logCe;
            throw IsoException      (   IST_LOC
                                    ,   className()
                                    ,   BadLogCeGTK2
                                    ,   sstr.str());
        }


    } catch (const IsoException& _isoExcept) {

        std::cout   << _isoExcept 
                    << "\n";
        exit(EXIT_FAILURE);

    }

auto value = sqrt((*ptrValue) / (*(ptrValue + 1) - logCe));


    return  (value >= ZERO ? value : 0.0) ;

}

}