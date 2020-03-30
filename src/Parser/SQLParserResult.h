#pragma once
#include "IAST.h"
#include <memory>
namespace Parser {

class SQLParserResult
{
private:
    IAST* sqlResult;
    char* errorMsg;
public:
    SQLParserResult() {}
    ~SQLParserResult() {
        delete errorMsg;
        delete sqlResult;
    }

    /// Set parser sql result
    void Set(IAST* sqlResult) {
        this->sqlResult = sqlResult;
    }

    /// Get the stmt as iast form
    IAST* Get() {
        return sqlResult;
    }
    
    /// Set Error msg
    void SetError(const char* msg) {
        errorMsg = const_cast<char*>(msg);
    }

    const char* GetErrorMsg() const {
        return errorMsg;
    }
};

using SQLParserResultPtr = std::shared_ptr<SQLParserResult>;
} 