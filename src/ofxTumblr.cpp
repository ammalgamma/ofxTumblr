/*
 *  ofxTumblr.cpp
 *  ofxTumblr
 *
 *  Created by igor line on 12/10/11.
 *  Copyright 2011 \line\o\i\\. All rights reserved.
 *
 */

#include "ofxTumblr.h"

ofxTumblr::ofxTumblr(){
	
};

ofxTumblr::~ofxTumblr(){
	ofRemoveListener(httpUtils.newResponseEvent, this, &ofxTumblr::responseEvent);
	
}

void ofxTumblr::setup(string _login, string _password, string _actionUrl){
	login = _login;
	password = _password;
	actionUrl = _actionUrl;
	
	ofLog(OF_LOG_VERBOSE, "ofxTumblr started");
	
	ofAddListener(httpUtils.newResponseEvent, this, &ofxTumblr::responseEvent);
	
	httpUtils.start();
}

bool ofxTumblr::sendRegular(string body, string title){
	
	form.action = actionUrl;
	form.method = OFX_HTTP_POST;
	form.addFormField("email", login);
	form.addFormField("password", password);
	form.addFormField("type", "regular");
	
	form.addFormField("title", title);
	form.addFormField("body", body);
	
	//FIXME: Need to create a queue for several posts
	
	httpUtils.addForm(form);
	
};

void ofxTumblr::responseEvent(ofxHttpResponse &response){
	if(response.status == 201){
		ofLog(OF_LOG_VERBOSE, "posted successfully");
		
	}else{
		//FIXME: Verbose errors
		
	}
}