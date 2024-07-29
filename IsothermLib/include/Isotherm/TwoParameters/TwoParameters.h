//==============================================================================
// Name        : TwoParameters.h
// Authors     : Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe base para as isotermas com 2 parametros
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

/** @defgroup TwoParameters
 *  @ingroup Base
 *  Classe base das isotermas com dois parametro.
 *  @{
 */


///  <summary>
///  Classe base para todas as classes com dois parametros.
/// </summary>
///  \authors   Lara Botelho Brum
///  \authors   Luan Rodrigues Soares de Souza
///  \authors   Joao Flavio Vieira de Vasconcellos
///  \version   1.0
///  \date      2022
///  \bug       Nao ha bugs conhecidos.
///
///  \copyright GNU Public License.

#ifndef __ISO__TWOPARAMETERS_H__
#define __ISO__TWOPARAMETERS_H__


//==============================================================================
// include da isotherm++
//==============================================================================

#include <Isotherm.h>



namespace ist {

class TwoParameters :   public virtual Isotherm  {

//==============================================================================
// ID da classe
//==============================================================================

public:

    DefineIdentity  (   "TwoParameters"
                    ,   ID::TwoParameters
                    );

//==============================================================================
// Construtores / Destrutora
//==============================================================================

protected:

    TwoParameters() : TwoParameters( 0.0, 0.0) {};
    TwoParameters(const TwoParameters&) = default;
    ~TwoParameters() override = default;

    TwoParameters   (    const Real&    _par_0      // Primeiro para�metro
                    ,    const Real&    _par_1      // Segundo para�metro
                    )
    {
        coeffValue   = VecReal({_par_0, _par_1});
    }

//==============================================================================
// Sobrecarga de operadores
//==============================================================================

protected:

    TwoParameters& operator = (const TwoParameters&) = default;

};

}

#endif /* __ISO__TWOPARAMETERS_H__ */

/** @} */

