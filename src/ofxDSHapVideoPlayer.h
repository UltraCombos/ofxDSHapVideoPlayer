
//ofxDSHapVideoPlayer written by Jeremy Rotsztain and Philippe Laurheret for Second Story, 2015
//DirectShowVideo and ofDirectShowPlayer written by Theodore Watson, Jan 2014
//See the cpp file for the DirectShow implementation 

#pragma once 

#include "ofMain.h"
#include "HapShared.h"

class DirectShowHapVideo;

class ofxDSHapVideoPlayer : public ofBaseVideoPlayer {

	public:

		ofxDSHapVideoPlayer();
		~ofxDSHapVideoPlayer();

		void enableAbsPath(bool yes);
		bool load(string path) override;
		void update() override;
		void waitUpdate(long milliseconds);
		void writeToTexture(ofTexture& texture);
		void draw(int x, int y, int w, int h);
		void draw(int x, int y) { draw(x, y, getWidth(), getHeight()); }
		void drawSubsection(float x, float y, float w, float h, float sx, float sy, float _sw, float _sh) const;

		 void				close() override;
	
		 void				play() override;
		 void				pause();
		 void				stop() override;
	
		 bool 				isFrameNew() const override;
		 ofPixels &		 	getPixels() override; // @NOTE: return uncompressed pixels
		 const ofPixels &    getPixels() const override;
	     //unsigned char *	getPixels();
	
		 float 				getWidth() const override;
		 float 				getHeight() const override;
	
		 bool				isPaused() const override;
		 bool				isLoaded() const override;
		 bool				isPlaying() const override;
	
		 bool setPixelFormat(ofPixelFormat pixelFormat) override;
		 ofPixelFormat 		getPixelFormat() const override;
         ofShader           getShader();
         ofTexture *        getTexturePtr() override;

		 float 				getPosition() const override;
		 float 				getSpeed() const override;
		 float 				getDuration() const override;
		 bool				getIsMovieDone() const override;
	
		 void 				setPaused(bool bPause) override;
		 void 				setPosition(float pct) override;
		 void 				setVolume(float volume) override; // 0..1
		 void 				setLoopState(ofLoopType state) override;
		 void   			setSpeed(float speed) override;
		 void				setFrame(int frame) override;  // frame 0 = first frame...
	
		 int				getCurrentFrame() const override;
		 int				getTotalNumFrames() const override;
		 ofLoopType			getLoopState() const override;
	
		 void				firstFrame() override;
		 void				nextFrame() override;
		 void				previousFrame() override;

         enum               HapType {
                                HAP,
                                HAPALPHA,
                                HAPQ
                            };

         HapType            getHapType();

		 int				height;
		 int				width;

	protected:

		// using DS for grabbing frames
		DirectShowHapVideo * player;
		
		// hap shader (for YCoCg)
		ofShader shader; 
		bool bShaderInitialized;
		bool bEanbleAbsPath;

		ofPixels pix; // copy of compressed pixels
		ofTexture tex; // texture for pix

		HapTextureFormat textureFormat;
};