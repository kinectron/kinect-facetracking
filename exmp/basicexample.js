var Kinect2 = require('../lib/kinect2');

var kinect = new Kinect2();

if(kinect.open()) {
	console.log("Kinect Opened");
	//listen for body frames

	// kinect.on('bodyFrame', function(bodyFrame){
	// 	for(var i = 0;  i < bodyFrame.bodies.length; i++) {
	// 		if(bodyFrame.bodies[i].tracked) {
	// 			console.log(bodyFrame.bodies[i]);
	// 		}
	// 	}
	// });

	//write a new example that opens the face reader
	//need to add to the library, as well as the module
	kinect.on('faceFrame', function(faceFrame){
		console.log(faceFrame);
	});

	kinect.openFaceReader();
	

	//request body frames
	//kinect.openBodyReader();

	//close the kinect after 5 seconds
	setTimeout(function(){
		//kinect.removeAllListeners('bodyFrame');
		kinect.removeAllListeners('faceFrame');
		kinect.close();
		console.log("Kinect Closed");
	}, 5000);
}
