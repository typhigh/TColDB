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

    /// Get a and expr-list by a expr
    static ExprNodeList* GetAndExprs(const ExprNode* expr);

/// Check
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

/// Get informations
public:
    /// Get the columns ref of the expr
    static FieldNames GetColumnsRef(const ExprNode* expr);

    /// Get the columns ref of the expr list
    static FieldNames GetColumnsRef(const ExprNodeList* expr);

    /// ExprNodeList's ToString 
    static std::string ToString(const std::string& prefix, const ExprNodeList* exprs);

    /// ExprNode's ToString
    static std::string ToString(const std::string& prefix, const ExprNode* expr);
    
/// Eval Operation
public:
    static EValue Eval(const ExprNode* expr, Columns::TuplePtr tuple);
    static EValue EvalLeafNode(const ExprNode* expr, Columns::TuplePtr tuple);

/// Const Optimize Expreesion Operation
public:
    static void ConstOptimize(ExprNode* expr);

    static void ConstOptimize(ExprNodeList* exprs);

    static bool IsConstVal (const ExprNode* expr);

private:
    static void GetAndExprs(const ExprNode* expr, ExprNodeList* exprs);
};


}