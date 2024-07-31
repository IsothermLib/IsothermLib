//==============================================================================
// Name        : OneParameter.h
// Authors     : Aline Zuliani Lunkes
//               Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe base para as isotermas com um parâmetro
//
// Copyright   : Copyright (C) <2024>  Joao Flavio Vasconcellos 
//                                      (jflavio at iprj.uerj.br)
//
// This program é software livre: você pode redistribuí-lo e/ou modificá-lo
// sob os termos da Licença Pública Geral GNU conforme publicada pela
// Free Software Foundation, na versão 3 da Licença.
//
// Este programa é distribuído na esperança de que seja útil,
// mas SEM NENHUMA GARANTIA; sem mesmo a garantia implícita de
// COMERCIABILIDADE ou ADEQUAÇÃO A UM DETERMINADO FIM. Veja a
// Licença Pública Geral GNU para mais detalhes.
//
// Você deve ter recebido uma cópia da Licença Pública Geral GNU
// junto com este programa. Se não, veja <http://www.gnu.org/licenses/>.
//
//==============================================================================

/** @defgroup OneParameter OneParameter
 *  @ingroup Isotherm_Base
 *  @brief Classe base para isotermas com um parâmetro.
 *  @{
 */

/// @file OneParameter.h
/// @brief Classe base para isotermas com um parâmetro

#ifndef ONEPARAMETER_H
#define ONEPARAMETER_H

//==============================================================================
// include da isotherm++
//==============================================================================
#include <Isotherm.h>

namespace ist {

/**
 * @brief Classe base para isotermas com um parâmetro.
 * 
 * Esta classe serve como base para todas as isotermas que dependem de um único parâmetro.
 */
class OneParameter : public virtual Isotherm {

//==============================================================================
// ID da classe
//==============================================================================

public:
    /// @brief Definição de ID para esta classe para fins de identificação de erros.
    DefineIdentity("OneParameter", ID::OneParameter);

//==============================================================================
// Funções Construtoras/Destrutora
//==============================================================================

public:
    /// @brief Construtora de cópia que será utilizada nas classes derivadas.
    OneParameter(const OneParameter&) = default;

    /// @brief Destrutora.
    virtual ~OneParameter() = default;

    /// @brief Construtora com um parâmetro utilizada nas classes derivadas.
    /// @param value Valor inicial do parâmetro.
    OneParameter(const Real& value = 0.0);

};

}

#endif /* ONEPARAMETER_H */

/** @} */
