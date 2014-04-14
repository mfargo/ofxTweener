/*
 *  ofxTweener.h
 *  openFrameworks
 *
 *  Created by Sander ter Braak on 26-08-10.
 *
 */

#include "ofMain.h"
#include "ofxTransitions.h"

#ifndef _OFXTWEEN
#define _OFXTWEEN

#define TWEENMODE_OVERRIDE 0x01
#define TWEENMODE_SEQUENCE 0x02

class TweenEvent : public ofEventArgs {
public:
    TweenEvent(float * value) {
        _value = value;
    }
    virtual ~TweenEvent() {}
    
    float * getValue() { return _value; }
private:
    float * _value;
};


class Tween {
public:
	typedef float(ofxTransitions::* easeFunction)(float,float,float,float);
	float* _var;
	float _from, _to, _duration,_by, _useBezier;
	easeFunction _easeFunction;
	Poco::Timestamp _timestamp;
    
    ofEvent<TweenEvent> ON_COMPLETE;
};


class ofxTweener : public ofBaseApp {

public:
	
	ofxTweener();
	
	Tween * addTween(float &var, float to, float time);
	Tween * addTween(float &var, float to, float time, float (ofxTransitions::*ease) (float,float,float,float));
	Tween * addTween(float &var, float to, float time, float (ofxTransitions::*ease) (float,float,float,float), float delay);
	Tween * addTween(float &var, float to, float time, float (ofxTransitions::*ease) (float,float,float,float), float delay, float bezierPoint);
    
	
	void removeTween(float &var);	
	void setTimeScale(float scale);
	void update();
	void removeAllTweens();	
	void setMode(int mode);
	
	int getTweenCount();	
	
	
private:
	float				_scale;
	ofxTransitions		a;
	bool				_override;
	Tween * 			addTween(float &var, float to, float time, float (ofxTransitions::*ease) (float,float,float,float), float delay, float bezierPoint, bool useBezier);
	float				bezier(float b, float e, float t, float p);
	vector<Tween *>		tweens;
    
};


extern ofxTweener Tweener;
#endif