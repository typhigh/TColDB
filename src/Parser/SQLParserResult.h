#include "IAST.h"
#include <memory>
namespace Parser {

class SQLParserResult
{
private:
    IAST* sqlResult;
    
public:
    SQLParserResult();
    ~SQLParserResult();
    void Set(IAST* sqlResult) {
        this->sqlResult = sqlResult;
        
    }

    
};

using SQLParserResultPtr = std::shared_ptr<SQLParserResult>;
} 