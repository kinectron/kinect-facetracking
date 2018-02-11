
# Getting Started with C++
Take some time to get familiar with a Windows development environment. The links below were good starting points. Eventually I only used Visual Studio to examine the Kinect SDK examples while writing my own code primarily using Sublime Text and Atom, and compiling it via the command line.
*[https://github.com/Microsoft/nodejs-guidelines/blob/master/windows-environment.md](https://github.com/Microsoft/nodejs-guidelines/blob/master/windows-environment.md)
*[https://github.com/bcoe/awesome-cross-platform-nodejs](https://github.com/bcoe/awesome-cross-platform-nodejs)
*[https://github.com/Microsoft/nodejs-guidelines/blob/master/windows-environment.md#editors-and-ides](https://github.com/Microsoft/nodejs-guidelines/blob/master/windows-environment.md#editors-and-ides)

# Compiling and Writing Native Node Add-ons
Before starting to write the add-on for exposing the Kinect face-tracking, I wrote a very simple "Hello World" add-on to understand the links between the different files. This add-on can be found in the "helloWorldAddon" folder of this repo, with comments throughout. The 'hello.cc' file uses the nan module to expose functions and their outcomes to javascript. The 'sayhello.js' file demonstrates the module in action. 

I found the following tutorials to be the most helpful without being overwhelming. As I continued to develop the face-tracking module, I would return to the tutorials when debugging. 
*[Marcin Baraniecki, Extending Nodejs with Native C Modules](https://medium.com/@marcinbaraniecki/extending-node-js-with-native-c-modules-63294a91ce4)
*[Tutsplus.com, Writing Nodejs Addons](https://code.tutsplus.com/tutorials/writing-nodejs-addons--cms-21771)
*[Hackernoon.com, Getting Started With Writing C Addons For Nodejs](https://hackernoon.com/n-api-and-getting-started-with-writing-c-addons-for-node-js-cf061b3eae75)
*[Risingstack.com, Writing Native Nodejs Modules](https://blog.risingstack.com/writing-native-node-js-modules/)
*[Nodejs, Node Addon Examples](https://github.com/nodejs/node-addon-examples)
*[Microsoft, Nodejs Guidelines](https://github.com/Microsoft/nodejs-guidelines/blob/master/windows-environment.md#compiling-native-addon-modules)

# Useful Libraries
The key libraries for building native libraries are Node-Gyp and NAN. Node-Gyp compiles the add-on while NAN provides a bridge between C++ and Javascript.

[https://github.com/nodejs/node-gyp/](https://github.com/Microsoft/nodejs-guidelines/blob/master/windows-environment.md#compiling-native-addon-modules)

Native Abstractions for Node are the bridge between the C++ and Javascript code [https://github.com/nodejs/nan](https://github.com/nodejs/nan)

# Microsoft Kinect SDK
I constantly found myself lost in the Microsoft documentation. These are the links I kept coming back so:
*[Description of face tracking](https://msdn.microsoft.com/en-us/library/dn782034.aspx#ID4E3B)
*[Create face frame source](https://msdn.microsoft.com/en-us/library/microsoft.kinect.face.createfaceframesource.aspx)
*[Get face frame source](https://msdn.microsoft.com/en-us/library/microsoft.kinect.face.ifaceframereader.get_faceframesource.aspx)
*[Face frame result](https://msdn.microsoft.com/en-us/library/microsoft.kinect.face.ifaceframeresult.aspx)
*[Kinect interfaces](https://msdn.microsoft.com/en-us/library/dn758674.aspx)
*[Kinect structures](https://msdn.microsoft.com/en-us/library/dn758676.aspx)
