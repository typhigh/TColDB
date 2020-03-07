#pragma once
#include "defs.h"
#include "FieldDef.h"
#include "IAST.h"

#include <vector>

namespace Parser {

class ASTTableDef : public IAST {
public:
	virtual ~ASTTableDef() {}
	ASTTableDef() {}
	virtual std::string ToString() const override ;

public:
	char* name;
	std::vector<FieldDef*>* fields;
	std::vector<ASTTableConstraint*>* constraints;
};

using ASTTableDefPtr = std::shared_ptr<ASTTableDef>;

}