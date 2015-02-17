#pragma once

#include "Audio.h"

#include <map>

class CMusicSystem//the main music engine
{
public:
	ISoundEngine* engine;

	typedef std::map<std::string,CAudio*> TAudioList;
	TAudioList bgmList;
	TAudioList soundList;
	unsigned short currentBgmTrack;
	unsigned short currentSoundTrack;
	static CMusicSystem* instance;
private:
	bool allSoundPaused;
	bool allSoundMuted;
private:
	CMusicSystem(void);
	bool Init();
	bool CleanUp();
	bool Release();
public:
	static CMusicSystem* GetInstance();
	~CMusicSystem(void);

	//this function only add CAudio class to be managed under bgmlist without offical register as one of bgm tracks.
	bool RegisterAudioAsBgm(CAudio * a_audio);
	//this function only add CAudio class to be managed under soundlist without offical register as one of sound tracks.
	bool RegisterAudioAsSound(CAudio * a_audio);
	//this function add CAudio class to be managed under bgmlist with offical register as one of bgm tracks.
	bool InsertBGMTrack(std::string filename);
	//this function add CAudio class to be managed under soundlist with offical register as one of sound tracks.
	bool InsertSoundTrack(std::string filename);
	//play a offically register bgm track
	bool PlayBGMTrack(unsigned short trackindex);
	//play a offically register sound track
	bool PlaySoundTrack(unsigned short trackindex);
	//mute all audio
	bool Mute();
	//unmute all audio
	bool UnMute();
	//resume all audio
	bool Resume();
	//pause all audio
	bool Pause();
	//stop all audio
	bool StopAllSounds();
	//traverse to next or previous officially registered bgm track
	bool TranverseBGMTrack();
	//traverse to next or previous officially registered sound track
	bool TranverseSoundTrack();
	//switch between pause or unpause all audio
	bool ToggleAllAudioPause();
	//switch between mute or unmute all audio
	bool ToggleAllAudioMute();
	//check if the audio with the passed in name is still playing
	bool CheckAudioIsPlaying(std::string audioname);
	//check if the audio with the passed in name is still playing
	bool CheckAudioIsPlaying(const char* audioname);
	//set all audio to the volume.
	bool SetAllAudioVolume(float volume);
	//reset the whole music system
	bool Reset();
	//exit the music system
	bool Exit();
	//print out some debug information
	void PrintDebugInformation();
};

