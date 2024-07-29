//==============================================================================
// includes lib c++
//==============================================================================

#include <iostream>
#include <cmath>

//==============================================================================
// include da isotherm++
//==============================================================================

#include <Misc/NewtonRaphson.h>
#include <Error/IsoException.h>


#undef  __FUNCT__
#define __FUNCT__ "Real  NewtonRaphson (std::function<Real(Real)> const Real&);"
Real  NewtonRaphson     (       std::function<Real(Real)>      _func
                        ,       const Real&     _ce
                        ) {
 

const Real  TOLE(1e-06);
const UInt  ITERMAX(100);
const UInt  ITERMIN(3);
const Real  DELTA(1e-04);



Real    ce_0(_ce);
Real    ce_1;
Real    fx,
        dfx,
        dc;
UInt    iter(0);

bool    flag1(true),
        flag2(true);

    do {

            fx    = _func(ce_0);
            dfx   = (_func(ce_0 + DELTA) - fx) / DELTA;
            ce_1  = ce_0 - fx / dfx;
            dc    = fabs((ce_1 - ce_0) / ce_1);
            ce_0  = ce_1;
        
            flag1 = fabs(fx) < TOLE && dc < TOLE && iter >= ITERMIN;     // Controle do erro
            flag2 = ++iter > ITERMAX;                                    // Controle do numero maximo de iteracoes


            
    } while (!(flag1 || flag2));
    
    try {
        
            if (flag2)  throw 
                    ist::IsoException   (   ist::IST_LOC
                                        ,   "NewtonRaphson"
                                        ,   ist::ConvergenceProblem); 

    } catch (const ist::IsoException& _isoExcept) {
            
        std::cout   << _isoExcept 
                    << "\n";
        exit(EXIT_FAILURE);
        
    };


    return ce_1;
}

