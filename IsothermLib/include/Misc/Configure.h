//==============================================================================
// Name        : IsothermConfig.h
// Authors     : Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Arquivo onde são definidas algumas variáveis de
//               configuração do programa
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

/**
 * @file IsothermConfig.h
 * @brief Arquivo de configuração para a biblioteca Isotherm++
 *
 * Este arquivo define variáveis e configurações utilizadas pela biblioteca
 * Isotherm++. Ele inclui os arquivos necessários e define macros para abrir
 * e fechar o namespace da biblioteca. Este arquivo deve ser incluído antes de
 * quaisquer outros arquivos da biblioteca Isotherm++.
 *
 * @authors Lara Botelho Brum, Luan Rodrigues Soares de Souza, Joao Flavio Vieira de Vasconcellos
 * @version 1.0
 * @date 2024
 *
 * @copyright Copyright (C) 2024 Joao Flavio Vasconcellos
 * @license GNU General Public License v3.0
 * @see <http://www.gnu.org/licenses/>
 */

/** @defgroup IsothermConfig Configurações da Biblioteca
 *  @ingroup Miscelânea
 *  @brief Definições e variáveis de configuração utilizadas pela biblioteca Isotherm++.
 *  @{
 */

#ifndef ISOTHERM_CONFIG_H_
#define ISOTHERM_CONFIG_H_

//==============================================================================
//  Includes C++
//==============================================================================

#include <iosfwd>           /**< Inclui definições de fluxo de entrada e saída. */
#include <functional>      /**< Inclui definições de objetos de função e ponteiros. */
#include <limits>          /**< Inclui definições de limites das características dos tipos primitivos. */

//==============================================================================
//  Includes da biblioteca Isotherm
//==============================================================================

#include <Misc/Type.h>    /**< Inclui definições de tipos personalizados utilizados pela biblioteca. */

//==============================================================================
//  Definição do namespace
//==============================================================================

/**
 * @def IST_NAMESPACE_OPEN
 * @brief Macro que define o início do namespace da biblioteca Isotherm++.
 *
 * Esta macro abre um namespace chamado `ist`, que é utilizado para encapsular
 * todas as classes e funções da biblioteca Isotherm++.
 */

/**
 * @brief Define o namespace `ist` e suas constantes.
 *
 * O bloco abaixo abre o namespace `ist`, define algumas constantes e, em seguida,
 * fecha o namespace. Estas constantes podem ser usadas por outras partes da
 * biblioteca.
 */
namespace ist {

/**
 * @brief Valor para zero usado em processos iterativos.
 *
 * Esta constante é definida como um valor grande multiplicado pelo valor mínimo
 * representável por `Real`. É utilizada para representar zero de maneira segura
 * durante iterações numéricas.
 */
const Real ZERO(1e250 * std::numeric_limits<Real>::min()); 

/**
 * @brief Tamanho default da linha utilizada pela função `PrintLine`.
 *
 * Esta constante define o tamanho padrão da linha a ser utilizada em funções
 * de impressão e outras operações relacionadas à exibição de dados.
 */
const UInt LSIZE(0x50); 

// Fecha o namespace `ist`
}

#endif /* ISOTHERM_CONFIG_H_ */

/** @} */  // Fecha o grupo de documentação `IsothermConfig`
