#ifndef ISOTHERM_NEWTONRAPHSON_H_
#define ISOTHERM_NEWTONRAPHSON_H_

/**
 * @defgroup NewtonRaphson Método de Newton-Raphson
 * @ingroup IsothermMisc
 * @brief Programação do método Newton-Raphson para o cálculo de raízes de funções.
 * @{
 */

/// @file NewtonRaphson.h
/// @brief Contém a programação do método Newton-Raphson para o cálculo de raízes de funções


#include <functional>
#include <Misc/Misc.h>

/**
 * @brief Função para o método Newton-Raphson.
 * @param func A função cuja raiz está sendo calculada.
 * @param initial_guess O palpite inicial para a raiz.
 * @return A raiz da função.
 */
Real NewtonRaphson(std::function<Real(Real)> func, const Real& initial_guess);

#endif /* ISOTHERM_NEWTONRAPHSON_H_ */

/** @} */
