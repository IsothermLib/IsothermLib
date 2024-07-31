//==============================================================================
// Name        : Configure.h
// Authors     : Aline Zuliani Lunkes
//               Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               João Flávio Vieira de Vasconcellos
// Version     : 1.0
// Description : Arquivo onde são definidas algumas variáveis de
//               configuração do programa
//
// Copyright   : Copyright (C) <2024>  João Flávio Vasconcellos 
//                                      (jflavio at iprj.uerj.br)
//
// Este programa é software livre: você pode redistribuí-lo e/ou modificá-lo
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
//==============================================================================

/** 
 * @defgroup Configure Configure
 * @ingroup IsothermMisc
 * @brief Definições e variáveis de configuração utilizadas pela biblioteca IsothermLib
 * @{
 */

/// @file Configure.h
/// @brief Arquivo de configuração para a biblioteca IsothermLib

#ifndef ISOTHERM_CONFIG_H_
#define ISOTHERM_CONFIG_H_

//==============================================================================
//  Includes C++
//==============================================================================

#include <iosfwd>          
#include <functional>       
#include <limits>            

//==============================================================================
//  Includes da biblioteca Isotherm
//==============================================================================

#include <Misc/Type.h>

//==============================================================================
//  Definição do namespace
//==============================================================================

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
 * @brief Tamanho padrão da linha utilizada pela função `PrintLine`.
 *
 * Esta constante define o tamanho padrão da linha a ser utilizada em funções
 * de impressão e outras operações relacionadas à exibição de dados.
 */
const UInt LSIZE(0x50); 

} // namespace ist

#endif /* ISOTHERM_CONFIG_H_ */

/** @} */  // Fecha o grupo de documentação `Configure`
