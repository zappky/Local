#include "MusicSystem.h"

CMusicSystem* CMusicSystem::instance = 0;

CMusicSystem::CMusicSystem(void)
	:engine(0)
	,allSoundPaused(false)
	,allSoundMuted(false)
{
	Init();
}

CMusicSystem::~CMusicSystem(void)
{
}

CMusicSystem* CMusicSystem::GetInstance()
{
	if(instance == 0)
	{
		instance = new CMusicSystem();
	}

	return instance;
}

bool CMusicSystem::RegisterAudioAsBgm(CAudio * a_audio)
{
	if(engine)
	{
		bgmList.insert(std::make_pair( a_audio->name, a_audio));
		return true;
	}
	return false;
}

bool CMusicSystem::RegisterAudioAsSound(CAudio * a_audio)
{
	if(engine)
	{
		soundList.insert(std::make_pair( a_audio->name, a_audio));
		return true;
	}
	return false;
}

bool CMusicSystem::InsertBGMTrack(std::string filename)
{
	if(engine)
	{
		return true;
	}
	return false;
}

bool CMusicSystem::InsertSoundTrack(std::string filename)
{
	if(engine)
	{
		return true;
	}
	return false;
}

bool CMusicSystem::PlayBGMTrack(unsigned short trackindex)
{
	if(engine)
	{
		
		return true;
	}
	return false;
}

bool CMusicSystem::PlaySoundTrack(unsigned short trackindex)
{
	if(engine)
	{
		return true;
	}
	return false;
}

bool CMusicSystem::SetAllAudioVolume(float volume)
{
	if(engine)
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
		engine->setSoundVolume(volume);
		return true;
	}
	return false;
}
bool CMusicSystem::UnMute()
{
	if(allSoundMuted)//if there are sound to unmute then bother to go in.
	{
		if(engine)
		{
			engine->setSoundVolume(1.f);
			return true;
		}
	}
	return false;
}
bool CMusicSystem::Mute()
{
	if(!allSoundMuted)//if there are sound to mute then bother to go in.
	{
		if(engine)
		{
			engine->setSoundVolume(0.f);
			return true;
		}
	}
	return false;
}

bool CMusicSystem::ToggleAllAudioMute()
{
	if(engine)
	{
		allSoundMuted = !allSoundMuted;
		if(allSoundMuted)
		{
			engine->setSoundVolume(0.f);
		}else
		{
			engine->setSoundVolume(1.f);
		}
		return true;
	}
	return false;
}

bool CMusicSystem::ToggleAllAudioPause()
{
	if(engine)
	{
		allSoundPaused = !allSoundPaused;
		engine->setAllSoundsPaused(allSoundPaused);
		return true;
	}
	return false;
}

bool CMusicSystem::Resume()
{
	if(engine)
	{
		allSoundPaused = false;
		engine->setAllSoundsPaused(false);
		return true;
	}
	return false;
}

bool CMusicSystem::Pause()
{
	if(engine)
	{
		allSoundPaused = true;
		engine->setAllSoundsPaused(true);

		return true;
	}
	return false;
}

bool CMusicSystem::StopAllSounds()
{
	if(engine)
	{
		engine->stopAllSounds();
		return true;
	}
	return false;
}

bool CMusicSystem::TranverseBGMTrack()
{
	if(engine)
	{
		return true;
	}
	return false;
}

bool CMusicSystem::TranverseSoundTrack()
{
	if(engine)
	{
		return true;
	}
	return false;
}

bool CMusicSystem::CheckAudioIsPlaying(std::string audioname)
{
	if(engine)
	{
		return engine->isCurrentlyPlaying(audioname.c_str());
	}
	return false;
}

bool CMusicSystem::CheckAudioIsPlaying(const char* audioname)
{
	if(engine)
	{
		return engine->isCurrentlyPlaying(audioname);
	}
	return false;
}

bool CMusicSystem::Init()
{
	engine = createIrrKlangDevice();

	if(engine)
	{
		return true;
	}

	return false;
}

bool CMusicSystem::CleanUp()
{
	if(engine)
	{
		engine->stopAllSounds();

		TAudioList::iterator it;

		for(it = bgmList.begin(); it!= bgmList.end();++it)
		{
			(*it).second->CleanUp();
			(*it).second = 0;
		
			//bgmList.erase(it);
		}

		for(it = soundList.begin(); it!= soundList.end();++it)
		{
			(*it).second->CleanUp();
			(*it).second = 0;
		
			//soundList.erase(it);
		}

		bgmList.clear();
		soundList.clear();

		//engine->drop();
		//engine = 0;
		return true;
	}
	return false;
}

bool CMusicSystem::Reset()
{
	if(engine)
	{
		if(CleanUp() && Init())
		{
			return true;
		}
	}else
	{
		return Init();
	}
	return false;
}

bool CMusicSystem::Release()
{
	if(engine)
	{
		engine->drop();
		engine = 0;
		delete this;

		return true;
	}
	return false;
}

bool CMusicSystem::Exit()
{
	if(engine)
	{
		if(CleanUp() && Release())
		{
			return true;
		}
	}
	return false;
}

void CMusicSystem::PrintDebugInformation()
{
}