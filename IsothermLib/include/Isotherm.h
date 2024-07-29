//==============================================================================
// Name        : Isotherm.h
// Authors     : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Jo�o Fl�vio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe base da biblioteca IsothermLib++
//
// Copyright   : Copyright (C) <2022>  Jo�o Fl�vio Vasconcellos 
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


/** @defgroup Isotherm  
 *  @ingroup Base
 *  Classe base de todas as isotermas.
 *  @{
 */

/// <summary>
/// Classe base de todas as outras classes de isotermas.
/// </summary>
///  \authors   Lara Botelho Brum
///  \authors   Luan Rodrigues Soares de Souza
///  \authors   Jo�o Fl�vio Vieira de Vasconcellos
///  \version   1.0
///  \date      2021
///  \bug       N�o h� bugs conhecidos.
///  
///  \copyright GNU Public License.

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

typedef std::pair < std::string, std::string >                 PairString; 
typedef std::vector < PairString >                             VecPairString; 
typedef std::vector < Real >                                   VecReal;
typedef std::function<Real(const Real&, const Real&)>          FunctionEscala;


//==============================================================================
// classe isotherm
//==============================================================================


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

    Isotherm() = default;
    Isotherm(const Isotherm&) = default;
    virtual ~Isotherm() = default;

//==============================================================================
// Sobrecarga de operadores
//==============================================================================

protected:

    Isotherm& operator = (const Isotherm&) = default;

//==============================================================================
// Funções inline
//==============================================================================

public:

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


};

//==============================================================================
// Funções
//==============================================================================

public:

    void PlotGraph  (   const std::string&  // Nome do arquivo
                    ,   const FunctionEscala&     // Funçao de conversao de escala direçao x
                    ,   const FunctionEscala&     // funçao de conversao de escala direçao y
                    ,   const UInt&         // Numero de pontos
                    ,   const Real&         // Valor Inicial
                    ,   const Real&         // Valor final
                    ,   const Real& = 0) const;   // Temperatura, opcional




//==============================================================================
// Funcoes puramente virtuais
//==============================================================================

public:

        [[nodiscard]] 
        virtual Real Qe  ( const Real&, const Real&) const = 0;

        [[maybe_unused]] virtual std::string CodeString (const UInt&) const;

        [[maybe_unused]] virtual std::string NameString (const UInt&) const;

        [[nodiscard]] virtual Real Qe ( const Real& _x ) const
        {
                return Qe(_x, 0);

        };
  
        
    [[nodiscard]]    
    virtual std::unique_ptr<Isotherm> Clone()  const 
    {
        return CloneImplementation();
    }   

    [[nodiscard]]
    virtual std::unique_ptr<Isotherm> CloneImplementation() const = 0;        


//==============================================================================
// Variaveis da classe
//==============================================================================

protected:

virtual const VecPairString&  InfoIsotherm() const = 0;

public:

/// <summary>
/// Sobrecarga do operador begin().
/// </summary>
    inline auto begin() const {return  InfoIsotherm().begin();};

/// <summary>
/// Sobrecarga do operador end().
/// </summary>
    inline auto end() const {return  InfoIsotherm().end();};

    [[nodiscard]] inline auto cbegin() const {return  InfoIsotherm().cbegin();};

/// <summary>
/// Sobrecarga do operador cend().
/// </summary>
    inline auto cend() const {return  InfoIsotherm().cend();};

    inline auto rbegin() const {return  InfoIsotherm().rbegin();};

/// <summary>
/// Sobrecarga do operador rend().
/// </summary>
    inline auto rend() const {return  InfoIsotherm().rend();};

    inline auto crbegin() const {return  InfoIsotherm().crbegin();};

/// <summary>
/// Sobrecarga do operador crend().
/// </summary>
    inline auto crend() const {return  InfoIsotherm().crend();};

protected:

    inline auto begin() {return  InfoIsotherm().begin();};

/// <summary>
/// Sobrecarga do operador end().
/// </summary>
    inline auto end() {return  InfoIsotherm().end();};
    inline auto rbegin() {return  InfoIsotherm().rbegin();};

/// <summary>
/// Sobrecarga do operador rend().
/// </summary>
    inline auto rend() {return  InfoIsotherm().rend();};

//==============================================================================
// Acesso as variaveis
//==============================================================================

protected:

/// <summary>
/// Vetor com os coeficientes de qualquer isoterma.
/// </summary>
[[nodiscard]] inline const VecReal  Value() const {return coeffValue;};
[[nodiscard]] inline Real Value (const UInt& _i) const {return coeffValue[_i];};


inline Real Value (const UInt& _i) {return coeffValue[_i];};
inline void Value (const UInt& _i, const Real& _val) {coeffValue[_i] = _val;};

//==============================================================================
// Dados privados da classe
//==============================================================================

public:

/// <summary>
/// Funçao que retorna o número de constantes de uma isoterma.
/// </summary>
[[nodiscard]] inline size_t NumberConst () const {return coeffValue.size();};

//==============================================================================
// Dados privados da classe
//==============================================================================

protected:

/*!
    Vetor que armazena todos os coeficientes das equações de isotermas
*/
VecReal                                                 coeffValue;
bool                                                    setup = false;

};


typedef std::shared_ptr<Isotherm>                   PtrIsotherm;

/** @} */




/** @defgroup IsothermTemplate  IsothermTemplate
 *  @ingroup Miscelânea
 *  Classe que gerencia o nome e detalhes sobre cada constante dos modelos das isotermas.
 *  @{
 */

/// <summary>
/// Classe que gerencia o nome e detalhes sobre cada constante dos modelos das isotermas.
/// </summary>
///  \authors   Lara Botelho Brum
///  \authors   Luan Rodrigues Soares de Souza
///  \authors   Jo�o Fl�vio Vieira de Vasconcellos
///  \version   1.0
///  \date      2021
///  \bug       N�o h� bugs conhecidos.
///
///  \copyright GNU Public License.


template <typename T>
class IsothermTemplate : public virtual Isotherm
{

//==============================================================================
// Sobrecarga de operadores
//==============================================================================

public:

    inline auto begin() const {return  InfoIsotherm().begin();};
    inline auto end() const {return  InfoIsotherm().end();};

    inline auto begin() {return  InfoIsotherm().begin();};
    inline auto end() {return  InfoIsotherm().end();};

    inline auto cbegin() const {return  InfoIsotherm().cbegin();};
    inline auto cend() const {return  InfoIsotherm().cend();};

    inline auto rbegin() const {return  InfoIsotherm().rbegin();};
    inline auto rend() const {return  InfoIsotherm().rend();};

    inline auto rbegin() {return  InfoIsotherm().rbegin();};
    inline auto rend() {return  InfoIsotherm().rend();};

    inline auto crbegin() const {return  InfoIsotherm().crbegin();};
    inline auto crend() const {return  InfoIsotherm().crend();};

//==============================================================================
// Funçao privada da classe
//==============================================================================

protected:

    const   VecPairString& InfoIsotherm() const override { return infoIsotherm; }

//==============================================================================
// Dados privados da classe
//==============================================================================

protected:

    static VecPairString                    infoIsotherm;       //! Vetor com nome e sigla das constantes de uma isoterma

};


}


namespace std
{

    inline auto begin( const ist::Isotherm& _iso ) {return  _iso.begin();}
    inline auto end( const ist::Isotherm& _iso ) {return  _iso.end();}

    inline auto cbegin( const ist::Isotherm& _iso ) {return  _iso.cbegin();}
    inline auto cend( const ist::Isotherm& _iso ) {return  _iso.cend();}

    inline auto rbegin( const ist::Isotherm& _iso ) {return  _iso.rbegin();}
    inline auto rend( const ist::Isotherm& _iso ) {return  _iso.rend();}

    inline auto crbegin( const ist::Isotherm& _iso ) {return  _iso.crbegin();}
    inline auto crend( const ist::Isotherm& _iso ) {return  _iso.crend();}

}


#endif /* __ISOTHERM_H__ */


