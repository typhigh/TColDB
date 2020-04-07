#pragma once
#include "Command.h"
#include "../Parser/IAST.h"

namespace Common {
class CommandWrap
{
private:
    /* data */
    CommandPtr data;
    Parser::IAST* parserResult;

public:
    CommandWrap(CommandPtr data) : data(data) {}
    ~CommandWrap() {}

    /// Get Content
    std::string GetContent() const;
    
    /// Set Result
    void SetResult(const std::string& result);
    
    /// Get Result (waiting future Set)
    std::string GetResult();

    /// Get parser result
    Parser::IAST* GetParserResult();

    /// Set parser result
    void SetParserResult(Parser::IAST* parserResult);

    /// Get client id
    ClientID GetClientID() const;

    /// Info
    std::string ToString() const;

};

using CommandWrapPtr = std::shared_ptr<CommandWrap>;
}