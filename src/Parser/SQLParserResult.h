#include <memory>
namespace Parser {

class SQLParserResult
{
private:
    
public:
    SQLParserResult();
    ~SQLParserResult();
};

using SQLParserResultPtr = std::shared_ptr<SQLParserResult>;
} 