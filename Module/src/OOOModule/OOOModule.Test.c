#include "OOOUnitTestDefines.h"
#include "OOOModule.h"

#define OOOClass MyClass
OOODeclare()
	OOOImplements
	OOOImplementsEnd
	OOOExports
	OOOExportsEnd
OOODeclareEnd
OOOPrivateData
OOOPrivateDataEnd
OOODestructor
{
}
OOODestructorEnd
OOOConstructor()
{
	OOOMapMethods
	OOOMapMethodsEnd
}
OOOConstructorEnd
#undef OOOClass

#define OOOClass YourClass
OOODeclare()
	OOOImplements
	OOOImplementsEnd
	OOOExports
	OOOExportsEnd
OOODeclareEnd
OOOPrivateData
OOOPrivateDataEnd
OOODestructor
{
}
OOODestructorEnd
OOOConstructor()
{
	OOOMapMethods
	OOOMapMethodsEnd
}
OOOConstructorEnd
#undef OOOClass

OOOTest(OOOModule)
{
	OOOModule * pModule = OOOConstruct(OOOModule);

	// Store the current constructors for future checks
	MyClass_constructor myClassConstructor = MyClass_construct;
	YourClass_constructor yourClassConstructor = YourClass_construct;

	// Verify that the current constructors are not NULL
	OOOCheck(myClassConstructor != NULL);
	OOOCheck(yourClassConstructor != NULL);

	// Register the MyClass constructor under "MyClass"
	OOOCall(pModule, set, "MyClass", MyClass_construct);

	// Shortcut for registering the YourClass constructor under "YourClass"
	OOOModuleExport(pModule, YourClass);

	// NULL out the existing constructors
	MyClass_construct = NULL;
	YourClass_construct = NULL;

	// Verify that the current constructors are now NULL
	OOOCheck(MyClass_construct == NULL);
	OOOCheck(YourClass_construct == NULL);

	// Set the MyClass constructor
	MyClass_construct = (MyClass_constructor) OOOCall(pModule, get, "MyClass");
	OOOCheck(MyClass_construct == myClassConstructor);

	// Shortcut to set the YourClass constructor
	OOOModuleLink(pModule, YourClass);
	OOOCheck(YourClass_construct == yourClassConstructor);

	OOODestroy(pModule);
}
