#ifndef Kinect2_Structs_h
#define Kinect2_Structs_h

#include "Globals.h"

// I think I will need to add stuff here for the face
// I think these are all just properties he came up with

// Structures are just properties (basically just like an object, but no methods)

typedef struct _JSJoint
{
	float depthX;
	float depthY;
	float colorX;
	float colorY;
	float cameraX;
	float cameraY;
	float cameraZ;
	//
	bool hasFloorData;
	float floorDepthX;
	float floorDepthY;
	float floorColorX;
	float floorColorY;
	float floorCameraX;
	float floorCameraY;
	float floorCameraZ;
	//
	float orientationX;
	float orientationY;
	float orientationZ;
	float orientationW;
	//
	int jointType;
} JSJoint;

typedef struct _JSBody
{
	bool tracked;
	bool hasPixels;
	UINT64 trackingId;
	char leftHandState;
	char rightHandState;
	JSJoint joints[JointType_Count];
} JSBody;

typedef struct _JSBodyFrame
{
	JSBody bodies[BODY_COUNT];
	//
	bool hasFloorClipPlane;
	float floorClipPlaneX;
	float floorClipPlaneY;
	float floorClipPlaneZ;
	float floorClipPlaneW;
	//
	float cameraAngle;
	float cosCameraAngle;
	float sinCameraAngle;
} JSBodyFrame;


// ADDED face structures
// do i need this one? below?....yes, so that I can identify the diff points?
typedef struct _JSPointF	// pointF is analogous to joint, but on the face...do I need this
{
	float X;
	float Y;
} JSPointF;

typedef struct _JSBoundBox
{
	float bottom;
	float left;
	float right;
	float top;
} JSBoundBox;

typedef struct _JSFace
{
	bool tracked;
	UINT64 trackingId;
} JSFace;

// ADDED faceframe structure
typedef struct _JSFaceFrame
{
	JSFace faces[BODY_COUNT];
} JSFaceFrame;



#endif
