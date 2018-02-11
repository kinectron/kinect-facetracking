# Setup
1. Install Python 2.7 and Node (http://blog.teamtreehouse.com/install-node-js-npm-windows)
3. Install Visual Studio 2013. There are more up to date Visual Studios available, but they're complicated to get the Kinect SDK examples running. I found it was quicker and easier to download the older release. 

# Understanding the SDK
Open Visual Studio 2013 and open the "FaceBasics-D2D" example. You can run this by plugging in the Kinect and then accessing "Debug > Start Debug" from the menu bar. Position the Kinect in a place where it can see most of your body, otherwise it will not detect you.

I started by trying to understand the Kinect SDK example It was helpful to understand the general properties of face-tracking but as with a lot of Microsoft code, it’s complicated and a lot of pointers. A key take-away from the example was understanding that the face-tracking data isn't its own stream, but a combination of the body and color streams. I found Vangos Pterneas has a thorough blog post explaining the [different streams](https://pterneas.com/2014/02/20/kinect-for-windows-version-2-color-depth-and-infrared-streams/) and another explaining the [face stream.](https://pterneas.com/2014/12/21/kinect-2-face-basics/)

# Understanding the Wouter verWeirder's Kinect2 module
Fortunately, Wouter ver Weirder has exposed most of the data streams from the Kinect 2 to javascript in his [Kinect2 module](ttps://github.com/wouterverweirder/kinect2). Before building out the face tracking methods, I read through his code and commented it extensively. This can be found in the "kinect2.cc" file in the "src" folder of this repo. The code for each data stream follows a similar pattern:
`NAUV_WORK_CB(Progress)`
..*Sets up the thread buffer
`HRESULT process Data Function(argument)`
..*Where we do any modification / conversion / analysis of data from the readers
`void Thread Loop Function(argument)`
..*This has to do with threading and memory management, passing into the buffer for V8
`NAN_METHOD(Open Reader)`
..*This is where the relevant readers are opened and frames are received
`NAN_METHOD(Close Reader)`
..*Close the readers

After adding in all the comments, the code is still able to compile by running `node-pre-gyp rebuild`. With the new library build, I confirmed that it still worked by running a basic skeleton tracking example which prints out the joint data. The example is available in the examples folder.

# Building out the Face Tracking Functionality
Following ver Weirder's patterns, I paralleled them for the face tracking. However, the Kinect2.face.dll had to be added to the binding.gyp file as it has methods and functions specific to face tracking that aren't included in the base ddl. 

As mentioned above, the face data isn't its own stream and thus a [Face Frame Source](https://msdn.microsoft.com/en-us/library/microsoft.kinect.face.createfaceframesource.aspx) must be constructed. As arguments, the function takes `the sensor, initial tracking ID, features to detect, what source to be assigned to` as arguments. While including the face .dll allowed the add-on to successfully compile, it still isn't functional. Seemingly, the face frame source is still being created properly. This might be because of bad pointers, or maybe threading is required as multiple data streams are required, or I might be missing a step need prior.







