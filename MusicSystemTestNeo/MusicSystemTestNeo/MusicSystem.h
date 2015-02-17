#pragma once

#include <map>

#include <iostream>
#include <string>

#include "irrKlang.h"

using namespace irrklang;

class CAudio//provding a ease of level of control and bad pointer protection
{
public:
	ISound* audio;
	ISoundEffectControl* audioEffectControl;
	std::string name;
	vec3d<float> position;
public:
	CAudio()
		:
		audio(0)
		,audioEffectControl(0)
		,name(" ")
	{
	}
	inline bool Init(ISound* pointerfromengine)
	{
		if(pointerfromengine != 0 )
		{
			audio = pointerfromengine;
			return true;
		}
		return false;
	}
	inline void SetVolume(float volume)
	{
		if(audio != 0 )
		{
			if(volume <0)
			{
				volume = 0.f;
			}else
			{
				while(volume >1)
				{
					volume *= 0.1;
				}
			}
			std::cout<<volume<<std::endl;
			audio->setVolume(volume);
		}
	}
	inline float GetVolume()
	{
		if(audio != 0 )
		{
			return audio->getVolume();
		}
	}
	inline bool CheckIsPaused()
	{
		if(audio != 0 )
		{
			return audio->getIsPaused();
		}
	}
	inline bool CheckIsFinised()
	{
		if(audio != 0 )
		{
			return audio->isFinished();
		}
	}
	inline bool CheckIsLooped()
	{
		if(audio != 0 )
		{
			return audio->isLooped();
		}
	}
	inline void SetIsLooped(bool looped)
	{
		if(audio != 0 )
		{
			audio->setIsLooped(looped);
		}
	}
	inline void SetIsPaused(bool paused = true)
	{
		if(audio != 0 )
		{
			audio->setIsPaused(paused);
		}
	}
	inline void Stop()
	{
		if(audio != 0 )
		{
			audio->stop();
		}
	}
	inline bool Drop()
	{
		if(audio != 0 )
		{
			audio->drop();
		}
	}
	inline bool EnableAudioEffectControl()
	{	
		if(audio != 0 )
		{
			if(audioEffectControl == 0 )
			{
				audioEffectControl = audio->getSoundEffectControl();
				return true;
			}
		}
		return false;
	}
	inline bool DisableAllAudioEffect()
	{
		if(audio != 0 )
		{
			if(audioEffectControl != 0 )
			{
				audioEffectControl->disableAllEffects();
				return true;
			}
		}
		return false;	
	}
	inline bool EnableChorusEffect(float wetDryMix = 50.f,float depth = 10.f,float feedback = 25.f,float frequency = 1.100000024f,bool sineWaveForm = true,float delay = 16.f,int phrase = 90)
	{	
		if(audio != 0 )
		{
			if(audioEffectControl != 0 )
			{
				audioEffectControl->enableChorusSoundEffect(wetDryMix,depth,feedback,frequency,sineWaveForm,delay,phrase);
				return true;
			}
			return false;
		}
	}
	inline bool Release()
	{
		if(audio != 0 )
		{
			Drop();
			delete this;
			return true;
		}
		return false;
	};
	void PrintDebugInformation()
	{
		std::cout<<"Name: "<<name<<std::endl;
	};
};

class CMusicSystem//the main music engine
{
public:
	std::map<std::string,CAudio*> bgmList;
	std::map<std::string,CAudio*> soundList;
	unsigned short currentBgmTrack;
	unsigned short currentSoundTrack;
public:
	CMusicSystem(void);
	~CMusicSystem(void);

	bool InsertBGMTrack(std::string filename);
	bool InsertSoundTrack(std::string filename);
	void PlayBGMTrack(unsigned short trackindex);
	void PlaySoundTrack(unsigned short trackindex);
	void SetVolume(float newVolume);
	void Mute();
	void Resume();
	void Pause();
	void TranverseBGMTrack();
	void TranverseSoundTrack();

	bool Init();
	bool CleanUp();
	bool Reset();
	bool Release();

	void PrintDebugInformation();
};

