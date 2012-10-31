OOOCode-Module
=================

Modules are collections of OOOCode classes that can be accessed by name. The OOOModule class is used
internally in module DLLs to expose classes

## Features

- Watch this space

## API

```C
#include "MyClass.h"
#include "YourClass.h"
#include "OOOModule.h"

// Construct a module instance
OOOModule * pModule = OOOConstruct(OOOModule);

// Register the MyClass constructor under "MyClass"
OOOCall(pModule, set, "MyClass", MyClass_construct);

// Shortcut for registering the YourClass constructor under "YourClass"
OOOModuleExport(pModule, YourClass);

// Set the MyClass constructor
MyClass_construct = (MyClass_constructor) OOOCall(pModule, get, "MyClass");

// Shortcut to set the YourClass constructor
OOOModuleLink(pModule, YourClass);

OOODestroy(pModule);
```

## Roadmap

* Should be possible to register a class constructor and then retrieve and link it by name

## Contributing

In lieu of a formal styleguide, take care to maintain the existing coding style. Add unit tests for any new or changed functionality. Lint and test your code using ``./grunt.sh`` or ``.\grunt.bat``.

## Prerequisites

- OpenTV SDK C2.2 from http://community.opentv.com

## Initialising

This projects references sub-modules so after cloning the repository...

```
git submodule init
git submodule update
```

Then the easiest way to work with the project in the OpenTV IDE...

1. Create a new workspace in the root of the project
1. In the IDE choose **File/Import...**
1. In the resulting dialog choose **General/Existing Projects Into Workspace** and press **Next**
1. Choose the **Select Root Directory:** Radio button and **Browse...** to the root of the project
1. A number of projects may be listed under **Projects**
1. Select the projects in the root, deselect those under the submodules folder and then click **Finish**
1. You should then be able to build the OpenTV projects by choosing **Project/Build All**

After you have built the projects at least once run the test application in the Virtual Set top box by...

1. Choosing the **ModuleFlow** project on the left
1. Pressing the green **Run** button at the top
1. In the resulting dialog choose **Local OpenTV Application** and press **OK**

## Release History
_(Nothing yet)_

## License
Copyright (c) 2012 Peter Halliday  
Licensed under the MIT license.