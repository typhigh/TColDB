#include "FieldsCreator.h"
#include "../../Parser/defs.h"

namespace Columns {

class Convertion
{
public:
    static FieldPtr Convert(FieldPtr field, Parser::FieldType_t type);
};

}