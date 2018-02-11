var Kinect2 = require('../lib/kinect2');

var kinect = new Kinect2();

if(kinect.open()) {
	console.log("Kinect Opened");
	
	// kinect.on('bodyFrame', function(bodyFrame){
	// 	for(var i = 0;  i < bodyFrame.bodies.length; i++) {
	// 		if(bodyFrame.bodies[i].tracked) {
	// 			console.log(bodyFrame.bodies[i]);
	// 		}
	// 	}
	// });
	// //request body frames
	// kinect.openBodyReader();

	//listen for face frames
	// kinect.on('faceFrame', function(faceFrame){
	// 	console.log(faceFrame);
	// });
	// request face frames
	// kinect.openFaceReader();
	



	//close the kinect after 5 seconds
	setTimeout(function(){
		kinect.removeAllListeners('bodyFrame');
		//kinect.removeAllListeners('faceFrame');
		kinect.close();
		console.log("Kinect Closed");
	}, 5000);
}
