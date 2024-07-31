//==============================================================================
// Name        : Isotherm.h
// Authors     : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               João Flávio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe base da biblioteca IsothermLib++
//
// Copyright   : Copyright (C) <2022>  João Flávio Vasconcellos 
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


/** @defgroup Isotherm Isotherm 
 *  @ingroup Isotherm_Base
 *  @brief Classe base de todas as isotermas.
 *  @{
 */

/// @file Isotherm.h
/// @brief Define a classe base para todas as isotermas

#ifndef __ISOTHERM_H__
#define __ISOTHERM_H__

//==============================================================================
// include da lib c++ 
//==============================================================================

#include <functional>       // std::function
#include <memory>           // std::shared_ptr
#include <vector>           // std::vector

//==============================================================================
// include da Isotherm++
//==============================================================================

#include <Misc/ID.h>

namespace ist {

//==============================================================================
// typedef
//==============================================================================

typedef std::pair <std::string, std::string> PairString; 
typedef std::vector <PairString> VecPairString; 
typedef std::vector <Real> VecReal;
typedef std::function<Real(const Real&, const Real&)> FunctionEscala;

//==============================================================================
// classe isotherm
//==============================================================================

/**
 * @brief Classe base para todas as isotermas
 */
    
class Isotherm {
    
//==============================================================================
// ID da classe
//==============================================================================

public:

    DefineIdentityBase  (   "Isotherm"
                        ,   ID::Isotherm
                        );

//==============================================================================
// constantes do modelo
//==============================================================================

protected:

    inline static const Real RGASCONST = 8.31446261815324L;

//==============================================================================
// Funções friend
//==============================================================================

public:

    friend std::ostream & operator << (std::ostream &, const Isotherm&);

//==============================================================================
// Construtoras / Destrutora
//==============================================================================

public:

    /**
     * @brief Construtora padrão.
     */
    Isotherm() = default;

    /**
     * @brief Construtora de cópia.
     */
    Isotherm(const Isotherm&) = default;

    /**
     * @brief Destrutora.
     */
    virtual ~Isotherm() = default;

//==============================================================================
// Sobrecarga de operadores
//==============================================================================

protected:

    /**
     * @brief Sobrecarga do operador de atribuição.
     * 
     * @param other Outra instância de Isotherm.
     * @return Referência para a instância atual.
     */
    Isotherm& operator = (const Isotherm& other) = default;

//==============================================================================
// Funções inline
//==============================================================================

public:

    /**
     * @brief Calcula a derivada da quantidade adsorvida em relação à concentração.
     * 
     * @param _ce Concentração de equilíbrio.
     * @param _temperature Temperatura (opcional).
     * @return Derivada da quantidade adsorvida em relação à concentração.
     */
    [[nodiscard]] inline Real DQDC (const Real& _ce, const Real& _temperature = 0) const
    {
        const Real PERC (1e-06);

        if (_ce > 0.0)
        {
            return  0.5 * ( Qe(_ce * (1 + PERC), _temperature) -
                            Qe(_ce * (1 - PERC), _temperature))
                    / (_ce * PERC);
        }

        return  (Qe(PERC, _temperature) - Qe(0, _temperature)) / PERC;
    }

//==============================================================================
// Funções
//==============================================================================

public:

    /**
     * @brief Plota um gráfico da isoterma.
     * 
     * @param filename Nome do arquivo.
     * @param xscale Função de conversão de escala para o eixo x.
     * @param yscale Função de conversão de escala para o eixo y.
     * @param numPoints Número de pontos.
     * @param startValue Valor inicial.
     * @param endValue Valor final.
     * @param temperature Temperatura (opcional).
     */
    void PlotGraph  (   const std::string& filename,
                        const FunctionEscala& xscale,
                        const FunctionEscala& yscale,
                        const UInt& numPoints,
                        const Real& startValue,
                        const Real& endValue,
                        const Real& temperature = 0) const;

//==============================================================================
// Funções puramente virtuais
//==============================================================================

public:

    /**
     * @brief Calcula a quantidade adsorvida em equilíbrio.
     * 
     * @param _ce Concentração de equilíbrio.
     * @param _temperature Temperatura.
     * @return Quantidade adsorvida.
     */
    [[nodiscard]] 
    virtual Real Qe  ( const Real& _ce, const Real& _temperature) const = 0;

    /**
     * @brief Retorna uma string com o código da isoterma.
     * 
     * @param _index Índice da isoterma.
     * @return String com o código.
     */
    [[maybe_unused]] virtual std::string CodeString (const UInt& _index) const;

    /**
     * @brief Retorna uma string com o nome da isoterma.
     * 
     * @param _index Índice da isoterma.
     * @return String com o nome.
     */
    [[maybe_unused]] virtual std::string NameString (const UInt& _index) const;

    /**
     * @brief Calcula a quantidade adsorvida em equilíbrio para uma determinada concentração.
     * 
     * @param _x Concentração.
     * @return Quantidade adsorvida.
     */
    [[nodiscard]] virtual Real Qe ( const Real& _x ) const
    {
        return Qe(_x, 0);
    };
  
    /**
     * @brief Clona a instância atual da isoterma.
     * 
     * @return Um ponteiro único para a nova instância clonada.
     */
    [[nodiscard]]    
    virtual std::unique_ptr<Isotherm> Clone()  const 
    {
        return CloneImplementation();
    }   

    /**
     * @brief Implementação da função de clonagem.
     * 
     * @return Um ponteiro único para a nova instância clonada.
     */
    [[nodiscard]]
    virtual std::unique_ptr<Isotherm> CloneImplementation() const = 0;        

//==============================================================================
// Variáveis da classe
//==============================================================================

protected:

    /**
     * @brief Retorna informações sobre a isoterma.
     * 
     * @return Vetor de pares de strings com informações sobre a isoterma.
     */
    virtual const VecPairString& InfoIsotherm() const = 0;

//==============================================================================
// Sobrecarga de iteradores
//==============================================================================

public:

    /**
     * @brief Sobrecarga do operador begin().
     * 
     * @return Iterador para o início das informações da isoterma.
     */
    inline auto begin() const { return InfoIsotherm().begin(); }

    /**
     * @brief Sobrecarga do operador end().
     * 
     * @return Iterador para o final das informações da isoterma.
     */
    inline auto end() const { return InfoIsotherm().end(); }

    /**
     * @brief Sobrecarga do operador cbegin().
     * 
     * @return Iterador constante para o início das informações da isoterma.
     */
    [[nodiscard]] inline auto cbegin() const { return InfoIsotherm().cbegin(); }

    /**
     * @brief Sobrecarga do operador cend().
     * 
     * @return Iterador constante para o final das informações da isoterma.
     */
    inline auto cend() const { return InfoIsotherm().cend(); }

    /**
     * @brief Sobrecarga do operador rbegin().
     * 
     * @return Iterador reverso para o início das informações da isoterma.
     */
    inline auto rbegin() const { return InfoIsotherm().rbegin(); }

    /**
     * @brief Sobrecarga do operador rend().
     * 
     * @return Iterador reverso para o final das informações da isoterma.
     */
    inline auto rend() const { return InfoIsotherm().rend(); }

    /**
     * @brief Sobrecarga do operador crbegin().
     * 
     * @return Iterador reverso constante para o início das informações da isoterma.
     */
    inline auto crbegin() const { return InfoIsotherm().crbegin(); }

    /**
     * @brief Sobrecarga do operador crend().
     * 
     * @return Iterador reverso constante para o final das informações da isoterma.
     */
    inline auto crend() const { return InfoIsotherm().crend(); }

protected:

    /**
     * @brief Sobrecarga do operador begin() para acesso não-constante.
     * 
     * @return Iterador para o início das informações da isoterma.
     */
    inline auto begin() { return InfoIsotherm().begin(); }

    /**
     * @brief Sobrecarga do operador end() para acesso não-constante.
     * 
     * @return Iterador para o final das informações da isoterma.
     */
    inline auto end() { return InfoIsotherm().end(); }

    /**
     * @brief Sobrecarga do operador rbegin() para acesso não-constante.
     * 
     * @return Iterador reverso para o início das informações da isoterma.
     */
    inline auto rbegin() { return InfoIsotherm().rbegin(); }

    /**
     * @brief Sobrecarga do operador rend() para acesso não-constante.
     * 
     * @return Iterador reverso para o final das informações da isoterma.
     */
    inline auto rend() { return InfoIsotherm().rend(); }

//==============================================================================
// Acesso às variáveis
//==============================================================================

protected:

    /**
     * @brief Retorna os coeficientes das isotermas.
     * 
     * @return Vetor de valores reais com os coeficientes.
     */
    [[nodiscard]] inline const VecReal Value() const { return coeffValue; }

    /**
     * @brief Retorna o coeficiente de uma isoterma em uma posição específica.
     * 
     * @param _i Índice do coeficiente.
     * @return Valor do coeficiente.
     */
    [[nodiscard]] inline Real Value (const UInt& _i) const { return coeffValue[_i]; }

    /**
     * @brief Retorna o coeficiente de uma isoterma em uma posição específica.
     * 
     * @param _i Índice do coeficiente.
     * @return Valor do coeficiente.
     */
    inline Real Value (const UInt& _i) { return coeffValue[_i]; }

    /**
     * @brief Define o coeficiente de uma isoterma em uma posição específica.
     * 
     * @param _i Índice do coeficiente.
     * @param _val Novo valor do coeficiente.
     */
    inline void Value (const UInt& _i, const Real& _val) { coeffValue[_i] = _val; }

//==============================================================================
// Dados privados da classe
//==============================================================================

public:

    /**
     * @brief Retorna o número de constantes de uma isoterma.
     * 
     * @return Número de constantes.
     */
    [[nodiscard]] inline size_t NumberConst () const { return coeffValue.size(); }

//==============================================================================
// Dados privados da classe
//==============================================================================

protected:

    /**
     * @brief Vetor que armazena todos os coeficientes das equações de isotermas.
     */
    VecReal coeffValue;
    bool setup = false;

};

typedef std::shared_ptr<Isotherm> PtrIsotherm;

/** @} */

/** @defgroup IsothermTemplate IsothermTemplate
 *  @ingroup Isotherm_Base
 *  @brief Classe que gerencia o nome e detalhes sobre cada constante dos modelos das isotermas.
 *  @{
 */

/// <summary>
/// Classe que gerencia o nome e detalhes sobre cada constante dos modelos das isotermas.
/// </summary>
template <typename T>
class IsothermTemplate : public virtual Isotherm
{

//==============================================================================
// Sobrecarga de operadores
//==============================================================================

public:

    /**
     * @brief Sobrecarga do operador begin().
     * 
     * @return Iterador para o início das informações da isoterma.
     */
    inline auto begin() const { return InfoIsotherm().begin(); }

    /**
     * @brief Sobrecarga do operador end().
     * 
     * @return Iterador para o final das informações da isoterma.
     */
    inline auto end() const { return InfoIsotherm().end(); }

    /**
     * @brief Sobrecarga do operador begin() para acesso não-constante.
     * 
     * @return Iterador para o início das informações da isoterma.
     */
    inline auto begin() { return InfoIsotherm().begin(); }

    /**
     * @brief Sobrecarga do operador end() para acesso não-constante.
     * 
     * @return Iterador para o final das informações da isoterma.
     */
    inline auto end() { return InfoIsotherm().end(); }

    /**
     * @brief Sobrecarga do operador cbegin().
     * 
     * @return Iterador constante para o início das informações da isoterma.
     */
    inline auto cbegin() const { return InfoIsotherm().cbegin(); }

    /**
     * @brief Sobrecarga do operador cend().
     * 
     * @return Iterador constante para o final das informações da isoterma.
     */
    inline auto cend() const { return InfoIsotherm().cend(); }

    /**
     * @brief Sobrecarga do operador rbegin().
     * 
     * @return Iterador reverso para o início das informações da isoterma.
     */
    inline auto rbegin() const { return InfoIsotherm().rbegin(); }

    /**
     * @brief Sobrecarga do operador rend().
     * 
     * @return Iterador reverso para o final das informações da isoterma.
     */
    inline auto rend() const { return InfoIsotherm().rend(); }

    /**
     * @brief Sobrecarga do operador rbegin() para acesso não-constante.
     * 
     * @return Iterador reverso para o início das informações da isoterma.
     */
    inline auto rbegin() { return InfoIsotherm().rbegin(); }

    /**
     * @brief Sobrecarga do operador rend() para acesso não-constante.
     * 
     * @return Iterador reverso para o final das informações da isoterma.
     */
    inline auto rend() { return InfoIsotherm().rend(); }

    /**
     * @brief Sobrecarga do operador crbegin().
     * 
     * @return Iterador reverso constante para o início das informações da isoterma.
     */
    inline auto crbegin() const { return InfoIsotherm().crbegin(); }

    /**
     * @brief Sobrecarga do operador crend().
     * 
     * @return Iterador reverso constante para o final das informações da isoterma.
     */
    inline auto crend() const { return InfoIsotherm().crend(); }

//==============================================================================
// Função privada da classe
//==============================================================================

protected:

    /**
     * @brief Retorna as informações da isoterma.
     * 
     * @return Vetor de pares de strings com as informações.
     */
    const VecPairString& InfoIsotherm() const override { return infoIsotherm; }

//==============================================================================
// Dados privados da classe
//==============================================================================

protected:

    /**
     * @brief Vetor com nome e sigla das constantes de uma isoterma.
     */
    static VecPairString infoIsotherm;
};

}

// Sobrecarga de operadores para a classe Isotherm no namespace std
namespace std
{
    inline auto begin(const ist::Isotherm& _iso) { return _iso.begin(); }
    inline auto end(const ist::Isotherm& _iso) { return _iso.end(); }

    inline auto cbegin(const ist::Isotherm& _iso) { return _iso.cbegin(); }
    inline auto cend(const ist::Isotherm& _iso) { return _iso.cend(); }

    inline auto rbegin(const ist::Isotherm& _iso) { return _iso.rbegin(); }
    inline auto rend(const ist::Isotherm& _iso) { return _iso.rend(); }

    inline auto crbegin(const ist::Isotherm& _iso) { return _iso.crbegin(); }
    inline auto crend(const ist::Isotherm& _iso) { return _iso.crend(); }
}

#endif /* __ISOTHERM_H__ */
