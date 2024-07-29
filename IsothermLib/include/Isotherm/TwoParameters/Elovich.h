//==============================================================================
// Name        : Elovich.h
// Authors     : Aline Zuliani Lunkes
//               Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Jo�o Fl�vio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equa��es da isoterma de Elovich
//
// Copyright   : Copyright (C) 2024 Jo�o Fl�vio Vieira de Vasconcellos 
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
 *  @ingroup Two_Parameters
 *  Classe Elovich cont�m a equa��o da isoterma de Elovich.
 *  @{
 */

#ifndef ISO_ELOVICH_H
#define ISO_ELOVICH_H

#include <Isotherm/TwoParameters/TwoParameters.h>
#include <memory>

namespace ist {

/**
 * @brief Implementa a isoterma de Elovich para adsor��o.
 * 
 * A isoterma de Elovich � uma equa��o usada para descrever o processo de adsor��o em fun��o da concentra��o do soluto. 
 * Ela utiliza dois par�metros, \f$ K_1 \f$ e \f$ q_{max} \f$, e suas f�rmulas s�o as seguintes:
 * 
 * \f[
 * Q_e (C_e) = q_{max} \theta
 * \f]
 * 
 * \f[
 * \theta = K_1 C_e e^{-\theta}
 * \f]
 * 
 * Um artigo de refer�ncia pode ser encontrado [aqui](https://doi.org/10.1007/BF00908016).
 * 
 * @authors Iasmim Barboza Storck
 *          Lara Botelho Brum
 *          Luan Rodrigues Soares de Souza
 *          Jo�o Fl�vio Vieira de Vasconcellos
 * @version 1.0
 * @date Julho 2024
 * @bug N�o h� bugs conhecidos.
 * 
 * @copyright GNU Public License.
 */
class Elovich : public virtual TwoParameters, public IsothermTemplate<Elovich> {
public:
    /**
     * @brief Construtor padr�o.
     * 
     * Cria um objeto `Elovich` com valores padr�o.
     */
    Elovich() = default;

    /**
     * @brief Construtor de c�pia.
     * 
     * @param _orig Objeto `Elovich` a ser copiado.
     */
    Elovich(const Elovich& _orig) = default;

    /**
     * @brief Destrutor.
     */
    ~Elovich() override = default;

    /**
     * @brief Construtor com par�metros.
     * 
     * @param _qmax Capacidade m�xima de adsor��o.
     * @param _k1 Constante da isoterma de Elovich.
     * 
     * @exception std::invalid_argument Se `_qmax` ou `_k1` forem menores ou iguais a zero.
     */
    Elovich(const Real& _qmax, const Real& _k1);

    /**
     * @brief Sobrecarga do operador de atribui��o.
     * 
     * @param _orig Objeto `Elovich` a ser atribu�do.
     * @return Refer�ncia para o objeto atual.
     */
    Elovich& operator=(const Elovich& _orig) = default;

    /**
     * @brief Obt�m o valor da capacidade m�xima de adsor��o.
     * 
     * @return Capacidade m�xima de adsor��o em [M/M].
     */
    [[nodiscard]] inline Real Qmax() const
    {
        return Value(0);
    }

    /**
     * @brief Obt�m o valor da constante de equil�brio de Elovich.
     * 
     * @return Constante de equil�brio de Elovich.
     */
    [[nodiscard]] inline Real K1() const
    {
        return Value(1);
    }

    /**
     * @brief Define o valor da capacidade m�xima de adsor��o.
     * 
     * @param _qmax Novo valor da capacidade m�xima de adsor��o.
     * 
     * @exception std::invalid_argument Se `_qmax` for menor ou igual a zero.
     */
    inline void Qmax(const Real& _qmax)
    {
        *this = Elovich(_qmax, Value(1));
    }

    /**
     * @brief Define o valor da constante de equil�brio de Elovich.
     * 
     * @param _k1 Novo valor da constante de equil�brio de Elovich.
     * 
     * @exception std::invalid_argument Se `_k1` for menor ou igual a zero.
     */
    inline void K1(const Real& _k1)
    {
        *this = Elovich(Value(0), _k1);
    }

    /**
     * @brief Calcula a quantidade de adsor��o no equil�brio.
     * 
     * @param _c Concentra��o do soluto.
     * @param _temp Par�metro de temperatura, n�o utilizado neste modelo.
     * 
     * @return Quantidade de adsor��o no equil�brio.
     * 
     * @exception std::invalid_argument Se `_c` for menor que zero.
     */
    [[nodiscard]] Real Qe(const Real& _c, const Real& _temp) const override;

    /**
     * @brief Calcula a quantidade de adsor��o no equil�brio com temperatura padr�o.
     * 
     * @param _c Concentra��o do soluto.
     * 
     * @return Quantidade de adsor��o no equil�brio.
     */
    [[nodiscard]] inline Real Qe(const Real& _c) const override
    {
        return Qe(_c, 0);
    }

    /**
     * @brief Cria uma c�pia da implementa��o da isoterma.
     * 
     * @return Ponteiro para a c�pia da implementa��o da isoterma.
     */
    [[nodiscard]] std::unique_ptr<Isotherm> CloneImplementation() const override
    {
        return std::make_unique<Elovich>(*this);
    }


private:
    /**
     * @brief Calcula o valor da fun��o auxiliar `FQe`.
     * 
     * @param _c Concentra��o do soluto.
     * 
     * @return Valor da fun��o auxiliar `FQe`.
     */
    [[nodiscard]] Real FQe(const Real& _c) const;

    Real auxiCe = 0; ///< Valor auxiliar para c�lculos internos.
};

} // namespace ist

#endif // ISO_ELOVICH_H

/** @} */
