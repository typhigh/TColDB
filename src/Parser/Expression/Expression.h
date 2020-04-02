#pragma once
#include "../ExprNode.h"
#include "../../Columns/Tuple.h"
#include "../../Columns/Field/Field.h"
namespace Parser {
using FieldNames = std::vector<std::string>;
using EValue = Columns::FieldPtr;

class Expression
{
private:
/// Copy/Free Operation
public:
    /// Deep copy a expr 
    static ExprNode* Copy(const ExprNode* expr);
    
    /// Deep copy a expr-list
    static ExprNodeList* Copy(const ExprNodeList* exprs);

    /// Deep free a expr
    static void Free(ExprNode* expr);

    /// Deep free a expr-list
    static void Free(ExprNodeList* exprs);

public:
    /// Is a expr aggregate
    static bool IsAggregate(const ExprNode* expr);
    
    /// Is a expr-list aggregate
    static bool IsAggregate(const ExprNodeList* epxrs);
    
    /// Is a expr a column ref
    static bool IsColumnRef(const ExprNode* expr);

    /// IS a expr a leaf node
    static bool IsLeafNode(const ExprNode* expr);

    /// Is a expr a unary expr
    static bool IsUnary(const ExprNode* expr);

    /// Get the columns ref of the expr
    static FieldNames GetColumnsRef(const ExprNode* expr);

    /// Get the columns ref of the expr list
    static FieldNames GetColumnsRef(const ExprNodeList* expr);

/// Eval Operation
public:
    static EValue Eval(const ExprNode* expr, Columns::TuplePtr tuple);
    static EValue EvalLeafNode(const ExprNode* expr, Columns::TuplePtr tuple);

/// Const Optimize Expreesion Operation
public:
    static void ConstOptimize(ExprNode* expr); 
    static bool IsConstVal (const ExprNode* expr);

private:
    /// Append other to result
    static void Append(FieldNames& result, const FieldNames& other);
};


}