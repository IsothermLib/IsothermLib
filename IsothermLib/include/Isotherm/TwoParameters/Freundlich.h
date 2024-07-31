//==============================================================================
// Name        : Freundlich.h
// Authors     : Aline Zuliani Lunkes
//               Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equações da isoterma de Freundlich
//
// Copyright   : Copyright (C) 2024 Joao Flavio Vieira de Vasconcellos 
//                                      (jflavio@iprj.uerj.br)
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

/** @defgroup Freundlich Freundlich
 *  @ingroup IsothermTwo_Parameters
 *  @brief Classe Freundlich contém a equação da isoterma de Freundlich.
 *  @{
 */

/// @file Freundlich.h
/// @brief Contém a definição da classe Freundlich


#ifndef FREUNDLICH_H
#define FREUNDLICH_H

//==============================================================================
// includes da isotherm++
//==============================================================================

#include <Isotherm/TwoParameters/TwoParameters.h>
#include <memory>
#include <stdexcept>

namespace ist {


    
/**
 * @brief Classe com as equações da isoterma de Freundlich.
 * 
 * Isoterma com dois parâmetros, \f$ K_1 \f$ e \f$ K_2 \f$, cujas fórmulas são as seguintes:
 * \f[
 * Q_e(C_e) = K_1 C_e^{\frac{1}{K_2}}
 * \f]
 * 
 * Um artigo de referência pode ser encontrado [aqui](https://www.degruyter.com/document/doi/10.1515/zpch-1907-5723/html).
 */
class Freundlich : public virtual TwoParameters, public IsothermTemplate<Freundlich> {
public:
    /**
     * @brief Construtor padrão.
     * 
     * Cria um objeto `Freundlich` com valores padrão.
     */
    Freundlich() = default;

    /**
     * @brief Construtor de cópia.
     * 
     * @param _orig Objeto `Freundlich` a ser copiado.
     */
    Freundlich(const Freundlich& _orig) = default;

    /**
     * @brief Destrutor.
     */
    ~Freundlich() override = default;

    /**
     * @brief Construtor com parâmetros.
     * 
     * @param _k1 Coeficiente de distribuição em [M/M].
     * @param _k2 Fator de correção.
     * 
     * @exception std::invalid_argument Se `_k1` ou `_k2` forem menores ou iguais a zero.
     */
    Freundlich(const Real& _k1, const Real& _k2);

    /**
     * @brief Sobrecarga do operador de atribuição.
     * 
     * @param _orig Objeto `Freundlich` a ser atribuído.
     * @return Referência para o objeto atual.
     */
    Freundlich& operator=(const Freundlich& _orig) = default;

    /**
     * @brief Obtém o valor do coeficiente de distribuição em [M/M].
     * 
     * @return Coeficiente de distribuição em [M/M].
     */
    [[nodiscard]] inline Real K1() const {
        return Value(0);
    }

    /**
     * @brief Obtém o valor do fator de correção.
     * 
     * @return Fator de correção.
     */
    [[nodiscard]] inline Real K2() const {
        return Value(1);
    }

    /**
     * @brief Define o valor do coeficiente de distribuição em [M/M].
     * 
     * @param _k1 Novo valor do coeficiente de distribuição em [M/M].
     * 
     * @exception std::invalid_argument Se `_k1` for menor ou igual a zero.
     */
    inline void K1(const Real& _k1) {
        *this = Freundlich(_k1, Value(1));
    }

    /**
     * @brief Define o valor do fator de correção.
     * 
     * @param _k2 Novo valor do fator de correção.
     * 
     * @exception std::invalid_argument Se `_k2` for menor ou igual a zero.
     */
    inline void K2(const Real& _k2) {
        *this = Freundlich(Value(0), _k2);
    }

    /**
     * @brief Calcula a quantidade de sorção no equilíbrio.
     * 
     * @param _c Concentração do soluto.
     * @param _temp Parâmetro de temperatura, não utilizado neste modelo.
     * 
     * @return Quantidade de sorção no equilíbrio.
     * 
     * @exception std::invalid_argument Se `_c` for menor que zero.
     */
    [[nodiscard]] Real Qe(const Real& _c, const Real& _temp = 0) const override;

    /**
     * @brief Cria uma cópia da implementação da isoterma.
     * 
     * @return Ponteiro para a cópia da implementação da isoterma.
     */
    [[nodiscard]] std::unique_ptr<Isotherm> CloneImplementation() const override {
        return std::make_unique<Freundlich>(*this);
    }

private:
    Real invK2 = 0.0; ///< Valor auxiliar para cálculos internos.
};

} // namespace ist

#endif // FREUNDLICH_H

/** @} */
