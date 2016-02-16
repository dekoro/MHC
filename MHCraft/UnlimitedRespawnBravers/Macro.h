#ifndef _GSYSTEM_MACRO_H_
#define _GSYSTEM_MACRO_H_

#include "GSystemHub.h"

class Debug;

#define SAFE_DELETE(x){\
	if(x != NULL){\
		delete(x);\
		x = NULL;\
	}\
}

#define SAFE_FREE(x){\
	if(x != NULL){\
		free(x);\
		x = NULL;\
	}\
}

#define ERROR_RETURN(message, returnValue){\
	Debug::Alert(message);\
	return returnValue;\
}
#define ERROR_RETURN_VOID(message){\
	Debug::Alert(message);\
	return;\
}
#define FAST_RETURN_VOID(returnFlag){\
	if (returnFlag){ return; }\
}

#define FAST_RETURN_AND_ERROR_VOID(returnFlag, message){\
	if (returnFlag){\
		ERROR_RETURN_VOID(message);\
	}\
}

#define FAST_RETURN_AND_ERROR(returnFlag, message, returnValue){\
	if (returnFlag){\
		ERROR_RETURN(message, returnValue);\
	}\
}

#define CHECK_OVER_ARRAY(arrayList, index){\
	(index<0 || index > arrayList.Count)\
}

#define STR(startMessage, leftMessage){\
	std::string(startMessage)+leftMessage\
}

#endif