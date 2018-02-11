// STEP 1: WRITE THE C++ / v8 stuff

#include <nan.h>

// Create a native node function called HelloFunction
NAN_METHOD(HelloFunction) {
	auto message = Nan::New("Hello from C++!").ToLocalChecked();
	// this is the bridge to expose stuff between C++ and Javascript
	// the "return"
	info.GetReturnValue().Set(message);	
}

//Set up the initialization function called Init
NAN_MODULE_INIT(Init) {
	//export the hello function created above
	NAN_EXPORT(target, HelloFunction);
}

//Create the module called "hello" and set the initial function to be called
NODE_MODULE(node_hello, Init);