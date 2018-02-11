# Questions
## What is the .h file versus the .cc file?
.h is a header file that can be included elsewhere. It usually contains function prototypes.
.cc is an implementation file

```c++
#include "myLib.h"
int square(int x)
{
	return x*x;
}
```

## What is a .dll or .so file?
.dll is a dynamically linked library. It's a compiled implementation which allows libraries to be distributed. With .dlls, only the header file containing the prototypes just needs to be included, which will reference the .dll
dynamically linked library. In this instance, it was important because Kinect needs two libraries included — the base one and an additional one for the face tracking.

## What is a binding file?
The binding file is used by node-gyp to create build files for the add-on. Within the binding tile, the target_name is anything you want to use to identify the add-on. The sources array contains all the code required for compiling the add-on.

## What is the package.json file?
The package.json file lists all dependencies associated with the model. When you're first creating a module, the command
`npm init -y` creates the package.json file. Any time you install additional dependencies, add `--save` to the end of the install command and it will be added to the package.json.

It can also include scripts, making the build reproducible, testable, and easily shareable. For example: 
``` javascript
"install": "node-pre-gyp install --fallback-to-build",
"compile": "node-pre-gyp rebuild",
```

For further information, [NPM has a thorough write up](https://docs.npmjs.com/getting-started/using-a-package.json).