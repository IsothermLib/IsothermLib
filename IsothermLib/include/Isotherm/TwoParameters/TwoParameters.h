//==============================================================================
// Name        : TwoParameters.h
// Authors     : Aline Zuliani Lunkes
//               Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe base para isotermas com 2 parâmetros
//
// Copyright   : Copyright (C) 2024 Joao Flavio Vasconcellos
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

/** @defgroup TwoParameters TwoParameters
 *  @ingroup Isotherm_Base
 *   @brief Classe base para isotermas com dois parâmetros.
 *  @{
 */


/// @file TwoParameters.h
/// @brief Classe base para todas as isotermas com dois parâmetros



/// <summary>
/// Classe base para todas as isotermas com dois parâmetros.
/// </summary>

#ifndef __ISO__TWOPARAMETERS_H__
#define __ISO__TWOPARAMETERS_H__

//==============================================================================
// Include da isotherm++
//==============================================================================

#include <Isotherm.h>

namespace ist {

/**
 * @brief Classe base para isotermas com dois parâmetros
 * 
 * Esta classe serve como base para todas as isotermas que dependem de dois parâmetros.
 */
    
class TwoParameters : public virtual Isotherm {

//==============================================================================
// ID da classe
//==============================================================================

public:
    /// <summary>
    /// Definição de ID para esta classe para fins de identificação de erros.
    /// </summary>
    DefineIdentity("TwoParameters", ID::TwoParameters);

//==============================================================================
// Construtores / Destrutora
//==============================================================================

protected:
    /// <summary>
    /// Construtora default. Inicializa os parâmetros com 0.0.
    /// </summary>
    TwoParameters() : TwoParameters(0.0, 0.0) {}

    /// <summary>
    /// Construtora de cópia.
    /// </summary>
    /// @param _orig Instância da classe TwoParameters a ser copiada.
    TwoParameters(const TwoParameters&) = default;

    /// <summary>
    /// Destrutora.
    /// </summary>
    ~TwoParameters() override = default;

    /// <summary>
    /// Construtora com parâmetros definidos.
    /// </summary>
    /// @param _par_0 Primeiro parâmetro.
    /// @param _par_1 Segundo parâmetro.
    TwoParameters(const Real& _par_0, const Real& _par_1)
    {
        coeffValue = VecReal({_par_0, _par_1});
    }

//==============================================================================
// Sobrecarga de operadores
//==============================================================================

protected:
    /// <summary>
    /// Sobrecarga do operador de atribuição.
    /// </summary>
    /// @param _orig Instância da classe TwoParameters a ser copiada.
    /// @return Referência para esta instância.
    TwoParameters& operator=(const TwoParameters&) = default;

};

} // namespace ist

#endif /* __ISO__TWOPARAMETERS_H__ */

/** @} */
