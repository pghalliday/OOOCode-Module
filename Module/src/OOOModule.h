#ifndef OOOModule_H
#define OOOModule_H

#include "OOOCode.h"

#define OOOModuleExport(MODULE, CLASS)	OOOCall(MODULE, set, OOOQuote(CLASS), OOOPaste(CLASS, _construct))

#define OOOModuleDeclare(CLASS)			OOOPaste(CLASS, _constructor) OOOPaste(CLASS, _construct) = NULL
#define OOOModuleLink(MODULE, CLASS)	OOOPaste(CLASS, _construct) = (OOOPaste(CLASS, _constructor)) OOOCall(MODULE, get, OOOQuote(CLASS))

#define OOOClass OOOModule
OOODeclare()
	OOOImplements
	OOOImplementsEnd
	OOOExports
		OOOExport(void, set, char * szClassName, void * pConstructor)
		OOOExport(void *, get, char * szClassName)
	OOOExportsEnd
OOODeclareEnd
#undef OOOClass

#endif
