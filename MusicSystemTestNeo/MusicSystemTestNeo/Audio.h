#pragma once

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
private:
	//irrklang::vec3df* position;
public:
	CAudio()
		:
		audio(0)
		,audioEffectControl(0)
		,name(" ")
	{
		
	}
	~CAudio()
	{
		std::cout<<"Audio "<<name<<" is deleted"<<std::endl;
	}
	inline bool Init(ISound* pointerfromengine)
	{
		if(pointerfromengine)
		{
			audio = pointerfromengine;
			//position = &audio->getPosition();
			return true;
		}
		return false;
	}

	inline bool CleanUp()
	{
		return StopAndRelease();
	}

	inline bool Stop()
	{
		if(audio)
		{
			audio->stop();
			return true;
		}
		return false;
	}
	inline bool Drop()
	{
		if(audio)
		{
			return audio->drop();
		}
		return false;
	}
	inline bool StopAndRelease()
	{
		if(audio)
		{
			Stop();
			Drop();
			audio = 0;
			return true;

			//if(audio->drop())
			//{
			//	audio = 0;
			//	std::cout<<"dropped"<<std::endl;
			//	return true;
			//}
			//return false;
		}
		return false;
	}
	inline bool Release()
	{
		if(audio)
		{
			Drop();
			audio = 0;
			return true;
			//if(Drop())
			//{
			//	audio = 0;
			//	return true;
			//}
		}
		return false;
	};
	inline float GetAudioMaximumDistance()
	{
		if(audio)
		{
			return audio->getMaxDistance();		
		}
		return 0;
	}
	inline float GetAudioMinimumDistance()
	{
		if(audio)
		{
			return audio->getMinDistance();		
		}
		return 0;
	}
	//distance of which audio cannot get anymore quieter
	inline bool SetAudioMaximunDistance(float distance)
	{
		if(audio)
		{
			audio->setMaxDistance(distance);
			return true;
		}
		return false;
	}

	//distance of which the audio cannot get anymore louder
	inline bool SetAudioMinimunDistance(float distance)
	{
		if(audio)
		{
			audio->setMinDistance(distance);
			return true;
		}
		return false;
	}

	inline float GetPositionX()
	{	
		if(audio)
		{
			return audio->getPosition().X;
		}
		return 0 ;
	}
	inline float GetPositionY()
	{		
		if(audio)
		{
			return audio->getPosition().Y;
		}
		return 0 ;
	}
	inline float GetPositionZ()
	{
		if(audio)
		{
			return audio->getPosition().Z;
		}
		return 0 ;
	}
	inline float* GetPositionArray3D()
	{
		if(audio)
		{
			float temp[3] = {0,0,0};
			irrklang::vec3df *vectemp = &audio->getPosition();
			temp[0] = vectemp->X;
			temp[1] = vectemp->Y;
			temp[2] = vectemp->Z;
			return temp;
		}
		return 0;
	};

	inline irrklang::vec3df GetPositionVec3df()
	{
		if(audio)
		{
			return audio->getPosition();
		}
		return  irrklang::vec3df(0,0,0) ;
	}
	inline bool SetPositionX(float x)
	{
		if(audio)
		{
			audio->setPosition(irrklang::vec3df(x,GetPositionY(),GetPositionZ()));
			return true;
		}
		return false;
	}
	inline bool SetPositionY(float y)
	{
		if(audio)
		{
			audio->setPosition(irrklang::vec3df(GetPositionX(),y,GetPositionZ()));
			return true;
		}
		return false;
	}
	inline bool SetPositionZ(float z)
	{
		if(audio)
		{
			audio->setPosition(irrklang::vec3df(GetPositionX(),GetPositionY(),z));
			return true;
		}
		return false;
	}
	inline bool SetPosition(irrklang::vec3df newPosition)
	{
		if(audio)
		{
			audio->setPosition(newPosition);
			return true;
		}
		return false;
	}
	inline bool SetPosition(float x,float y,float z)
	{
		if(audio)
		{
			audio->setPosition(irrklang::vec3df(x,y,z));
			return true;
		}
		return false;
	}
	inline bool SetPosition(float newPosition[3])
	{
		if(audio)
		{
			audio->setPosition(irrklang::vec3df(newPosition[0],newPosition[1],newPosition[3]));
			return true;
		}
		return false;
	}
	inline bool SetVolume(float volume)
	{
		if(audio)
		{
			if(volume <0)
			{
				volume = 0.f;
			}else
			{
				while(volume >1)
				{
					volume *= 0.1f;
				}
			}
			//std::cout<<volume<<std::endl;
			audio->setVolume(volume);
			return true;
		}
		return false;
	}
	inline float GetVolume()
	{
		if(audio)
		{
			return audio->getVolume();
		}
		return 0;
	}
	inline bool CheckIsPaused()
	{
		if(audio)
		{
			return audio->getIsPaused();
		}
		return false;
	}
	inline bool CheckIsFinised()
	{
		if(audio)
		{
			return audio->isFinished();
		}
		return false;
	}
	inline bool CheckIsLooped()
	{
		if(audio)
		{
			return audio->isLooped();
		}
		return false;
	}
	inline bool SetIsLooped(bool looped)
	{
		if(audio)
		{
			audio->setIsLooped(looped);
			return true;
		}
		return false;
	}
	inline bool SetIsPaused(bool paused = true)
	{
		if(audio)
		{
			audio->setIsPaused(paused);
			return true;
		}
		return false;
	}
	inline bool EnableAudioEffectControl()
	{	
		if(audio)
		{
			if(!audioEffectControl)
			{
				audioEffectControl = audio->getSoundEffectControl();
				return true;
			}
		}
		return false;
	}
	inline bool DisableAllAudioEffect()
	{
		if(audio)
		{
			if(audioEffectControl)
			{
				audioEffectControl->disableAllEffects();
				return true;
			}
		}
		return false;	
	}
	inline bool EnableChorusEffect(float wetDryMix = 50.f,float depth = 10.f,float feedback = 25.f,float frequency = 1.100000024f,bool sineWaveForm = true,float delay = 16.f,int phrase = 90)
	{	
		if(audio)
		{
			if(audioEffectControl)
			{
				audioEffectControl->enableChorusSoundEffect(wetDryMix,depth,feedback,frequency,sineWaveForm,delay,phrase);
				return true;
			}	
		}
		return false;
	}

	inline bool Move(float newPosition[3])
	{
		if(audio)
		{
			float* ownposition = GetPositionArray3D();
			SetPosition(ownposition[0] + newPosition[0],ownposition[1] + newPosition[1],ownposition[2] + newPosition[2]);
			return true;
		}
		return false;
	}
	inline bool Move(float x,float y,float z)
	{
		if(audio)
		{
			float* ownposition = GetPositionArray3D();
			SetPosition(ownposition[0] + x,ownposition[1] + y,ownposition[2] + z);
			return true;
		}
		return false;
	}
	inline bool Move(irrklang::vec3df newPosition)
	{
		if(audio)
		{
			irrklang::vec3df *ownposition = &GetPositionVec3df();
			SetPosition(ownposition->X + newPosition.X,ownposition->Y + newPosition.Y,ownposition->Z + newPosition.Z);
			return true;
		}
		return false;
	}
	inline void PrintDebugPosition()
	{
		std::cout<<"Position: X:"<<GetPositionX()<<" , "<<GetPositionY()<<" , "<<GetPositionZ()<<std::endl;
	}
	inline void PrintDebugName()
	{
		std::cout<<"Name: "<<name<<std::endl;
	}
	inline void PrintDebugPointer()
	{
		std::cout<<"Audio Pointer: "<<audio<<std::endl;
		std::cout<<"Audio SFX Pointer: "<<audioEffectControl<<std::endl;
	}
	inline void PrintDebugInformation()
	{	
		PrintDebugPosition();
		PrintDebugName();
	};
};