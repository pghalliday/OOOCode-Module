#include "OOOModule.h"

#define OOOClass OOOModule

typedef struct _ModuleEntry ModuleEntry;
struct _ModuleEntry
{
	char * szClassName;
	void * pConstructor;
	ModuleEntry * pNext;
};

OOOPrivateData
	ModuleEntry * pEntries;
OOOPrivateDataEnd

OOODestructor
{
	ModuleEntry * pEntry = OOOF(pEntries);
	ModuleEntry * pLastEntry = NULL;
	while (pEntry)
	{
		pLastEntry = pEntry;
		O_free(pLastEntry->szClassName);
		O_free(pLastEntry);
		pEntry = pEntry->pNext;
	}
}
OOODestructorEnd

OOOMethod(void, set, char * szClassName, void * pConstructor)
{
	ModuleEntry * pEntry = O_malloc(sizeof(ModuleEntry));
	pEntry->pNext = OOOF(pEntries);
	OOOF(pEntries) = pEntry;
	pEntry->szClassName = O_strdup(szClassName);
	pEntry->pConstructor = pConstructor;
}
OOOMethodEnd

OOOMethod(void *, get, char * szClassName)
{
	void * pConstructor = NULL;
	ModuleEntry * pEntry = OOOF(pEntries);
	while (pEntry)
	{
		if (O_strcmp(pEntry->szClassName, szClassName) == 0)
		{
			pConstructor = pEntry->pConstructor;
			break;
		}
		pEntry = pEntry->pNext;
	}
	return pConstructor;
}
OOOMethodEnd

OOOConstructor()
{
	OOOMapMethods
		OOOMapMethod(set)
		OOOMapMethod(get)
	OOOMapMethodsEnd
}
OOOConstructorEnd

#undef OOOClass
