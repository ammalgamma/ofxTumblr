/*
 *  ofxTumblr.h
 *  ofxTumblr
 *
 *  Created by igor line on 26/4/11.
 *  Copyright 2011 \line\o\i\\. All rights reserved.
 *
 */

#ifndef OFXTUMBRL_H_
#define OFXTUMBRL_H_

#include "ofxHttpUtils.h"

class ofxTumblr{
	
public:
	
	ofxTumblr();
	~ofxTumblr();
	void setup(string login, string password, string actionUrl);
	
	//FIXME: Definition for several post types
	bool sendRegular(string body, string title = "");
	
	void responseEvent(ofxHttpResponse & response);

private:
	
	ofxHttpForm form;
	ofxHttpUtils httpUtils;
	
	string login;
	string password;
	string actionUrl;
	
	
};

#endif /* OFXTUMBRL_H_ */
