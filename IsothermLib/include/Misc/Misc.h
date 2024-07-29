#ifndef ISOTHERM_MISC_H_
#define ISOTHERM_MISC_H_

/**
 * @defgroup Misc Miscelânea
 * @ingroup Miscelânea
 * Programas com funções acessórias da classe.
 * @{
 */

//============================================================================
// Includes da biblioteca Isotherm
//============================================================================

#include <Misc/Configure.h>

//============================================================================
// Include das funções que não pertencem a nenhuma classe
//============================================================================

/**
 * @brief Imprime uma linha em uma saída específica.
 * @param os O fluxo de saída onde a linha será impressa.
 * @param size O tamanho da linha a ser impressa.
 */
void PrintLine(std::ostream& os, const UInt& size = ist::LSIZE);

#endif /* ISOTHERM_MISC_H_ */

/** @} */
