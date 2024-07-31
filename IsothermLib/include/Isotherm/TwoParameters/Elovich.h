//==============================================================================
// Name        : Elovich.h
// Authors     : Aline Zuliani Lunkes
//               Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               João Flávio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equações da isoterma de Elovich
//
// Copyright   : Copyright (C) 2024 João Flávio Vieira de Vasconcellos 
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

/** @defgroup Elovich Elovich
 *  @ingroup IsothermTwo_Parameters
 *  @brief Classe Elovich contém a equação da isoterma de Elovich.
 *  @{
 */

/// @file Elovich.h
/// @brief Contém a definição da classe Elovich


#ifndef ISO_ELOVICH_H
#define ISO_ELOVICH_H

#include <Isotherm/TwoParameters/TwoParameters.h>
#include <memory>

namespace ist {

/**
 * @brief Classe com as equações da isoterma de Elovich.
 * 
 *  Isoterma com dois parâmetros, \f$ q_{max} \f$ e \f$ K_1 \f$, cujas fórmulas são as seguintes:
 * 
 * \f[
 * Q_e (C_e) = q_{max} \theta
 * \f]
 * 
 * \f[
 * \theta = K_1 C_e e^{-\theta}
 * \f]
 * 
 * Um artigo de referência pode ser encontrado [aqui](https://doi.org/10.1007/BF00908016).
 */
class Elovich : public virtual TwoParameters, public IsothermTemplate<Elovich> {
public:
    /**
     * @brief Construtor padrão.
     * 
     * Cria um objeto `Elovich` com valores padrão.
     */
    Elovich() = default;

    /**
     * @brief Construtor de cópia.
     * 
     * @param _orig Objeto `Elovich` a ser copiado.
     */
    Elovich(const Elovich& _orig) = default;

    /**
     * @brief Destrutor.
     */
    ~Elovich() override = default;

    /**
     * @brief Construtor com parâmetros.
     * 
     * @param _qmax Capacidade máxima de adsorção.
     * @param _k1 Constante da isoterma de Elovich.
     * 
     * @exception std::invalid_argument Se `_qmax` ou `_k1` forem menores ou iguais a zero.
     */
    Elovich(const Real& _qmax, const Real& _k1);

    /**
     * @brief Sobrecarga do operador de atribuição.
     * 
     * @param _orig Objeto `Elovich` a ser atribuído.
     * @return Referência para o objeto atual.
     */
    Elovich& operator=(const Elovich& _orig) = default;

    /**
     * @brief Obtém o valor da capacidade máxima de adsorção.
     * 
     * @return Capacidade máxima de adsorção em [M/M].
     */
    [[nodiscard]] inline Real Qmax() const
    {
        return Value(0);
    }

    /**
     * @brief Obtém o valor da constante de equilíbrio de Elovich.
     * 
     * @return Constante de equilíbrio de Elovich.
     */
    [[nodiscard]] inline Real K1() const
    {
        return Value(1);
    }

    /**
     * @brief Define o valor da capacidade máxima de adsorção.
     * 
     * @param _qmax Novo valor da capacidade máxima de adsorção.
     * 
     * @exception std::invalid_argument Se `_qmax` for menor ou igual a zero.
     */
    inline void Qmax(const Real& _qmax)
    {
        if (_qmax <= 0) {
            throw std::invalid_argument("_qmax deve ser maior que zero");
        }
        *this = Elovich(_qmax, Value(1));
    }

    /**
     * @brief Define o valor da constante de equilíbrio de Elovich.
     * 
     * @param _k1 Novo valor da constante de equilíbrio de Elovich.
     * 
     * @exception std::invalid_argument Se `_k1` for menor ou igual a zero.
     */
    inline void K1(const Real& _k1)
    {
        if (_k1 <= 0) {
            throw std::invalid_argument("_k1 deve ser maior que zero");
        }
        *this = Elovich(Value(0), _k1);
    }

    /**
     * @brief Calcula a quantidade de adsorção no equilíbrio.
     * 
     * @param _c Concentração do soluto.
     * @param _temp Parâmetro de temperatura, não utilizado neste modelo.
     * 
     * @return Quantidade de adsorção no equilíbrio.
     * 
     * @exception std::invalid_argument Se `_c` for menor que zero.
     */
    [[nodiscard]] Real Qe(const Real& _c, const Real& _temp) const override;

    /**
     * @brief Calcula a quantidade de adsorção no equilíbrio com temperatura padrão.
     * 
     * @param _c Concentração do soluto.
     * 
     * @return Quantidade de adsorção no equilíbrio.
     */
    [[nodiscard]] inline Real Qe(const Real& _c) const override
    {
        return Qe(_c, 0);
    }

    /**
     * @brief Cria uma cópia da implementação da isoterma.
     * 
     * @return Ponteiro para a cópia da implementação da isoterma.
     */
    [[nodiscard]] std::unique_ptr<Isotherm> CloneImplementation() const override
    {
        return std::make_unique<Elovich>(*this);
    }

private:
    /**
     * @brief Calcula o valor da função auxiliar `FQe`.
     * 
     * @param _c Concentração do soluto.
     * 
     * @return Valor da função auxiliar `FQe`.
     */
    [[nodiscard]] Real FQe(const Real& _c) const;

    Real auxiCe = 0; ///< Valor auxiliar para cálculos internos.
};

} // namespace ist

#endif // ISO_ELOVICH_H

/** @} */
