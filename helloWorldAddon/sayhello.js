
const hello = require('./build/Release/node_hello'); // this is the path to the compiled module
var returnedString = hello.HelloFunction();

console.log(returnedString);
