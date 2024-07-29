#include <Misc/SourceInfo.h>

namespace ist {

SourceInfo :: SourceInfo    (       const std::string&      _file 
                            ,       const long&             _line
                            ,       const std::string&      _function
                            ) 
                            :       fileLocation(_file) 
                            ,       lineLocation (_line)
                            ,       functionName(_function) 
{
}
        
}